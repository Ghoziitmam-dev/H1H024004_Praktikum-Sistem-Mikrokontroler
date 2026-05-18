1. Sebutkan dan jelaskan keuntungan menggunakan interrupt dibanding polling!
Lebih cepat merespon kejadian
Mikrokontroler langsung menangani event saat interrupt terjadi tanpa harus mengecek input terus-menerus.

Lebih efisien penggunaan CPU
CPU dapat menjalankan proses lain dan hanya bekerja saat interrupt aktif.

Menghemat waktu proses
Sistem tidak perlu melakukan pengecekan berulang seperti pada polling.

2. Mengapa timer penting dalam sistem embedded dan real-time?
   Timer penting karena digunakan untuk mengatur proses berbasis waktu secara akurat.
   Dalam sistem embedded dan real-time, banyak proses yang harus dijalankan pada interval tertentu, seperti:
   blinking LED,
   pembacaan sensor,
   komunikasi data,
3. Jika interrupt dan timer digabung dalam satu sistem, bagaimana alur kerja sistem 
tersebut?
Program utama berjalan normal.
Timer menghitung waktu secara terus-menerus.
Ketika waktu tertentu tercapai, timer menjalankan proses sesuai interval.
Jika terjadi event eksternal (misalnya tombol ditekan), interrupt akan aktif.
Mikrokontroler menghentikan sementara program utama dan menjalankan ISR.
Setelah ISR selesai, program utama kembali dilanjutkan.

4. Apa yang terjadi jika ISR terlalu panjang atau kompleks?
program utama menjadi lambat
Karena CPU terlalu lama berada di dalam ISR.

Interrupt lain dapat terlewat
Mikrokontroler mungkin tidak sempat menangani interrupt berikutnya.

Sistem menjadi tidak stabil
Terjadi delay atau respon yang tidak konsisten.
