unsigned long time;
unsigned int timemicro,timemili,timesec,timemin;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  Serial.print("Time: ");
  time = micros();
  
  timemicro = time % 1000;
  time = time / 1000;
  timemili = time % 1000;
  time = time / 1000;
  timesec = time % 60;
  timemin = time / 60;
  Serial.print(timemin);
  Serial.print(":");
  Serial.print(timesec);
  Serial.print("."); 
  if (timemili < 100) Serial.print("0");
  if (timemili < 10) Serial.print("0");
  Serial.print(timemili);
  Serial.print(" ");
  if (timemicro < 100) Serial.print("0");
  if (timemicro < 10) Serial.print("0");
  Serial.println(timemicro);


  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
}
