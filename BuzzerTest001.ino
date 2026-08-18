// កំណត់ជើង GPIO សម្រាប់ Buzzer
const int BUZZER_PIN = 12;

void setup() {
  // កំណត់ជើង GPIO 12 ជា OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // beep លើកទី១
  digitalWrite(BUZZER_PIN, HIGH); // បើកសំឡេង
  delay(100);                     // រង់ចាំ 0.1 វិនាទី
  digitalWrite(BUZZER_PIN, LOW);  // បិទសំឡេង
  delay(100);                     // រង់ចាំ 0.1 វិនាទី

  // beep លើកទី២
  digitalWrite(BUZZER_PIN, HIGH); // បើកសំឡេង
  delay(100);                     // រង់ចាំ 0.1 វិនាទី
  digitalWrite(BUZZER_PIN, LOW);  // បិទសំឡេង

  // សម្រាក ២ វិនាទីមុនពេលរោទ៍ម្តងទៀត
  delay(2000);
}
