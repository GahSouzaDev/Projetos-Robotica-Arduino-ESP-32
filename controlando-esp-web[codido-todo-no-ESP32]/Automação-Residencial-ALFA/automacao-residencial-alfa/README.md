# Controle de Automação Residencial com ESP32

Este projeto de automação residencial utiliza um ESP32 configurado como ponto de acesso para controlar dispositivos remotamente, sem a necessidade de aplicativos ou programas complexos. A interface é uma página web hospedada pelo próprio ESP32, que permite gerenciar dispositivos como luzes e janelas através de comandos simples, diretamente no navegador.

## Funcionalidades

- **Ponto de Acesso Wi-Fi**: O ESP32 cria uma rede Wi-Fi para que os dispositivos possam se conectar diretamente.
- **Controle de Dispositivos**: Controle o estado de luzes e janelas através de botões na interface web.
- **Interface Web Responsiva**: A página web é adaptada para dispositivos móveis e desktops, com comandos fáceis de usar.
- **Controle Simultâneo**: Vários dispositivos podem se conectar ao mesmo tempo para enviar comandos.

## Como Funciona

1. O ESP32 cria um ponto de acesso com o nome "MeuESP32" e a senha "12345678".
2. Ao conectar-se à rede, o usuário acessa a interface web no endereço `http://192.168.4.1`.
3. A página inicial oferece opções de navegação para controlar dispositivos da casa.
4. As ações, como ligar/desligar luzes ou abrir/fechar janelas, são realizadas através de requisições HTTP simples.

## Hardware Necessário

- ESP32
- LED interno (conectado ao pino 2 para indicar o estado da luz)
- Sensores ou atuadores opcionais para controle de outros dispositivos

## Estrutura do Código

O código é dividido nas seguintes partes principais:

- **Configuração do Ponto de Acesso e Servidor Web**: Configura o ESP32 para funcionar como um ponto de acesso e iniciar um servidor na porta 80.
- **Página Inicial e Página de Controle**: Funções para gerar e enviar o código HTML para o navegador do usuário.
- **Tratamento de Requisições HTTP**: Verifica as requisições recebidas e altera o estado dos dispositivos com base nos comandos enviados.
- **Atualização do Estado dos Dispositivos**: Mostra o status atual na interface web, refletindo o estado dos dispositivos controlados.

## Como Usar

1. **Carregue o código no ESP32** usando a IDE Arduino.
2. **Conecte-se à rede Wi-Fi "MeuESP32"** com a senha "12345678".
3. **Acesse `http://192.168.4.1`** no navegador para abrir a interface de controle.
4. **Controle os dispositivos** clicando nos botões para ligar/desligar luzes ou abrir/fechar janelas.

## Personalização

- Para alterar o SSID ou a senha do ponto de acesso, modifique as variáveis `ssid` e `password` no código.
- Outros dispositivos podem ser adicionados ou configurados, bastando ajustar o código para novos sensores ou atuadores.
- O design e os estilos da interface web podem ser modificados na função que gera o HTML.

## Licença

Este projeto está sob a licença MIT. Sinta-se à vontade para usá-lo e modificá-lo conforme necessário.
