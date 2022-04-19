//kode ini hanya bisa digunakan pd dataset iris, kode univesal dapat ditemukan pada kode sapi dan gurami

#include <EEPROM.h>

float test[15][5] = {{4.9, 3.0, 1.4, 0.2, 1}, {5.0, 3.4, 1.5, 0.2, 1}, {5.1, 3.8, 1.5, 0.3, 1}, {5.4, 3.4, 1.7, 0.2, 1}, {4.4, 3.2, 1.3, 0.2, 1}, {5.0, 2.0, 3.5, 1.0, 2}, {4.9, 2.4, 3.3, 1.0, 2}, {5.6, 2.7, 4.2, 1.3, 2}, {5.7, 2.8, 4.1, 1.3, 2}, {6.1, 2.9, 4.7, 1.4, 2}, {5.8, 2.7, 5.1, 1.9, 3}, {7.7, 2.6, 6.9, 2.3, 3}, {5.8, 2.7, 5.1, 1.9, 3}, {5.9, 3.0, 5.1, 1.8, 3}, {6.0, 2.2, 5.0, 1.5, 3}};
float mf1_1, mf2_1, mf3_1, mf4_1, sf1_1, sf2_1, sf3_1, sf4_1, mf1_2, mf2_2, mf3_2, mf4_2, sf1_2, sf2_2, sf3_2, sf4_2, mf1_3, mf2_3, mf3_3, mf4_3, sf1_3, sf2_3, sf3_3, sf4_3;
//mf=median fitur 1  sf=standar deviasi firur1     pf=probabilitas fitur    pk=probbabilitas kelas
float pf1_1, pf2_1, pf3_1, pf4_1, pf1_2, pf2_2, pf3_2, pf4_2, pf1_3, pf2_3, pf3_3, pf4_3, pk1, pk2, pk3, variabel;
byte datake, count;
unsigned long mulai, selesai;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

int average(byte fitur, byte kelas){
  variabel = 0;
  while (count<45){
    variabel = variabel + (EEPROM.read(5*count+(fitur-1)+((kelas-1)*225)));
    //Serial.println (EEPROM.read(5*count+(fitur-1)+((kelas-1)*225)));
    count++;
  }
  count=0;
  variabel = variabel/450;
  //Serial.println (variabel);
}
int deviasi(byte fitur, byte kelas, float ratarata){
  float memori;
  variabel = 0;
    while (count<45){
    memori = ((EEPROM.read(5*count+(fitur-1)+((kelas-1)*225))));
    memori = memori/10;
    memori = (memori -ratarata);
    memori = pow(memori,2);
    variabel = variabel +memori;
    //Serial.println (EEPROM.read(5*count+(fitur-1)+((kelas-1)*225)));
    count++;
  }
  variabel = variabel/45;
  variabel = sqrt (variabel);
  Serial.println (variabel);
  count=0;
}
void loop() {
  mulai = millis();
  average(1,1);mf1_1 = variabel;
  average(2,1);mf2_1 = variabel;
  average(3,1);mf3_1 = variabel;
  average(4,1);mf4_1 = variabel;
  deviasi(1,1,mf1_1);sf1_1 = variabel;
  deviasi(2,1,mf2_1);sf2_1 = variabel;
  deviasi(3,1,mf3_1);sf3_1 = variabel;
  deviasi(4,1,mf4_1);sf4_1 = variabel;
  //-----;
  average(1,2);mf1_2 = variabel;
  average(2,2);mf2_2 = variabel;
  average(3,2);mf3_2 = variabel;
  average(4,2);mf4_2 = variabel;
  deviasi(1,2,mf1_2);sf1_2 = variabel;
  deviasi(2,2,mf2_2);sf2_2 = variabel;
  deviasi(3,2,mf3_2);sf3_2 = variabel;
  deviasi(4,2,mf4_2);sf4_2 = variabel;
  //-----
  average(1,3);mf1_3 = variabel;
  average(2,3);mf2_3 = variabel;
  average(3,3);mf3_3 = variabel;
  average(4,3);mf4_3 = variabel;
  deviasi(1,3,mf1_3);sf1_3 = variabel;
  deviasi(2,3,mf2_3);sf2_3 = variabel;
  deviasi(3,3,mf3_3);sf3_3 = variabel;
  deviasi(4,3,mf4_3);sf4_3 = variabel;
  selesai = millis();
  Serial.println(selesai - mulai);
  
  //delay(10000000);
  datake = 0;
  while (datake < 15) {
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
    pf4_3 = (1 / sqrt(2 * 3.14 * sf4_3)) * exp(-((pow((test[datake][3] - mf4_3), 2))) / (2 * pow(sf4_3, 2)));

    pk1 = pf1_1 + pf2_1 + pf3_1 + pf4_1;
    pk2 = pf1_2 + pf2_2 + pf3_2 + pf4_2;
    pk3 = pf1_3 + pf2_3 + pf3_3 + pf4_3;

    Serial.print (test[datake][4],0);
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
