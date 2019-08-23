/*
 *  AUTOR:          Thiago Vilella
 *  YOUTUBE:        https://www.youtube.com/channel/UCpg7_v1Wtvp-XPj-vjh8igQ
 *  DAILYMOTION:    https://www.dailymotion.com/dm_2f470f25794e41f057a2fba895ff6f3c
 *  CURSO ARDUINO:  http://bit.ly/2ZhypC9
 *  CURSO ROBOTICA: http://bit.ly/2zjK9Eo
 *  COMPRE:         https://www.arducore.com.br/
 *  SKETCH:         AbacoIno
 *  VERSÃO:         1.0.1
 *  DATA:           22/08/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include <myPushButton.h>

// DEFINIÇÕES DE PINOS
#define pinPot1 A5
#define pinPot2 A3
#define pinPot3 A0
#define pinBot1 3

// INSTANCIANDO OBJETOS
myPushButton botao(pinBot1);

void setup() {
  Serial.begin(9600);

  Serial.println(F("Título - Ábaco com Arduino"));
  Serial.println(F("Objetivo - Exibir um número inteiro em função das posições dos potenciômetros quando o botão for pressionado"));
  Serial.println(F("Função - pot1 = unidade ; pot2 = dezena ; pot3 = centena"));
  Serial.println(F("Material - Arduino Uno, protoboard, 3 potenciômetros, 1 pushbutton"));
  Serial.println(F("Dica- Utilizar a biblioteca PushButton.h feita no cursodearduino.net"));
  Serial.println(F("Link do Curso : https://go.hotmart.com/W8213658G "));

  Serial.println(F("Fim do Setup, bora pro exercícío"));

}

void loop() {
  botao.lerBotao();

  if(botao.pressed()){
    int unidade,dezena,centena,valor;
    
    unidade = map(analogRead(pinPot1),0,1023,0,9);
    dezena  = map(analogRead(pinPot2),0,1023,0,9);
    centena = map(analogRead(pinPot3),0,1023,0,9);
    
    valor = (centena*100)+(dezena*10)+unidade;
    Serial.print("Valor lido é: ");
    Serial.println(valor);

  }

}
