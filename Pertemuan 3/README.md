1) Jelaskan proses dari input keyboard hingga LED menyala/mati!
   
1. Input dari Keyboard
2. User mengetik karakter (misalnya '1' atau '0') di Serial Monitor.
3. Data dikirim melalui Serial
4. Data dikirim dari komputer ke Arduino melalui komunikasi serial (USB).
5. Arduino membaca data
6. Arduino mengecek apakah ada data masuk dengan:
    Serial.available()
    Jika ada, data dibaca menggunakan:
    Serial.read()
7. Pengolahan data
8. Arduino membandingkan data yang diterima:
    '1' → LED nyala
    '0' → LED mati
9. Output ke LED

2) Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika 
baris tersebut dihilangkan?
digunakan untuk mengecek apakah ada data yang masuk di buffer serial supaya Arduino tidak membaca data kosong

3) Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi 
jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan 
berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

const int ledPin = 13; // Menentukan pin LED
char data; // Variabel untuk menyimpan data dari serial
bool blinkMode = false; // Status mode blink

void setup() { 
pinMode(ledPin, OUTPUT); // Mengatur pin LED sebagai output 
Serial.begin(9600); // Memulai komunikasi serial 
}

void loop() { // Mengecek apakah ada data masuk 
    if (Serial.available() > 0) { 
    data = Serial.read(); // Membaca data dari serial 
        if (data == '1') { 
        digitalWrite(ledPin, HIGH); // LED nyala 
        blinkMode = false; // Matikan mode blink 
       } 
        else if (data == '0') { 
        digitalWrite(ledPin, LOW); // LED mati 
        blinkMode = false; // Matikan mode blink 
       } else if (data == '2') {
       blinkMode = true; // Aktifkan mode blink 
      } 
    }

// Jika mode blink aktif 
   if (blinkMode) { 
   digitalWrite(ledPin, HIGH); // LED nyala 
   delay(500); // Tunggu 500 ms 
   digitalWrite(ledPin, LOW); // LED mati 
   delay(500); // Tunggu 500 ms 
   } 
}

4) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap 
sistem

Menggunakan delay()
Kelebihan:
Mudah digunakan
Cocok untuk pemula
Kekurangan:
Program berhenti sementara (blocking)
Tidak bisa menerima input baru saat delay berlangsung

Dampak:
Saat LED blink, Arduino tidak responsif terhadap input baru

Menggunakan millis()
Kelebihan:
Non-blocking (tidak menghentikan program)
Bisa multitasking
Tetap bisa membaca Serial

Kekurangan:
Lebih kompleks

Dampak:
Sistem lebih responsif
Bisa membaca input sambil LED berkedip
