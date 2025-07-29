#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {7, 6, 5, 4}; // connected rows to pins 7,6,5,4
byte colPins[ROWS] = {3, 2, 1, 0}; //connected cols to pins 3,2,1,0
char keys[ROWS][COLS] =
{
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
};
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
//long int regNo[] = {2017364053, 2017364030};
//size_t regNo_size = sizeof(regNo)/sizeof(int);
//size_t regNo_size = sizeof(regNo)/sizeof(regNo[0]); 

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  // put your setup code here, to run once:
  for (int k = 8; k < 14; k++)
  {
    pinMode(k, OUTPUT);
  }

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ECE334 PROJECT");
  lcd.setCursor(0, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = kpd.getKey();
  if (key != NO_KEY) // if the key is pressed
  {
    lcd.print(key); // print the key when pressed
  }
  if (key == 'c')
  {
    lcd.clear();
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("ECE334 PROJECT");
    lcd.setCursor(0, 1);
    }
  if (key == '=')
  { 
//    verify();
    digitalWrite(A0, HIGH);
    delay(0050);
    lcd.clear();
    lcd.print("DONE");
    delay(1000);
    digitalWrite(A0, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ECE334 PROJECT");
    lcd.setCursor(0, 1);
    }
   if (key == '+')
  { 
    digitalWrite(A1, HIGH);
    delay(0050);
    digitalWrite(A1, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ECE334 PROJECT");
    lcd.setCursor(0, 1);
    }
}

//void verify(){
//  for (int i=0; i<regNo_size; i++)
//    {
//      if (regNo[i] == 'a')
//      {
//        digitalWrite(A0, HIGH);
//        delay(0050);
//        lcd.clear();
//        lcd.print("DONE");
//        delay(1200);
//        digitalWrite(A0, LOW);
//        lcd.clear();
//        lcd.setCursor(0, 0);
//        lcd.print(String("TOTAL NO: " ) + String(regNo_size));
//        lcd.setCursor(0, 1);
//        }
//      }
//  }
