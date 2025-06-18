#define enA 13
#define enB 33

#define in1 12
#define in2 27
#define in3 26
#define in4 25

#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6XgOREHBE"
#define BLYNK_TEMPLATE_NAME "RobotController"
#define BLYNK_AUTH_TOKEN "MC443CBJy--RZFHo3ZC_l8XRJr1eXShl"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "bisma1";
char pass[] = "bisma0809";

int maju, mundur, pwmOutput, kiri, kanan;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
}

void loop() {
  //Serial.println(WiFi.localIP());
  Blynk.run();
  if (maju == 1) {
    analogWrite(enA, pwmOutput);
    analogWrite(enB, pwmOutput);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(50);
  } else if (mundur == 1) {
    analogWrite(enA, pwmOutput);
    analogWrite(enB, pwmOutput);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(50);
  } else if (kiri == 1) {
    analogWrite(enA, 0);
    analogWrite(enB, pwmOutput);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(50);
  } else if (kanan == 1) {
    analogWrite(enA, pwmOutput);
    analogWrite(enB, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(50);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
}

BLYNK_WRITE(V1) {
  maju = param.asInt();  // assigning incoming value from pin V1 to a variable
  Serial.print("V1 value is: ");
  Serial.println(maju);
}
BLYNK_WRITE(V2) {
  mundur = param.asInt();  // assigning incoming value from pin V1 to a variable
  Serial.print("V2 value is: ");
  Serial.println(mundur);
}
BLYNK_WRITE(V3) {
  pwmOutput = param.asInt();  // assigning incoming value from pin V1 to a variable
  Serial.print("V3 value is: ");
  Serial.println(pwmOutput);
}
BLYNK_WRITE(V4) {
  kanan = param.asInt();  // assigning incoming value from pin V1 to a variable
  Serial.print("V4 value is: ");
  Serial.println(kanan);
}
BLYNK_WRITE(V5) {
  kiri = param.asInt();  // assigning incoming value from pin V1 to a variable
  Serial.print("V5 value is: ");
  Serial.println(kiri);
}
