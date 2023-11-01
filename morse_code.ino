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
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(100);
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
      delay(300);  // Pause between letters
    } else if (c == ' ') {
      delay(700);  // Pause between words
    }
  }
}
