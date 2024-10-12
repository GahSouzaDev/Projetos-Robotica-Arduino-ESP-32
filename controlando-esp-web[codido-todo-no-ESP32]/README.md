# Projeto de Controle de Dispositivos IoT com ESP32

## Descoberta Incrível!

Você sabia que é possível compilar HTML, CSS e JavaScript diretamente no seu ESP32 ou Arduino? Isso mesmo! É possível criar interfaces web personalizadas para controlar seus projetos de forma intuitiva, sem a necessidade de aplicativos extras.

Imagine criar um painel de controle completo, acessível por qualquer navegador, para gerenciar seus dispositivos IoT. Essa funcionalidade abre um mundo de possibilidades para projetos mais interativos e acessíveis.

## Tecnologias Utilizadas

- **ESP32**: Módulo microcontrolador com conectividade Wi-Fi.
- **Arduino IDE**: Ambiente de desenvolvimento integrado para programar o ESP32.
- **HTML**: Linguagem de marcação para criar a estrutura da página web.
- **CSS**: Folhas de estilo para personalizar a aparência da interface.
- **JavaScript**: Linguagem de programação para adicionar interatividade à página.

## Funcionalidades

- **Controle de LED**: Acender e apagar um LED interno através de um painel web.
- **Acesso via navegador**: O painel de controle pode ser acessado de qualquer dispositivo conectado à mesma rede.
- **Interface Personalizável**: Modifique o design e a funcionalidade da página conforme suas necessidades.

## Como Funciona

1. **Configuração do ESP32**: O ESP32 é configurado como um ponto de acesso Wi-Fi.
2. **Servidor Web**: Um servidor web é iniciado no ESP32, servindo uma página HTML com botões para controlar o LED.
3. **Comunicação**: A interação com os botões é gerenciada por JavaScript, que envia requisições HTTP ao ESP32 para ligar ou desligar o LED.

## Como Usar

1. **Carregue o código no ESP32**: Utilize a Arduino IDE para compilar e carregar o código fornecido.
2. **Conecte-se ao ponto de acesso**: No seu dispositivo, conecte-se à rede Wi-Fi criada pelo ESP32.
3. **Acesse o painel**: Abra um navegador e digite o endereço `http://192.168.4.1` para acessar a interface de controle.
4. **Controle o LED**: Use os botões na página para ligar e desligar o LED.

## Contribuições

Sinta-se à vontade para contribuir com melhorias ou sugestões! Faça um fork do repositório e envie suas alterações através de um pull request.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).

## Contato

Para dúvidas ou sugestões, entre em contato através do site: [gahsouza.com.br]
