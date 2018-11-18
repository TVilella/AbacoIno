/*  Projeto:          Execício
 *  Autor:            Thiago Vilella
 *  Objetivo:         Prática em programação com Arduino e conceitos de Eletrônica Básica
 *  Canal Youtube:    https://www.youtube.com/channel/UCpg7_v1Wtvp-XPj-vjh8igQ <-- Maiores explicações sobre o exercício e os objetivos
 *  Link do Curso:    https://go.hotmart.com/W8213658G
 *  AbacoIno Versão:  1.0.0
*/

#include <PushButton.h>

#define pinPot1 A5
#define pinPot2 A3
#define pinPot3 A0
#define pinBot1 3

PushButton botao(pinBot1);

void setup() {
  Serial.begin(9600);

  Serial.println("Título - Ábaco com Arduino");
  Serial.println("Objetivo - Exibir um número inteiro em função das posições dos potenciômetros quando o botão for pressionado");
  Serial.println("Função - pot1 = unidade ; pot2 = dezena ; pot3 = centena");
  Serial.println("Material - Arduino Uno, protoboard, 3 potenciômetros, 1 pushbutton");
  Serial.println("Dica- Utilizar a biblioteca PushButton.h feita no cursodearduino.net");
  Serial.println("Link do Curso : https://go.hotmart.com/W8213658G ");

  Serial.println("Fim do Setup, bora pro exercícío");

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
