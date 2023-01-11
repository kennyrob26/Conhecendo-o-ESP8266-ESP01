/*
  Meu primeiro contato utilizando o ESP como um servidor web, o código apenas conecta a rede e inicia o servidor
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define NOME "Valdirene" //colocar o ssid da rede utilizada
#define SENHA "wifi@@@@"

//Definição da porta que vamos utilizar
ESP8266WebServer server(80);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //Definindo o nome (SSID) e a senha da rede que vamos utilizar
  WiFi.begin(NOME, SENHA);

  //Apenas feedback
  Serial.println("");
  Serial.print("Conectado");

  //apenas exibe "." enquanto o ESP tenta conectar ao roteador, 
  //o processo pode DEMORAR um pouco
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  //Configuração do IP fixo, deve ser congigurado com base na rede utilizada
  IPAddress ip(10, 0, 0, 125);
  IPAddress gateway(10, 0, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  Serial.print("Configurando IP fixo para: ");
  Serial.println(ip);

  //enviamos todas as informações que configuramos
  WiFi.config(ip, gateway, subnet);

  //Feedback
  Serial.println("");
  Serial.println("Connectado");
  Serial.print ("IP: ");
  Serial.println(WiFi.localIP());

  
  //Aqui começamos a declarar as funções da páginas

  //O que acontece aqui é muito simples
  //quando a url estiver no caminho "/", ou seja,
  //a página inicial, a função handle_pagina_inicial será chamada
  //A função handle_pagina_inicial basicamente "printa" para o browser tags HTML
  //server.on("/", handle_pagina_inicial);

  //iniciamos o server na porta 80
  server.begin();
  Serial.println("Servidor HTTP iniciado");

  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //responsável por responder as requisições
  server.handleClient();

}

/*void handle_pagina_inicial(){
  String message = "<!DOCTYPE html>";
  message += "<html lang='pt-br'>";
  message += "<meta http-equiv=\'content-type\' content=\'text/html; charset=utf-8\'>";
  message += "<body>";
  message += "<h1>Olá Mundo</h1>";
  message += "<p>Olá, essa é a primeira vez que utilizo o ESP como um servidor Web";
  message += "</body>";
  message += "</html>";

  server.send(200, "text/html", message);
  
}

*/
