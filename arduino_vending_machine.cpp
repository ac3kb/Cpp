#include <Servo.h> //servo library
#include <Keypad.h> //keypad library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <IRremoteInt.h>

//STEMMA_LiquidCrystal lcd; 
//Adafruit_LiquidCrystal lcd_1(0);
LiquidCrystal_I2C lcd(0x20, 16, 2);
Servo myservo1;

int pos1 = 0; // position of servo motor 0 - 180 or 0 - 360
int IRPin = 7;

long reset;

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
byte colPins[COLS] = {3, 2}; //assigning keypad coloumns to pins

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //creating the keypad?

char snack; //variable that will hold value of which servo motor to turn
int servoNum;

int curr{0};// the users inputed cash

unsigned long timer1 = 0;

void turnServo(int);

void setup()
{
  receiver.enableIRIn();
  Serial.begin(9600);
  myservo1.attach(0);
  //lcd_1.begin(16, 2); //set lcd display settings, 16 x 2
  //lcd_1.print("Welcome!");//write a string to the lcd
  //lcd.begin
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
    snack = wait;
    dispenseingMsg();
    //dispense snack
    turnServo( snackSelection(snack) );
    //charge user for snack
    decrementFunds();
  }else{
    noFundsMsg();
    if(receiver.decode(&results)){
      //Serial.println(results.value, HEX);
      reset = (results.value);
      Serial.println(reset);
      receiver.resume();
    }
  }
  //if not enough money promt that theres no money

  //Serial.print(timer1);
}

int snackSelection(char snack){
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
	lcd.clear();
    lcd.print("no funds");
  	delay(3000);
}

void turnServo(int num){
  //spin 360 and check if sensor was obstructed. repeat loop until
  //sensor is obstructed
    myservo1.attach(num);
  	for(pos1 = 0; pos1 <= 360; pos1 += 1){
    	myservo1.write(pos1);
    	delay(10);
    }
  myservo1.detach();
  lcd.clear();
  lcd.print("Thank You");
  delay(1000);
}

void startMsg(){
    lcd.clear();
    lcd.print("Welcome!");
    lcd.setCursor(0,1);
    lcd.print("balance: $");
    lcd.print(curr);
}

int decrementFunds(){
	return --curr;
}

void dispenseingMsg(){
  	lcd.clear();
    lcd.print("Dispenseing");
    lcd.setCursor(0,1);
    lcd.print("snack ");
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
