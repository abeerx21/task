#include <WiFi.h>

const char*  ssid ="abeer";
const char* password = "123456";

WiFiServer server(80);

String header;

String output19 = "OFF";


const int LED19 = 19;


unsigned long currentTime = millis ();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin (115200);
  pinMode(LED19, OUTPUT);
  
  digitalWrite(LED19, LOW);
  
  Serial.print("Message received: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() !=WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

  Serial.println("");
  Serial.println("Connected");
  Serial.println("IP ;");
  Serial.println(WiFi.localIP());
  server.begin();
  }
 void loop () {
  WiFiClient client = server.available();

   if (client) {
    currentTime =millis();
    previousTime = currentTime;
    Serial.println("NEW COSTUMR");
    String currentLine = "";
    while (client.available()){
      char c = client .read();
      Serial.write(c);
      header  += c;
      if (c == '/n') {
        if (currentLine.length() == 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text?html");
          client.println("Connection: close");
          client.println();



 if (header.indexOf("GET /19/on") >= 0) {
              Serial.println("GPIO 19 on");
              output19 ="ON";
              digitalWrite(LED19, HIGH);
            } else if (header.indexOf("GET /19/off") >=0) {
              Serial.println("GPLO 19 off");
              output19="off";
              digitalWrite(LED19,LOW);
            }
client.println("<!DOCTYPE html><html>");
client.println("<head><meta http-equiv=\"content-Type\" content=\"taxt/html; charset=utf-8\"width=device-width, initial-scale=1\">");

            if (output19=="OFF") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">on</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">off</button></a></p>");
            }

            client.println("</body></html>");
            }
              
            }
            }

  
