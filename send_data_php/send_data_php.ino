/*
 * HTTP Client GET Request
 * Copyright (c) 2018, circuits4you.com
 * All rights reserved.
 * https://circuits4you.com 
 * Connects to WiFi HotSpot. */
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
 
const char *ssid = "Seibergerber-2.4";
const char *password = "M0ntigue!";

const char *host = "192.168.0.24";
const char *port = "4000";
 
void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
 
  String data, url;
  int data1 = analogRead(A0);  //Read Analog value of LDR
  int data2 = analogRead(A0);  //Read Analog value of LDR

  data1 = 5;
  data2 = 13;
 
  data = "?data1=" + String(data1) + "&data2=" + String(data2);
  url = "http://" + String(host) + "/test_data_in.php" + data;

  Serial.println(url);
  
  http.begin(url);
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection

  
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(2900);  //GET Data at every 5 seconds
}
//=======================================================================
