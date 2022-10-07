#include <Arduino.h>

/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port D2 on the Arduino
#define ONE_WIRE_BUS 4

const int LEDBLEUE = 2;

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// Replace with your network credentials
const char* ssid     = "Le J c'est le S";
const char* password = "eyvq9619381";

// Set web server port number to 80
ESP8266WebServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output5 = 5;
const int output4 = 4;

// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleCapteur() {
 float a = sensors.getTempCByIndex(0);
 String b = String(a);
  
server.send(200, "text/plane", b);
 
}

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(LEDBLEUE, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/readCapteur", handleCapteur);
  server.begin();

  sensors.begin();
}

void loop(){
  server.handleClient();
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println(sensors.getTempCByIndex(0));
  digitalWrite(LEDBLEUE, LOW);

  // WiFiClient client = server.available();   // Listen for incoming clients

  // if (client) {                             // If a new client connects,
  //   Serial.println("New Client.");          // print a message out in the serial port
  //   String currentLine = "";                // make a String to hold incoming data from the client
  //   currentTime = millis();
  //   previousTime = currentTime;
  //   while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
  //     currentTime = millis();         
  //     if (client.available()) {             // if there's bytes to read from the client,
  //       char c = client.read();             // read a byte, then
  //       Serial.write(c);                    // print it out the serial monitor
  //       header += c;
  //       if (c == '\n') {                    // if the byte is a newline character
  //         // if the current line is blank, you got two newline characters in a row.
  //         // that's the end of the client HTTP request, so send a response:
  //         if (currentLine.length() == 0) {
  //           // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  //           // and a content-type so the client knows what's coming, then a blank line:
  //           client.println("HTTP/1.1 200 OK");
  //           client.println("Content-type:text/html");
  //           client.println("Connection: close");
  //           client.println();
            
  //           // turns the GPIOs on and off
  //           if (header.indexOf("GET /5/on") >= 0) {
  //             Serial.println("GPIO 5 on");
  //             output5State = "on";
  //             digitalWrite(output5, HIGH);
  //           } else if (header.indexOf("GET /5/off") >= 0) {
  //             Serial.println("GPIO 5 off");
  //             output5State = "off";
  //             digitalWrite(output5, LOW);
  //           } else if (header.indexOf("GET /4/on") >= 0) {
  //             Serial.println("GPIO 4 on");
  //             output4State = "on";
  //             digitalWrite(output4, HIGH);
  //           } else if (header.indexOf("GET /4/off") >= 0) {
  //             Serial.println("GPIO 4 off");
  //             output4State = "off";
  //             digitalWrite(output4, LOW);
  //           }
            
  //           // Display the HTML web page
  //           client.println("<!DOCTYPE html><html>");
  //           client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  //           client.println("<link rel=\"icon\" href=\"data:,\">");
  //           // CSS to style the on/off buttons 
  //           // Feel free to change the background-color and font-size attributes to fit your preferences
  //           client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  //           client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
  //           client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  //           client.println(".button2 {background-color: #77878A;}</style></head>");
            
  //           // Web Page Heading
  //           client.println("<body><h1>ESP8266 Web Server TEST</h1>");
            
  //           // Display current state, and ON/OFF buttons for GPIO 5  
  //           client.println("<p>GPIO 5 - State " + output5State + "</p>");
  //           // If the output5State is off, it displays the ON button       
  //           if (output5State=="off") {
  //             client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
  //           } else {
  //             client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
  //           } 
               
  //           // Display current state, and ON/OFF buttons for GPIO 4  
  //           client.println("<p>GPIO 4 - State " + output4State + "</p>");
  //           // If the output4State is off, it displays the ON button       
  //           if (output4State=="off") {
  //             client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
  //           } else {
  //             client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
  //           }
  //           client.println("</body></html>");
            
  //           // The HTTP response ends with another blank line
  //           client.println();
  //           // Break out of the while loop
  //           break;
  //         } else { // if you got a newline, then clear currentLine
  //           currentLine = "";
  //         }
  //       } else if (c != '\r') {  // if you got anything else but a carriage return character,
  //         currentLine += c;      // add it to the end of the currentLine
  //       }
}
