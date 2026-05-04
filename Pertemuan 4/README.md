PERTANYAAN PRAKTIKUM
1. Bagaimana proses konversi sinyal analog menjadi digital pada Arduino? Jelaskan!
Proses konversi dilakukan oleh ADC (Analog to Digital Converter) yang terdapat pada Arduino. 
Ketika fungsi analogRead() dipanggil, Arduino membaca tegangan analog (misalnya dari potensiometer) dalam rentang tertentu (biasanya 0–5V). Tegangan ini kemudian dibandingkan dengan tegangan referensi (Vref) dan dikonversi menjadi nilai digital.
Pada Arduino Uno dengan resolusi 10-bit, nilai analog akan diubah menjadi angka digital dalam rentang 0–1023. Semakin besar tegangan input, semakin besar nilai digital yang dihasilkan. Proses ini memungkinkan mikrokontroler mengolah data dari sensor analog menjadi informasi digital yang dapat diproses lebih lanjut.

2. Faktor apa saja yang dapat mempengaruhi keakuratan pembacaan ADC?
Beberapa faktor yang dapat mempengaruhi keakuratan pembacaan ADC antara lain:
Noise (gangguan listrik): menyebabkan nilai ADC tidak stabil
Tegangan referensi (Vref): jika tidak stabil, hasil pembacaan ikut berubah
Resolusi ADC: semakin tinggi resolusi, semakin akurat hasil
Kualitas sensor/potensiometer: komponen yang kurang baik menghasilkan data tidak presisi
Koneksi rangkaian: kabel longgar atau breadboard kurang baik dapat menimbulkan error
Fluktuasi tegangan supply: tegangan tidak stabil mempengaruhi hasil ADC


3. Apa kendala yang mungkin terjadi saat mengintegrasikan ADC dan PWM dalam satu sistem?
Beberapa kendala yang mungkin terjadi saat menggabungkan ADC dan PWM:

Noise dari PWM
Sinyal PWM dapat menimbulkan gangguan yang mempengaruhi pembacaan ADC

Jitter (ketidakstabilan output)
Perubahan ADC yang cepat dapat membuat output (servo/LED) tidak stabil

Delay yang tidak tepat
Jika delay terlalu kecil, sistem menjadi tidak stabil; jika terlalu besar, respon menjadi lambat

Resolusi berbeda
ADC (0–1023) harus dikonversi ke PWM (0–255), sehingga perlu proses scaling (map())

Keterbatasan hardware (timer & pin)
PWM menggunakan timer tertentu yang bisa bentrok dengan fungsi lain


MODIFIKASI PROGRAM ADC PERTANYAAN NOMER 3
ubah pada bagian map():
pos = map(val, 0, 1023, 30, 150);
Penjelasan:
Nilai ADC tetap 0–1023
Output servo dibatasi hanya dari 30° hingga 150°

MODIFIKASI PROGRAM PWM PERTANYAAN NOMER 3
// Mengecek apakah nilai PWM berada dalam rentang 50 sampai 200
if (pwm >= 50 && pwm <= 200) {

  // Jika YA → kirim sinyal PWM ke LED sesuai nilai pwm
  // LED akan menyala dengan tingkat kecerahan sedang
  analogWrite(ledPin, pwm);

} else {

  // Jika TIDAK (di bawah 50 atau di atas 200)
  // LED dimatikan (duty cycle = 0)
  analogWrite(ledPin, 0);

}
