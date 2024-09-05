------------------------------------[Link para ver o projeto funcionando](https://www.linkedin.com/feed/update/urn:li:activity:7237537728865685506/)------------------------------------

Projeto IoT - Controle via Bluetooth com ESP32

Este projeto IoT permite controlar dispositivos conectados ao ESP32 utilizando comandos de voz transmitidos via Bluetooth. Ao contrário da versão anterior baseada em HTTP, esta versão substitui a comunicação via Wi-Fi por uma conexão Bluetooth, o que torna o sistema mais acessível em situações sem conexão de internet.

O aplicativo foi desenvolvido no App Inventor e permite o envio de comandos via Bluetooth para o ESP32, que os interpreta e executa ações como ligar relés, controlar motores e LEDs, entre outros dispositivos conectados.

Embora o aplicativo em si não esteja disponível devido a questões de confidencialidade, o código do ESP32 permite que você configure seu próprio sistema, adaptando a comunicação via Bluetooth e utilizando o Monitor Serial para monitorar e testar os comandos.

Funcionalidades Principais:
Controle remoto de dispositivos via Bluetooth
Conexão e integração com dispositivos móveis via Bluetooth
Monitoramento e debug via Monitor Serial
Flexível para ser controlado por diferentes aplicativos móveis
Ideal para automação residencial e industrial sem depender de Wi-Fi

Como Funciona:

Configuração do Bluetooth: 
O ESP32 é configurado como um servidor Bluetooth, aguardando conexões de dispositivos móveis.

Envio de Comandos:
 O aplicativo envia comandos de voz, convertidos em texto, via Bluetooth para o ESP32.

Interpretação de Comandos:
 O ESP32 interpreta os comandos recebidos e executa ações como ligar ou desligar dispositivos, controlar motores ou ajustar parâmetros.

Monitoramento via Serial: 
Caso necessario, configure para que os logs e respostas sejam exibidos no Monitor Serial, permitindo acompanhamento em tempo real.

Requisitos:

ESP32
Conexão Bluetooth
Monitor Serial para depuração e testes
App Inventor ou qualquer outra solução para criar o aplicativo controlador
Adaptando o Projeto para Bluetooth
Se você já possui um projeto utilizando HTTP, a migração para Bluetooth requer a substituição das chamadas HTTP pelas funções de comunicação Bluetooth do ESP32. No código, as portas de comunicação utilizadas anteriormente para a interface HTTP podem ser removidas, e é necessário configurar o ESP32 para atuar como servidor Bluetooth, esperando comandos via SerialBT.

Sem portas HTTP: No caso do Bluetooth, não há necessidade de configurar portas HTTP, já que a comunicação acontece exclusivamente via conexão Bluetooth.
Monitoramento: A utilização do Monitor Serial continua sendo essencial para verificar os logs e mensagens recebidas, facilitando o processo de depuração.
Emparelhamento Bluetooth: Certifique-se de que o aplicativo controlador esteja emparelhado com o ESP32 antes de enviar comandos.

Conclusão:
Migrar para Bluetooth torna seu projeto mais flexível e menos dependente de redes Wi-Fi, ideal para situações de automação onde a conectividade com a internet não é garantida. O código pode ser adaptado conforme necessário para diferentes tipos de dispositivos e comandos.