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

// BUZZER PINI
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

// Frekansa göre doğru LED pinini döndürür
int getLedPin(int frekans) {
  switch (frekans) {
    case g3: case gd3: case g4: case gd4: case g5: case gd5: case g6: case gd6: return LED_G;
    case a3: case ad3: case a4: case ad4: case a5: case ad5: case a6: return LED_A;
    case b3: case b4: case b5: return LED_B;
    case c4: case cd4: case c5: case cd5: case c6: case cd6: return LED_C;
    case d4: case dd4: case d5: case dd5: case d6: case dd6: return LED_D;
    case e4: case e5: case e6: return LED_E;
    case f4: case fd4: case f5: case fd5: case f6: case fd6: return LED_F;
    default: return -1; // Bilinmeyen nota
  }
}

// BİRLEŞTİRİLMİŞ playTone FONKSİYONU
void playTone(int frekans, int deger, bool tekrar, int cursor1, String yazi1, int cursor2, String yazi2) {

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
  double sure = s4; // Varsayılan değer
  double es = 0;   // Varsayılan değer

  // (Süre hesaplama bloğu)
  if (deger == 1) {
    sure = s1 - s4;
    es = s4;
  }
  else if (deger == 2) {
    sure = s2 - s8;
    es = s8;
  }
  else if (deger == 4) {
    sure = s4 - s16;
    es = s16;
  }
  else if (deger == 8) {
    sure = s8 - s32;
    es = s32;
  }
  else if (deger == 16) {
    sure = s16;
    es = 0;
  }
  else if (deger == 161) {
    sure = s16 - s64;
    es = s64;
  }
  else if (deger == 32) {
    sure = s32;
    es = 0;
  }
  else if (deger == 43) {
    sure = s4 * 2 / 3 - s4 * 2 / 3 / 4;
    es = s4 * 2 / 3 / 4;
  }
  else if (deger == 430) {
    sure = 0;
    es = s4 * 2 / 3;
  }
  else if (deger == 432) {
    sure = (s4 * 2 / 3) * 2 - (s4 * 2 / 3) * 2 / 4;
    es = (s4 * 2 / 3) * 2 / 4;
  }
  else if (deger == 4320) {
    sure = 0;
    es = (s4 * 2 / 3) * 2;
  }
  else if (deger == 83) {
    sure = s8 * 2 / 3 - s8 * 2 / 3 / 4;
    es = s8 * 2 / 3 / 4;
  }
  else if (deger == 830) {
    sure = 0;
    es = s8 * 2 / 3;
  }
  else if (deger == 832) {
    sure = (s8 * 2 / 3) * 2 - (s8 * 2 / 3) * 2 / 4;
    es = (s8 * 2 / 3) * 2 / 4;
  }
  else if (deger == 8320) {
    sure = 0;
    es = (s8 * 2 / 3) * 2;
  }
  else if (deger == 163) {
    sure = s16 * 2 / 3 - s16 * 2 / 3 / 4;
    es = s16 * 2 / 3 / 4;
  }
  else if (deger == 1632) {
    sure = (s16 * 2 / 3) * 2 - (s16 * 2 / 3) * 2 / 4;
    es = (s16 * 2 / 3) * 2 / 4;
  }
  else if (deger == 1630) {
    sure = 0;
    es = s16 * 2 / 3;
  }
  else if (deger == 16320) {
    sure = 0;
    es = (s16 * 2 / 3) * 2;
  }
  else if (deger == 15) {
    sure = s15 - s4;
    es = s4;
  }
  else if (deger == 166) {
    sure = s4 / 6 - s4 / 6 / 4;
    es = s4 / 6 / 4;
  }
  else if (deger == 1660) {
    sure = 0;
    es = s4 / 6;
  }
  else if (deger == 16621) {
    sure = (s4 / 6) + (s4 / 6 * 2) - (((s4 / 6) + (s4 / 6 * 2)) / 4);
    es = ((s4 / 6) + (s4 / 6 * 2)) / 4;
  }
  else if (deger == 1662) {
    sure = (s4 / 6) * 2 - (s4 / 6) * 2 / 4;
    es = (s4 / 6) * 2 / 4;
  }
  else if (deger == 16620) {
    sure = 0;
    es = (s4 / 6) * 2;
  }
  else if (deger == 25) {
    sure = s25 - s8;
    es = s8;
  }
  else if (deger == 45) {
    sure = s45 - s16;
    es = s16;
  }
  else if (deger == 455) {
    sure = s45 + s16 - (s45 + s16) / 4;
    es = (s45 + s16) / 4;
  }
  else if (deger == 85) {
    sure = s85 - s32;
    es = s32;
  }
  else if (deger == 165) {
    sure = s165 - s64;
    es = s64;
  }
  else if (deger == 10) {
    sure = 0;
    es = s1;
  }
  else if (deger == 20) {
    sure = 0;
    es = s2;
  }
  else if (deger == 40) {
    sure = 0;
    es = s4;
  }
  else if (deger == 80) {
    sure = 0;
    es = s8;
  }
  else if (deger == 160) {
    sure = 0;
    es = s16;
  }
  else if (deger == 320) {
    sure = 0;
    es = s32;
  }
  else if (deger == 150) {
    sure = 0;
    es = s15;
  }
  else if (deger == 250) {
    sure = 0;
    es = s25;
  }
  else if (deger == 450) {
    sure = 0;
    es = s45;
  }
  else if (deger == 850) {
    sure = 0;
    es = s85;
  }
  else if (deger == 1650) {
    sure = 0;
    es = s165;
  }
  else if (deger == 255) {
    sure = (s25 + s8) - (s25 + s8) / 4;
    es = (s25 + s8) / 4;
  }
  else if (deger == 8322) {
    sure = (s8 * 2 / 3) * 2 * 2 - (s8 * 2 / 3) * 2 * 2 / 4;
    es = (s8 * 2 / 3) * 2 * 2 / 4;
  }
  else if (deger == 8324) {
    sure = (s8 * 2 / 3) * 2 + s4 - ((s8 * 2 / 3) * 2 + s4) / 4;
    es = ((s8 * 2 / 3) * 2 + s4) / 4;
  }
  else if (deger == 49) {
    sure = s8;
    es = s8;
  }
  else if (deger == 89) {
    sure = s16;
    es = s16;
  }
  else if (deger == 8329) {
    sure = (s8 * 2 / 3);
    es = (s8 * 2 / 3);
  }
  else if (deger == 839) {
    sure = s8 * 2 / 3 / 2; // Hata düzeltmesi
    es = s8 * 2 / 3 / 2;
  }
  else if (deger == 44) {
    sure = s4;
    es = 0;
  }
  else if (deger == 88) {
    sure = s8;
    es = 0;
  }

  // === LCD YAZDIRMA MANTIĞI DEVRE DIŞI BIRAKILDI ===
  /*
  // LCD Yazdırma Mantığı
  if (tekrar == 0) {
    if (cursor1 == 0) lcd.clear();
    else if (cursor1 == 1) lcd.setCursor(0, 1);
    if (yazi1 != "") lcd.print(yazi1);
  } else {
    if (cursor2 == 0) lcd.clear();
    else if (cursor2 == 1) lcd.setCursor(0, 1);
    if (yazi2 != "") lcd.print(yazi2);
  }
  */

  // LED ve Buzzer Kontrol Mantığı
  int activeLed = getLedPin(frekans);
  if (frekans > 0) {
    if (activeLed != -1) digitalWrite(activeLed, HIGH); // LED'i yak
    tone(BUZZER_PIN, frekans);
    delay(sure);
    noTone(BUZZER_PIN);
    if (activeLed != -1) digitalWrite(activeLed, LOW); // LED'i söndür
  } else {
    delay(sure);
  }
  
  if (es > 0) delay(es);
}


void setup() {
  // Pinleri ayarla (2-8 LEDler, 9 Buzzer)
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  
  lcd.begin(16, 2);
  
  s4 = bpm(156); // Tempo 156

  // Giriş Ekranı (Bu yazı ekranda sabit kalacak)
  lcd.setCursor(0, 0);
  lcd.print("Mor ve Otesi");
  lcd.setCursor(0, 1);
  lcd.print("   Cambaz");
  delay(3000); // 3 saniye göster

  // === ŞARKI BAŞLIYOR (SÖZSÜZ) ===
  // Not: playTone çağrılarındaki "yazi" parametreleri
  // artık playTone fonksiyonu tarafından yok sayılacak.
  
  // Hızlı Intro Melodisi 1
  playTone(b4, 43, 0, 0, "", 2, ""); 
  playTone(c5, 43, 0, 1, "", 2, "");
  playTone(b4, 43, 0, 2, "", 2, "");
  playTone(fd5, 45, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(d5, 8, 0, 2, "", 2, "");
  playTone(d5, 45, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(b4, 4, 0, 2, "", 2, "");
  playTone(g5, 4, 0, 2, "", 2, "");
  playTone(fd5, 4, 0, 2, "", 2, "");
  playTone(fd5, 4, 0, 2, "", 2, "");
  playTone(e5, 8, 0, 2, "", 2, "");
  playTone(e5, 2, 0, 2, "", 2, "");

  // Hızlı Intro Melodisi 2
  playTone(d5, 43, 0, 2, "", 2, "");
  playTone(c5, 43, 0, 2, "", 2, "");
  playTone(b4, 43, 0, 2, "", 2, "");
  playTone(fd5, 45, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(dd5, 8, 0, 2, "", 2, "");
  playTone(dd5, 45, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(b4, 8, 0, 2, "", 2, "");
  playTone(b4, 4, 0, 2, "", 2, "");
  playTone(a4, 8, 0, 2, "", 2, "");
  playTone(b4, 8, 0, 2, "", 2, "");
  playTone(a4, 8, 0, 2, "", 2, "");
  playTone(fd4, 8, 0, 2, "", 2, "");
  playTone(g4, 8, 0, 2, "", 2, "");
  playTone(gd4, 45, 0, 2, "", 2, "");

  // Hızlı Intro Melodisi 3
  playTone(b4, 4, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(b4, 4, 0, 2, "", 2, "");
  playTone(fd5, 45, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(d5, 8, 0, 2, "", 2, "");
  playTone(d5, 45, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(b4, 4, 0, 2, "", 2, "");
  playTone(a5, 4, 0, 2, "", 2, "");
  playTone(g5, 4, 0, 2, "", 2, "");
  playTone(fd5, 4, 0, 2, "", 2, "");
  playTone(e5, 8, 0, 2, "", 2, "");
  playTone(e5, 2, 0, 2, "", 2, "");

  // Hızlı Intro Melodisi 4
  playTone(d5, 43, 0, 2, "", 2, "");
  playTone(c5, 43, 0, 2, "", 2, "");
  playTone(b4, 43, 0, 2, "", 2, "");
  playTone(fd5, 4, 0, 2, "", 2, "");
  playTone(fd5, 8, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(e5, 4, 0, 2, "", 2, "");
  playTone(dd5, 8, 0, 2, "", 2, "");
  playTone(dd5, 4, 0, 2, "", 2, "");
  playTone(dd5, 8, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(c5, 4, 0, 2, "", 2, "");
  playTone(dd5, 8, 0, 2, "", 2, "");
  playTone(e5, 2, 0, 2, "", 2, "");
  playTone(0, 20, 0, 2, "", 2, ""); // Es

  // Yavaş Intro Melodisi
  for (int i = 0; i < 7; i++) playTone(e4, 8, 0, 2, "", 2, "");
  for (int i = 0; i < 9; i++) playTone(dd4, 8, 0, 2, "", 2, "");
  for (int i = 0; i < 7; i++) playTone(d4, 8, 0, 2, "", 2, "");
  for (int i = 0; i < 9; i++) playTone(cd4, 8, 0, 2, "", 2, "");
  playTone(c4, 4, 0, 2, "", 2, "");
  playTone(c4, 4, 0, 2, "", 2, "");
  playTone(c4, 8, 0, 2, "", 2, "");
  playTone(c4, 8, 0, 2, "", 2, "");
  playTone(c4, 8, 0, 2, "", 2, "");
  playTone(dd4, 4, 0, 2, "", 2, "");
  for (int i = 0; i < 7; i++) playTone(dd4, 8, 0, 2, "", 2, "");
  // === INTRO BİTTİ ===


  // === ŞARKININ GERİ KALANI (SÖZSÜZ) ===
  for (int j = 0; j < 2; j++) {
    playTone(0, 40, 0, 0, "", 2, ""); // Es
    
    // (Melodi 1)
    playTone(g5, 4, 0, 0, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(e5, 4, 0, 2, "", 2, "");
    playTone(fd5, 45, 0, 2, "", 2, "");
    playTone(g5, 8, 0, 1, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(e5, 45, 0, 2, "", 2, "");
    playTone(0, 40, 0, 2, "", 2, "");
    
    // (Melodi 2)
    playTone(fd5, 8, 0, 0, "", 2, "");
    playTone(g5, 8, 0, 2, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(e5, 45, 0, 2, "", 2, "");
    playTone(fd5, 4, 0, 1, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(g5, 8, 0, 2, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    
    // (Melodi 3)
    playTone(c4, 4, 0, 0, "", 2, "");
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(dd4, 4, 0, 1, "", 2, "");
    
    // (Melodi 4)
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 0, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 1, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(0, 40, 0, 2, "", 2, "");
  
    // (Melodi 5)
    playTone(fd5, 4, 0, 0, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(fd5, 4, 0, 1, "", 2, "");
    playTone(g5, 4, 0, 2, "", 2, "");
    playTone(fd5, 45, 0, 2, "", 2, "");
    playTone(0, 40, 0, 2, "", 2, "");
    
    // (Melodi 6)
    playTone(fd5, 4, 0, 0, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(g5, 45, 0, 1, "", 2, "");
    playTone(fd5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    
    // (Melodi 7)
    playTone(c4, 4, 0, 0, "", 2, "");
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(dd4, 4, 0, 1, "", 2, "");
    
    // (Melodi 8)
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 0, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    
    // (Ara Müzik)
    playTone(c4, 4, 0, 0, "", 2, ""); 
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(0, 40, 0, 2, "", 2, "");

    // (Melodi 9 "Var mısın?")
    playTone(b4, 8, 0, 0, "", 2, "");
    playTone(c5, 4, 0, 2, "", 2, "");
    playTone(b4, 45, 0, 2, "", 2, "");
    playTone(fd5, 45, 0, 1, "", 2, "");
    playTone(e5, 4, 0, 0, "", 2, "");
    playTone(e5, 4, 0, 2, "", 2, "");
    playTone(d5, 8, 0, 2, "", 2, "");
    playTone(d5, 45, 0, 1, "", 2, "");
    playTone(c5, 4, 0, 0, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(g5, 4, 0, 1, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(e5, 4, 0, 2, "", 2, "");
    playTone(0, 40, 0, 2, "", 2, "");
    
    // (Melodi 10 "Var mısın?")
    playTone(b4, 8, 0, 0, "", 2, "");
    playTone(b4, 8, 0, 2, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 8, 0, 1, "", 2, "");
    playTone(fd5, 45, 0, 0, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 1, "", 2, "");
    playTone(dd5, 8, 0, 2, "", 2, ""); 
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(c5, 2, 0, 2, "", 2, "");
    playTone(dd5, 4, 0, 2, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 8, 0, 2, "", 2, "");
    playTone(b4, 2, 0, 2, "", 2, "");
    playTone(0, 20, 0, 2, "", 2, "");
    playTone(0, 450, 0, 2, "", 2, "");

    // (Çıkış Melodisi 1 "Sen Yoksun")
    playTone(b4, 4, 0, 0, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(fd5, 25, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(e5, 45, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 0, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(fd5, 25, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(e5, 2, 0, 2, "", 2, "");
    playTone(0, 20, 0, 2, "", 2, "");
    
    // (Çıkış Melodisi 2 "İki gözüm...")
    playTone(fd5, 8, 0, 0, "", 2, "");
    playTone(fd5, 4, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(fd5, 45, 0, 2, "", 2, "");
    playTone(0, 80, 0, 1, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(e5, 8, 0, 2, "", 2, "");
    playTone(dd5, 4, 0, 2, "", 2, "");
    playTone(c5, 4, 0, 2, "", 2, "");
    playTone(dd5, 4, 0, 2, "", 2, "");
    playTone(b4, 2, 0, 2, "", 2, "");
    playTone(0, 20, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(0, 450, 0, 2, "", 2, "");

    // (Son "Sen Yoksun")
    playTone(b4, 4, 0, 0, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(fd5, 25, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(e5, 45, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 0, "", 2, "");
    playTone(c5, 8, 0, 2, "", 2, "");
    playTone(b4, 4, 0, 2, "", 2, "");
    playTone(fd5, 25, 0, 2, "", 2, "");
    playTone(0, 80, 0, 2, "", 2, "");
    playTone(e5, 1, 0, 2, "", 2, "");
    
    // (Son Ara Solo)
    playTone(g5, 8, 0, 0, "", 2, ""); 
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(dd4, 4, 0, 2, "", 2, "");
    for (int i = 0; i < 7; i++) playTone(dd4, 8, 0, 2, "", 2, "");
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 4, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(c4, 8, 0, 2, "", 2, "");
    playTone(dd4, 8, 0, 2, "", 2, "");
  }
  
  // Şarkı bitti, ekranı temizle
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bitti!");
}

void loop() {
  // Setup'ta her şey bir kez çaldığı için burası boş.
  // (Yeniden çalması için reset tuşuna basın)
}