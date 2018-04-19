#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
//#define COMMON_ANODE
#define redPin 12
#define greenPin 11
#define bluePin 13
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  topServo.attach(7);
  bottomServo.attach(8);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  topServo.write(115);
  delay(500);
  for (int i = 115; i > 60; i--) {
    topServo.write(i);
    //delay(1);
  }
  delay(500);

  color = readColor();
  delay(10);
  /*switch (color) {
    case 1:
      bottomServo.write(25);
      break;
    case 2:
      bottomServo.write(50);
      break;
    case 3:
      bottomServo.write(75);
      break;
    case 4:
      bottomServo.write(100);
      break;
    case 5:
      bottomServo.write(125);
      break;
    case 6:
      bottomServo.write(150);
      break;
  }*/
  switch (color) {
    case 1:
      bottomServo.write(150);
      break;
    case 2:
      bottomServo.write(150);
      break;
    case 3:
      bottomServo.write(150);
      break;
    case 4:
      bottomServo.write(150);
      break;
    case 5:
      bottomServo.write(150);
      break;
    case 6:
      bottomServo.write(150);
      break;
  }
  delay(300);

  for (int i = 60; i > 29; i--) {
    topServo.write(i);
    //delay(3);
  }
  delay(200);

  for (int i = 29; i < 115; i++) {
    topServo.write(i);
    //delay(2);
  }
  color = 0;
}

// funcion que lee el color
int readColor() {
  // se configuran los diodos de color rojo
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // se lee la frecuencia
  frequency = pulseIn(sensorOut, LOW);
  //frequency = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  int R = frequency;
  // Impresion del valor
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
  // se configuran los diodos de color verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // leemos el valor
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // se imprime en serial
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  setColor(0,0,0);
  if (R <= 40 & R >= 30 & G <= 64 & G >= 54 & B >= 36 & B <= 46) {
    color = 1; // Red
    Serial.println("///Rojo");
    setColor(255, 0, 0);  // red
  } else {
    if (G <= 48 & G >= 38 & B <= 41 & B >= 31 & R >= 17 & R <= 27) {
      color = 2; // Orange
      setColor(255, 165, 0);
      Serial.println("///Naranja");
    } else {
      if (R <= 44 & R >= 34 & G <= 44 & G >= 34 & B >= 35 & B <= 45) {
        color = 3; // Green
        setColor(0, 255, 0); // yellow
        Serial.println("///verde");
      } else {
        if (R <= 64 & R >= 54 & G <= 73 & G >= 63 & B >= 43 & B <= 53) {
          color = 4; // Brown
          setColor(102, 0, 51);
          Serial.println("///Cafe");
        } else {
          if (G <= 35 & G >= 25 & B <= 41 & B >= 31 & R >= 18 & R <= 28 ) {
            color = 5; //
            setColor(255, 255, 0);
            Serial.println("///Amarillo");
          } else {
            color = 6;
            setColor(0, 0, 0);
            Serial.println("///Tremenda Basura");
          }
        }
      }
    }
  }
  return color;
}
void setColor(int red, int green, int blue)
{
  /*#ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    #endif*/
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);
  // delay(1000);
}
