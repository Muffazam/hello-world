const int pinLDR = A0;// Sensor LDR dihubungkan dengan A0 dan

                      // A0 dihubungkan seri dengan Resistor 10 KOhm ke Ground
const int pinLED = 8; //LED1 dihubungkan ke pin8 melalui Resistor 560 Ohm
int sensorValue = 0; //var utk nilai yang terbaca di sensor
int outputValue = 0; //var utk penskalaan nilai sensor (0-1023)jadi nilai (0-255)

void setup() {
}

void loop() {
  // baca nilai dari sensor:
  sensorValue = analogRead(pinLDR);            
  // penskalaan nilai sensor (0-1023) menjadi nilai output (0-255)
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // deteksi, jika nilai OutputValue <=200 , kondisi lingkungan redup/gelap
  // catatan: angka 200 dapat diubah-ubah disesuaikan dengan kondisi cahaya lingkungan
  // makin gelap nilai outputValue akan makin kecil dan sebaliknya
  if(outputValue<=200)
    digitalWrite(pinLED,HIGH);
  else digitalWrite(pinLED,LOW);     
  // delay 300 milidetik sebelum loop berikutnya
  // agar analog-to-digital converter siap membaca data berikutnya
  delay(300);                     
}
