//Definição dos pinos de controle do motor
#define M1 10 // pino de controle de velocidade do motor da esquerda
//velocidade do motor varia de “0” a “255”

#define M2 5 //pino de controle de velocidade do motor da direita
//velocidade do motor varia de “0” a “255”
#define dir1 11 //pino de controle de direção do motor da esquerda
//HIGH roda o motor para um lado e LOW roda o motor para outro lado

#define dir2 6 ///pino de controle de direção do motor da direita
//HIGH roda o motor para um lado e LOW roda o motor para outro lado

//definindo pinos dos sensores (IR) Infra Vermelho
#define pin_S1 2 //sensor (IR) do lado direito
#define pin_S2 3 //sensor (IR) do lado esquerdo

//define valor de referência para sensores (IR) Infra Vermelho
bool Sensor1 = 0;
bool Sensor2 = 0;

//variável responsável por controlar a velocidade dos motores
int velocidade = 80; //valor pode ser alterado para deixa o robô mais rápido ou mais lente

void setup(){

//declara os pinos digitais como saída
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);

//declara os pinos dos sensores (IR) como entrada
pinMode(pin_S1, INPUT);
pinMode(pin_S2, INPUT);
}

void loop(){

//neste processo armazenamos o valor lido pelo sensor na variável 
Sensor1 = digitalRead(pin_S1);
Sensor2 = digitalRead(pin_S2);

//aqui está toda a lógica do comportamento do robô
//para a cor branca atribuímos o valor 0 e para a cor preta o valor 1.

if //variavel se
((Sensor1 == 0) && (Sensor2 == 0)){ // se detectar na extremidade das faixas duas cores brancas
analogWrite(M1, velocidade); // ambos motores ligam na mesma velocidade e direção
analogWrite(M2, velocidade);
digitalWrite(dir1, LOW);
digitalWrite(dir2, LOW);
}
if //variavel se
((Sensor1 == 1) && (Sensor2 == 0)){ // se detectar um lado preto e o outro branco
analogWrite(M1, 170); //um motor roda para um lado, e outro de forma invertida
analogWrite(M2, velocidade); //para alinhar o robô na faixa
digitalWrite(dir1, HIGH);
digitalWrite(dir2, LOW);// }

if //variavel se
((Sensor1 == 0) && (Sensor2 == 1)){ //  se detectar um lado preto e o outro branco
analogWrite(M1, velocidade); //um motor roda para um lado, e outro de forma invertida
analogWrite(M2, 170); //para alinhar o robô na faixa
digitalWrite(dir1, LOW);
digitalWrite(dir2, HIGH);// 
}
if((Sensor1 == 1) && (Sensor2 == 1)){ // se detectar os dois lados a cor preta
analogWrite(M1, 0); // ambos motores desligam, parando o robo
analogWrite(M2, 0);
digitalWrite(dir1, LOW);
digitalWrite(dir2, LOW);
}
}
