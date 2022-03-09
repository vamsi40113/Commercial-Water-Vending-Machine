// Constants
const int coinpin = 2;
const int moterpin1 = 13;
const int moterpin2 =12;

// Variables
volatile int pulse = 0;

boolean bInserted = false;

// Setup
void setup() {
 
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, RISING);
  pinMode(moterpin1, OUTPUT);
   pinMode(moterpin2, OUTPUT);
 
}

// Main loop
void loop() {
 
 
  if( bInserted  )
  { // for show LED ON when Inserted
     bInserted = false;
     digitalWrite(moterpin1, HIGH);
     digitalWrite(moterpin2,LOW);
     Serial.print("\n moter is on");
        
     delay(7000);
      Serial.print("\n moter is off");
     digitalWrite(moterpin1, LOW);
     
     
    
     
     
  }
  
  else{
   
  // Turn off LED
  digitalWrite(moterpin1, LOW);
 // digitalWrite(moterpin2, LOW);
  } 
}

// Interrupt
void coinInterrupt(){
 
  // Each time a pulse is sent from the coin acceptor,
  // interrupt main loop to add 1  and flip on the LED
  pulse++ ;
  bInserted = true;

 // digitalWrite(ledpin, HIGH);
 // Serial.println( pulse ); 
}
