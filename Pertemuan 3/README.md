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

4) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap 
sistem
