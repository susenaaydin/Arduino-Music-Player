#include <LiquidCrystal.h>

// LCD PINLERI: RS=12, E=11, D4=A0, D5=A1, D6=A2, D7=A3
LiquidCrystal lcd(12, 11, A0, A1, A2, A3);

// LED PINLERI (7 NOTA)
const int LED_A = 2; // La
const int LED_B = 3; // Si
const int LED_C = 4; // Do
const int LED_D = 5; // Re
const int LED_E = 6; // Mi
const int LED_F = 7; // Fa
const int LED_G = 8; // Sol

// BUZZER PINI (Eski 'h' pini)
const int BUZZER_PIN = 9;

// NOTA FREKANSLARI
const int g3 = 196;
const int gd3 = 207;
const int a3 = 220;
const int ad3 = 233;
const int b3 = 247;
const int c4 = 261;
const int cd4 = 277;
const int d4 = 293;
const int dd4 = 311;
const int e4 = 329;
const int f4 = 349;
const int fd4 = 370;
const int g4 = 392;
const int gd4 = 415;
const int a4 = 440;
const int ad4 = 466;
const int b4 = 494;
const int c5 = 523;
const int cd5 = 554;
const int d5 = 587;
const int dd5 = 622;
const int e5 = 659;
const int f5 = 698;
const int fd5 = 740;
const int g5 = 784;
const int gd5 = 830;
const int a5 = 880;
const int ad5 = 932;
const int b5 = 988;
const int c6 = 1046;
const int cd6 = 1109;
const int d6 = 1174;
const int dd6 = 1244;
const int e6 = 1318;
const int f6 = 1397;
const int fd6 = 1480;
const int g6 = 1568;
const int gd6 = 1661;
const int a6 = 1760;

double s4;

double bpm(int tempo) {
  double tam = 60.0 / tempo * 1000.0;
  return tam;
}

// Notalara göre LED pinini döndürür
int getLedPin(int frekans) {
  switch (frekans) {
    case a3: case ad3: case a4: case ad4: case a5: case ad5: case a6: return LED_A;
    case b3: case b4: case b5: return LED_B;
    case c4: case cd4: case c5: case cd5: case c6: case cd6: return LED_C;
    case d4: case dd4: case d5: case dd5: case d6: case dd6: return LED_D;
    case e4: case e5: case e6: return LED_E;
    case f4: case fd4: case f5: case fd5: case f6: case fd6: return LED_F;
    case g3: case gd3: case g4: case gd4: case g5: case gd5: case g6: case gd6: return LED_G;
    default: return -1;
  }
}

// LED ve Buzzer eklenmiş playTone fonksiyonu
void playTone(int frekans, int deger) {
  double s1 = s4 + s4 + s4 + s4;
  double s2 = s4 + s4;
  double s8 = s4 / 2.0;
  double s16 = s4 / 4.0;
  double s32 = s4 / 8.0;
  double s64 = s4 / 16.0;
  double s15 = s1 + s2;
  double s25 = s4 + s2;
  double s45 = s4 + s8;
  double s85 = s8 + s16;
  double s165 = s8 + s32;
  double sure = s4; // Varsayılan değer ataması
  double es = 0;   // Varsayılan değer ataması

  switch (deger) {
    case 1:
      sure = s1 - s4;
      es = s4;
      break;
    case 2:
      sure = s2 - s8;
      es = s8;
      break;
    case 4:
      sure = s4 - s16;
      es = s16;
      break;
    case 8:
      sure = s8 - s32;
      es = s32;
      break;
    case 16:
      sure = s16;
      es = 0;
      break;
    case 161:
      sure = s16 - s64;
      es = s64;
      break;
    case 32:
      sure = s32;
      es = 0;
      break;
    case 43:
      sure = s4 * 2 / 3 - s4 * 2 / 3 / 4;
      es = s4 * 2 / 3 / 4;
      break;
    case 430:
      sure = 0;
      es = s4 * 2 / 3;
      break;
    case 432:
      sure = (s4 * 2 / 3) * 2 - (s4 * 2 / 3) * 2 / 4;
      es = (s4 * 2 / 3) * 2 / 4;
      break;
    case 4320:
      sure = 0;
      es = (s4 * 2 / 3) * 2;
      break;
    case 83:
      sure = s8 * 2 / 3 - s8 * 2 / 3 / 4;
      es = s8 * 2 / 3 / 4;
      break;
    case 830:
      sure = 0;
      es = s8 * 2 / 3;
      break;
    case 832:
      sure = (s8 * 2 / 3) * 2 - (s8 * 2 / 3) * 2 / 4;
      es = (s8 * 2 / 3) * 2 / 4;
      break;
    case 8320:
      sure = 0;
      es = (s8 * 2 / 3) * 2;
      break;
    case 163:
      sure = s16 * 2 / 3 - s16 * 2 / 3 / 4;
      es = s16 * 2 / 3 / 4;
      break;
    case 1632:
      sure = (s16 * 2 / 3) * 2 - (s16 * 2 / 3) * 2 / 4;
      es = (s16 * 2 / 3) * 2 / 4;
      break;
    case 1630:
      sure = 0;
      es = s16 * 2 / 3;
      break;
    case 16320:
      sure = 0;
      es = (s16 * 2 / 3) * 2;
      break;
    case 15:
      sure = s15 - s4;
      es = s4;
      break;
    case 25:
      sure = s25 - s8;
      es = s8;
      break;
    case 45:
      sure = s45 - s16;
      es = s16;
      break;
    case 85:
      sure = s85 - s32;
      es = s32;
      break;
    case 165:
      sure = s165 - s64;
      es = s64;
      break;
    case 10:
      sure = 0;
      es = s1;
      break;
    case 20:
      sure = 0;
      es = s2;
      break;
    case 40:
      sure = 0;
      es = s4;
      break;
    case 80:
      sure = 0;
      es = s8;
      break;
    case 160:
      sure = 0;
      es = s16;
      break;
    case 320:
      sure = 0;
      es = s32;
      break;
    case 150:
      sure = 0;
      es = s15;
      break;
    case 250:
      sure = 0;
      es = s25;
      break;
    case 450:
      sure = 0;
      es = s45;
      break;
    case 850:
      sure = 0;
      es = s85;
      break;
    case 1650:
      sure = 0;
      es = s165;
      break;
    case 255:
      sure = (s25 + s8) - (s25 + s8) / 4;
      es = (s25 + s8) / 4;
      break;
    case 8322:
      sure = (s8 * 2 / 3) * 2 * 2 - (s8 * 2 / 3) * 2 * 2 / 4;
      es = (s8 * 2 / 3) * 2 * 2 / 4;
      break;
    case 8324:
      sure = (s8 * 2 / 3) * 2 + s4 - ((s8 * 2 / 3) * 2 + s4) / 4;
      es = ((s8 * 2 / 3) * 2 + s4) / 4;
      break;
    case 49:
      sure = s8;
      es = s8;
      break;
    case 89:
      sure = s16;
      es = s16;
      break;
    case 8329:
      sure = (s8 * 2 / 3);
      es = (s8 * 2 / 3);
      break;
    case 839:
      sure = s8 * 2 / 3 / 2; // HATA DÜZELTMESİ: 'sure =' eklendi
      es = s8 * 2 / 3 / 2;
      break;
  }

  // === LED ve BUZZER KONTROLÜ EKLENDİ ===
  int activeLed = getLedPin(frekans);
  if (frekans > 0) {
    if (activeLed != -1) digitalWrite(activeLed, HIGH);
    tone(BUZZER_PIN, frekans);
    delay(sure);
    noTone(BUZZER_PIN);
    if (activeLed != -1) digitalWrite(activeLed, LOW);
  } else {
    // Es (frekans=0) ise sadece bekle
    delay(sure);
  }
  
  // Nota sonrası 'es' payı varsa bekle
  if (es > 0) delay(es);
}

void setup() {
  // === YENİ SETUP (baslatici ile birleştirildi) ===
  // Tüm LED'leri (2-8) ve Buzzer'ı (9) OUTPUT yap
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  
  // LCD'yi başlat ve yazıyı yaz
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Kenan Dogulu");
  lcd.setCursor(0, 1);
  lcd.print("Ara Beni Lutfen");

  // Tempoyu ayarla
  s4 = bpm(95);
  
  // 3 saniye bekle
  delay(3000);
  
  // === "ARA BENİ LÜTFEN" MELODİSİ BAŞLIYOR ===
  playTone(ad4, 8); //1
  playTone(fd5, 25); //2
  playTone(f5, 16);
  playTone(fd5, 16);
  playTone(gd5, 8);
  playTone(f5, 4); //3
  playTone(0, 40);
  playTone(f5, 85);
  playTone(dd5, 16);
  playTone(f5, 8);
  playTone(fd5, 8);
  playTone(dd5, 4); //4
  playTone(0, 250);
  playTone(0, 250); //5
  playTone(0, 80);
  playTone(fd5, 8);
  playTone(fd5, 25); //6
  playTone(fd5, 8);
  playTone(gd5, 8);
  playTone(f5, 8); //7
  playTone(0, 40);
  playTone(f5, 8);
  playTone(dd5, 8);
  playTone(f5, 8);
  playTone(fd5, 8);
  playTone(dd5, 4); //8
  playTone(0, 250);
  playTone(0, 250); //9
  playTone(ad4, 8);
  playTone(c5, 16);
  playTone(cd5, 16);
  playTone(dd5, 8); //10
  playTone(f5, 8);
  playTone(cd5, 8);
  playTone(dd5, 8);
  playTone(0, 40);
  playTone(0, 80);
  playTone(fd5, 161);
  playTone(fd5, 16);
  playTone(gd5, 8); //11
  playTone(f5, 8);
  playTone(dd5, 4);
  playTone(0, 80);
  playTone(fd5, 16);
  playTone(gd5, 16);
  playTone(fd5, 16);
  playTone(f5, 16);
  playTone(fd5, 8);
  playTone(dd5, 4); //12
  playTone(0, 250);
  playTone(0, 250); //13
  playTone(0, 80);
  playTone(ad4, 161);
  playTone(ad4, 16);
  playTone(fd5, 25); //14
  playTone(fd5, 16);
  playTone(f5, 16);
  playTone(fd5, 16);
  playTone(gd5, 16);
  playTone(f5, 4); //15
  playTone(0, 40);
  playTone(f5, 16);
  playTone(dd5, 85);
  playTone(f5, 8);
  playTone(fd5, 8);
  playTone(dd5, 4); //16
  playTone(ad4, 4);
  playTone(0, 20);
  playTone(0, 250); //17
  playTone(0, 160);
  playTone(ad4, 161);
  playTone(ad4, 8);
  playTone(fd5, 2); //18
  playTone(fd5, 16);
  playTone(f5, 8);
  playTone(gd5, 16);
  playTone(f5, 4); //19
  playTone(0, 40);
  playTone(f5, 16);
  playTone(dd5, 85);
  playTone(f5, 8);
  playTone(fd5, 8);
  playTone(dd5, 4); //20
  playTone(0, 250);
  playTone(0, 250); //21
  playTone(0, 80);
  playTone(c5, 16);
  playTone(cd5, 16);
  playTone(dd5, 85); //22
  playTone(f5, 85);
  playTone(cd5, 8);
  playTone(dd5, 85);
  playTone(cd5, 85);
  playTone(c5, 8);
  playTone(cd5, 4); //23
  playTone(dd5, 4);
  playTone(0, 160);
  playTone(fd5, 16);
  playTone(gd5, 8);
  playTone(fd5, 16);
  playTone(f5, 16);
  playTone(fd5, 8);
  playTone(dd5, 4); //24
  playTone(0, 250);
  playTone(0, 250); //25
  playTone(0, 80);
  playTone(c5, 16);
  playTone(cd5, 16);
  playTone(dd5, 85); //26
  playTone(f5, 85);
  playTone(cd5, 8);
  playTone(dd5, 85);
  playTone(cd5, 85);
  playTone(c5, 8);
  playTone(cd5, 4); //27
  playTone(dd5, 4);
  playTone(0, 80);
  playTone(fd5, 16);
  playTone(gd5, 16);
  playTone(fd5, 16);
  playTone(f5, 16);
  playTone(fd5, 8);
  playTone(dd5, 4); //28
  playTone(0, 250);
  playTone(0, 10); //29
  for (int i = 0; i < 2; i++) {
    playTone(0, 80); //30
    playTone(fd5, 8);
    playTone(fd5, 8);
    playTone(gd5, 8);
    playTone(f5, 85);
    playTone(f5, 161);
    playTone(f5, 8);
    playTone(dd5, 8);
    playTone(f5, 8); //31
    playTone(dd5, 8);
    playTone(cd5, 16);
    playTone(c5, 8);
    playTone(ad4, 16);
    playTone(ad4, 4);
    playTone(0, 40);
    playTone(0, 80); //32
    playTone(fd5, 161);
    playTone(fd5, 161);
    playTone(fd5, 8);
    playTone(gd5, 16);
    playTone(fd5, 16);
    playTone(0, 80);
    playTone(f5, 161);
    playTone(f5, 16);
    playTone(f5, 8);
    playTone(dd5, 8);
    playTone(f5, 8); //33
    playTone(dd5, 8);
    playTone(cd5, 8);
    playTone(c5, 16);
    playTone(ad4, 16);
    playTone(c5, 4);
    playTone(0, 40);
    playTone(0, 160); //34
    playTone(gd5, 8);
    playTone(gd5, 16);
    playTone(gd5, 8);
    playTone(g5, 8);
    playTone(gd5, 8);
    playTone(ad5, 8);
    playTone(c6, 4);
    playTone(fd5, 8); //35
    playTone(fd5, 8);
    playTone(fd5, 8);
    playTone(dd5, 8);
    playTone(f5, 8);
    playTone(fd5, 8);
    playTone(gd5, 4);
    playTone(0, 80); //36
    playTone(fd5, 8);
    playTone(fd5, 8);
    playTone(f5, 8);
    playTone(fd5, 8);
    playTone(f5, 8);
    playTone(dd5, 8);
    playTone(cd5, 8);
    playTone(dd5, 8); //37
    playTone(cd5, 85);
    playTone(c5, 16);
    playTone(c5, 8);
    playTone(ad4, 2);
  }

  // Şarkı bitince "Bitti!" yaz
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bitti!");
}

void loop() {
  // put your main code here, to run repeatedly:
}