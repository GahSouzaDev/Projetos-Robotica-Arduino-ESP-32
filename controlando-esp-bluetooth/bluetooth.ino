#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

/* Define a pinagem dos LEDs */
#define vermelho 15
#define amarelo 2
#define verde 4
#define azul 16
#define branco 17

void setup() {
  Serial.begin(9600);
  SerialBT.begin("------ ESP32_BLUETOOTH------");

  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(branco, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    String comando = ""; // Inicializa string para armazenar o comando
    while (SerialBT.available()) {  // Lê o comando completo do Bluetooth
      comando += char(SerialBT.read());
    }

    // Verifica o comando e realiza a ação correspondente
    if (comando == "vermelhoon") {
      digitalWrite(vermelho, HIGH);  // Liga o LED vermelho
    } else if (comando == "vermelhooff") {
      digitalWrite(vermelho, LOW);   // Desliga o LED vermelho
    } else if (comando == "amareloon") {
      digitalWrite(amarelo, HIGH);   // Liga o LED amarelo
    } else if (comando == "amarelooff") {
      digitalWrite(amarelo, LOW);    // Desliga o LED amarelo
    } else if (comando == "verdeon") {
      digitalWrite(verde, HIGH);     // Liga o LED verde
    } else if (comando == "verdeoff") {
      digitalWrite(verde, LOW);      // Desliga o LED verde
    } else if (comando == "azulon") {
      digitalWrite(azul, HIGH);      // Liga o LED azul
    } else if (comando == "azuloff") {
      digitalWrite(azul, LOW);       // Desliga o LED azul
    } else if (comando == "brancoon") {
      digitalWrite(branco, HIGH);    // Liga o LED branco
    } else if (comando == "brancooff") {
      digitalWrite(branco, LOW);     // Desliga o LED branco
    } else if (comando == "ledson") {
      // Liga todos os LEDs
      digitalWrite(vermelho, HIGH);
      digitalWrite(amarelo, HIGH);
      digitalWrite(verde, HIGH);
      digitalWrite(azul, HIGH);
      digitalWrite(branco, HIGH);
    } else if (comando == "ledsoff") {
      // Desliga todos os LEDs
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(branco, LOW);
    }
  }
}