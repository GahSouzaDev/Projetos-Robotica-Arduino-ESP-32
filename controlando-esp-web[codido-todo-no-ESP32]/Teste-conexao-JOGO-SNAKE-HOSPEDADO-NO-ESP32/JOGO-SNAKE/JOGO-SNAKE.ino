#include <WiFi.h>

// Nome (SSID) e senha do ponto de acesso
const char* ssid = "MeuESP32";    // Nome do ponto de acesso
const char* password = "12345678"; // Senha do ponto de acesso

// Servidor web na porta 80
WiFiServer server(80);

void setup() {
  Serial.begin(115200); // Aumentar a velocidade da comunicação serial para 115200
  
  // Define a frequência máxima da CPU (240 MHz)
  setCpuFrequencyMhz(240);

  // Configura o ESP32 como ponto de acesso
  WiFi.softAP(ssid, password);
  Serial.println("Ponto de acesso criado");

  // Inicia o servidor web
  server.begin();
  Serial.println("Servidor web iniciado");
  Serial.println("Acesse http://192.168.4.1");
}

void loop() {
  // Verifica se há um cliente conectado
  WiFiClient client = server.available();
  if (!client) {
    return; // Se não há cliente, retorna imediatamente para evitar atrasos
  }

  Serial.println("Novo cliente conectado.");
  String request = client.readStringUntil('\r');
  client.flush(); // Limpa o buffer do cliente imediatamente após a leitura

  // Responde ao cliente com a página HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html; charset=utf-8");
  client.println("Connection: close");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html lang=\"pt-BR\">");
  client.println("<head>");
  client.println("<title>Jogo Snake</title>");
  client.println("<style>");
  client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f0f0f0; margin: 0; margin-top: 100px; padding: 0; }");
  client.println("h1 { font-size: 32px; color: #333; }");
  client.println("canvas { border: 1px solid #000; }");
  client.println(".button { padding: 40px; font-size: 30px; margin: 10px; cursor: pointer; }");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Jogo Snake</h1>");
  client.println("<canvas id=\"snakeCanvas\" width=\"700\" height=\"700\"></canvas>");
  client.println("<div>");
  client.println("<button class=\"button\" onclick=\"changeDirection('UP')\">Cima</button><br>");
  client.println("<button class=\"button\" onclick=\"changeDirection('LEFT')\">Esquerda</button>");
  client.println("<button class=\"button\" onclick=\"changeDirection('RIGHT')\">Direita</button><br>");
  client.println("<button class=\"button\" onclick=\"changeDirection('DOWN')\">Baixo</button>");
  client.println("</div>");
  client.println("<script>");
  client.println("var canvas = document.getElementById('snakeCanvas');");
  client.println("var ctx = canvas.getContext('2d');");
  client.println("var snake = [{ x: 10, y: 10 }];");
  client.println("var direction = 'RIGHT';");
  client.println("var food = { x: 0, y: 0 };");
  client.println("var score = 0;");
  client.println("var gameInterval;");
  client.println("function createFood() { food.x = Math.floor(Math.random() * 35); food.y = Math.floor(Math.random() * 35); }");
  client.println("function draw() { ctx.clearRect(0, 0, canvas.width, canvas.height); ctx.fillStyle = 'red'; ctx.fillRect(food.x * 20, food.y * 20, 20, 20); ctx.fillStyle = 'green'; snake.forEach(function(part) { ctx.fillRect(part.x * 20, part.y * 20, 20, 20); }); var head = { x: snake[0].x, y: snake[0].y }; if (direction === 'LEFT') head.x--; if (direction === 'RIGHT') head.x++; if (direction === 'UP') head.y--; if (direction === 'DOWN') head.y++; if (head.x === food.x && head.y === food.y) { score++; snake.unshift(head); createFood(); } else { snake.unshift(head); snake.pop(); } if (head.x < 0 || head.x >= 35 || head.y < 0 || head.y >= 35 || collision(head)) { clearInterval(gameInterval); alert('Game Over! Sua pontuação: ' + score); document.location.reload(); } }");
  client.println("function collision(head) { for (var i = 1; i < snake.length; i++) { if (head.x === snake[i].x && head.y === snake[i].y) return true; } return false; }");
  client.println("function changeDirection(newDirection) { if (newDirection === 'LEFT' && direction !== 'RIGHT') direction = 'LEFT'; if (newDirection === 'RIGHT' && direction !== 'LEFT') direction = 'RIGHT'; if (newDirection === 'UP' && direction !== 'DOWN') direction = 'UP'; if (newDirection === 'DOWN' && direction !== 'UP') direction = 'DOWN'; }");
  client.println("createFood(); gameInterval = setInterval(draw, 100);");
  client.println("</script>");
  client.println("</body>");
  client.println("</html>");

  // Fecha a conexão com o cliente
  client.stop();
  Serial.println("Cliente desconectado.");
}
