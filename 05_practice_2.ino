#define PIN_7 7
unsigned int count, toggle;

void setup() {
  pinMode(PIN_7, OUTPUT);
  Serial.begin(115200); // Initialize serial port
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  count = toggle = 0;
  digitalWrite(PIN_7, toggle); // turn off LED.
  delay(1000);
}

void loop() {
  Serial.println(++count);
  
  digitalWrite(PIN_7, HIGH);
  delay(200);
  
  for (int i = 0; i < 10; i++) {
    toggle = toggle_state(toggle); // toggle LED value.
    digitalWrite(PIN_7, toggle);
    delay(200);
  }
  
  digitalWrite(PIN_7, LOW); // turn off LED
  
  while(1) {}} // infinite loop

int toggle_state(int toggle) {
  return (toggle+1)%2;
}
