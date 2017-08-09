#include <Wire.h>
#include "SparkFunHTU21D.h"
#include <ESP8266WiFi.h>
HTU21D testHTU21D;

//Thingspeak 설정
String apiKey = "********"; // 채널 Write Api Key 넣기
const char* server = "api.Thingspeak.com";

//WiFi 설정
const char* ssid = "***"; //와이파이 SSID 넣기
const char* password = "******"; // 와이파이 비밀번호 넣기

//WiFi 클라이언트 설정
WiFiClient client;

void setup() {
  testHTU21D.begin(); // HTU21D 시작
  Wire.begin(); // SDA to GPIO4 (D2), SCL to GPIO05 (D1)
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  float humd = testHTU21D.readHumidity(); // 습도값 저장
  float temp = testHTU21D.readTemperature(); // 온도값 저장
  // Thingspeak에 온습도값 보내기
  if (client.connect(server,80)) {
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(temp);
    postStr +="&field2=";
    postStr += String(humd);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: Api.thingspeak.com\n");
    client.print("connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  client.stop();
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(11000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(11000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(11000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(11000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(11000);                       // wait for a second


}
