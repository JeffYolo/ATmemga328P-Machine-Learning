//klasifikasiEuclidean[]&kelasEuclidean[] sebanyak data latih
//while (bruh <)sebanyak data uji
//while (datake < ) sebanyak data latih
//loop for (i = 0; i < ; ++i) sebanyak data uji

float test[27][5] = {{127, 73, 69, 17, 1}, {153, 72, 74, 15, 1}, {180, 85, 84, 16, 1}, {167, 89, 87, 12, 1}, {171, 85, 84, 11, 1}, {197, 97, 96, 12, 1}, {193, 102, 99, 8, 1}, {189, 106, 102, 5, 1}, {197, 97, 102, 4, 1}, {136, 80, 84, 8, 2}, {145, 93, 93, 4, 2}, {145, 85, 84, 3, 2}, {140, 89, 90, 2, 2}, {140, 85, 84, 3, 2}, {131, 80, 80, 2, 2}, {114, 72, 74, 1, 2}, {126, 80, 80, 2, 2}, {114, 72, 71, 2, 2}, {41, 23, 31, 1, 3}, {56, 33, 46, 1, 3}, {68, 55, 70, 2, 3}, {56, 30, 39, 1, 3}, {70, 52, 66, 1, 3}, {62, 50, 61, 1, 3}, {79, 55, 68, 1, 3}, {49, 39, 48, 1, 3}, {60, 51, 69, 2, 3}};
#include <EEPROM.h>
float f1, f2, f3, f4, akar, klasifikasiEuclidean [81], a;
int datake, kelasEuclidean[81], i, j, n, iris1, iris2, iris3, addrEEPROM;
byte bruh;
unsigned long mulai, selesai;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (bruh <27)
  {
    mulai = millis(); //mulai timer
    datake = 0;
    while (datake < 81)
    {

      f1 = abs(((EEPROM.read(addrEEPROM + 0))) - test[bruh][0]);
      f2 = abs(((EEPROM.read(addrEEPROM + 1))) - test[bruh][1]);
      f3 = abs(((EEPROM.read(addrEEPROM + 2))) - test[bruh][2]);
      f4 = abs(((EEPROM.read(addrEEPROM + 3))) - test[bruh][3]);
      
      f1  = sq(f1);
      f2  = sq(f2);
      f3  = sq(f3);
      f4  = sq(f4);

      akar = (f1 + f2 + f3 + f4);
      klasifikasiEuclidean [datake] = sqrt(akar);
      kelasEuclidean [datake]       = EEPROM.read(addrEEPROM + 4);
      
      datake++;
      addrEEPROM = (datake * 5);
    }
    int neighbor = 3;
    for (i = 0; i < 81; ++i)
    {
      for (j = i + 1; j < 81; ++j)
      {
        if (klasifikasiEuclidean[i] > klasifikasiEuclidean[j])
        {
          a =  klasifikasiEuclidean[i];
          klasifikasiEuclidean[i] = klasifikasiEuclidean[j];
          klasifikasiEuclidean[j] = a;

          n = kelasEuclidean [i];
          kelasEuclidean[i] = kelasEuclidean[j];
          kelasEuclidean[j] = n;
        }
      }
    }

    iris1 = 0;
    iris2 = 0;
    iris3 = 0;

    for (i = 0; i < neighbor; ++i)
    {
      if (kelasEuclidean[i] == 1)
      {
        iris1++;
      }
      if (kelasEuclidean[i] == 2)
      {
        iris2++;
      }
      if (kelasEuclidean[i] == 3)
      {
        iris3++;
      }
    }
    selesai = millis();
    
    if (iris1 >= 2){
      Serial.print (bruh);
      Serial.print (" 1 ");
      Serial.print (test[bruh][4]);
      }
    if (iris2 >= 2){
      Serial.print (bruh);
      Serial.print (" 2 ");
      Serial.print (test[bruh][4]);
      }
      if (iris3 >= 2){
      Serial.print (bruh);
      Serial.print (" 3 ");
      Serial.print (test[bruh][4]);
      }
      Serial.print("   ");
      Serial.println (selesai-mulai);
    delay (0);
    bruh++;
  }
  
}
