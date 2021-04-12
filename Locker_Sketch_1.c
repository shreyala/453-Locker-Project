int pushButton = 10;
int rfid = 9;
int solenoid = 8;
int elecMagnets = 7;
int circuitBreaker = 6;
unsigned long delayStart = 0;
bool timeExpired = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton, INPUT);
  pinMode(rfid, INPUT);
  pinMode(solenoid, OUTPUT);
  pinMode(elecMagnets, OUTPUT);
  pinMode(circuitBreaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (timeExpired == false) && ((millis() - delayStart) >= 30000) {
    timeExpired = true;
    digitalWrite(circuitBreaker, HIGH);
    Serial.println("System Timed Out After 30 Sec.")
  }
  // code for reading RFID here
  val = digitalRead(rfid);
  if (val == HIGH) {
    digitalWrite(solenoid, HIGH);
    delay(250);
    digitalWrite(elecMagnets, HIGH);
    delay(250);
    digitalWrite(solenoid, LOW);
    digitalWrite(elecMagnets, LOW);
  }
}
