#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "iEzOccbHiAx3dnYZxQtZX281xRWnozwy";
char ssid[] = "prateeksingh";
char pass[] = "kumar@12345";

BlynkTimer timer;

#define DO_PIN D1
#define Buzzer D3
#define Green D2
#define Red D4

void setup() {
  Serial.begin(9600);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(DO_PIN, INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void sensor() {
  int flame_state = digitalRead(DO_PIN);

  if (flame_state == HIGH) {
    Serial.println("No flame dected => The fire is NOT detected");
    digitalWrite(Green, HIGH);
    digitalWrite(Buzzer, LOW);
    WidgetLED LED(V0);
    LED.on();
    WidgetLED LED1(V1);
    LED1.off();
  } else {
    Serial.println("Flame dected => The fire is detected");
    digitalWrite(Green, LOW);
    digitalWrite(Buzzer, HIGH);
    WidgetLED LED(V0);
    LED.off();
    WidgetLED LED1(V1);
    LED1.on();
  }
}

  void loop() {
    sensor();
    Blynk.run();
    delay(200);
  }