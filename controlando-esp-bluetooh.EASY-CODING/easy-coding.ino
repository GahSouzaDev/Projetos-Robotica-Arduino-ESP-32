#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String  comando;
void setup()
{
comando = "";

pinMode(15, OUTPUT);
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);
  SerialBT.begin("------ ESP32_BLUETOOTH------");

}


void loop()
{

    if (SerialBT.available()) {
      do {
        comando = (SerialBT.readString());
      } while ((SerialBT.available()));
    }
    if (comando.equals("vermelhoon")) {
      digitalWrite(15,HIGH);

    }
    if (comando.equals("vermelhooff")) {
      digitalWrite(15,LOW);

    }
    if (comando.equals("amareloon")) {
      digitalWrite(2,HIGH);

    }
    if (comando.equals("amarelooff")) {
      digitalWrite(2,LOW);

    }
    if (comando.equals("verdeon")) {
      digitalWrite(4,HIGH);

    }
    if (comando.equals("verdeoff")) {
      digitalWrite(4,LOW);

    }
    if (comando.equals("azulon")) {
      digitalWrite(16,HIGH);

    }
    if (comando.equals("azuloff")) {
      digitalWrite(16,LOW);

    }
    if (comando.equals("brancoon")) {
      digitalWrite(17,HIGH);

    }
    if (comando.equals("brancooff")) {
      digitalWrite(17,LOW);

    }
    if (comando.equals("ledson")) {
      digitalWrite(17,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(2,HIGH);

    }
    if (comando.equals("ledsoff")) {
      digitalWrite(17,LOW);
      digitalWrite(16,LOW);
      digitalWrite(15,LOW);
      digitalWrite(4,LOW);
      digitalWrite(2,LOW);

    }

}