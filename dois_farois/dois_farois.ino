#define led_vermelho 4
#define led_amarelo 3
#define led_verde 2
#define led_outrovermelho 7
#define led_outroamarelo 6
#define led_outroverde 5

// Função SETUP de inicilização é executada apenas uma vez quando o arduíno liga
void setup() {

  pinMode (led_vermelho, OUTPUT);
  pinMode (led_amarelo, OUTPUT);
  pinMode (led_verde, OUTPUT);
  pinMode (led_outrovermelho, OUTPUT);
  pinMode (led_outroamarelo, OUTPUT);
  pinMode (led_outroverde, OUTPUT);

// Apagando todos os pinos  
  digitalWrite (led_vermelho, LOW);
  digitalWrite (led_amarelo, LOW);
  digitalWrite (led_verde, LOW);
  digitalWrite (led_outrovermelho, LOW);
  digitalWrite (led_outroamarelo, LOW);
  digitalWrite (led_outroverde, LOW);
}

// Função LOOP função do programa que se repete indefinidamente
void loop() {
  
  digitalWrite (led_vermelho, HIGH);  // Acende o led vermelho
  digitalWrite (led_outroverde, HIGH);
  delay (5000);

  digitalWrite (led_outroverde, LOW);
  digitalWrite (led_outroamarelo, HIGH);
  delay (1250);
  digitalWrite (led_outroamarelo, LOW);
  digitalWrite (led_outrovermelho, HIGH);
  digitalWrite (led_vermelho, LOW);
  digitalWrite (led_verde, HIGH);
  delay (5000);

  digitalWrite (led_verde, LOW);
  digitalWrite (led_amarelo, HIGH);
  delay (1250);
  digitalWrite (led_amarelo, LOW);
  digitalWrite (led_outrovermelho, LOW);
  
 

}
