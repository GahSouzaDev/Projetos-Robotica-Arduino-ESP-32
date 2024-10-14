#include <WiFi.h>
#include <WebServer.h>

// Configurações da rede Wi-Fi
const char* ssid = "XXXXX";    // Substitua pelo SSID da sua rede WiFi
const char* password = "XXXXXX";  // Substitua pela senha da sua rede WiFi

// LED no GPIO2 (LED interno do ESP32)
const int ledVermelho = 15;
const int ledAmarelo = 2;
const int ledVerde = 4;
const int ledAzul = 16;
const int ledBranco = 17;

// Criação do servidor web na porta 80
WebServer server(80);

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Configura os pinos dos LEDs como saídas
  pinMode(ledVermelho, OUTPUT);
  digitalWrite(ledVermelho, LOW);  // Inicialmente, mantém o LED apagado
  pinMode(ledAmarelo, OUTPUT);
  digitalWrite(ledAmarelo, LOW);
  pinMode(ledVerde, OUTPUT);
  digitalWrite(ledVerde, LOW);
  pinMode(ledAzul, OUTPUT);
  digitalWrite(ledAzul, LOW);
  pinMode(ledBranco, OUTPUT);
  digitalWrite(ledBranco, LOW);

  // Conecta à rede Wi-Fi
  Serial.print("Conectando-se à ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Espera pela conexão Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  // Exibe o IP atribuído ao ESP32 após conexão bem-sucedida
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  
  // Define as rotas para os URLs /acender e /apagar o LED vermelho
  server.on("/acender-led-vermelho", []() {
    digitalWrite(ledVermelho, HIGH);   // Acende o LED vermelho
    server.send(200, "text/plain", "LED aceso");
  });
  
  server.on("/apagar-led-vermelho", []() {
    digitalWrite(ledVermelho, LOW);    // Apaga o LED vermelho
    server.send(200, "text/plain", "LED apagado");
  });

  // Define as rotas para os URLs /acender e /apagar o LED amarelo
  server.on("/acender-led-amarelo", []() {
    digitalWrite(ledAmarelo, HIGH);   // Acende o LED amarelo
    server.send(200, "text/plain", "LED aceso");
  });
  
  server.on("/apagar-led-amarelo", []() {
    digitalWrite(ledAmarelo, LOW);    // Apaga o LED amarelo
    server.send(200, "text/plain", "LED apagado");
  });

  // Define as rotas para os URLs /acender e /apagar o LED verde
  server.on("/acender-led-verde", []() {
    digitalWrite(ledVerde, HIGH);   // Acende o LED verde
    server.send(200, "text/plain", "LED aceso");
  });
  
  server.on("/apagar-led-verde", []() {
    digitalWrite(ledVerde, LOW);    // Apaga o LED verde
    server.send(200, "text/plain", "LED apagado");
  });

  // Define as rotas para os URLs /acender e /apagar o LED azul
  server.on("/acender-led-azul", []() {
    digitalWrite(ledAzul, HIGH);   // Acende o LED azul
    server.send(200, "text/plain", "LED aceso");
  });
  
  server.on("/apagar-led-azul", []() {
    digitalWrite(ledAzul, LOW);    // Apaga o LED azul
    server.send(200, "text/plain", "LED apagado");
  });

  // Define as rotas para os URLs /acender e /apagar o LED branco
  server.on("/acender-led-branco", []() {
    digitalWrite(ledBranco, HIGH);   // Acende o LED branco
    server.send(200, "text/plain", "LED aceso");
  });
  
  server.on("/apagar-led-branco", []() {
    digitalWrite(ledBranco, LOW);    // Apaga o LED branco
    server.send(200, "text/plain", "LED apagado");
  });

  // Inicia o servidor web
  server.begin();
  Serial.println("Servidor HTTP iniciado.");
}

void loop() {
  // Mantém o servidor rodando e processando requisições
  server.handleClient();
}