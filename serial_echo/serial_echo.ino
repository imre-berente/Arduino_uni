

void setup() {
  Serial.begin(9600);
}


void loop() {
  if (not Serial.available()) return;

  String msg = Serial.readStringUntil('\n');
  int lpos = msg.indexOf(";");
  if (-1 == lpos) {
    Serial.println("No separator in "+msg); 
    return;}
 
  if (msg.lastIndexOf(";") > lpos) {
    Serial.println("More than one separator in "+msg); 
    return;}
  
  String servoselectstr = msg.substring(lpos+1);
  int servoselect;
  if (servoselectstr == "1") servoselect=1;
  else if (servoselectstr == "2") servoselect=2;
  else {
    Serial.println("Invalid servo selected in "+msg); 
    return;}

  msg.remove(lpos);
  int target=msg.toInt();
  if ((msg != "0") and (0 == target)) {
    Serial.println("A number needed as servo angle instead of " + msg); 
    return; 
  }
  if ((0 > target) or (180 < target)) {
    Serial.println(msg + "is outside of 0-180 "); 
    return; 
  }


  Serial.print("Valid command received: Servo: ");
  Serial.print(servoselect);
  Serial.print(" Angle: ");
  Serial.println(target);

}