// C++ code
//
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
  
  
  //sensor will have a value of 0-1023
  int sensor = analogRead(A0);
  int pent = analogRead(A1);
 
  Serial.println(pent);
  
  int sensoradj = map(sensor, 0, 50, 0, 255);
  int sensoradi = map(pent, 0, 50, 0, 255);
  
  //analog write wants a value of 0-255
  analogWrite(6, sensoradj); 
  analogWrite(5, sensoradi);


}
