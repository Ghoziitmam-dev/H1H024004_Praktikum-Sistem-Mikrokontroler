Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan! 
Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan! 
Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri! 
Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian 



Jawaban
1. <img width="744" height="755" alt="image" src="https://github.com/user-attachments/assets/2962b5e1-ae19-4bdc-aa99-039cc16c0747" />
2. Menyalakan LED satu per satu dari pin terkecil ke terbesar
   Memberikan jeda (delay)
   Mematikan LED sebelum pindah ke LED berikutnya
   Urutan:
   LED 1, LED 2, LED 3,LED 2, LED 1
3. LED dinyalakan dari pin terbesar ke terkecil
   Menggunakan loop mundur
   Urutan:
   LED 5, LED 4, LED 3, LED 2, LED 1
4. // Mendefinisikan pin LED
int led[] = {2, 3, 4, 5, 6}; // Array berisi pin LED

void setup() {
  // Mengatur semua pin LED sebagai OUTPUT
  for (int i = 0; i < 5; i++) {
    pinMode(led[i], OUTPUT); // Set pin sebagai output
  }
}

void loop() {

  // === Pola 3 LED kiri menyala ===
  digitalWrite(led[0], HIGH); // LED 1 ON
  digitalWrite(led[1], HIGH); // LED 2 ON
  digitalWrite(led[2], HIGH); // LED 3 ON
  digitalWrite(led[3], LOW);  // LED 4 OFF
  digitalWrite(led[4], LOW);  // LED 5 OFF
  delay(500); // Tunggu 0.5 detik

  // === Semua LED mati (transisi) ===
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], LOW); // Semua LED OFF
  }
  delay(200); // Jeda pendek

  // === Pola 3 LED kanan menyala ===
  digitalWrite(led[2], HIGH); // LED 3 ON
  digitalWrite(led[3], HIGH); // LED 4 ON
  digitalWrite(led[4], HIGH); // LED 5 ON
  digitalWrite(led[0], LOW);  // LED 1 OFF
  digitalWrite(led[1], LOW);  // LED 2 OFF
  delay(500); // Tunggu 0.5 detik

  // === Semua LED mati lagi ===
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], LOW); // Semua LED OFF
  }
  delay(200); // Jeda sebelum ulang
}
   

