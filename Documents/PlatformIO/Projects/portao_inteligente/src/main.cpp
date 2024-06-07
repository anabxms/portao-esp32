#include <Arduino.h>
#include <Ultrasonic.h> // Inclua a biblioteca do sensor ultrassônico

// leds
#define ledPinBranco 19
#define ledPinAmarelo 21

// sensor proximidade
#define trigger 4
#define echo 5

// Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(trigger, echo);

int getDistance() {
    // Faz a leitura das informações do sensor (em cm)
    int distanciaCM;
    long microsec = ultrasonic.timing();
    // Pode ser um float ex: 20,42 cm se declarar a var float 
    distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
 
    return distanciaCM;
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPinBranco, OUTPUT);  
  pinMode(ledPinAmarelo, OUTPUT);  
  Serial.println("Setup completo");
}

void loop() {
  int distancia = getDistance();
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 20) { // Exemplo: se a distância for menor que 20 cm, acenda o LED branco
    Serial.println("Objeto próximo. Ligando LED branco.");
    digitalWrite(ledPinBranco, HIGH);  
    digitalWrite(ledPinAmarelo, LOW); 
  } else { // Caso contrário, acenda o LED amarelo
    Serial.println("Objeto distante. Ligando LED amarelo.");
    digitalWrite(ledPinBranco, LOW); 
    digitalWrite(ledPinAmarelo, HIGH);  
  }
  
  delay(1000);  
}
