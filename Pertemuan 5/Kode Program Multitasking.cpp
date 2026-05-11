#include <Arduino_FreeRTOS.h>

// Deklarasi task
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void Taskprint(void *pvParameters);

void setup() {
  Serial.begin(9600);

  // Set pin di awal (lebih aman)
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  // Task 1 (LED pin 8)
  xTaskCreate(
    TaskBlink1,
    "Task1",
    128,
    NULL,
    1,
    NULL
  );

  // Task 2 (LED pin 7)
  xTaskCreate(
    TaskBlink2,
    "Task2",
    128,
    NULL,
    1,
    NULL
  );

  // Task 3 (Counter)
  xTaskCreate(
    Taskprint,
    "Task3",
    128,
    NULL,
    1,
    NULL
  );

  // Jalankan scheduler
  vTaskStartScheduler();
}

void loop() {
  // Kosong (tidak dipakai di FreeRTOS)
}

// Task 1: LED pin 8
void TaskBlink1(void *pvParameters) {
  (void) pvParameters;

  while (1) {
    digitalWrite(8, HIGH);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    digitalWrite(8, LOW);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

// Task 2: LED pin 7
void TaskBlink2(void *pvParameters) {
  (void) pvParameters;

  while (1) {
    digitalWrite(7, HIGH);
    vTaskDelay(300 / portTICK_PERIOD_MS);

    digitalWrite(7, LOW);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

// Task 3: Counter (Serial dipisah biar aman)
void Taskprint(void *pvParameters) {
  (void) pvParameters;

  int counter = 0;

  while (1) {
    counter++;
    Serial.println(counter);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
