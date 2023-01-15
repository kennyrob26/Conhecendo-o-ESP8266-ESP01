/*
 * Programinha bem simples, apenas para adaptação com o ESP, ao pressionar o botão BT o led LED acende
 */
//Definindo os GPIO
#define LED 2
#define BT 0
//variável que guarda se o botão está ou não pressionado (0 ou 1)
int pressionado = 0;
void setup() {
  // put your setup code here, to run once:
  //Definição dos pinos de entrada e saída
  pinMode(LED, OUTPUT);
  pinMode(BT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pressionado = digitalRead(BT);
  //Quando o botão estiver pressionado o Led liga
  if(pressionado == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }

}
