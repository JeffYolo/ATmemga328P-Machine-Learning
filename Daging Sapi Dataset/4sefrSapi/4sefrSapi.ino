#define S0  2
#define S1  3
#define S2  4
#define S3  5
#define OUT 6
#define CLK 7
#define DIO 8

const unsigned int DATASIZE = 81; // dataset size
const byte         FEATURES = 4;   // number of features
const byte         LABELS   = 4;   // number of labels

// the dataset
const int DATASET[DATASIZE][FEATURES] = {
  {127, 72, 71, 25}, {131, 68, 62, 24}, {127, 72, 68, 22}, {118, 59, 56, 20}, {117, 58, 56, 21}, {114, 59, 55, 19}, {118, 71, 67, 20}, {122, 71, 67, 21}, {112, 60, 56, 20}, {121, 68, 62, 22}, {115, 69, 55, 19}, {110, 66, 58, 21}, {111, 68, 62, 23}, {125, 70, 66, 21}, {115, 55, 57, 20}, {110, 60, 56, 18}, {113, 65, 66, 19}, {112, 64, 56, 21}, {123, 68, 63, 18}, {109, 66, 54, 16}, {117, 58, 57, 22}, {118, 59, 56, 20}, {114, 59, 55, 19}, {125, 71, 67, 19}, {124, 69, 60, 21}, {118, 59, 55, 21}, {114, 59, 55, 18}, {109, 63, 65, 13}, {109, 55, 62, 10}, {101, 55, 52, 9}, {105, 59, 55, 7}, {104, 51, 53, 7}, {108, 62, 64, 13}, {107, 65, 65, 13}, {106, 62, 64, 13}, {101, 55, 61, 10}, {96, 42, 26, 7}, {99, 46, 46, 7}, {101, 55, 52, 10}, {109, 63, 65, 13}, {98, 47, 46, 9}, {109, 62, 64, 13}, {109, 53, 61, 10}, {106, 51, 51, 9}, {105, 55, 52, 10}, {109, 55, 62, 10}, {105, 57, 54, 9}, {100, 60, 60, 10}, {109, 63, 65, 12}, {101, 57, 53, 13}, {105, 59, 55, 9}, {96, 54, 62, 10}, {105, 59, 55, 9}, {80, 62, 64, 13}, {87, 46, 49, 11}, {74, 42, 43, 9}, {74, 42, 43, 8}, {61, 34, 37, 7}, {65, 34, 37, 7}, {87, 42, 46, 8}, {79, 42, 43, 8}, {85, 42, 49, 7}, {79, 46, 43, 7}, {83, 46, 49, 6}, {61, 34, 37, 6}, {61, 34, 46, 6}, {71, 34, 46, 7}, {73, 41, 42, 9}, {71, 41, 45, 9}, {77, 41, 43, 8}, {65, 34, 38, 6}, {70, 42, 44, 9}, {65, 34, 38, 7}, {80, 42, 46, 7}, {61, 32, 37, 7}, {72, 42, 41, 8}, {63, 34, 35, 6}, {62, 35, 37, 6}, {70, 41, 42, 8}, {60, 34, 46, 5}, {68, 38, 46, 6}
  };

// labels of the dataset
const byte TARGET[DATASIZE] = {
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
 };

int weights[LABELS][FEATURES]; // model weights on each labels
int bias[LABELS];              // model bias on each labels
unsigned long mulai, selesai;

void setup() {

  Serial.begin(9600);
  mulai = millis();
  fit();
  selesai = millis();
  Serial.println(selesai - mulai);
}

void loop() {
  int test[27][5] = {{127, 73, 69, 17, 1}, {153, 72, 74, 15, 1}, {180, 85, 84, 16, 1}, {167, 89, 87, 12, 1}, {171, 85, 84, 11, 1}, {197, 97, 96, 12, 1}, {193, 102, 99, 8, 1}, {189, 106, 102, 5, 1}, {197, 97, 102, 4, 1}, {136, 80, 84, 8, 2}, {145, 93, 93, 4, 2}, {145, 85, 84, 3, 2}, {140, 89, 90, 2, 2}, {140, 85, 84, 3, 2}, {131, 80, 80, 2, 2}, {114, 72, 74, 1, 2}, {126, 80, 80, 2, 2}, {114, 72, 71, 2, 2}, {41, 23, 31, 1, 3}, {56, 33, 46, 1, 3}, {68, 55, 70, 2, 3}, {56, 30, 39, 1, 3}, {70, 52, 66, 1, 3}, {62, 50, 61, 1, 3}, {79, 55, 68, 1, 3}, {49, 39, 48, 1, 3}, {60, 51, 69, 2, 3}};
  int bruh =0;
  while (bruh < 27)
  {
    mulai = millis();
    int r = test[bruh][0];
    int g = test[bruh][1];
    int b = test[bruh][2];
    int w = test[bruh][3];

    int new_data[FEATURES] = {r, g, b, w};
    int prediction = predict(new_data);  // detect the label
    Serial.print("Aktual: ");
    Serial.print(test[bruh][4]);
    Serial.print(" - ");
    Serial.print("Prediksi: ");
    Serial.print(prediction);
    Serial.print(" - ");
    selesai = millis();
    Serial.print("Waktu Klasifikasi: ");
    Serial.println(selesai - mulai);
    bruh++;
    delay(100);
  }
  delay(10000000);
}

// train SEFR model
void fit() {

  for (byte l = 0; l < LABELS; l++) {

    unsigned int count_pos = 0, count_neg = 0;

    for (byte f = 0; f < FEATURES; f++) {
      float avg_pos = 0.0, avg_neg = 0.0;
      count_pos = 0;
      count_neg = 0;
      for (unsigned int s = 0; s < DATASIZE; s++) {
        if (TARGET[s] != l) {
          avg_pos += float(DATASET[s][f]);
          count_pos++;
        } else {
          avg_neg += float(DATASET[s][f]);
          count_neg++;
        }
      }
      avg_pos /= float(count_pos);
      avg_neg /= float(count_neg);
      weights[l][f] = int((avg_pos - avg_neg) / (avg_pos + avg_neg) * 100);
    }

    float avg_pos_w = 0.0, avg_neg_w = 0.0;
    for (unsigned int s = 0; s < DATASIZE; s++) {
      float weighted_score = 0.0;
      for (byte f = 0; f < FEATURES; f++) {
        weighted_score += (float(DATASET[s][f]) * float(weights[l][f]) / 100);
      }
      if (TARGET[s] != l) {
        avg_pos_w += weighted_score;
      } else {
        avg_neg_w += weighted_score;
      }
    }
    avg_pos_w /= float(count_pos);
    avg_neg_w /= float(count_neg);
    bias[l] = int(-100 * (float(count_neg) * avg_pos_w + float(count_pos) * avg_neg_w) / float(count_pos + count_neg));
  }

}

// predict label of a new data instance
byte predict(int new_data[FEATURES]) {
  float score[LABELS];
  for (byte l = 0; l < LABELS; l++) {
    score[l] = 0.0;
    for (byte f = 0; f < FEATURES; f++) {
      score[l] += (float(new_data[f]) * (float(weights[l][f]) / 1000));
    }
    score[l] += (float(bias[l]) / 1000);
  }

  float min_score = score[0];
  byte min_label = 0;
  for (byte l = 1; l < LABELS; l++) {
    if (score[l] < min_score) {
      min_score = score[l];
      min_label = l;
    }
  }
  return min_label;

}
