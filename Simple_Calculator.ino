
#include <Keypad.h> 
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns as this is a 4*4 Keypad

char keys[ROWS][COLS] = {

{'7','8','9','/'},

{'4','5','6','*'},

{'1','2','3','-'},

{'c','0','=','+'}

}; // defining the keys in the keypad

byte rowPins[ROWS] = { 13, 12, 11, 10 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 9, 8, 7, 6 }; // Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Create the Keypad variable to identify and store the pressed key.



double Result,Num1,Num2,Number; // defining the variables for the operations
char key,action;
boolean result = false; // boolean variable so that we display the result whenever its available

void setup() {
Serial.begin(9600);
}

void loop() {

key = kpd.getKey(); // for storing pressed key value in a character variable (char)

if (key!= 0)
DetectButtons(); // Identify which button is being pressed and work accordingly

if (result==true)
CalculateResult(); // If the result needs to be calculated then this function will take care of it
result = false; 
 
}

void DetectButtons()
{

if (key=='c') //If cancel Button is pressed perform the below mentioned equation or function
{Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}

if (key == '1') //If Button 1 is pressed
{Serial.println ("Button 1");
if (Number==0)
Number=1;
else
Number = (Number*10) + 1; // Perform this if the button is Pressed twice
}

if (key == '4') //If Button 4 is pressed
{Serial.println ("Button 4");
if (Number==0)
Number=4;
else
Number = (Number*10) + 4; // Perform this if the button is Pressed twice
}

if (key == '7') //If Button 7 is pressed
{Serial.println ("Button 7");
if (Number==0)
Number=7;
else
Number = (Number*10) + 7; // Perform this if the button is Pressed twice
}


if (key == '0')
{Serial.println ("Button 0"); //Button 0 is Pressed
if (Number==0)
Number=0;
else
Number = (Number*10) + 0; // Perform this if the button is Pressed twice
}

if (key == '2') //Button 2 is Pressed
{Serial.println ("Button 2");
if (Number==0)
Number=2;
else
Number = (Number*10) + 2; // Perform this if the button is Pressed twice
}

if (key == '5')
{Serial.println ("Button 5");
if (Number==0)
Number=5;
else
Number = (Number*10) + 5; //Pressed twice
}

if (key == '8')
{Serial.println ("Button 8");
if (Number==0)
Number=8;
else
Number = (Number*10) + 8; //Pressed twice
}



if (key == '=')
{Serial.println ("Button Equal");
Num2=Number;
result = true;
}

if (key == '3')
{Serial.println ("Button 3");
if (Number==0)
Number=3;
else
Number = (Number*10) + 3; //Pressed twice
}

if (key == '6')
{Serial.println ("Button 6");
if (Number==0)
Number=6;
else
Number = (Number*10) + 6; //Pressed twice
}

if (key == '9')
{Serial.println ("Button 9");
if (Number==0)
Number=9;
else
Number = (Number*10) + 9; //Pressed twice
}

if (key == '+' || key == '-' || key == '*' || key == '/') //Detecting Buttons on Column 4
{
Num1 = Number;
Number =0;
if (key == '+')
{Serial.println ("Addition"); action = '+';}
if (key == '-')
{Serial.println ("Subtraction"); action = '-'; }
if (key == '*')
{Serial.println ("Multiplication"); action = '*';}
if (key == '/')
{Serial.println ("Devesion"); action = '/';}

delay(100);
}

}

void CalculateResult()
{
if (action=='+')
Number = Num1+Num2;

if (action=='-')
Number = Num1-Num2;

if (action=='*')
Number = Num1*Num2;

if (action=='/')
Number = Num1/Num2;

Result = Number;
Serial.println(Result); // Display the obtained result on the Display or serial monitor
}
