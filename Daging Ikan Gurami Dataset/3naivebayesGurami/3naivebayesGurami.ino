//while (count<) sebanyak dataset di eeprom
//while (datake < )  sebanyak data uji
#include <EEPROM.h>

float test [20][5] = {{213, 230, 184, 0, 1}, {162, 179, 123, 0, 1}, {153, 170, 123, 0, 1}, {170, 187, 133, 1, 1}, {145, 204, 153, 0, 1}, {85, 111, 51, 2, 1}, {111, 136, 82, 3, 1}, {102, 119, 62, 3, 1}, {111, 145, 82, 20, 1}, {102, 135, 62, 23, 2}, {128, 153, 92, 25, 2}, {68, 85, 21, 26, 2}, {51, 68, 72, 28, 2}, {85, 119, 51, 30, 2}, {68, 94, 21, 30, 2}, {128, 162, 92, 36, 2}, {68, 94, 21, 38, 2}, {51, 68, 11, 50, 2}, {51, 60, 0, 54, 3}, {60, 68, 0, 78, 3}};
float mf1_1, mf2_1, mf3_1, mf4_1, sf1_1, sf2_1, sf3_1, sf4_1, mf1_2, mf2_2, mf3_2, mf4_2, sf1_2, sf2_2, sf3_2, sf4_2, mf1_3, mf2_3, mf3_3, mf4_3, sf1_3, sf2_3, sf3_3, sf4_3;
//mf=median fitur 1  sf=standar deviasi firur1     pf=probabilitas fitur    pk=probbabilitas kelas
float pf1_1, pf2_1, pf3_1, pf4_1, pf1_2, pf2_2, pf3_2, pf4_2, pf1_3, pf2_3, pf3_3, pf4_3, pk1, pk2, pk3, variabel;
byte datake, count, count2;
unsigned long mulai, selesai;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}
int average(byte fitur, byte kelas) {
  variabel = 0; count = 0; count2 = 0;
  while (count < 80) {
    if (kelas == EEPROM.read(5 * count + 4))
    {
      variabel = variabel + EEPROM.read(5 * count + (fitur - 1));
      count2++;
    }
    count++;
  }
  count = 0;
  variabel = variabel / count2;
  //Serial.println (count2);
}
int deviasi(byte fitur, byte kelas, float ratarata) {
  float memori;
  variabel = 0; count = 0; count2 = 0;
  while (count < 80) 
  {
    if (kelas == EEPROM.read(5*count+4))
    {
      memori = (EEPROM.read(5*count+(fitur-1)));
      memori = (memori - ratarata);
      memori = pow(memori, 2);
      variabel = variabel + memori;
      //Serial.println (EEPROM.read(5*count+(fitur-1)+((kelas-1)*225)));
      count2++;
      //Serial.println (variabel);
    }
    count++;
  }
  variabel = variabel / count2;
  variabel = sqrt (variabel);
  //Serial.println (count2);
  //Serial.println (variabel);
  count = 0;
}
void loop() {
  mulai = millis();
  average(1, 1); mf1_1 = variabel;
  average(2, 1); mf2_1 = variabel;
  average(3, 1); mf3_1 = variabel;
  average(4, 1); mf4_1 = variabel;
  deviasi(1, 1, mf1_1); sf1_1 = variabel;
  deviasi(2, 1, mf2_1); sf2_1 = variabel;
  deviasi(3, 1, mf3_1); sf3_1 = variabel;
  deviasi(4, 1, mf4_1); sf4_1 = variabel;
  //-----;
  average(1, 2); mf1_2 = variabel;
  average(2, 2); mf2_2 = variabel;
  average(3, 2); mf3_2 = variabel;
  average(4, 2); mf4_2 = variabel;
  deviasi(1, 2, mf1_2); sf1_2 = variabel;
  deviasi(2, 2, mf2_2); sf2_2 = variabel;
  deviasi(3, 2, mf3_2); sf3_2 = variabel;
  deviasi(4, 2, mf4_2); sf4_2 = variabel;
  //-----
  average(1, 3); mf1_3 = variabel;
  average(2, 3); mf2_3 = variabel;
  average(3, 3); mf3_3 = variabel;
  average(4, 3); mf4_3 = variabel;
  deviasi(1, 3, mf1_3); sf1_3 = variabel;
  deviasi(2, 3, mf2_3); sf2_3 = variabel;
  deviasi(3, 3, mf3_3); sf3_3 = variabel;
  deviasi(4, 3, mf4_3); sf4_3 = variabel;
  selesai = millis();
  Serial.println(selesai - mulai);

  //delay(10000000);
  datake = 0;
  Serial.println("sebenarnya-prediksi-waktu");
  while (datake < 20) {
    mulai = millis();
    //probabilitas kelas 1
    pf1_1 = (1 / sqrt(2 * 3.14 * sf1_1)) * exp(-((pow((test[datake][0] - mf1_1), 2))) / (2 * pow(sf1_1, 2)));
    pf2_1 = (1 / sqrt(2 * 3.14 * sf2_1)) * exp(-((pow((test[datake][1] - mf2_1), 2))) / (2 * pow(sf2_1, 2)));
    pf3_1 = (1 / sqrt(2 * 3.14 * sf3_1)) * exp(-((pow((test[datake][2] - mf3_1), 2))) / (2 * pow(sf3_1, 2)));
    pf4_1 = (1 / sqrt(2 * 3.14 * sf4_1)) * exp(-((pow((test[datake][3] - mf4_1), 2))) / (2 * pow(sf4_1, 2)));

    //probabilitas kelas 2
    pf1_2 = (1 / sqrt(2 * 3.14 * sf1_2)) * exp(-((pow((test[datake][0] - mf1_2), 2))) / (2 * pow(sf1_2, 2)));
    pf2_2 = (1 / sqrt(2 * 3.14 * sf2_2)) * exp(-((pow((test[datake][1] - mf2_2), 2))) / (2 * pow(sf2_2, 2)));
    pf3_2 = (1 / sqrt(2 * 3.14 * sf3_2)) * exp(-((pow((test[datake][2] - mf3_2), 2))) / (2 * pow(sf3_2, 2)));
    pf4_2 = (1 / sqrt(2 * 3.14 * sf4_2)) * exp(-((pow((test[datake][3] - mf4_2), 2))) / (2 * pow(sf4_2, 2)));

    //probabilitas kelas 3
    pf1_3 = (1 / sqrt(2 * 3.14 * sf1_3)) * exp(-((pow((test[datake][0] - mf1_3), 2))) / (2 * pow(sf1_3, 2)));
    pf2_3 = (1 / sqrt(2 * 3.14 * sf2_3)) * exp(-((pow((test[datake][1] - mf2_3), 2))) / (2 * pow(sf2_3, 2)));
    pf3_3 = (1 / sqrt(2 * 3.14 * sf3_3)) * exp(-((pow((test[datake][2] - mf3_3), 2))) / (2 * pow(sf3_3, 2)));
    if (isnan(pf3_3)) {pf3_3=0;} //perlu ditambahkan karena dataset pada fitur 3, kelas 3 bernilai 0. sehingga tidak dapat di komputasi (NaN)
    pf4_3 = (1 / sqrt(2 * 3.14 * sf4_3)) * exp(-((pow((test[datake][3] - mf4_3), 2))) / (2 * pow(sf4_3, 2)));

    pk1 = pf1_1 + pf2_1 + pf3_1 + pf4_1;
    pk2 = pf1_2 + pf2_2 + pf3_2 + pf4_2;
    pk3 = pf1_3 + pf2_3 + pf3_3 + pf4_3;
    //Serial.println(pf1_3);
    //Serial.println(pf2_3);
    //Serial.println(pf3_3);
    //Serial.println(pf4_3);
    //Serial.println("----");

    //Serial.println(pk1);
    //Serial.println(pk2);
    //Serial.println(pk3);

    Serial.print (test[datake][4], 0);
    if (pk1 > pk2 && pk1 > pk3) {
      Serial.print(" 1 ");
    }
    else if (pk2 > pk3 && pk2 > pk1) {
      Serial.print(" 2 ");
    }
    else {
      Serial.print(" 3 ");
    }
    selesai = millis();
    Serial.println(selesai - mulai);
    datake++;
  }
  delay(10000000);
  // put your main code here, to run repeatedly:
}
