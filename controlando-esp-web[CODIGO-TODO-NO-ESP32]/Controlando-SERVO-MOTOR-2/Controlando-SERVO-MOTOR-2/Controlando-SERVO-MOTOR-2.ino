#include <WiFi.h>
#include <ESP32Servo.h>

// Nome (SSID) e senha do ponto de acesso
const char* ssid = "MeuESP32";    // Nome do ponto de acesso
const char* password = "12345678"; // Senha do ponto de acesso

// Configuração do servo
const int servoPin = 4; // Pino do servo motor
Servo myServo; // Cria um objeto Servo

// Servidor web na porta 80
WiFiServer server(80);

// Variáveis para controle do servo
int currentPos = 90; // Posição atual do servo
int targetPos = 90;  // Posição alvo do servo
int speed = 10;      // Velocidade do servo (graus por passo)

void setup() {
  Serial.begin(9600);
  
  // Configura o pino do servo
  myServo.attach(servoPin);
  myServo.write(currentPos); // Inicializa o servo na posição 90

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
    client.flush(); // Limpa o buffer do cliente

    // Verifica se a requisição contém a nova posição do servo
    if (request.indexOf("/servo?pos=") != -1) {
      targetPos = request.substring(request.indexOf('=') + 1).toInt();
      targetPos = constrain(targetPos, 0, 180); // Limita o ângulo entre 0 e 180
      Serial.print("Nova posição do servo: ");
      Serial.println(targetPos);
    }

    // Verifica se a requisição contém a nova velocidade
    if (request.indexOf("/servo?speed=") != -1) {
      speed = request.substring(request.indexOf('=') + 1).toInt();
      speed = constrain(speed, 1, 30); // Limita a velocidade entre 1 e 30
      Serial.print("Nova velocidade: ");
      Serial.println(speed);
    }

    // Responde ao cliente com a página HTML e JavaScript
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html; charset=utf-8");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html lang=\"pt-BR\">");
    client.println("<head>");
    client.println("<title>Controle do Servo Motor</title>");
    
    // Estilo e script para o controle circular
    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f0f0f0; margin: 0; padding: 0; }");
    client.println("h1 { font-size: 40px; color: #333; }");
    client.println("p { font-size: 30px; color: #4CAF50; }");
    client.println(".knob { position: relative; width: 300px; height: 300px; border-radius: 50%; border: 10px solid #4CAF50; margin: 20px auto; overflow: hidden; }");
    client.println(".pointer { position: absolute; width: 6px; height: 150px; background-color: #4CAF50; bottom: 50%; left: 50%; transform-origin: bottom; transform: rotate(0deg); }");
    client.println("</style>");
    
    client.println("<script>");
    client.println("let angle = 90;");
    client.println("let speed = 10;");
    client.println("function updateServo() {");
    client.println("  const pos = Math.round((angle / 180) * 180);"); // Converte o ângulo para a posição do servo
    client.println("  var xhttp = new XMLHttpRequest();");
    client.println("  xhttp.open('GET', '/servo?pos=' + pos + '&speed=' + speed, true);");
    client.println("  xhttp.send();");
    client.println("  document.getElementById('position').innerText = pos;");
    client.println("  document.getElementById('speed').innerText = speed;");
    client.println("}");
    client.println("function rotateKnob(event) {");
    client.println("  const knob = document.querySelector('.knob');");
    client.println("  const rect = knob.getBoundingClientRect();");
    client.println("  const centerX = rect.left + rect.width / 2;");
    client.println("  const centerY = rect.top + rect.height / 2;");
    client.println("  const mouseX = event.clientX;");
    client.println("  const mouseY = event.clientY;");
    client.println("  angle = Math.atan2(mouseY - centerY, mouseX - centerX) * (180 / Math.PI) + 90;");
    client.println("  angle = Math.max(0, Math.min(180, angle));");
    client.println("  document.querySelector('.pointer').style.transform = 'rotate(' + angle + 'deg)';");
    client.println("  updateServo();");
    client.println("}");
    client.println("</script>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>Controle do Servo Motor</h1>");
    client.println("<div class='knob' onmousemove='rotateKnob(event)'>");
    client.println("  <div class='pointer'></div>");
    client.println("</div>");
    client.println("<p>Posição: <span id='position'>90</span></p>");
    client.println("<p>Velocidade: <span id='speed'>10</span></p>");
    client.println("</body>");
    client.println("</html>");

    // Fecha a conexão com o cliente
    client.stop();
    Serial.println("Cliente desconectado.");
  }

  // Atualiza a posição do servo gradualmente
  if (currentPos != targetPos) {
    if (currentPos < targetPos) {
      currentPos = min(currentPos + 1, targetPos);
    } else {
      currentPos = max(currentPos - 1, targetPos);
    }
    myServo.write(currentPos);
    delay(100 / speed); // Ajusta o delay conforme a velocidade
  }
}
