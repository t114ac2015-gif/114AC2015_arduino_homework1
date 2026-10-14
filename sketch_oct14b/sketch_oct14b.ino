
const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int buttonState = HIGH;
int ledState = LOW;
int ledcolor = 0;

bool ButtonPressed = false;

String currentcolor = "LED off";

unsigned long previousMillis = 0;
const long interval = 1000;

unsigned long debounceMillis = 0;
const long debounceDelay = 50;

int lastButtonState = HIGH;
int stableButtonState = HIGH;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
}

void loop() {

  unsigned long currentMillis = millis();
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    debounceMillis = currentMillis;
    lastButtonState = buttonState;
  }

  if (currentMillis - debounceMillis >= debounceDelay) {

    if (buttonState != stableButtonState) {

      stableButtonState = buttonState;

      if (stableButtonState == LOW) {

        ledcolor++;

        if (ledcolor > 7) {
          ledcolor = 0;
        }

        Serial.print("LED Color: ");
        Serial.println(ledcolor);
      }
    }
  }
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
  }
  if (ledcolor == 0) {

    currentcolor = "LED off";

  }
  else if (ledcolor == 1) {

    currentcolor = "Red";

  }
  else if (ledcolor == 2) {

    currentcolor = "Green";

  }
  else if (ledcolor == 3) {

    currentcolor = "Blue";

  }
  else if (ledcolor == 4) {

    currentcolor = "Yellow";

  }
  else if (ledcolor == 5) {

    currentcolor = "Purple";

  }
  else if (ledcolor == 6) {

    currentcolor = "Cyan";

  }
  else if (ledcolor == 7) {

    currentcolor = "White";

  }
if (ledcolor == 0) {

    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);

}
else {

    digitalWrite(RledPin, ledcolor == 1 || ledcolor == 4 ||
                           ledcolor == 5 || ledcolor == 7 ? LOW : HIGH);

    digitalWrite(GledPin, ledcolor == 2 || ledcolor == 4 ||
                           ledcolor == 6 || ledcolor == 7 ? LOW : HIGH);

    digitalWrite(BledPin, ledcolor == 3 || ledcolor == 5 ||
                           ledcolor == 6 || ledcolor == 7 ? LOW : HIGH);
}
  static String lastColor = "";

  if (currentcolor != lastColor) {
    Serial.print("Current Color: ");
    Serial.println(currentcolor);

    lastColor = currentcolor;
  }
}
