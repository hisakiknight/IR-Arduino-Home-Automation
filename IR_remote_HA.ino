#include <IRremote.h>

//if RECV_PIN = 2; cannot work then change it to 11.

int RECV_PIN = 2; 
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;
int led7 = 6;
int led8 = 5;
boolean bt1;
boolean bt2;
boolean bt3;
boolean bt4;
boolean bt5;
boolean bt6;
boolean bt7;
boolean bt8;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}


void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    dump(&results);
    
  // Button 1
    if (results.value == 16582903){
      if (bt1 == 0){
      bt1++;
     Serial.println(bt1);
        digitalWrite(led1, HIGH);
        delay(50);
      }
      
  else if (bt1 == 1){
      bt1 = 0;
     Serial.println(bt1);
      digitalWrite(led1, LOW);
      delay(50);
      }
    };
    
    //Button 2
        if (results.value == 16615543){
      if (bt2 == 0){
      bt2++;
     Serial.println(bt2);
        digitalWrite(led2, HIGH);
        delay(50);
      }
      
  else if (bt2 == 1){
      bt2 = 0;
     Serial.println(bt2);
      digitalWrite(led2, LOW);
      delay(50);
      }
    };
    
        //Button 3
        if (results.value == 16599223){
      if (bt3 == 0){
      bt3++;
     Serial.println(bt3);
     digitalWrite(led3, HIGH);
     delay(50);
      }
      
  else if (bt3 == 1){
      bt3 = 0;
     Serial.println(bt3);
      digitalWrite(led3, LOW);
      delay(50);
      }
    };
    
        //Button 4
        if (results.value == 16591063){
      if (bt4 == 0){
      bt4++;
     Serial.println(bt4);
        digitalWrite(led4, HIGH);
        delay(50);
      }
      
  else if (bt4 == 1){
      bt4 = 0;
     Serial.println(bt4);
      digitalWrite(led4, LOW);
      delay(50);
      }
    };
    
        //Button 5
        if (results.value == 16623703){
      if (bt5 == 0){
      bt5++;
     Serial.println(bt5);
        digitalWrite(led5, HIGH);
        delay(50);
      }
      
  else if (bt5 == 1){
      bt5 = 0;
     Serial.println(bt5);
      digitalWrite(led5, LOW);
      delay(50);
      }
    };
    
        //Button 6
        if (results.value == 16607383){
      if (bt6 == 0){
      bt6++;
     Serial.println(bt6);
        digitalWrite(led6, HIGH);
        delay(50);
      }
      
  else if (bt6 == 1){
      bt6 = 0;
     Serial.println(bt6);
      digitalWrite(led6, LOW);
      delay(50);
      }
    };
    
        //Button 7
        if (results.value == 16586983){
      if (bt7 == 0){
      bt7++;
     Serial.println(bt7);
        digitalWrite(led7, HIGH);
        delay(50);
      }
      
  else if (bt7 == 1){
      bt7 = 0;
     Serial.println(bt7);
      digitalWrite(led7, LOW);
      delay(50);
      }
    };
    
        //Button 8
        if (results.value == 16619623){
      if (bt8 == 0){
      bt8++;
     Serial.println(bt8);
        digitalWrite(led8, HIGH);
        delay(50);
      }
      
  else if (bt8 == 1){
      bt8 = 0;
     Serial.println(bt8);
      digitalWrite(led8, LOW);
      delay(50);
      }
    };
    
    //I/O
        if (results.value == 16580863)
      {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
        delay(50);
      };
    
     irrecv.resume(); // Receive the next value
  }
}
