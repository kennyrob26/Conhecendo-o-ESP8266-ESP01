/*
  Esse código faz com que o esp crie um webserver e funcione como um pequeno servidor
  O código externo foi a única maneira em que consegui utilizar o DOM do JS
  Além de permitr uma melhor organização
  
  Para mais informações, a referência utilizada está em:  https://akuzechie.blogspot.com/2020/12/esp8266-web-server-using-css-and.html
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//Aqui está o html externo que vamos utilizar como nossa página inicial,
//é um pequeno código do curso de JS
#include "webpageCode.h"


#define NOME "Valdirene" //colocar o ssid da rede utilizada
#define SENHA "wifi@@@@"
#define BOTAO 2 //botão está na GPIO 2

//Definição da porta que vamos utilizar
ESP8266WebServer server(80);




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //Definimos o botão como output
  pinMode(BOTAO, INPUT);

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

  

  //Funções das requisições

  server.on("/", HTTP_GET, pgInicial);
  //Utilizado para quando o cliente digita uma URL não existente
  server.onNotFound(onNotFound);

  //iniciamos o server na porta 80
  server.begin();
  Serial.println("Servidor HTTP iniciado");

  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //responsável por responder as requisições
  //reencaminhando cada uma delas para as suas
  //devidas funções
  server.handleClient();

}

//Então começamos a criar as funções 

void onNotFound()
{
  server.send(404, "text/plain", "Not Found");    
}

void pgInicial(){

  server.send(200, "text/html", webpageCode);
      
}
