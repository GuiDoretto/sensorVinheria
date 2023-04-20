// Define as portas de saída dos LEDs e do buzzer
int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;
int buzzer = 6;

void setup() {
  // Define as portas de saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Lê a quantidade de luz no ambiente
  int valorLuz = analogRead(A0);
  Serial.println(valorLuz);
  
  // Se a quantidade de luz for menor que 300, acende o LED verde
  if (valorLuz < 100) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  }
  // Se a quantidade de luz estiver entre 300 e 700, acende o LED amarelo
  else if (valorLuz >= 100 && valorLuz < 200) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  }
  // Se a quantidade de luz for maior ou igual a 700, acende o LED vermelho e toca o buzzer
  if (valorLuz >= 200)
  {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000);
    delay(200);
       tone(buzzer, 2000);
    delay(200);
  }
  
  // Aguarda 100ms antes de ler novamente a quantidade de luz
  delay(100);
}