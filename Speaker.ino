// C++ code
//

const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor

//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
int tones[] = {
220,
233,
246,
261,
277,
293,
311,
329,
349,
369,
392,
415,
440,
466,
493,
523,
554,
587,
622,
659,
698,
739,
783,
830,
880};

void setup()

{
  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
 // Beep speed and LED blink speed
  
  int pent = analogRead(A1);
  int pulse = map(pent, 0, 1023, 800, 0);
  digitalWrite(6, LOW);
  delay(pulse);
  digitalWrite(6, HIGH);

Serial.println(pent);

// Sensor Code

long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
//   Serial.print(inches);
//   Serial.print("in, ");
//   Serial.print(cm);
//   Serial.print("cm");
//   Serial.println();
//   delay(100);

  // Speaker Pitch from echo sensor
  int pot_to_tone = map(cm, 3, 50, 0, 24);
  
  if(pot_to_tone > 50 || pot_to_tone < 3){ //set to silent if too cloe or too far
    tone(9, 0,200);
  }
  else{
  tone(9, tones[pot_to_tone],200);
  }

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
