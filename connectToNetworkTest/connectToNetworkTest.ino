#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

char* ssid = "";
char* password = "";

int gpio0_pin = 0; 
int gpio1_pin = 2;

string webhtml = "";


void setup() {
  // put your setup code here, to run once:
  webhtml += "<h1>ESP8266 Webserver</h1><p>Pin 1<a href=\"pin1On\"><button>ON</button></a><\p><a href=\"pin1Off\"><button>OFF<\button><\a><\p>
  webhtml += "<p>Pin 2<a href=\"pin2On\"><button>ON<\button><\a><\p><a href=\"pin2Off\"><button>OFF</button><\a><\p>

  
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
