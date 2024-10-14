#include <WiFi.h>

// Nome (SSID) e senha do ponto de acesso
const char* ssid = "MeuESP32";
const char* password = "12345678";

// Servidor web na porta 80
WiFiServer server(80);

// Estados dos dispositivos
bool LuzLigada = false; 
bool JanelaAberta = false; 

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(240); // Define a frequência máxima da CPU (240 MHz)
  WiFi.softAP(ssid, password); // Configura o ESP32 como ponto de acesso
  Serial.println("Ponto de acesso criado");
  
  server.begin(); // Inicia o servidor web
  Serial.println("Servidor web iniciado");
  Serial.println("Acesse http://192.168.4.1");
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  
}

void loop() {
  WiFiClient client = server.available(); // Verifica se há um cliente conectado
  if (!client) return; // Se não há cliente, retorna imediatamente

  String request = client.readStringUntil('\r'); // Lê a requisição do cliente
  //client.flush(); // Limpa o buffer do cliente

  // Verifica a ação a ser tomada com base na requisição
  if (request.indexOf("GET /sala") >= 0) {
    sala(client); // Chama a função que serve a página "sala"
  } else if (request.indexOf("GET /ligar-luz") >= 0) {
    LuzLigada = true; // Atualiza o estado da luz
    sala(client); // Recarrega a página "sala"
  } else if (request.indexOf("GET /desligar-luz") >= 0) {
    LuzLigada = false; // Atualiza o estado da luz
    sala(client); // Recarrega a página "sala"
  } else if (request.indexOf("GET /abrir-janela") >= 0) {
    JanelaAberta = true; // Atualiza o estado da janela
    sala(client); // Recarrega a página "sala"
  } else if (request.indexOf("GET /fechar-janela") >= 0) {
    JanelaAberta = false; // Atualiza o estado da janela
    sala(client); // Recarrega a página "sala"
  } else {
    inicio(client); // Chama a função que serve a página inicial
  }
  
  client.stop(); // Fecha a conexão com o cliente
}

// Função para servir a página inicial
void inicio(WiFiClient& client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html; charset=utf-8");
  client.println("Connection: close");
  client.println();

  // Estrutura HTML da página inicial
  client.println("<!DOCTYPE HTML>");
  client.println("<html lang=\"pt-BR\">");
  client.println("<head>");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"); // Escala para celular
  client.println("<title>Página Inicial</title>");
  client.println("<style>");
  client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f0f0f0; margin: 0; margin-top: 100px; padding: 0; }");
  client.println(".button { font-size: 50px; padding: 15px 30px; margin: 10px; font-weight: bold; border: none; cursor: pointer; }");
  client.println(".sala { background-color: #FFD700; color: #000; }");
  client.println(".text-autoria { font-size: 15px; color: #808080; margin-top: 150px; }");

  // Estilos específicos para celulares
  client.println("@media only screen and (max-width: 600px) {");
  client.println("  body { font-size: 20px; margin-top: 50px; }");
  client.println("  .button { font-size: 35px; padding: 10px 20px; }");
  client.println("  .text-autoria { font-size: 10px; }");
  client.println("}");

  // Estilos específicos para desktop
  client.println("@media only screen and (min-width: 601px) {");
  client.println("  body { font-size: 20px; }");
  client.println("  .button { font-size: 20px; padding: 15px 30px; }");
  client.println("  .text-autoria { font-size: 15px; }");
  client.println("}");
  
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Bem-vindo ao Controle de Dispositivos</h1>");
  client.println("<p>Escolha uma opção:</p>");
  client.println("<button class=\"button sala\" onclick=\"location.href='/sala'\">Ir para Sala</button>");
  client.println("<p class=\"text-autoria\">Projeto criado por:<br>Emerson Gabriel Souza<br>www.gahsouza.com.br</p>");
  client.println("</body></html>");
}

// Função para servir a página da sala
// Função para servir a página da sala
void sala(WiFiClient& client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html; charset=utf-8");
  client.println("Connection: close");
  client.println();

  // Estrutura HTML da página da sala
  client.println("<!DOCTYPE HTML>");
  client.println("<html lang=\"pt-BR\">");
  client.println("<head>");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"); // Escala para dispositivos móveis
  client.println("<title>Página da Sala</title>");
  client.println("<style>");
  client.println("body { font-family: Arial, sans-serif; font-size: 35px; text-align: center; background-color: #f0f0f0; margin: 0; padding: 0; }");
  client.println(".button { font-size: 35px; padding: 15px 30px; margin: 10px; font-weight: bold; border: none; cursor: pointer; }");

  // Estilos de botões
  client.println(".ligar { background-color: #ADD8E6; color: #000; }");
  client.println(".ligar-on { background-color: #6495ED; color: #FFF; }");
  client.println(".desligar { background-color: #ff9999; color: #000; }");
  client.println(".desligar-on { background-color: #f44336; color: #FFF; }");
  client.println(".abrir { background-color: #ADD8E6; color: #000; }");
  client.println(".abrir-on { background-color: #6495ED; color: #FFF; }");
  client.println(".fechar { background-color: #ff9999; color: #000; }");
  client.println(".fechar-on { background-color: #f44336; color: #FFF; }");

  // Estilos específicos para dispositivos móveis
  client.println("@media only screen and (max-width: 600px) {");
  client.println("  body { font-size: 20px; }");
  client.println("  .button { font-size: 15px; padding: 10px 20px; }");
  client.println("  .text-atualizar { font-size: 15px;  }");
  client.println("  .atualizar { font-size: 20px; }");
  client.println("  .voltar { font-size: 20px;  }");
  client.println("  .div { width: auto; height: auto; padding: 10px; }");
  client.println("  .text-autoria { font-size: 18px; }");  
  // Estilo para o botão atualizar e outros elementos
  client.println(".text-atualizar { font-size:15 px; color: #808080;  }");
  client.println(".atualizar { background-color: #90EE90; color: #000; }");
  client.println(".voltar { background-color: #FFD700; color: #000; }");  
  // Definindo a div com borda e margens
  client.println(".div { border: 1px solid #000; margin-top: 100px;  margin: 0 auto; padding: 20px; background-color: #fff; }");
  // Texto de direitos autorais
  client.println(".text-autoria { font-size: 10px; color: #808080; }");
  client.println("}");

  // Estilos específicos para desktop
  client.println("@media only screen and (min-width: 601px) {");
  client.println("  body { font-size: 15px; }");
  client.println("  .button { font-size: 13px; padding: 15px 30px; }");
  // Estilo para o botão atualizar e outros elementos
  client.println(".text-atualizar { font-size: 10px; color: #808080;  }");
  client.println(".atualizar { background-color: #90EE90; color: #000; width: 800px;}");
  client.println(".voltar { background-color: #FFD700; color: #000; width: 800px;}");  
  // Definindo a div com borda e margens
  client.println(".div { border: 1px solid #000;  width: 800px; height: auto; margin: 0 auto; padding: 10px; background-color: #fff; }");
  // Texto de direitos autorais
  client.println(".text-autoria { font-size: 10px; color: #808080; ");
  client.println("}");
  
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Controle da Sala</h1>");
  client.println("<p>Controle os dispositivos da sala aqui.</p>");

  // Abertura da div com a classe
  client.println("<div class=\"div\">");

  // Mostra o estado atual da luz
  if (LuzLigada) {
    digitalWrite(2,HIGH);
    client.println("<p>Status: <strong>Luz Ligada</strong></p>");
    client.println("<button class=\"button ligar-on\">Ligar Luz</button>");
    client.println("<button class=\"button desligar\" onclick=\"location.href='/desligar-luz'\">Desligar Luz</button>");
  } else {
    digitalWrite(2,LOW);
    client.println("<p>Status: <strong>Luz Desligada</strong></p>");
    client.println("<button class=\"button ligar\" onclick=\"location.href='/ligar-luz'\">Ligar Luz</button>");
    client.println("<button class=\"button desligar-on\">Desligar Luz</button>");
  }

  // Mostra o estado atual da janela
  if (JanelaAberta) {
    client.println("<p>Status: <strong>Janela Aberta</strong></p>");
    client.println("<button class=\"button abrir-on\">Abrir Janela</button>");
    client.println("<button class=\"button fechar\" onclick=\"location.href='/fechar-janela'\">Fechar Janela</button>");
  } else {
    client.println("<p>Status: <strong>Janela Fechada</strong></p>");
    client.println("<button class=\"button abrir\" onclick=\"location.href='/abrir-janela'\">Abrir Janela</button>");
    client.println("<button class=\"button fechar-on\">Fechar Janela</button>");
  }

  client.println("</div>"); // Fechamento da div

  client.println("<br><br>");
  client.println("<p class=\"text-atualizar\">Verifique se há novos comandos disponíveis.</p>");
  client.println("<button class=\"button atualizar\" onclick=\"location.href='/sala'\">Recarregar Estado</button>");
  client.println("<button class=\"button voltar\" onclick=\"location.href='/'\">Voltar para o Início</button>");
  client.println("<p class=\"text-autoria\">Projeto criado por:<br>Emerson Gabriel Souza<br>www.gahsouza.com.br</p>");
  client.println("</body></html>");
}
