// script ir breakbeam - franckysolo 18/12/2016

#define LED_PIN  13
#define SENSOR_PIN  4
#define BLUE_LED_PIN  2

int sensorState = 0, lastState = 0;

void setup() {
  // on intialise la LED en sortie
  pinMode(LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  // le pin du capteur en entrée
  pinMode(SENSOR_PIN, INPUT);
  // On met en route le capteur infra-rouge
  digitalWrite(SENSOR_PIN, HIGH);
  // console de sortie
  Serial.begin(9600);
}

void loop() {
  // A chaque tour on vérifie l'état du capteur
  sensorState = digitalRead(SENSOR_PIN);
  if (sensorState == LOW) {
    // on allume la led
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BLUE_LED_PIN, HIGH);
  } else {
    // on eteint la led
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
  }

  if (!sensorState && lastState) {
    Serial.println("Alerte, Intrusion détectée");
  }

  lastState = sensorState;
  
}
