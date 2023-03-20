#include <IRremote.h>

// Define os pinos utilizados pelo módulo de IR
int IR_PIN = 11;
IRrecv irrecv(IR_PIN);
decode_results results;

// Define os pinos do motor do carrinho
int motor1_pin1 = 9;
int motor1_pin2 = 8;
int motor2_pin1 = 6;
int motor2_pin2 = 7;

void setup()
{
  // Inicializa o módulo de IR
  irrecv.enableIRIn();

  // Configura os pinos dos motores como saídas
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    // Comando para frente
    if (results.value == 0xFF629D)
    {
      digitalWrite(motor1_pin1, HIGH);
      digitalWrite(motor1_pin2, LOW);
      digitalWrite(motor2_pin1, HIGH);
      digitalWrite(motor2_pin2, LOW);
    }
    // Comando para trás
    else if (results.value == 0xFFA857)
    {
      digitalWrite(motor1_pin1, LOW);
      digitalWrite(motor1_pin2, HIGH);
      digitalWrite(motor2_pin1, LOW);
      digitalWrite(motor2_pin2, HIGH);
    }
    // Comando para esquerda
    else if (results.value == 0xFF22DD)
    {
      digitalWrite(motor1_pin1, HIGH);
      digitalWrite(motor1_pin2, LOW);
      digitalWrite(motor2_pin1, LOW);
      digitalWrite(motor2_pin2, HIGH);
    }
    // Comando para direita
    else if (results.value == 0xFFC23D)
    {
      digitalWrite(motor1_pin1, LOW);
      digitalWrite(motor1_pin2, HIGH);
      digitalWrite(motor2_pin1, HIGH);
      digitalWrite(motor2_pin2, LOW);
    }

    // Reinicia o módulo de IR para o próximo comando
    irrecv.resume();
  }
}
