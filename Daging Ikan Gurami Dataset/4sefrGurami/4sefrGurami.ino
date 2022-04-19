#define S0  2
#define S1  3
#define S2  4
#define S3  5
#define OUT 6
#define CLK 7
#define DIO 8

const unsigned int DATASIZE = 80; // dataset size
const byte         FEATURES = 4;   // number of features
const byte         LABELS   = 4;   // number of labels

// the dataset
const int DATASET[DATASIZE][FEATURES] = {
  {238, 255, 204, 0}, {221, 238, 123, 0}, {136, 145, 153, 0}, {145, 145, 153, 0}, {187, 196, 153, 0}, {162, 179, 184, 0}, {170, 187, 143, 1}, {187, 187, 113, 1}, {119, 187, 133, 0}, {153, 157, 102, 0}, {153, 102, 102, 0}, {187, 145, 143, 1}, {162, 179, 123, 0}, {136, 145, 123, 0}, {136, 153, 92, 0}, {179, 221, 102, 0}, {145, 162, 102, 0}, {128, 145, 123, 1}, {128, 145, 92, 1}, {128, 153, 102, 1}, {128, 153, 92, 1}, {111, 126, 72, 1}, {85, 102, 41, 2}, {128, 153, 92, 2}, {136, 153, 41, 3}, {94, 102, 41, 3}, {136, 102, 31, 5}, {68, 77, 31, 4}, {68, 94, 31, 4}, {119, 145, 92, 5}, {162, 187, 82, 2}, {151, 77, 71, 6}, {102, 128, 72, 8}, {111, 145, 92, 8}, {85, 111, 62, 9}, {119, 153, 102, 9}, {119, 94, 31, 10}, {111, 136, 82, 11}, {111, 136, 82, 12}, {85, 128, 51, 13}, {43, 119, 62, 14}, {51, 77, 21, 14}, {34, 111, 51, 16}, {77, 102, 41, 17}, {102, 136, 82, 18}, {128, 162, 51, 19}, {102, 136, 72, 20}, {43, 60, 72, 21}, {85, 102, 21, 23}, {85, 111, 51, 26}, {68, 94, 41, 27}, {77, 51, 41, 28}, {43, 68, 11, 29}, {85, 111, 51, 29}, {60, 85, 51, 29}, {77, 102, 31, 30}, {69, 94, 31, 32}, {77, 102, 31, 32}, {77, 102, 21, 33}, {69, 94, 21, 33}, {60, 85, 21, 42}, {43, 68, 62, 43}, {77, 102, 31, 44}, {60, 85, 31, 44}, {60, 85, 11, 47}, {77, 102, 31, 48}, {60, 77, 11, 49}, {60, 77, 0, 51}, {51, 68, 0, 52}, {77, 34, 0, 56}, {43, 60, 0, 60}, {34, 60, 0, 62}, {26, 43, 0, 63}, {34, 51, 0, 64}, {43, 26, 0, 64}, {17, 68, 0, 70}, {17, 43, 0, 72}, {51, 60, 0, 81}, {85, 83, 0, 86}, {34, 43, 0, 96}
  };

// labels of the dataset
const byte TARGET[DATASIZE] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
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
  int test[20][5] = {{213, 230, 184, 0, 1}, {162, 179, 123, 0, 1}, {153, 170, 123, 0, 1}, {170, 187, 133, 1, 1}, {145, 204, 153, 0, 1}, {85, 111, 51, 2, 1}, {111, 136, 82, 3, 1}, {102, 119, 62, 3, 1}, {111, 145, 82, 20, 1}, {102, 135, 62, 23, 2}, {128, 153, 92, 25, 2}, {68, 85, 21, 26, 2}, {51, 68, 72, 28, 2}, {85, 119, 51, 30, 2}, {68, 94, 21, 30, 2}, {128, 162, 92, 36, 2}, {68, 94, 21, 38, 2}, {51, 68, 11, 50, 2}, {51, 60, 0, 54, 3}, {60, 68, 0, 78, 3}};
  int bruh =0;
  while (bruh < 20)
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
