//Edited by Jashoskam Bora
//On 27/5/20

#include <Keypad.h>
#include <Servo.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

int Led=11;
int Red=12;

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Servo Lock;

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "1234"; // change your password here
String input_password;

void setup(){
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
  Lock.attach(10);
  Lock.write(90);
  pinMode(Led,OUTPUT);
  pinMode(Red,OUTPUT);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
    //input_password=key;
    //input_password="123" + key;
  
    if(key == '*') {
      input_password = ""; 
    }else if(key == '#') {
            Serial.println("input_password = " + input_password);
            if(password == input_password) {
              digitalWrite(Red,LOW);
              Serial.println ("**************************");
              Serial.println("password is correct");   
              Serial.println ("**************************");
              Lock.write(0);
              digitalWrite(Led,HIGH);

            } else {
                  digitalWrite(Led,LOW);
                  Serial.println("password is incorrect, try again");
                  input_password = ""; 
                  Lock.write(90);
                  digitalWrite(Red,HIGH);
                  
            }
      }else
        input_password= input_password + key;
      }
      
  } 
