Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian 
tersebut!
Komunikasi I2C (Inter-Integrated Circuit) hanya menggunakan 2 jalur utama:
SDA (Serial Data) → jalur data
SCL (Serial Clock) → jalur sinkronisasi

Alur kerjanya:
1. Arduino sebagai Master
   Arduino mengontrol komunikasi (memberi clock)
2. LCD sebagai Slave
   LCD memiliki alamat I2C (misalnya 0x27)
3. Pengiriman data
   Arduino mengirim:
     Alamat LCD
     Data/perintah (misalnya tampilkan teks)
4. Sinkronisasi
   SCL mengatur kapan data dibaca
   SDA mengirim bit data satu per satu
5. LCD menampilkan
   Data diterjemahkan menjadi karakter di layar
   
2) Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan 
pin kanan tertukar!
Potensiometer punya 3 pin:
Kiri = VCC (5V)
Tengah = Output (ke analog pin Arduino)
Kanan = GND

Jika pin kiri dan kanan tertukar:
Yang terjadi:
Tegangan tetap berubah (0–5V)
Tapi arah putaran terbalik

3) Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai 
output) sehingga:
- Data tidak hanya ditampilkan di LCD tetapi juga di Serial Monitor
- Adapun data yang ditampilkan pada Serial Monitor sesuai dengan table berikut:
ADC: 0 Volt: 0.00 V Persen: 0%
Tampilan jika potensiometer dalam kondisi diputar paling kiri
- ADC: 0 0% | setCursor(0, 0) dan Bar (level) | setCursor(0, 1)
- Berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int adc = analogRead(pinPot);

  float volt = adc * (5.0 / 1023.0);
  int persen = map(adc, 0, 1023, 0, 100);
  int bar = map(adc, 0, 1023, 0, 16);

  // ===== SERIAL MONITOR (FORMAT SESUAI SOAL) =====
  Serial.print("ADC: ");
  Serial.print(adc);
  Serial.print(" | Volt: ");
  Serial.print(volt, 2);
  Serial.print(" V | Persen: ");
  Serial.print(persen);
  Serial.println("%");

  // ===== LCD =====
  // Baris 1 → ADC & Persen
  lcd.setCursor(0, 0);
  lcd.print("ADC:");
  lcd.print(adc);
  lcd.print(" ");
  lcd.print(persen);
  lcd.print("%   "); // clear sisa

  // Baris 2 → Bar (level)
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < bar) {
      lcd.print((char)255);
    } else {
      lcd.print(" ");
    }
  }

  delay(200);
}

PENJELASAN CODE

#include <Wire.h>

→ Library untuk komunikasi I2C (menggunakan SDA & SCL)

#include <LiquidCrystal_I2C.h>

→ Library untuk mengontrol LCD berbasis I2C

#include <Arduino.h>

→ Library dasar Arduino (biasanya otomatis, tapi ditambahkan untuk kompatibilitas)

LiquidCrystal_I2C lcd(0x27, 16, 2);

→ Membuat objek LCD dengan:

Alamat I2C: 0x27
16 kolom
2 baris
const int pinPot = A0;

→ Menentukan bahwa potensiometer terhubung ke pin analog A0

SETUP
void setup() {

→ Fungsi yang dijalankan sekali saat Arduino dinyalakan

  Serial.begin(9600);

→ Memulai komunikasi serial dengan baudrate 9600

  lcd.init();

→ Inisialisasi LCD

  lcd.backlight();

→ Menyalakan lampu latar LCD

}
LOOP
void loop() {

→ Fungsi utama yang berjalan berulang-ulang

  int adc = analogRead(pinPot);

→ Membaca nilai analog dari potensiometer (0–1023)

  float volt = adc * (5.0 / 1023.0);

→ Mengubah nilai ADC menjadi tegangan (Volt)

  int persen = map(adc, 0, 1023, 0, 100);

→ Mengubah nilai ADC menjadi persen (0–100%)

  int bar = map(adc, 0, 1023, 0, 16);

→ Mengubah nilai ADC menjadi panjang bar (0–16 karakter di LCD)

SERIAL MONITOR
  Serial.print("ADC: ");

→ Menampilkan teks "ADC: "

  Serial.print(adc);

→ Menampilkan nilai ADC

  Serial.print(" | Volt: ");

→ Menampilkan pemisah dan label tegangan

  Serial.print(volt, 2);

→ Menampilkan tegangan dengan 2 angka di belakang koma

  Serial.print(" V | Persen: ");

→ Menampilkan label persen

  Serial.print(persen);

→ Menampilkan nilai persen

  Serial.println("%");

4).
  <img width="741" height="158" alt="image" src="https://github.com/user-attachments/assets/4c572582-8c0c-45eb-aa3a-361c56312894" />
