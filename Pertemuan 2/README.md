1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
2. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? 
Apa keuntungannya dibandingkan rangkaian biasa?
Tidak perlu resistor eksternal
menghindari resiko floating
rangkaian lebih seerhana
3. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari 
sisi hardware maupun software?
dari sisi hardware
Segment rusak
Resistor nilainya tidak benar
Pin arduino rusak
dari sisi software
data array angka salah
logic terbalik
salah mapping pin
4. Modifikasi rangkaian dan program dengan dua push button yang berfungsi sebagai 
penambahan (increment) dan pengurangan (decrement) pada sistem counter dan 
berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
const int btnUp = 10;
const int btnDown = 11;

int counter = 0;

// contoh untuk 7 segment sederhana (0-9)
byte angka[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

int segPins[7] = {2,3,4,5,6,7,8};

void setup() {
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);

  for(int i=0;i<7;i++){
    pinMode(segPins[i], OUTPUT);
  }
}

void tampil(int angkaKe){
  for(int i=0;i<7;i++){
    digitalWrite(segPins[i], angka[angkaKe][i]);
  }
}

void loop() {
  if(digitalRead(btnUp) == LOW){
    counter++;
    if(counter > 9) counter = 0;
    delay(200);
  }

  if(digitalRead(btnDown) == LOW){
    counter--;
    if(counter < 0) counter = 9;
    delay(200);
  }

  tampil(counter);
}
