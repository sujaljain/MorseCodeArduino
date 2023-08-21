const int ledPin = 13;    // Built-in LED pin
const int buttonPin = 2;  // Push button pin

String morseCodes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
  };

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor for the button
  Serial.begin(9600);
}

void loop() {
  String message = "SUJAL JAIN";
  if (digitalRead(buttonPin) == LOW) {
    convertAndBlink(message);
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void convertAndBlink(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);

    if (c >= 'a' && c <= 'z') { // Comparing according to ASCII Code
      int index = c - 'a';
      String morseCode = morseCodes[index];

      for (int j = 0; j < morseCode.length(); j++) {
        if (morseCode.charAt(j) == '.') {
          dot();
        } else if (morseCode.charAt(j) == '-') {
          dash();
        }
      }
      delay(600);  // Pause between characters
    } else if (c == ' ') {
      delay(1200);  // Pause between words
    }
  }
}
