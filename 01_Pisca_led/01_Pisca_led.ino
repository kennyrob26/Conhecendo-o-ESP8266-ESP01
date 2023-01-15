//Define o pino GPIO2 para o LED
#define LED 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Led ligado por 1s
  digitalWrite(LED, HIGH);
  delay(1000);
  
  //Led desligado por 1s
  digitalWrite(LED, LOW);
  delay(1000);

}
