int TURBIDITY_PIN = A1;
int TDS_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float turbidityValue = analogRead(TURBIDITY_PIN);
  float tdsValue = analogRead(TDS_PIN);

  String taste = "taste unknown";
  if (tdsValue >= 60 && tdsValue <= 63) {
    taste = "Regular Water";
  } else if (tdsValue >= 104 && tdsValue <= 118) {
    taste = "Sour Solution";
  } else if (tdsValue >= 480 && tdsValue <= 486) {
    taste = "Salty Solution";
  } else if ((tdsValue >= 73 && tdsValue <= 113) || (tdsValue >= 57 && tdsValue <= 59)) {
    taste = "Sweet Solution";
  } else if ((tdsValue >= 122 && tdsValue <= 156) || (tdsValue >= 150 && tdsValue <= 206)) {
    taste = "Spicy Solution";
  }

  //verify classification using turbidity ranges
  if (taste == "Spicy Solution" && (turbidityValue >= 377 && turbidityValue <= 422)) {
  } else if (taste == "Regular Water" && (turbidityValue >= 720 && turbidityValue <= 730 || turbidityValue >= 400 && turbidityValue <= 440)) {
  } else if (taste == "Spicy Solution" && (turbidityValue >= 377 && turbidityValue <= 422)) {
  } else if (tdsValue == 0 && turbidityValue >= 6 && turbidityValue <= 9) {
    taste = "Sensor Idle/No Water";
  }

  //Serial.print("TDS Sensor Value: ");
  //Serial.print(tdsValue);
  //Serial.print(" | Turbidity Sensor Value: ");
  //Serial.print(turbidityValue);
  Serial.print("|Detected Taste: |");
  Serial.println(taste);

  delay(1000);
}
