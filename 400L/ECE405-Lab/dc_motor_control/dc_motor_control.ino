int val = 250;
int motorpin = 9;
int potpin = A0;
int speed;
int dir1 = 11;
int dir2 = 10;
int sw = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(sw, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw)==HIGH){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  else{
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    }
  speed = analogRead(potpin)/4.0;
  analogWrite(motorpin, speed);
  delay(20);
}
