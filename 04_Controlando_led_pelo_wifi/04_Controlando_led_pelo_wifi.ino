/*
  
*/

#include <ESP8266WiFi.h>

#define NOME "Valdirene" //colocar o ssid da rede utilizada
#define SENHA "wifi@@@@"


//Definição da porta que vamos utilizar
WiFiServer server(80);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //setando os pinos GPIO para output
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);

  //Vamos deixar as GPIO em nível baixo
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);

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

  

  //iniciamos o server na porta 80
  server.begin();
  Serial.println("Servidor HTTP iniciado");

  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Verifica se existe algum cliente tentando se conectar ao ESP
 //E aí, caso nenhum cliente seja encontrando ele retorna ao inicio
 
  WiFiClient client = server.available();
  
  if(!client){
    return;   //Apenas reforçando, caso não tenha cliente retorna ao topo do código  
  }
  //Apenas feedback
  Serial.println("Novo cliente conectou");
  
  //client.available representa uma requisição, então o while
  //a baixo "busca" uma nova requisição a cada 0.100s
  while(!client.available()){
    delay(100);
  }
  
  
  //A variável req vai armazenar a requisição,
  //que nada mais é do que uma string
  String req = client.readStringUntil('\r');
  Serial.print("Requisição");
  Serial.println(req);

  /*
   * Aqui é um ponto muito importante, é onde está presente o nosso código HTML  
   * É aqui que vamos "criar" os botões
   * A parte mais importante é o "link" que a tag <a href> vai nos redirecionar
   * Pois na verdade não é um link, e sim a String que vai para req, que definimos no código a cima.
   */
   client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n "));

   String html = 
   "<html>"
    "<head>"
      "<meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>"
      "<title>LED via Wifi com ESP</title>"
     "</head>"
     "<body>"
      "<p>GPIO0</p>"
      "<p><a href='?acao=gpio0On'><button>ON</button></a></p>"
      "<p><a href='?acao=gpio0Off'><button>OFF</button></a></p>"
      "<p>GPIO2</p>"
      "<p><a href='?acao=gpio2On'><button>ON</button></a></p>"
      "<p><a href='?acao=gpio2Off'><button>OFF</button></a></p>"
     "</body>"
    "</html>";

    //Escreve o html no buffer que será enviado para o cliente
    client.print(html);

    //Envia os dados do buffer para o cliente
    client.flush();

    //O que vamos fazer agora é verificar se alguma das 4 requisições que definimos estão sendo "chamadas"
    if(req.indexOf("acao=gpio0On") != -1){
      digitalWrite(0, HIGH);
    }else if(req.indexOf("acao=gpio0Off") != -1){
      digitalWrite(0, LOW); 
    }else if(req.indexOf("acao=gpio2On") != -1){
      digitalWrite(2, HIGH);
    }else if(req.indexOf("acao=gpio2Off") != -1){
      digitalWrite(2, LOW);
    }

    //Resumindo, a conexão com o cliente é encerrada a cada requisição
    client.stop();
    Serial.println("Cliente desconectado");
   
}
