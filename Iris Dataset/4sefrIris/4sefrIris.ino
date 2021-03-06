#define S0  2
#define S1  3
#define S2  4
#define S3  5
#define OUT 6
#define CLK 7
#define DIO 8

const unsigned int DATASIZE = 135; // dataset size
const byte         FEATURES = 4;   // number of features
const byte         LABELS   = 4;   // number of labels

// the dataset
//Nilai dataset dikalikan 10 supaya tidak menggunakan variabel float untuk meringkas memeori
const int DATASET[DATASIZE][FEATURES] = {
  {51, 35, 14, 2}, {47, 32, 13, 2}, {46, 31, 15, 2}, {50, 36, 14, 2}, {54, 39, 17, 4}, {46, 34, 14, 3}, {44, 29, 14, 2}, {49, 31, 15, 1}, {54, 37, 15, 2}, {48, 34, 16, 2}, {48, 30, 14, 1}, {43, 30, 11, 1}, {58, 40, 12, 2}, {57, 44, 15, 4}, {54, 39, 13, 4}, {51, 35, 14, 3}, {57, 38, 17, 3}, {51, 37, 15, 4}, {46, 36, 10, 2}, {51, 33, 17, 5}, {48, 34, 19, 2}, {50, 30, 16, 2}, {50, 34, 16, 4}, {52, 35, 15, 2}, {52, 34, 14, 2}, {47, 32, 16, 2}, {48, 31, 16, 2}, {54, 34, 15, 4}, {52, 41, 15, 1}, {55, 42, 14, 2}, {49, 31, 15, 1}, {50, 32, 12, 2}, {55, 35, 13, 2}, {49, 31, 15, 1}, {44, 30, 13, 2}, {51, 34, 15, 2}, {50, 35, 13, 3}, {45, 23, 13, 3}, {50, 35, 16, 6}, {51, 38, 19, 4}, {48, 30, 14, 3}, {51, 38, 16, 2}, {46, 32, 14, 2}, {53, 37, 15, 2}, {50, 33, 14, 2}, {70, 32, 47, 14}, {64, 32, 45, 15}, {69, 31, 49, 15}, {55, 23, 40, 13}, {65, 28, 46, 15}, {57, 28, 45, 13}, {63, 33, 47, 16}, {66, 29, 46, 13}, {52, 27, 39, 14}, {59, 30, 42, 15}, {60, 22, 40, 10}, {56, 29, 36, 13}, {67, 31, 44, 14}, {56, 30, 45, 15}, {58, 27, 41, 10}, {62, 22, 45, 15}, {56, 25, 39, 11}, {59, 32, 48, 18}, {61, 28, 40, 13}, {63, 25, 49, 15}, {61, 28, 47, 12}, {64, 29, 43, 13}, {66, 30, 44, 14}, {68, 28, 48, 14}, {67, 30, 50, 17}, {60, 29, 45, 15}, {57, 26, 35, 10}, {55, 24, 38, 11}, {55, 24, 37, 10}, {58, 27, 39, 12}, {60, 27, 51, 16}, {54, 30, 45, 15}, {60, 34, 45, 16}, {67, 31, 47, 15}, {63, 23, 44, 13}, {56, 30, 41, 13}, {55, 25, 40, 13}, {55, 26, 44, 12}, {61, 30, 46, 14}, {58, 26, 40, 12}, {50, 23, 33, 10}, {57, 30, 42, 12}, {57, 29, 42, 13}, {62, 29, 43, 13}, {51, 25, 30, 11}, {63, 33, 60, 25}, {71, 30, 59, 21}, {63, 29, 56, 18}, {65, 30, 58, 22}, {76, 30, 66, 21}, {49, 25, 45, 17}, {73, 29, 63, 18}, {67, 25, 58, 18}, {72, 36, 61, 25}, {65, 32, 51, 20}, {64, 27, 53, 19}, {68, 30, 55, 21}, {57, 25, 50, 20}, {58, 28, 51, 24}, {64, 32, 53, 23}, {65, 30, 55, 18}, {77, 38, 67, 22}, {69, 32, 57, 23}, {56, 28, 49, 20}, {77, 28, 67, 20}, {63, 27, 49, 18}, {67, 33, 57, 21}, {72, 32, 60, 18}, {62, 28, 48, 18}, {61, 30, 49, 18}, {64, 28, 56, 21}, {72, 30, 58, 16}, {74, 28, 61, 19}, {79, 38, 64, 20}, {64, 28, 56, 22}, {63, 28, 51, 15}, {61, 26, 56, 14}, {77, 30, 61, 23}, {63, 34, 56, 24}, {64, 31, 55, 18}, {60, 30, 48, 18}, {69, 31, 54, 21}, {67, 31, 56, 24}, {69, 31, 51, 23}, {68, 32, 59, 23}, {67, 33, 57, 25}, {67, 30, 52, 23}, {63, 25, 50, 19}, {65, 30, 52, 20}, {62, 34, 54, 23}
};

// labels of the dataset
const byte TARGET[DATASIZE] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};

int weights[LABELS][FEATURES]; // model weights on each labels
int bias[LABELS];              // model bias on each labels
unsigned long mulai, selesai;
byte bruh;

void setup() {

  Serial.begin(9600);
  mulai = millis();
  fit();
  selesai = millis();
  Serial.print("Waktu Training :");
  Serial.println(selesai - mulai);
}

void loop() {
  int test[15][5] = {{49, 30, 14, 2, 1}, {50, 34, 15, 2, 1}, {51, 38, 15, 3, 1}, {54, 34, 17, 2, 1}, {44, 32, 13, 2, 1}, {50, 20, 35, 10, 2}, {49, 24, 33, 10, 2}, {56, 27, 42, 13, 2}, {57, 28, 41, 13, 2}, {61, 29, 47, 14, 2}, {58, 27, 51, 19, 3}, {77, 26, 69, 23, 3}, {58, 27, 51, 19, 3}, {59, 30, 51, 18, 3}, {60, 22, 50, 15, 3}};
  bruh =0;
  while (bruh < 15)
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
