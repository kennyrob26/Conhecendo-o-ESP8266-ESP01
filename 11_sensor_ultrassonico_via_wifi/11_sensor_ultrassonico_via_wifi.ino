#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Ultrassonico.h>
#include "homePage.h"

//Configuração da rede
#define NOME "Valdirene" 
#define SENHA "wifi@@@@"

//Definição dos pinos
#define TRIG 0
#define ECHO 2

//Instânciando o o objeto da classe ultrassonico
Ultrassonico distancia(TRIG, ECHO);

//Definindo o servidor
ESP8266WebServer server(80);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //================== Configurações da rede =================
  
  WiFi.begin(NOME, SENHA);
  Serial.println("");
  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
  }

  //Definindo um IP fixo
  IPAddress ip(10, 0, 0, 125);
  IPAddress gateway(10, 0, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  Serial.print("Configurando IP fixo para: ");
  Serial.println(ip);

  //enviamos todas as informações que configuramos
  WiFi.config(ip, gateway, subnet);
  
  Serial.println("");
  Serial.println("Connectado");
  Serial.print ("IP: ");
  Serial.println(WiFi.localIP());

  //================= Requisições ===============
  
  server.on("/home", HTTP_GET, pgInicial);
  server.on("/distancia", HTTP_GET, getDistancia);
  server.onNotFound(onNotFound);
  
  //===============================================
  //Inicia o servidor
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

  //================= LOOP =======================

void loop() {
  //Responsável por monitorar as requisições
  server.handleClient();
}

  //================ Funções ========================

void onNotFound(){
  server.send(404, "text/plain", "Not Found");
}

void getDistancia(){
  float d = distancia.emCentimetro();

  String json = "{\"distancia\":"+String(d)+"}";

  server.send(200, "application/json", json);
}

void pgInicial(){
  server.send(200, "text/html", homePage);
}
