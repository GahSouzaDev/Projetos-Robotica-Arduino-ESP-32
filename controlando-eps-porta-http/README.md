------------------------------------[Link para ver o projeto funcionando](https://www.linkedin.com/posts/emerson-gabriel-souza-558841324_iot-arduino-esp32-activity-7236799599795941376-kkUH?utm_source=share&utm_medium=member_desktop)------------------------------------

Projeto IoT - Controle via HTTP com ESP32

Este projeto IoT permite controlar um ESP32 remotamente utilizando um aplicativo desenvolvido no App Inventor. O app envia comandos através de uma interface HTTP, que são recebidos e processados pelo ESP32, permitindo o controle de dispositivos conectados, como relés, motores, LEDs, entre outros.

Embora o aplicativo desenvolvido não possa ser disponibilizado por razões de confidencialidade, o código no ESP32 permite o uso do Monitor Serial para acompanhar e testar os comandos enviados pela interface HTTP. Isso facilita a criação de um aplicativo ou solução personalizada para controlar o ESP32 remotamente.

Funcionalidades Principais:
Controle remoto de dispositivos via HTTP
Conexão e integração com rede Wi-Fi
Monitoramento e debug via Serial Monitor
Flexível para ser controlado por diferentes aplicativos móveis ou web
Perfeito para automação residencial ou industrial

Como funciona:
O ESP32 é conectado à rede Wi-Fi e expõe uma interface HTTP.
O aplicativo envia comandos específicos para o ESP32 via HTTP.
O ESP32 interpreta os comandos e executa as ações correspondentes, como ligar/desligar dispositivos ou ajustar parâmetros.
Você pode visualizar os logs e respostas via Monitor Serial para acompanhar o que está acontecendo no dispositivo.

Requisitos:
ESP32
Conexão Wi-Fi
Monitor Serial para depuração e testes
App Inventor ou qualquer outra solução para criar o aplicativo controlador
