
#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>

int Led = 2;
int Foco = 3;

const char* ssid = "MaciasTLA";
const char* password = "WifiDeFamiliaMacias0371";

Espalexa alexita;

void FuncionFoco(uint8_t brightness);
void FuncionPuerta(uint8_t brightness);

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  pinMode(Foco, OUTPUT);
  ConectarWifi();
  alexita.addDevice("Foco", FuncionFoco);
  alexita.addDevice("Puerta", FuncionPuerta);
  alexita.begin();
}

void loop() {
  ConectarWifi();
  alexita.loop();
  delay(1);
}

void ConectarWifi() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");
    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(Led, 1);
      delay(500);
      digitalWrite(Led, 1);
      delay(500);
      Serial.print(".");
    }
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void FuncionFoco(uint8_t brightness) {
  Serial.print("Funcion Foco - ");

  if (brightness) {
    digitalWrite(Foco, 1);
    Serial.println(" Encender ");
  }
  else {
    digitalWrite(Foco, 0);
    Serial.println(" Apagar ");
  }
}

void FuncionPuerta(uint8_t brightness) {
  Serial.print("Funcion Cama -");

  if (brightness) {
    Serial.println(" Encender ");
  }
  else {
    Serial.println(" Apagar ");
  }

}
