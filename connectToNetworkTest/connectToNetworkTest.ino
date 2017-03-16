//credit to Rui Santos for the example that got this started. 

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

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

  //gpio setup
  pinMode(gpio0_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  pinMode(gpio1_pin, OUTPUT);
  digitalWrite(gpio1_pin, LOW);

  //Setup serial
  Serial.begin(115200);
  //Setup wifi and connect
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  //DNS responder
  if(mdns.begin("esp8266", WiFi.localIP()){
      Serial.println("MDNS Started");
  }
  server.on("/", [](){
    server.send(200,"text/html", webhtml);
  });
  server.on("/pin1On, [](){
    server.send(200,"text/html", webhtml);
    digitalWrite(gpio0_pin, HIGH);
    delay(500);
  });
  server.on("/pin1Off, [](){
    server.send(200,"text/html", webhtml);
    digitalWrite(gpio0_pin, LOW);
    delay(500);
    });
  server.on("/pin2On, [](){
    server.send(200,"text/html", webhtml);
    digitalWrite(gpio1_pin, HIGH);
    delay(500);
    });
  server.on("/pin2Off, [](){
    server.send(200,"text/html", webhtml);
    digitalWrite(gpio1_pin, LOW);
    delay(500);
    });
}

void loop() {
  // put your main code here, to run repeatedly:

}
