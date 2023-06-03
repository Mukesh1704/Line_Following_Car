#include <RedBot.h>   // Only Headerfile needed
#define Right_Sensor A0     // Intialize the Right Sensor of the car with a pin or making a Variable.
#define Left_Sensor A1    // Initialize the Left Sensor of the Car with a pin or making a Variable.
#define Engiene_1 5   // Initializing the pins for the control of the first Motor of the Car or making a Variable.
#define Engiene_2 6   // Initializing the pins for the second Motor of the Car or making a Variable.
#define IN_1 7    // Initializing the pin for one direction of the 1st Motor or making a Variable.
#define IN_2 10   // Initializing the pin for the other Direction of the 1st Motor or making a Variable.
#define IN_3 9    // Initializing the pin for the one direction of the 2nd Motor or making a Variable.
#define IN_4 8    // Initializing the pin for the other direction of the 2nd Motor or making a Variable.

int Motor_Speed = 1;    // Initializing the Speed of the Motor in an integer value.
int Turn_Speed = 1;   // Initializing the Speed of the Motor when the car turns in an integer value. 

void setup() {

Serial.begin ();    // Beggining the Serial Monitor and Serial Plotter for later use.

pinMode (Right_Sensor, INPUT);    // Declaring the Right sensor as INPUT or a component which is giving info to us.
pinMode (Left_Sensor, INPUT);   // Declaring the Left sensor as INPUT or a component which is giving info to us
pinMode (Engiene_1, OUTPUT);    // Declaring the Variable as OUTPUT or a component which we order to do something
pinMode (Engiene_2, OUTPUT);    // Declaring the Variable as OUTPUT or a component which we order to do something
pinMode (IN_1, OUTPUT);   // Declaring the Variable as OUTPUT or a component which we order to do something
pinMode (IN_2, OUTPUT);   // Declaring the Variable as OUTPUT or a component which we order to do something
pinMode (IN_3, OUTPUT);   // Declaring the Variable as OUTPUT or a component which we order to do something
pinMode (IN_4, OUTPUT);   // Declaring the Variable as OUTPUT or a component which we order to do something
}

void loop()   // Main Code comes here because it runs again and again 
{

int ls=digitalRead(Left_Sensor);    // We are making a new Variable which gets the value of the Left Sensor   
Serial.print("Left_Sensor Value:  ");  // When you upload the code you will see what is in the ""  
Serial.print (ls);    // We are ordering ls to show us the values of the Left Sensor in the Serial Monitor and Plotter
Serial.print ("                               ")    // We are ordering to print spaces
int rs=digitalRead(Right_Sensor);   // We are making a new Variable which gets the value of the Right Sensor   
Serial.print("right_Sensor Value:  ");    // When you upload the code you will see what is in the ""    
Serial.print (rs);    // We are ordering ls to show us the values of the Left Sensor in the Serial Monitor and Plotter    
delay (5000);   // We are letting it make a pause after every time it repeats

// IF condition makes it easier when you want something specific to happen in a a specific condition.

if ((rs=0)&& (ls=0))  
{Forward ();}         

else if ((rs=1)&&(ls=0))
{Turn_Right ();}

else if ((rs=0)&(ls=1));
{Turn_Right ();}

else
{Stop ();}
}


void Forward ()
{
  digitalWrite ( Engiene_1, Motor_Speed);
  digitalWrite ( Engiene_2, Motor_Speed);
  digitalWrite ( IN_1, LOW);
  digitalWrite ( IN_2, HIGH);
  digitalWrite ( IN_3, LOW);
  digitalWrite ( IN_4, HIGH);
  }

void Turn_Left ()
{
  digitalWrite ( Engiene_1, Motor_Speed);
  digitalWrite ( Engiene_2, Turn_Speed);
  digitalWrite ( IN_1, HIGH);
  digitalWrite ( IN_2, LOW);
  digitalWrite ( IN_3, LOW);
  digitalWrite ( IN_4, LOW);
  }

void Turn_Right ()
{
  
  digitalWrite ( Engiene_1, Turn_Speed);
  digitalWrite ( Engiene_2, Motor_Speed);
  digitalWrite ( IN_1, LOW);
  digitalWrite ( IN_2, LOW);
  digitalWrite ( IN_3, HIGH);
  digitalWrite ( IN_4, LOW);  
  }  

void Stop ()

{
  
  digitalWrite ( Engiene_1, Turn_Speed);
  digitalWrite ( Engiene_2, Motor_Speed);
  digitalWrite ( IN_1, LOW);
  digitalWrite ( IN_2, LOW);
  digitalWrite ( IN_3, LOW);
  digitalWrite ( IN_4, LOW);  
  }
