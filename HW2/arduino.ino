int receivedValue;
int yellowPin = 13;
int redPin = 11;
int fact = 1;
int num;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming integer
    receivedValue = Serial.parseInt();
    // Process the received integer (e.g., control an LED)
    if (receivedValue == 1) {
         digitalWrite(yellowPin, HIGH);
      // Do something when the received value is 1
    } if (receivedValue == 2) {
      digitalWrite(yellowPin, LOW);
      // Do something when the received value is 1
    }
    if (receivedValue == 3) {
      for(int i=0;i<5;i++){
      digitalWrite(yellowPin,HIGH);
      delay(500);
      digitalWrite(yellowPin, LOW);
      delay(500);
      }
        
      // Do something when the received value is 1
    }
    else if (receivedValue == 4) {
          num = Serial.parseInt();
          for(int i=1;i<=num;i++){
          fact = fact * i;
          }
    Serial.print("Factorial is ");
    Serial.println( fact);
    fact = 1;
    }
     if (receivedValue == 5) {


     }
    if (receivedValue == 1) {
      digitalWrite(redPin, HIGH);
      delay(2000);
      digitalWrite(redPin, LOW);



  }
}
}