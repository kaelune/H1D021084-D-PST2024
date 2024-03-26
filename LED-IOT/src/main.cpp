#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

const char *ap_ssid = "kaedelun";
const char *ap_password = "1223334444";

const char *sta_ssid = "TEKNIK UNSOED D3";
const char *sta_password = "";

AsyncWebServer server(80);
String webpage;

int redLED = LED_BUILTIN, yelLED = D0, greLED = D1;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(greLED, OUTPUT);

  Serial.begin(9600);
  delay(10);

  /*local */
  // Serial.println("Configuring access point...");
  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ap_ssid, ap_password);
  // Serial.print("Wifi: ");
  // Serial.println(ap_ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  /*wifi station*/
  Serial.print("Connecting to ");
  Serial.println(sta_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid, sta_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  webpage+= "<h1> Web Control ESP8266</h1>";
  webpage+= "<p>LED 1: ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2: ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3: ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, LOW);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yelLED, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greLED, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, HIGH);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yelLED, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greLED, LOW);
    request->send(200, "text/html", webpage);
  });

  server.begin();
}

void loop() {
  
}