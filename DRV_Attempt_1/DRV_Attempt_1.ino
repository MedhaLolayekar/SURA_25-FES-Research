// Basic sketch for setting up stimulation trigger for OpenXstim
// For any queries please contact: md.malam@connect.polyu.hk

// #define Hz 20 // set your stimulation frequency
// #define burst 10 // set your pulse number in the burst
//#define interphase_delay 20 // units are microseconds

#define LOGIC_IN1 5
#define LOGIC_IN2 6

// unsigned int frequency = 10; // HZ
// unsigned int interphaseDelay = 5000; // microseconds
// unsigned int interpulseDelay = 1000/frequency; // miliseconds

// unsigned int positivePulse = 5000; // microseconds
// unsigned int negativePulse = 5000; // microseconds

void setup() {
  Serial.begin(9600);

  pinMode(LOGIC_IN1, OUTPUT);
  pinMode(LOGIC_IN2, OUTPUT); 

  digitalWrite(LOGIC_IN1, LOW);
  digitalWrite(LOGIC_IN2, LOW);
}
void loop() {
  
  // positive phase
  Serial.print("positive phase: ");

  digitalWrite(LOGIC_IN1, LOW);
  digitalWrite(LOGIC_IN2, HIGH);

  Serial.print(digitalRead(LOGIC_IN1));
  Serial.print(" ");
  Serial.println(digitalRead(LOGIC_IN2));  
  delay(5000);

  // // interphase delay
  // Serial.print("i-phase delay: ");
  
  // digitalWrite(LOGIC_IN1, LOW);    
  // digitalWrite(LOGIC_IN2, LOW);

  // Serial.print(digitalRead(LOGIC_IN1));
  // Serial.print(" ");
  // Serial.println(digitalRead(LOGIC_IN2));
  // delay(5000);
    
  // // negetive phase
  // Serial.print("negative phase: ");

  // digitalWrite(LOGIC_IN1, HIGH);    
  // digitalWrite(LOGIC_IN2, LOW);

  // Serial.print(digitalRead(LOGIC_IN1));
  // Serial.print(" ");
  // Serial.println(digitalRead(LOGIC_IN2));
  // delay(5000);
  
  // // interpulse delay
  // Serial.print("i-pulse delay: ");

  // digitalWrite(LOGIC_IN1, LOW);    
  // digitalWrite(LOGIC_IN2, LOW);

  // Serial.print(digitalRead(LOGIC_IN1));
  // Serial.print(" ");
  // Serial.println(digitalRead(LOGIC_IN2));
  // delay(5000);
}











//_________________//
// String inputString = "";
// bool stringComplete = false;


// unsigned int frequency = 20; // HZ
// unsigned int interphaseDelay = 5000000000; // microseconds
// unsigned int interpulseDelay = 1000/frequency; // miliseconds

// unsigned int positivePulse = 5000000000; // microseconds
// unsigned int negativePulse = 5000000000; // microseconds

// void setup() {
//   // initialized serial
//   Serial.begin(9600);
//   // reserve 200 bytes for the input string
//   inputString.reserve(200);

//   // pinMode(LED_BUILTIN, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT); 
//   // pinMode(LED_BUILTIN, OUTPUT);

//   // set everything as low initially
//   // digitalWrite(IN1, LOW);
//   // digitalWrite(IN2, LOW);
// }
// void loop() {

//   // positive phase
//   Serial.println("Positive pulse");
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);  
//   delayMicroseconds(positivePulse);
  
//   // interphase delay
//   Serial.println("I-Phase delay");
//   digitalWrite(IN1, LOW);    
//   digitalWrite(IN2, LOW);
//   delayMicroseconds(interphaseDelay);

//   // negetive phase
//   Serial.println("Negative pulse");
//   digitalWrite(IN1, HIGH);    
//   digitalWrite(IN2, LOW);
//   delayMicroseconds(negativePulse);

//   // interpulse delay
//   Serial.println("I-Pulse delay");
//   digitalWrite(IN1, LOW);    
//   digitalWrite(IN2, LOW);
//   delay(interpulseDelay);

//   // digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

// }


