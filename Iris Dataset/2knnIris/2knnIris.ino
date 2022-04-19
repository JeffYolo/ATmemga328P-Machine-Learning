//klasifikasiEuclidean[]&kelasEuclidean[] sebanyak data latih
//while (bruh <)sebanyak data uji
//while (datake < ) sebanyak data latih
//loop for (i = 0; i < ; ++i) sebanyak data uji

float test[15][5] = {{4.9, 3.0, 1.4, 0.2, 1}, {5.0, 3.4, 1.5, 0.2, 1}, {5.1, 3.8, 1.5, 0.3, 1}, {5.4, 3.4, 1.7, 0.2, 1}, {4.4, 3.2, 1.3, 0.2, 1}, {5.0, 2.0, 3.5, 1.0, 2}, {4.9, 2.4, 3.3, 1.0, 2}, {5.6, 2.7, 4.2, 1.3, 2}, {5.7, 2.8, 4.1, 1.3, 2}, {6.1, 2.9, 4.7, 1.4, 2}, {5.8, 2.7, 5.1, 1.9, 3}, {7.7, 2.6, 6.9, 2.3, 3}, {5.8, 2.7, 5.1, 1.9, 3}, {5.9, 3.0, 5.1, 1.8, 3}, {6.0, 2.2, 5.0, 1.5, 3}};
#include <EEPROM.h>
float f1, f2, f3, f4, akar, klasifikasiEuclidean [135], a;
int datake, kelasEuclidean[135], i, j, n, iris1, iris2, iris3, addrEEPROM;
byte bruh;
unsigned long mulai, selesai;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (bruh <15)
  {
    mulai = millis(); //mulai timer
    datake = 0;
    while (datake < 135)
    {

      f1 = abs(((EEPROM.read(addrEEPROM + 0))/10) - test[bruh][0]);
      f2 = abs(((EEPROM.read(addrEEPROM + 1))/10) - test[bruh][1]);
      f3 = abs(((EEPROM.read(addrEEPROM + 2))/10) - test[bruh][2]);
      f4 = abs(((EEPROM.read(addrEEPROM + 3))/10) - test[bruh][3]);
      
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
    for (i = 0; i < 135; ++i)
    {
      for (j = i + 1; j < 135; ++j)
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
