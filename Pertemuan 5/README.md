1. Perbedaan loop() pada Arduino Biasa dan Sistem RTOS
Pada Arduino biasa, fungsi loop() digunakan sebagai program utama yang berjalan terus-menerus secara berurutan (sequential). Semua proses dijalankan satu per satu di dalam loop(), sehingga jika ada proses yang membutuhkan waktu lama maka proses lain harus menunggu.
Sedangkan pada sistem yang menggunakan RTOS, program dibagi menjadi beberapa task yang dapat berjalan secara multitasking. RTOS memiliki scheduler yang mengatur kapan setiap task dijalankan berdasarkan prioritas dan waktu tertentu. Dengan demikian, beberapa proses dapat berjalan secara bersamaan secara lebih efisien dan responsif.

2. Mengapa fungsi loop() dibiarkan kosong?
Pada sistem RTOS, seluruh proses program sudah dijalankan di dalam task yang dibuat menggunakan fungsi seperti xTaskCreate(). 
Scheduler RTOS akan mengatur eksekusi setiap task secara otomatis, sehingga fungsi loop() tidak lagi digunakan sebagai pusat program. 
Oleh karena itu, loop() biasanya dibiarkan kosong agar tidak mengganggu kerja multitasking dari RTOS.

3. Insight utama yang dipelajari dari praktikum
Mempelajari tentang multitasking pada RTOS sehingga arduino dapat menjalankan tugas dengan lebih efisien
dan secara bersamaan. Serta memberikan pemahaman tentang pembagian task dan komunikasi task
