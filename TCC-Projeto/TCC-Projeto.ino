//declaração dos botões
#define botaoA 2 
#define botaoB 4
#define botaoC 6

//declaração dos LEDs
#define ledA 8
#define ledB 9
#define ledC 10

//declaração do sentido de rotação e velocidade
#define movdireita 12
#define movesquerda 13
#define velmotor 5
int vel=0;

//saída que aciona o relé da tocha
#define solda 7

/*declarações dos tipos das entradas e seus esta-
dos lógicos*/
void setup() {
  pinMode (botaoA, INPUT_PULLUP);
  pinMode (botaoB, INPUT_PULLUP);
  pinMode (botaoC, INPUT_PULLUP);
  pinMode (ledA, OUTPUT);
  pinMode (ledB, OUTPUT);
  pinMode (ledC, OUTPUT);
  digitalWrite (ledA, LOW);
  digitalWrite (ledB, LOW);
  digitalWrite (ledC, LOW);

  pinMode (velmotor, OUTPUT);
  pinMode (movdireita, OUTPUT);
  pinMode (movesquerda, OUTPUT);
  digitalWrite (movdireita, LOW);
  digitalWrite (movdireita, LOW);
  analogWrite (velmotor, vel);

  pinMode (solda, OUTPUT);
  digitalWrite (solda, LOW);
}

void loop() {
/*definição da velocidade de giro do motor
pela entrada analógica do arduino*/ 
  vel=255;

// primeiro botão azul, movimentar a direita  
  if (digitalRead (botaoA) == LOW){
    digitalWrite (ledA, HIGH);
    digitalWrite (movdireita, HIGH);
    delay (100);
    digitalWrite (ledA, LOW);
    digitalWrite (movdireita, LOW);
  }
  
// segundo botão azul, movimentar a esquerda  
  if (digitalRead (botaoB) == LOW){
    digitalWrite (ledB, HIGH);
    digitalWrite (movesquerda, HIGH);
    delay (100);
    digitalWrite (ledB, LOW);
    digitalWrite (movesquerda, LOW);
  }

// botão verde, movimenta a direita e liga a tocha
  if (digitalRead (botaoC) == LOW){
    digitalWrite (ledC, HIGH);
    delay (5000);
    digitalWrite (movdireita, HIGH);
    digitalWrite (solda, HIGH);
    delay (10000);
    digitalWrite (ledC, LOW);
    digitalWrite (movdireita, LOW);

    digitalWrite (solda, LOW);
  }
} 
