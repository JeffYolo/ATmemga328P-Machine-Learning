//klasifikasiEuclidean[]&kelasEuclidean[] sebanyak data latih
//while (bruh <)sebanyak data uji
//while (datake < ) sebanyak data latih
//loop for (i = 0; i < ; ++i) sebanyak data uji

float test [20][5] = {{213, 230, 184, 0, 1}, {162, 179, 123, 0, 1}, {153, 170, 123, 0, 1}, {170, 187, 133, 1, 1}, {145, 204, 153, 0, 1}, {85, 111, 51, 2, 1}, {111, 136, 82, 3, 1}, {102, 119, 62, 3, 1}, {111, 145, 82, 20, 1}, {102, 135, 62, 23, 2}, {128, 153, 92, 25, 2}, {68, 85, 21, 26, 2}, {51, 68, 72, 28, 2}, {85, 119, 51, 30, 2}, {68, 94, 21, 30, 2}, {128, 162, 92, 36, 2}, {68, 94, 21, 38, 2}, {51, 68, 11, 50, 2}, {51, 60, 0, 54, 3}, {60, 68, 0, 78, 3}};
#include <EEPROM.h>
float f1, f2, f3, f4, akar, klasifikasiEuclidean [100], a;
int datake, kelasEuclidean[100], i, j, n, iris1, iris2, iris3, addrEEPROM;
byte bruh;
unsigned long mulai, selesai;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (bruh <20)
  {
    mulai = millis(); //mulai timer
    datake = 0;
    while (datake < 80)
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
    for (i = 0; i < 80; ++i)
    {
      for (j = i + 1; j < 80; ++j)
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
