# Conhecendo-o-ESP8266-ESP01
Criei esse repositório no intuito de conhecer um pouco melhor o microcontrolador ESP01.  
Os arquivos que utilizei para iniciar os estudos estão presentes em:

FilipeFlop: https://www.filipeflop.com/blog/primeiros-passos-com-o-modulo-esp8266-esp-01/

Robocore: https://www.robocore.net/tutorials/programando-o-esp8266-pela-arduino-ide?newlang=english

Site do Fernando K: https://www.fernandok.com/2017/10/introducao-ao-esp8266.html
 
Alguns detalhes que queria destacar, pois provavelmente irei esquecer no futuro:

1.Nunca esquecer que o pino GPIO0 deve estar em nível baixo (jumpeado com o GND) para conseguir gravar utilizando a IDE do Arduino.  
2.Quando a placa estiver em funcionamento normal, o pino CH_PD deve estar em nível alto (jumpeado com o VCC), se não nada funcionará.
