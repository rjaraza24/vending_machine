int ov = 8; //negative motor terminal
int gateT = 2000;
int flowT = 20000;
int cv = 9; //positive motor terminal
int ol = 11; // opening limit button;
int cl = 10; //closing limit button;
boolean os =false; // opened stop now
boolean cs =false; //closed stop now
boolean flowing =false; //flowing
boolean ok = false;
int raspiBut = 5;  //raspi button
enum {OPEN, CLOSED, OPENING, CLOSING, UNKNOWN};
byte get_roof_status()
{
    if (digitalRead(cl) == LOW) return CLOSED;
    else if (digitalRead(ol) == LOW) return OPEN; // Fixed typo
    else if (digitalRead(raspiBut) == HIGH) return UNKNOWN;
//    else if (digitalRead(cv) == LOW) return CLOSING;
    return UNKNOWN;
}


void close_roof() {
//    digitalWrite(alarm, HIGH);
//    digitalWrite(enable_motor, HIGH);
    digitalWrite(cv, LOW);
    digitalWrite(ov, HIGH);
    // Loop until roof is open
    while (OPEN != get_roof_status()) /* NULL */;
    stop();
}
void open_roof() {
//    digitalWrite(alarm, HIGH);
//    digitalWrite(enable_motor, HIGH);
    digitalWrite(ov, LOW);
    digitalWrite(cv, HIGH);
    // Loop until roof is closed
    while (CLOSED != get_roof_status()) /* NULL */;
    stop();
}
void stop() {
//    digitalWrite(alarm, LOW);
//    digitalWrite(enable_motor, LOW);
    digitalWrite(ov, HIGH);
    digitalWrite(cv, HIGH);
}

void setup() {
  Serial.begin(9600);
pinMode(ov, OUTPUT);
pinMode(cv, OUTPUT);
pinMode(ol, INPUT_PULLUP);
pinMode(cl, INPUT_PULLUP);
pinMode(raspiBut, INPUT_PULLUP);
delay(1000);
stop();
delay(3000);
}

void loop() {
  if(digitalRead(raspiBut) == LOW) {
       Serial.println("button");

   ok = true;
       delay(200);
  }
  if ( ok == true) {
    Serial.println("Detected");
    flowing = true;
  }
   if(flowing == true){
    delay(200);
    Serial.println("flowing");
      open_roof();
delay(8000);

    Serial.println("closing");
      close_roof();
      Serial.println("closed");
      ok = false;
      flowing = false;
          delay(200);
   }
  delay(100);


}
