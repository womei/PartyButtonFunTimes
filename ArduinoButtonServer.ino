// This sends the state of a button, connected between the pin and GROUND to the serial connection
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
boolean firstPushed = true;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if the button is not pushed the state is 'HIGH', it's more stable I guess.... pullup something
  if (buttonState == HIGH) {  
    Serial.println("1");
    firstPushed = true;
  } 
  else {
    // turn LED off:
    if(firstPushed){
      Serial.println("2");
      firstPushed = false;
    }
    else{
      Serial.println("3");
    }
    
  }

}


