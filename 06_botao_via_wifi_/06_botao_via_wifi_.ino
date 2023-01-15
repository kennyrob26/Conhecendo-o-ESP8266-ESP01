/*
  O código a baixo é bem simples, apenas lê o status de um botão
  se ele está em nível alto mostramos pressionado = 1 na tela
  se ele está em nivel baixo mostramos pressionado = 0 na tela
  Por mais que seja um código bem simples, ele me exigiu muito tempo,
  as referências utilizadas são:
  A referência principal:
    https://www.fernandok.com/2017/10/blog-post.html
  Outras: 
     https://akuzechie.blogspot.com/2020/12/esp8266-web-server-using-css-and.html
     https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WebServer/README.rst
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
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
  //A função getPressionado será chamda todas
  // as vezes que uma requisição do tipo GET no caminho
  // http://MeuIP/pressionado acontecer
  server.on("/pressionado", HTTP_GET, getPressionado);
  //a lógica aqui é a mesma
  server.on("/monitor", HTTP_GET, showMonitor);
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

void getPressionado()
{
  //Verifica em que nivel lógico o botão se encontra
  int p = digitalRead(BOTAO); 

  //Cria um json com os dados do botão
  String json = "{\"pressionado\":"+String(p)+"}";
  
  //envia a string json com o código de requisição 200 (tudo ok")
  server.send(200, "application/json", json);

   
}

//Funcao que contém o nosso código HTML
//É basicamente a página inicial
void showMonitor()
{
  server.send(200, "text/html", webpageCode);    
}
