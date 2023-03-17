#include <Servo.h> //servo library
#include <Keypad.h> //keypad library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <IRremoteInt.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo1;

int pos1 = 0; // position of servo motor 0 - 180 or 0 - 360
int IRPin = 7;

long reset;
long irResult;

IRrecv receiver(IRPin);
decode_results results;

const byte ROWS = 3; //delcaring the ammount of rows for keypad
const byte COLS = 2; //declaring the ammount of coloumns for keypad

char hexaKeys[ROWS][COLS] = { //matrix of the keypad
  {'1', '2'},
  {'4', '5'},
  {'7', '8'},
};

byte rowPins[ROWS] = {6,5,4}; //assigning keypad rows to pins
byte colPins[COLS] = {3, 2}; //assigning keypad coloumns to pins4
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //creating the keypad?

char snack; //variable that will hold value of which servo motor to turn
int servoNum;

int curr{0};// the users inputed cash

unsigned long timer1 = 0;
char lang{'E'};

void turnServo(int);

void setup()
{
  receiver.enableIRIn();
  Serial.begin(9600);
  myservo1.attach(0);
  lcd.init();
  lcd.backlight();
}

void loop(){
    timers();
  //if theres enough money let user choose snack

  
  if(curr >= 1){
    //promt user to pick a snack
	  startMsg();
    //wait for user to input snack number
    char wait = customKeypad.waitForKey();
    Serial.println(wait);
    snack = wait;
    dispenseingMsg();
    //dispense snack
    turnServo( snackSelection(snack) );
    //charge user for snack
    decrementFunds();
  }else{
    noFundsMsg(); //Display no funds message
    if(receiver.decode(&results)){
      //Serial.println(results.value, DEC);
      reset = (results.value); //save ir remote input to reset variable
      receiver.resume();
    }
    if(reset == 16748655){ //check if reset is equal to 9
      	lcd.clear(); //clear display
      	addFunds(); //display add funds message
      while(curr <= 0){ // only runs when curr is less  than or equal to 0
        if(receiver.decode(&results)){
          if(remoteInput(results.value) == 0){
            return; //if users trys to add 0 dollars return 
          }
          else{
          	curr = remoteInput(results.value); //set the input cash to curr variable
          }
      		receiver.resume();
          delay(1);
    	}
      }
      reset = 0;
    }
  }
}

void addFunds(){
  /*
    Displays add funds message on LCD
  */
  if(reset == 16748655){
      	lcd.clear();
      	lcd.setCursor(0,0);
        switch(lang){
          case 'E':
            lcd.print("how much cash");
            lcd.setCursor(0,1);
      	    lcd.print("youd like to add");
          break;
          case 'S':
            lcd.print("cuanto efectivo");
            lcd.setCursor(0,1);
      	    lcd.print("te gustaría agregar");
          break;
        } 
  }
}

 
int remoteInput(int irResult){
  /*
    convert ir remote input value into a integer value of button
  */
      switch(irResult){
        case 16753245:
        return 1;
        break;
        case 16736925:
        return 2;
        break;
        case 16769565:
        return 3;
        break;
        case 16720605:
        return 4;
        break;
        case 16712445:
        return 5;
        break;
        case 16761405:
        return 6;
        break;
        case 16769055:
        return 7;
        break;
        case 16754775:
        return 8;
        break;
        case 16748655:
        return 9;
        break;
        case 16750695:
        return 0;
        break;
      }
}

int snackSelection(char snack){
  /*
    convert keypad char into a servo number
  */

  switch(snack){
    case '1':
    	servoNum = 8;
    break;
    case '2':
    	servoNum = 9;
    break;
    case '4':
    	servoNum = 10;
    break;
    case '5':
    	servoNum = 11;
    break;
    case '7':
    	servoNum = 12;
    break;
    case '8':
    	servoNum = 13;
    break;
  }
  return servoNum;
}
  

void noFundsMsg(){
  /*
    display the no funds message
  */
	lcd.clear();
    switch(lang){
      case 'E':
        lcd.print("no funds");
  	    lcd.setCursor(0,1);
  	    lcd.print("press 9 to add $");
      break;
      case 'S':
        lcd.print("sin fondos");
  	    lcd.setCursor(0,1);
  	    lcd.print("9 para agregar $");
      break;
    }
  	delay(3000);
}

void turnServo(int num){
  /*
    takes in a servo number and turns
    that specific servo
  */
  myservo1.attach(num);
  myservo1.write(180);
  delay(3000);
  myservo1.write(90);
  delay(1000);
  myservo1.detach();
  lcd.clear();
  switch(lang){
    case 'E':
      lcd.print("Thank You!");
    break;
    case 'S':
      lcd.print("Gracias!");
    break;
  }
  delay(1000);
}

void startMsg(){
  /*
    displays greeting
  */
    lcd.clear();
    switch(lang){
      case 'E':
        lcd.print("Welcome!");
        lcd.setCursor(0,1);
        lcd.print("balance: $");
      break;
      case 'S':
        lcd.print("¡Bienvenidos!");
        lcd.setCursor(0,1);
        lcd.print("saldo: $");
      break;
    }
    lcd.print(curr);
}

int decrementFunds(){
  /*
    removes one dollar from curr variable
  */
	return --curr;
}

void dispenseingMsg(){
  /*
    Displays dispenseing message on 
    LCD
  */
  	lcd.clear();
    switch(lang){
      case 'E':
        lcd.print("Dispenseing");
        lcd.setCursor(0,1);
        lcd.print("snack ");
      break;
      case 'S':
        lcd.print("dispensación");
        lcd.setCursor(0,1);
        lcd.print("merienda "); 
      break;    
    }
    lcd.print(snack);
}

void timers(void){
  static unsigned long ms_runtime;
  static int one_ms_timer;
  if(millis() > (ms_runtime + 1)){
    ms_runtime = ms_runtime + 1;
    one_ms_timer++;
  }
  else if (ms_runtime > millis())
    ms_runtime = millis();
    
  if(one_ms_timer > 90){
   	timer1++;
    one_ms_timer = 0;
  }
}
