/*
 * NodeMCU/ESP8266 act as AP (Access Point) and simplest Web Server
 * Connect to AP "arduino-er", password = "password"
 * Open browser, visit 192.168.4.1
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <Servo.h>

const char *ssid = "aZeus";
const char *password = "nikmok69";

Servo servo;
ESP8266WebServer server(80);

void handleRoot() {
    server.send(200, "text/html", "<h1>Hello! from arduino-er!</h1>");
}

char* htmlBody_help = "<h1>Help</h1><br/>\n"
  "Visit http://192.168.4.1/ to access web server.<br/>\n"
  "Visit http://192.168.4.1/help to access this page.<br/>\n";

void handleHelp(){
  server.send(200, "text/html", htmlBody_help);
}

void start_pc(){
  server.send(200, "text/html", "<h1>Pc ch3el</h1>");
  servo.write(180);
  delay(1000);
  servo.write(90);
  
}

void setup() {
    servo.attach(2); //D4
    
    delay(2000);
    servo.write(90);
    Serial.begin(9600);
    Serial.println();

    WiFi.softAP(ssid, password);

    IPAddress apip = WiFi.softAPIP();
    Serial.print("visit: \n");
    Serial.println(apip);
    server.on("/", handleRoot);
    server.on("/help", handleHelp);
    server.on("/ch3al", start_pc);
    
    server.begin();
    Serial.println("HTTP server beginned");
}

void loop() {
    server.handleClient();
}
