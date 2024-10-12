#include <WiFi.h>

// Nome (SSID) e senha do ponto de acesso
const char* ssid = "MeuESP32";    // Nome do ponto de acesso
const char* password = "12345678"; // Senha do ponto de acesso

// Servidor web na porta 80
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  
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

    // Responde ao cliente com a página HTML estilizada
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
    client.println(".button { padding: 40px; font-size: 30px; margin: 10px; cursor: pointer; }"); // Ajuste o tamanho dos botões
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>Jogo Snake</h1>");
    client.println("<canvas id=\"snakeCanvas\" width=\"700\" height=\"700\"></canvas>"); // Aumentando a área do jogo
    
    // Botões de controle
    client.println("<div>");
    client.println("<button class=\"button\" onclick=\"changeDirection('UP')\">Cima</button><br>");
    client.println("<button class=\"button\" onclick=\"changeDirection('LEFT')\">Esquerda</button>");
    client.println("<button class=\"button\" onclick=\"changeDirection('RIGHT')\">Direita</button><br>");
    client.println("<button class=\"button\" onclick=\"changeDirection('DOWN')\">Baixo</button>");
    client.println("</div>");
    
    client.println("<script>");
    client.println("var canvas = document.getElementById('snakeCanvas');");
    client.println("var ctx = canvas.getContext('2d');");

    // Configurações do jogo
    client.println("var snake = [{ x: 10, y: 10 }];");
    client.println("var direction = 'RIGHT';");
    client.println("var food = { x: 0, y: 0 };");
    client.println("var score = 0;"); 
    client.println("var gameInterval;");

    // Função para criar a comida
    client.println("function createFood() {");
    client.println("  food.x = Math.floor(Math.random() * 35);"); // Ajuste para nova largura (700/20)
    client.println("  food.y = Math.floor(Math.random() * 35);"); // Ajuste para nova altura (700/20)
    client.println("}");

    // Função para desenhar o jogo
    client.println("function draw() {");
    client.println("  ctx.clearRect(0, 0, canvas.width, canvas.height);");

    // Desenha a comida
    client.println("  ctx.fillStyle = 'red';");
    client.println("  ctx.fillRect(food.x * 20, food.y * 20, 20, 20);");

    // Desenha a cobra
    client.println("  ctx.fillStyle = 'green';");
    client.println("  snake.forEach(function(part) {");
    client.println("    ctx.fillRect(part.x * 20, part.y * 20, 20, 20);");
    client.println("  });");

    // Move a cobra
    client.println("  var head = { x: snake[0].x, y: snake[0].y };");
    client.println("  if (direction === 'LEFT') head.x--;");
    client.println("  if (direction === 'RIGHT') head.x++;");
    client.println("  if (direction === 'UP') head.y--;");
    client.println("  if (direction === 'DOWN') head.y++;");

    // Verifica se a cobra comeu a comida
    client.println("  if (head.x === food.x && head.y === food.y) {");
    client.println("    score++;");
    client.println("    snake.unshift(head);");
    client.println("    createFood();");
    client.println("  } else {");
    client.println("    snake.unshift(head);");
    client.println("    snake.pop();");
    client.println("  }");

    // Verifica colisão com as paredes ou com a própria cobra
    client.println("  if (head.x < 0 || head.x >= 35 || head.y < 0 || head.y >= 35 || collision(head)) {");
    client.println("    clearInterval(gameInterval);");
    client.println("    alert('Game Over! Sua pontuação: ' + score);");
    client.println("    document.location.reload();");
    client.println("  }");
    client.println("}");

    // Verifica se a cabeça da cobra colidiu com o corpo
    client.println("function collision(head) {");
    client.println("  for (var i = 1; i < snake.length; i++) {");
    client.println("    if (head.x === snake[i].x && head.y === snake[i].y) return true;");
    client.println("  }");
    client.println("  return false;");
    client.println("}");

    // Função para mudar a direção
    client.println("function changeDirection(newDirection) {");
    client.println("  if (newDirection === 'LEFT' && direction !== 'RIGHT') direction = 'LEFT';");
    client.println("  if (newDirection === 'RIGHT' && direction !== 'LEFT') direction = 'RIGHT';");
    client.println("  if (newDirection === 'UP' && direction !== 'DOWN') direction = 'UP';");
    client.println("  if (newDirection === 'DOWN' && direction !== 'UP') direction = 'DOWN';");
    client.println("}");

    // Inicia o jogo
    client.println("createFood();");
    client.println("gameInterval = setInterval(draw, 100);");
    client.println("</script>");
    client.println("</body>");
    client.println("</html>");

    // Fecha a conexão com o cliente
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
