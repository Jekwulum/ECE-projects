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
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};

// for the board 
//char keys[ROWS][COLS] =
//{
//  {'1', '2', '3', 'A'},
//  {'4', '5', '6', 'B'},
//  {'7', '8', '9', 'C'},
//  {'*', '0', '#', 'D'}
//};
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String inputString;
String enteredString;

String regNo[30] = {"2017364053", "2017364106", "2017364110", "2017364030", "2017364034",
                   "2017364019", "2017364016", "2017364102", "2017364099", "2014364328",
                   "2017364068", "2017364081", "2017364065", "2017364057", "2017364082",
                   "2017234094", "2017234007", "2018234018", "2017234021", "2017234026",
                   "2017234076", "2017234034", "2017234073", "2017234098", "2017234069",
                   "2017234011", "2017234036", "2017234079"};
String enteredVals[30];

int count = 0;

void setup() {
//  Serial.begin(9600);
  inputString.reserve(10); // maximum number of digits in a reg number
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
  delay(1900);
  lcd.clear();
  lcd.print(String("COUNT: ") + String(count));
  lcd.setCursor(0, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = kpd.getKey();
//  if (key != NO_KEY) // if the key is pressed
  if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9') { // we only want to print numeric keys
      inputString += key; // append the entered key to inputString
      lcd.print(key); // print the key when pressed
    }
    
  if (key == '*') // clear input incase there was a mistake in inputting reg number
  {
    lcd.clear();
    inputString = ""; // clear the already entered String of inputs
    lcd.setCursor(0, 0);
    lcd.print("ECE334 PROJECT");
    delay(0700);
    lcd.clear();
    lcd.print(String("COUNT: ") + String(count));
    lcd.setCursor(0, 1);
  }

  if (key == '#') // reset
  {
    count = 0; // reset the already counted values to zero
    reset();
    digitalWrite(A1, HIGH);
    delay(0050);
    digitalWrite(A1, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ECE334 PROJECT");
    delay(0700);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String("COUNT: ") + String(count));
    lcd.setCursor(0, 1);
  }

  if (key == 'D') // enter in values
  {
    verify(); // verify values and display
  }
}


void verify() {
  lcd.clear();
  if (inputString.length() == 10) { // if the length of the inputted reg number is 10
    enteredString = inputString; // convert the inputstring to int to enable us check if in the reg numbers register/array
    inputString = ""; // reset the inputstring to empty to enable us enter new values
    if (testRegNo(enteredString)) { // if the value entered is in list of reg numbers

      if (testEnteredVals(enteredString)) { // if the value has been entered before

        lcd.print("Already Entered!!!");// display that it has been entered before
        delay(0700);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(String("COUNT: ") + String(count));
        lcd.setCursor(0, 1);
      }
      else {
        
        count = count + 1; // increase count if the reg number has not been entered before
        enteredVals[count] = enteredString; // add the reg number to list of counted regnos
        digitalWrite(A0, HIGH);
        delay(0050);
        lcd.clear();
        lcd.print("DONE");
        delay(1000);
        digitalWrite(A0, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(String("COUNT: ") + String(count));
        lcd.setCursor(0, 1);
      }
    }
    else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NOT IN GRP-4!");
      inputString = "";
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(String("COUNT: ") + String(count));
      lcd.setCursor(0, 1);
      }
    }
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INCORRECT!");
    inputString = "";
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String("COUNT: ") + String(count));
    lcd.setCursor(0, 1);
    }
}

bool testRegNo(String test) {
  for (int x = 0; x < 30; x++) {
    if (regNo[x] == test) {
      return true;
    }
  }
  return false;
}

bool testEnteredVals(String test) {
  for (int x = 0; x < 30; x++) {
    if (enteredVals[x] == test) {
      return true;
    }
  }
  return false;
}

void reset(){
  for(int i=0; i<30; ++i){ 
    enteredVals[i] = (char)0;
  }
  }
