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
const int e3 = 164;  const int a3 = 220;  const int ad3 = 233; const int b3 = 247;
const int c4 = 261;  const int cd4 = 277; const int d4 = 293;  const int dd4 = 311;
const int e4 = 329;  const int f4 = 349;  const int fd4 = 370; const int g4 = 392;
const int gd4 = 415; const int a4 = 440;  const int ad4 = 466; const int b4 = 494;
const int c5 = 523;  const int cd5 = 554; const int d5 = 587;  const int dd5 = 622;
const int e5 = 659;  const int f5 = 698;  const int fd5 = 740; const int g5 = 784;
const int gd5 = 830; const int a5 = 880;  const int ad5 = 932; const int b5 = 988;
const int c6 = 1046; const int cd6 = 1109; const int d6 = 1174; const int dd6 = 1244;
const int e6 = 1318; const int f6 = 1397; const int fd6 = 1480; const int g6 = 1568;
const int gd6 = 1661; const int a6 = 1760;

double s4;

double bpm(int tempo){
  return 60.0/tempo*1000.0;
}

int getLedPin(int frekans) {
  switch(frekans) {
    case a3: case ad3: case a4: case ad4: case a5: case ad5: case a6: return LED_A;
    case b3: case b4: case b5: return LED_B;
    case c4: case cd4: case c5: case cd5: case c6: case cd6: return LED_C;
    case d4: case dd4: case d5: case dd5: case d6: case dd6: return LED_D;
    case e3: case e4: case e5: case e6: return LED_E;
    case f4: case fd4: case f5: case fd5: case f6: case fd6: return LED_F;
    case g4: case gd4: case g5: case gd5: case g6: case gd6: return LED_G;
    default: return -1;
  }
}

void playTone(int frekans, int deger, bool tekrar, int cursor1, String yazi1, int cursor2, String yazi2) {
  double s1 = s4 * 4.0; double s2 = s4 * 2.0; double s8 = s4 / 2.0; double s16 = s4 / 4.0;
  double s32 = s4 / 8.0; double s64 = s4 / 16.0;
  double s45 = s4 + s8; double s85 = s8 + s16; double s165 = s8 + s32; double s161 = s16 - s64;

  double sure = s4; double es = 0;
  switch (deger) {
    case 1: sure = s1 - s4; es = s4; break;
    case 2: sure = s2 - s8; es = s8; break;
    case 4: sure = s4 - s16; es = s16; break;
    case 8: sure = s8 - s32; es = s32; break;
    case 16: sure = s16; es = 0; break;
    case 161: sure = s161; es = s64; break;
    case 32: sure = s32; es = 0; break;
    case 45: sure = s45 - s16; es = s16; break;
    case 85: sure = s85 - s32; es = s32; break;
    case 165: sure = s165 - s64; es = s64; break;
    case 40: sure = 0; es = s4; break;
    case 80: sure = 0; es = s8; break;
    case 160: sure = 0; es = s16; break;
    case 450: sure = 0; es = s45; break;
    case 850: sure = 0; es = s85; break;
    case 1650: sure = 0; es = s165; break;
    default: sure = s4; es = 0; break;
  }

  if (tekrar == 0) {
    if (cursor1 == 0) lcd.clear();
    else if (cursor1 == 1) lcd.setCursor(0, 1);
    if(yazi1 != "") lcd.print(yazi1);
  } else {
    if (cursor2 == 0) lcd.clear();
    else if (cursor2 == 1) lcd.setCursor(0, 1);
    if(yazi2 != "") lcd.print(yazi2);
  }

  int activeLed = getLedPin(frekans);
  if (frekans > 0) {
    if (activeLed != -1) digitalWrite(activeLed, HIGH);
    tone(BUZZER_PIN, frekans);
    delay(sure);
    noTone(BUZZER_PIN);
    if (activeLed != -1) digitalWrite(activeLed, LOW);
  } else {
    delay(sure);
  }
  if(es > 0) delay(es);
}

void setup() {
  for(int i = 2; i <= 9; i++) pinMode(i, OUTPUT);
  lcd.begin(16, 2);
  s4 = bpm(81);

  lcd.setCursor(0, 0); lcd.print("Kufi");
  lcd.setCursor(0, 1); lcd.print("Duman");
  delay(3000);

  // --- DUMAN - KUFİ (TÜM SÖZLER) ---
  playTone(0, 80, 0, 0, "", 2, "");  //1
  playTone(e4, 4, 0, 2, "El", 2, "");
  playTone(e4, 8, 0, 2, "le", 2, "");
  playTone(dd4, 8, 0, 2, "ri", 2, "");
  playTone(e4, 8, 0, 2, " ha", 2, "");
  playTone(fd4, 8, 0, 2, "va", 2, "");
  playTone(g4, 45, 0, 2, "da", 2, ""); //2
  playTone(0, 80, 0, 2, "", 2, "");
  playTone(b4, 8, 0, 1, "Ku", 2, "");
  playTone(a4, 8, 0, 2, "fi", 2, "");
  playTone(b4, 8, 0, 2, " ka", 2, "");
  playTone(a4, 8, 0, 2, "fa", 2, "");
  playTone(g4, 45, 0, 2, "da", 2, ""); //3
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "Se", 2, "");
  playTone(a4, 8, 0, 2, "ker", 2, "");
  playTone(b4, 8, 0, 2, " e", 2, "");
  playTone(a4, 4, 0, 2, "zer", 2, "");
  playTone(fd4, 4, 0, 1, "ay", 2, ""); //4
  playTone(a4, 8, 0, 2, "na", 2, "");
  playTone(g4, 8, 0, 2, "da", 2, "");
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(e4, 4, 0, 2, "Ay", 2, "");
  playTone(dd4, 8, 0, 2, "ni", 2, "");
  playTone(e4, 4, 0, 2, " ay", 2, ""); //5
  playTone(e4, 4, 0, 2, "ran", 2, "");
  playTone(dd4, 8, 0, 1, "gi", 2, "");
  playTone(e4, 8, 0, 2, "bi", 2, "");
  playTone(fd4, 8, 0, 2, " te", 2, "");
  playTone(g4, 45, 0, 2, "miz", 2, ""); //6
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "ka", 2, "");
  playTone(a4, 8, 0, 2, "fa", 2, "");
  playTone(b4, 8, 0, 2, "si", 2, "");
  playTone(a4, 8, 0, 1, "le", 2, "");
  playTone(g4, 45, 0, 2, "ziz", 2, ""); //7
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "Yu", 2, "");
  playTone(a4, 8, 0, 2, "ru", 2, "");
  playTone(b4, 8, 0, 2, " yol", 2, "");
  playTone(a4, 4, 0, 2, "lar", 2, "");
  playTone(fd4, 4, 0, 1, "sa", 2, ""); //8
  playTone(a4, 8, 0, 2, "ra", 2, "");
  playTone(g4, 4, 0, 2, "ya", 2, "");
  playTone(e4, 8, 0, 2, " sa", 2, "");
  playTone(e4, 8, 0, 2, "ra", 2, "");
  playTone(e4, 8, 0, 2, "ya", 2, "");
  playTone(0, 160, 0, 0, "", 2, ""); //9
  playTone(b4, 8, 0, 2, "Ben", 2, "");
  playTone(b4, 161, 0, 2, " bu", 2, "");
  playTone(b4, 161, 0, 2, " ge", 2, "");
  playTone(b4, 161, 0, 2, "ze", 2, "");
  playTone(b4, 161, 0, 2, "ge", 2, "");
  playTone(b4, 16, 0, 2, "ne", 2, "");
  playTone(fd4, 161, 0, 1, "i", 2, "");
  playTone(fd4, 161, 0, 2, "ne", 2, "");
  playTone(fd4, 161, 0, 2, "me", 2, "");
  playTone(fd4, 16, 0, 2, "dim", 2, "");
  playTone(a4, 8, 0, 2, " a", 2, "");
  playTone(g4, 8, 0, 2, "bi", 2, "");
  playTone(0, 450, 0, 0, "", 2, ""); //10
  playTone(g4, 8, 0, 2, "Gok", 2, "");
  playTone(fd4, 161, 0, 2, "yu", 2, "");
  playTone(fd4, 161, 0, 2, "zu", 2, "");
  playTone(fd4, 8, 0, 1, "mas", 2, "");
  playTone(a4, 8, 0, 2, "ma", 2, "");
  playTone(g4, 8, 0, 2, "vi", 2, "");
  playTone(0, 450, 0, 0, "", 2, ""); //11
  playTone(g4, 8, 0, 2, "Yil", 2, "");
  playTone(fd4, 8, 0, 2, "diz", 2, "");
  playTone(fd4, 8, 0, 2, "lar", 2, "");
  playTone(a4, 161, 0, 2, " da", 2, "");
  playTone(a4, 16, 0, 2, "ha", 2, "");
  playTone(g4, 161, 0, 1, "i", 2, "");
  playTone(g4, 16, 0, 2, "yi", 2, "");
  playTone(fd4, 8, 0, 2, "", 2, ""); //12
  playTone(0, 850, 0, 0, "", 2, "");
  playTone(fd4, 16, 0, 2, "Bu", 2, "");
  playTone(g4, 8, 0, 2, " yil", 2, "");
  playTone(fd4, 8, 0, 2, "diz", 2, "");
  playTone(e4, 16, 0, 2, "lar", 2, "");
  playTone(d4, 16, 0, 1, "", 2, "");
  playTone(e4, 161, 0, 2, "da", 2, "");
  playTone(e4, 161, 0, 2, "ha", 2, "");
  playTone(e4, 161, 0, 2, " i", 2, "");
  playTone(e4, 16, 0, 2, "yi", 2, "");
  playTone(0, 160, 0, 0, "", 2, ""); //13
  playTone(b4, 8, 0, 2, "Us", 2, "");
  playTone(b4, 161, 0, 2, "ku", 2, "");
  playTone(b4, 161, 0, 2, "da", 2, "");
  playTone(b4, 161, 0, 2, "ri", 2, "");
  playTone(b4, 161, 0, 2, " yi", 2, "");
  playTone(b4, 16, 0, 2, "ne", 2, "");
  playTone(fd4, 161, 0, 1, "ge", 2, "");
  playTone(fd4, 161, 0, 2, "ce", 2, "");
  playTone(fd4, 161, 0, 2, "me", 2, "");
  playTone(fd4, 16, 0, 2, "dik", 2, "");
  playTone(a4, 8, 0, 2, " a", 2, "");
  playTone(g4, 8, 0, 2, "bi", 2, "");
  playTone(0, 40, 0, 0, "", 2, ""); //14
  playTone(0, 160, 0, 2, "", 2, "");
  playTone(g4, 161, 0, 2, "Bu", 2, "");
  playTone(g4, 8, 0, 2, " at", 2, "");
  playTone(fd4, 8, 0, 2, "lar", 2, "");
  playTone(fd4, 8, 0, 1, "cok", 2, "");
  playTone(a4, 8, 0, 2, " ha", 2, "");
  playTone(g4, 8, 0, 2, "in", 2, "");
  playTone(0, 450, 0, 0, "", 2, ""); //15
  playTone(g4, 8, 0, 2, "E", 2, "");
  playTone(fd4, 8, 0, 2, "sek", 2, "");
  playTone(fd4, 8, 0, 2, "ler", 2, "");
  playTone(a4, 161, 0, 2, " da", 2, "");
  playTone(a4, 16, 0, 2, "ha", 2, "");
  playTone(g4, 161, 0, 1, "i", 2, "");
  playTone(g4, 16, 0, 2, "yi", 2, "");
  playTone(fd4, 8, 0, 2, "", 2, ""); //16
  playTone(0, 850, 0, 0, "", 2, "");
  playTone(fd4, 16, 0, 2, "Bu", 2, "");
  playTone(g4, 8, 0, 2, " e", 2, "");
  playTone(fd4, 8, 0, 2, "sek", 2, "");
  playTone(e4, 16, 0, 2, "ler", 2, "");
  playTone(d4, 16, 0, 2, "", 2, "");
  playTone(e4, 161, 0, 1, "da", 2, "");
  playTone(e4, 161, 0, 2, "ha", 2, "");
  playTone(e4, 161, 0, 2, " i", 2, "");
  playTone(e4, 16, 0, 2, "yi", 2, "");
  // TEKRAR
  playTone(0, 80, 0, 0, "", 2, "");  //1
  playTone(e4, 4, 0, 2, "El", 2, "");
  playTone(e4, 8, 0, 2, "le", 2, "");
  playTone(dd4, 8, 0, 2, "ri", 2, "");
  playTone(e4, 8, 0, 2, " ha", 2, "");
  playTone(fd4, 8, 0, 2, "va", 2, "");
  playTone(g4, 45, 0, 2, "da", 2, ""); //2
  playTone(0, 80, 0, 2, "", 2, "");
  playTone(b4, 8, 0, 1, "Ku", 2, "");
  playTone(a4, 8, 0, 2, "fi", 2, "");
  playTone(b4, 8, 0, 2, " ka", 2, "");
  playTone(a4, 8, 0, 2, "fa", 2, "");
  playTone(g4, 45, 0, 2, "da", 2, ""); //3
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "Se", 2, "");
  playTone(a4, 8, 0, 2, "ker", 2, "");
  playTone(b4, 8, 0, 2, " e", 2, "");
  playTone(a4, 4, 0, 2, "zer", 2, "");
  playTone(fd4, 4, 0, 1, "ay", 2, ""); //4
  playTone(a4, 8, 0, 2, "na", 2, "");
  playTone(g4, 8, 0, 2, "da", 2, "");
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(e4, 4, 0, 2, "Ay", 2, "");
  playTone(dd4, 8, 0, 2, "ni", 2, "");
  playTone(e4, 4, 0, 2, " ay", 2, ""); //5
  playTone(e4, 4, 0, 2, "ran", 2, "");
  playTone(dd4, 8, 0, 1, "gi", 2, "");
  playTone(e4, 8, 0, 2, "bi", 2, "");
  playTone(fd4, 8, 0, 2, " te", 2, "");
  playTone(g4, 45, 0, 2, "miz", 2, ""); //6
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "ka", 2, "");
  playTone(a4, 8, 0, 2, "fa", 2, "");
  playTone(b4, 8, 0, 2, "si", 2, "");
  playTone(a4, 8, 0, 1, "le", 2, "");
  playTone(g4, 45, 0, 2, "ziz", 2, ""); //7
  playTone(0, 80, 0, 0, "", 2, "");
  playTone(b4, 8, 0, 2, "Yu", 2, "");
  playTone(a4, 8, 0, 2, "ru", 2, "");
  playTone(b4, 8, 0, 2, " yol", 2, "");
  playTone(a4, 4, 0, 2, "lar", 2, "");
  playTone(fd4, 4, 0, 1, "sa", 2, ""); //8
  playTone(a4, 8, 0, 2, "ra", 2, "");
  playTone(g4, 4, 0, 2, "ya", 2, "");
  playTone(e4, 8, 0, 2, " sa", 2, "");
  playTone(e4, 8, 0, 2, "ra", 2, "");
  playTone(e4, 8, 0, 2, "ya", 2, "");
}

void loop() {
}