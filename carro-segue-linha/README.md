------------------------------------------------Programação------------------------------------------------

A programação de exemplo tem como propósito fazer o robô identificar a cor do chão, ativando e desativando os motores de acordo com a variação de cor, possibilitando que o robô possa seguir a linha em qualquer formato desejado.

No início da programação é dado novos nomes para cada porta utilizada para facilitar o entendimento da programação, depois ativa os sensores para iniciar o processo de seguir a linha, controlando a velocidade e direção dos motores.

------------------------------------------------Preparação------------------------------------------------

-	Conecte um jumper na porta cinco volts do Arduino na trilha de alimentação positiva da protoboard, onde está sinalizado com o sinal de mais (+);
-	Conecte um jumper na porta GND do Arduino na trilha de alimentação negativa da protoboard, onde está sinalizado com o sinal de menos (-);
-	Conecte os jumpers GND dos sensores (IR) Infra Vermelho na trilha de alimentação negativa da protoboard, onde está sinalizado com o sinal de menos (-);
-	Conecte os jumpers cinco voltes dos sensores (IR) Infra Vermelho na trilha de alimentação positiva da protoboard, onde está sinalizado com o sinal de mais (+);
-	Conecte o jumper “D0” do sensor (IR) Infra Vermelho do lado direito na porta digital de número três do Arduino;
-	Conecte o jumper “D0” do sensor (IR) Infra Vermelho do lado esquerdo na porta digital de número dois do Arduino;
-	Conecte os motores no controlador de motores usando uma chave Philips;
-	Conecte um jumper no terminal “A1” do controlador de motores e na porta digital de número cinco do Arduino;
-	Conecte um jumper no terminal “A2” do controlador de motores e na porta digital de número seis do Arduino;
-	Conecte um jumper no terminal “A3” do controlador de motores e na porta digital de número dez do Arduino;
-	Conecte um jumper no terminal “A2” do controlador de motores e na porta digital de número onze do Arduino;
-	Conecte um dos lados da bateria ou fonte de alimentação em um dos jumpers da chave gangorra e conecte o outro jumper no controlador de motores;
-	Conecte o outro lado da bateria ou da fonte de alimentação diretamente no controlador de motores.

Para alimentar o Arduino com bateria basta conectar os polos da bateria nas trilhas da protoboard, respeitando o lado positivo e negativo para não danificar nenhum componente.

------------------------------------CODIGO FEITO NA IDE-ARDUINO------------------------------------

-------------------------------------------[Link para ver o projeto funcionando](https://www.instagram.com/p/C5VY6kgOXce/)-------------------------------------------
