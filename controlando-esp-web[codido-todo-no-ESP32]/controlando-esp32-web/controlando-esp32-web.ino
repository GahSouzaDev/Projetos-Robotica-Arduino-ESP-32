#include <WiFi.h>

// Nome (SSID) e senha do ponto de acesso
const char* ssid = "MeuESP32";    // Nome do ponto de acesso
const char* password = "12345678"; // Senha do ponto de acesso

// Porta do LED
const int ledPin = 2;

// Servidor web na porta 80
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  
  // Configura o LED como saída
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED começa desligado

  // Configura o ESP32 como ponto de acesso
  WiFi.softAP(ssid, password);
  Serial.println("Ponto de acesso criado");

  // Inicia o servidor web
  server.begin();
  Serial.println("Servidor web iniciado");
  Serial.print("Acesse http://192.168.4.1");
}

void loop() {
  // Verifica se há um cliente conectado
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Novo cliente conectado.");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    //client.flush(); // Limpa o buffer do cliente

    // Verifica se a requisição é para ligar o LED
    if (request.indexOf("/LED=ON") != -1) {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ligado");
    }
    // Verifica se a requisição é para desligar o LED
    if (request.indexOf("/LED=OFF") != -1) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED desligado");
    }

    // Responde ao cliente com a página HTML estilizada
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html; charset=utf-8"); // Adiciona charset
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html lang=\"pt-BR\">"); // Define o idioma como português do Brasil
    client.println("<head>");
    client.println("<title>Controle do LED interno</title>");
    // Estilo CSS
    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif;  text-align: center; background-color: #f0f0f0; margin: 0; padding: 0; }");
    client.println("h1 { font-size: 56px; color: #333; }");
    client.println("button { padding: 30px 60px; font-size: 40px; margin: 10px; cursor: pointer; }");
    client.println(".btn-on { background-color: #4CAF50; color: white; border: none; }");
    client.println(".btn-off { background-color: #f44336; color: white; border: none; }");
    client.println(".btn-on:hover { background-color: #45a049; }");
    client.println(".btn-off:hover { background-color: #e53935; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>Controle do LED</h1>");
    client.println("<p><a href=\"/LED=ON\"><button class=\"btn-on\">Ligar LED</button></a></p>");
    client.println("<p><a href=\"/LED=OFF\"><button class=\"btn-off\">Desligar LED</button></a></p>");
    client.println("</body>");
    client.println("</html>");

    // Fecha a conexão com o cliente
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}