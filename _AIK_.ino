#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SoftwareSerial.h>
#include <SPI.h>

#define cs         10
#define rst        8
#define dc         9

#define CLK 2
#define DT 3
#define SWT 4

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
SoftwareSerial Ser(A0, A1);
Servo Servo_1;
Servo Servo_2;

int B_MOD = 0;

int r = 25;
int r2 = 5;
int c = ST77XX_BLUE;
int artis = 15;
int x = tft.width() - r;
int y = tft.height() - r;

int x2 = tft.width() - r;
int y2 = tft.height() - r;

bool AA = true;

int say = 1;
int say1 = 1;

int CLK_D;
int S_CLK_D;

int MOD = 0;
int K = 0;
int M1 = 0;
int M2 = 0;
int M3 = 0;
int M4 = 0;
int M5 = 0;
int M1_1 = 0;
int M1_2 = 0;
int M2_1 = 0;
int M2_2 = 0;
int M3_1 = 0;
int M3_2 = 0;
int M4_1 = 0;
int M4_2 = 0;


int NO1 = 0;
int NO2 = 55;
int NO3 = 110;
int NO4 = 165;

int NO = 0;
int M5Say = 1;

int saat[] = {0, 10, 12, 7};
int dakka[] = {0, 0, 30, 15};

unsigned long e_zaman;
unsigned long e_z2;

int MB  =  0;
int MB1 =  0;
int MB2 =  0;
int MB3 =  0;
int MB4 =  0;
int M1_3 = 1;

int SM = 0;

bool Alarm = true;

int KS[] = {1, 2, 3};

void setup() {

  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  pinMode(SWT, INPUT);
  pinMode(7, OUTPUT);

  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);

  Servo_1.attach(6);
  Servo_1.write(0);

  Servo_2.attach(5);
  Servo_2.write(150);

  yaz();

  S_CLK_D = digitalRead(CLK);

  saatV(false);
  Serial.begin(9600);
  Ser.begin   (9600);
  Serial.println("255");
}

void sil(int M) {
  tft.setCursor(0, uint16_t(tft.height() / 2));
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextSize(4);
  tft.println(String(saat[M]));
  tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
  tft.println(String(dakka[M]));
}
void Menu1() {
  if (M1 == 0) {
    //tft.fillScreen(ST77XX_BLACK);
    //Setup
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
    if (M1_2 == 0) {
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(0);
      //------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
    } if (M1_2 == 1) {
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(0);
      //--------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
    }

    M1 = 1;
  }
  if (MB == 1) {
    if (M1_1 == 0) {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
      //----
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
      M1_1 = 1;
    } else {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
      //-------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[0]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[0]));
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
      M1_1 = 0;
    }
    MB = 0;
  }
}

void M_SD(int a, int mod) {
  if (mod == 1) {
    if (a == 0) {
      if (M1_1 == 0) {
        saat[0]++;
        M1 = 0;
        M1_2 = 0;
      }
      if (M1_1 == 1) {
        dakka[0]++;
        M1 = 0;
        M1_2 = 1;
      }
    }
    if (a == 1) {
      if (M1_1 == 0) {
        saat[0]--;
        M1 = 0;
        M1_2 = 0;
      }
      if (M1_1 == 1) {
        dakka[0]--;
        M1 = 0;
        M1_2 = 1;
      }
    }


    if (dakka[0] < 0) {
      sil(0);
      if (saat[0] != 0)saat[0]--;
      dakka[0] = 59;
      M1 = 0;
      M1_2 = 1;
      Menu1();
    }
    if (dakka[0] >= 60) {
      sil(0);
      dakka[0] = 0;
      saat[0]++;
      M1 = 0;
      M1_2 = 1;
      Menu1();
    }
    if (saat[0] > 23) {
      sil(0);
      saat[0] = 0;
      M1 = 0;
      M1_2 = 0;
      Menu1();
    }
    if (saat[0] < 0) {
      sil(0);
      saat[0] = 0;
      M1 = 0;
      M1_2 = 0;
      Menu1();
    }
  } else if (mod == 2) {
    if (a == 0) {
      if (M2_1 == 0) {
        saat[1]++;
        M2 = 0;
        M2_2 = 0;
      }
      if (M2_1 == 1) {
        dakka[1]++;
        M2 = 0;
        M2_2 = 1;
      }
    }
    if (a == 1) {
      if (M2_1 == 0) {
        saat[1]--;
        M2 = 0;
        M2_2 = 0;
      }
      if (M2_1 == 1) {
        dakka[1]--;
        M2 = 0;
        M2_2 = 1;
      }
    }


    if (dakka[1] < 0) {
      sil(1);
      if (saat[1] != 0)saat[1]--;
      dakka[1] = 59;
      M2 = 0;
      M2_2 = 1;
      Menu2();
    }
    if (dakka[1] >= 60) {
      sil(1);
      dakka[1] = 0;
      saat[1]++;
      M2 = 0;
      M2_2 = 1;
      Menu2();
    }
    if (saat[1] > 23) {
      sil(1);
      saat[1] = 0;
      M2 = 0;
      M2_2 = 0;
      Menu2();
    }
    if (saat[1] < 0) {
      sil(1);
      saat[1] = 0;
      M2 = 0;
      M2_2 = 0;
      Menu2();
    }
  } else if (mod == 3) {
    if (a == 0) {
      if (M3_1 == 0) {
        saat[2]++;
        M3 = 0;
        M3_2 = 0;
      }
      if (M3_1 == 1) {
        dakka[2]++;
        M3 = 0;
        M3_2 = 1;
      }
    }
    if (a == 1) {
      if (M3_1 == 0) {
        saat[2]--;
        M3 = 0;
        M3_2 = 0;
      }
      if (M3_1 == 1) {
        dakka[2]--;
        M3 = 0;
        M3_2 = 1;
      }
    }


    if (dakka[2] < 0) {
      sil(2);
      if (saat[2] != 0)saat[2]--;
      dakka[2] = 59;
      M3 = 0;
      M3_2 = 1;
      Menu3();
    }
    if (dakka[2] >= 60) {
      sil(2);
      dakka[2] = 0;
      saat[2]++;
      M3 = 0;
      M3_2 = 1;
      Menu3();
    }
    if (saat[2] > 23) {
      sil(2);
      saat[2] = 0;
      M3 = 0;
      M3_2 = 0;
      Menu3();
    }
    if (saat[2] < 0) {
      sil(2);
      saat[2] = 0;
      M3 = 0;
      M3_2 = 0;
      Menu3();
    }
  } else if (mod == 4) {
    if (a == 0) {
      if (M4_1 == 0) {
        saat[3]++;
        M4 = 0;
        M4_2 = 0;
      }
      if (M4_1 == 1) {
        dakka[3]++;
        M4 = 0;
        M4_2 = 1;
      }
    }
    if (a == 1) {
      if (M4_1 == 0) {
        saat[3]--;
        M4 = 0;
        M4_2 = 0;
      }
      if (M4_1 == 1) {
        dakka[3]--;
        M4 = 0;
        M4_2 = 1;
      }
    }


    if (dakka[3] < 0) {
      sil(3);
      if (saat[3] != 0)saat[3]--;
      dakka[3] = 59;
      M4 = 0;
      M4_2 = 1;
      Menu4();
    }
    if (dakka[3] >= 60) {
      sil(3);
      dakka[3] = 0;
      saat[3]++;
      M4 = 0;
      M4_2 = 1;
      Menu4();
    }
    if (saat[3] > 23) {
      sil(3);
      saat[3] = 0;
      M4 = 0;
      M4_2 = 0;
      Menu4();
    }
    if (saat[3] < 0) {
      sil(3);
      saat[3] = 0;
      M4 = 0;
      M4_2 = 0;
      Menu4();
    }
  } else if (mod == 5) {
    if (a == 0) {
      KS[M5Say - 1]++;
      if (KS[M5Say - 1] < 1)KS[M5Say - 1] = 1;
      if (KS[M5Say - 1] > 5)KS[M5Say - 1] = 5;
      switch (M5Say) {
        case 1:
          M5YAZ(1, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(1, 2, ST77XX_CYAN, c);
          break;
        case 2:
          M5YAZ(2, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(2, 2, ST77XX_CYAN, c);
          break;
        case 3:
          M5YAZ(3, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(3, 2, ST77XX_CYAN, c);
          break;
      }
    }
    else {
      KS[M5Say - 1]--;
      if (KS[M5Say - 1] < 1)KS[M5Say - 1] = 1;
      if (KS[M5Say - 1] > 5)KS[M5Say - 1] = 5;
      switch (M5Say) {
        case 1:
          M5YAZ(1, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(1, 2, ST77XX_CYAN, c);
          break;
        case 2:
          M5YAZ(2, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(2, 2, ST77XX_CYAN, c);
          break;
        case 3:
          M5YAZ(3, 2, ST77XX_BLACK, ST77XX_BLACK);
          M5YAZ(3, 2, ST77XX_CYAN, c);
          break;
      }
    }
  }

}

void yaz() {

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_CYAN);
  tft.setTextSize(2);

  tft.println("Saat Ayari");
  tft.println("Sabah");
  tft.println("Oglen");
  tft.println("Aksam");
  tft.println("Bolme Ayar");


  tft.fillCircle(X(13), Y(1), r2, c);
}

uint16_t X(int a) {
  return tft.width() - r2;
}
uint16_t Y(int a) {
  return (artis * a) + 20;
}
void CONTROL() {
  CLK_D = digitalRead(CLK);
  if (CLK_D != S_CLK_D) {
    if (digitalRead(DT) != CLK_D) {
      if (MOD == 1) {
        M_SD(1, 1);
      } else if (MOD == 2) {
        M_SD(1, 2);
      } else if (MOD == 3) {
        M_SD(1, 3);
      }
      else if (MOD == 4) {
        M_SD(1, 4);
      }
      else if (MOD == 5) {
        M_SD(1, 5);
      }
    } else {
      say++;
      if (MOD == 0) {
        if (say == 2) {
          tft.fillCircle(X(13), Y(1), r2, ST77XX_BLACK);
          tft.fillCircle(X(13), Y(2), r2, c);
        } else if (say == 3) {
          tft.fillCircle(X(13), Y(2), r2, ST77XX_BLACK);
          tft.fillCircle(X(13), Y(3), r2, c);
        } else if (say == 4) {
          tft.fillCircle(X(13), Y(3), r2, ST77XX_BLACK);
          tft.fillCircle(X(13), Y(4), r2, c);
        } else if (say == 5) {
          tft.fillCircle(X(13), Y(4), r2, ST77XX_BLACK);
          tft.fillCircle(X(13), Y(5), r2, c);
        } else if (say == 6) {
          tft.fillCircle(X(13), Y(5), r2, ST77XX_BLACK);
          tft.fillCircle(X(13), Y(1), r2, c);
          say = 1;
        }
      } else if (MOD == 1) {
        M_SD(0, 1);
      } else if (MOD == 2) {
        M_SD(0, 2);
      } else if (MOD == 3) {
        M_SD(0, 3);
      } else if (MOD == 4) {
        M_SD(0, 4);
      } else if (MOD == 5) {
        M_SD(0, 5);
      }
    }

  }
  S_CLK_D = CLK_D;

  if (digitalRead(SWT) == LOW) {
    if (K == 2) {
      if (millis() - e_zaman > 1000) {
        MOD = 0;
        say = 1;
        yaz();
        K = 1;
        saatV(false);
      }
    }
    if (K == 0) {
      if (MOD != 0) {
        e_zaman = millis();
        K = 2;
      }
      else {
        K = 3;
      }
    }
  }
  if (digitalRead(SWT) == HIGH) {
    if (K == 2) {
      MB = 1;
      MB1 = 1;
      MB2 = 1;
      MB3 = 1;
      MB4 = 1;
    }
    if (K == 3) {
      if (say == 1) {
        tft.fillScreen(ST77XX_BLACK);
        M1 = 0;
        M1_3 = 0;
        MOD = 1;
      }
      else if (say == 2) {
        tft.fillScreen(ST77XX_BLACK);
        M2 = 0;
        MOD = 2;
      }
      else if (say == 3) {
        tft.fillScreen(ST77XX_BLACK);
        M3 = 0;
        MOD = 3;
      } else if (say == 4) {
        tft.fillScreen(ST77XX_BLACK);
        M4 = 0;
        MOD = 4;
      } else if (say == 5) {
        tft.fillScreen(ST77XX_BLACK);
        M5 = 0;
        MOD = 5;
      }
    }
    K = 0;
  }
}
void saatV(boolean aaa) {
  if (aaa) {
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_BLACK);
    tft.println(String(saat[0]));
    tft.setCursor(35, 0);
    tft.println(String(dakka[0]));
    tft.fillCircle(28, 2, 2, ST77XX_BLACK);
    tft.fillCircle(28, 10, 2, ST77XX_BLACK);
  } else {
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_ORANGE);
    tft.println(String(saat[0]));
    tft.setCursor(35, 0);
    tft.println(String(dakka[0]));
    tft.fillCircle(28, 2, 2, ST77XX_ORANGE);
    tft.fillCircle(28, 10, 2, ST77XX_ORANGE);
  }
}
void Menu2() {
  if (M2 == 0) {
    //tft.fillScreen(ST77XX_BLACK);
    //Setup
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
    if (M2_2 == 0) {
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(1);
      //------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
    } if (M2_2 == 1) {
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(1);
      //--------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
    }

    M2 = 1;
  }
  if (MB1 == 1) {
    if (M2_1 == 0) {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
      //----
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
      M2_1 = 1;
    } else {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
      //-------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[1]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[1]));
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
      M2_1 = 0;
    }
    MB1 = 0;
  }
}
void Menu3() {
  if (M3 == 0) {
    //tft.fillScreen(ST77XX_BLACK);
    //Setup
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
    if (M3_2 == 0) {
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(2);
      //------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
    } if (M3_2 == 1) {
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(2);
      //--------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
    }

    M3 = 1;
  }
  if (MB2 == 1) {
    if (M3_1 == 0) {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
      //----
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
      M3_1 = 1;
    } else {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
      //-------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[2]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[2]));
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
      M3_1 = 0;
    }
    MB2 = 0;
  }
}

void Menu4() {
  if (M4 == 0) {
    //tft.fillScreen(ST77XX_BLACK);
    //Setup
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
    tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
    if (M4_2 == 0) {
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(3);
      //------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
    } if (M4_2 == 1) {
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      sil(3);
      //--------------------------------------------------------------------------------------------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
    }

    M4 = 1;
  }
  if (MB3 == 1) {
    if (M4_1 == 0) {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
      //----
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
      M4_1 = 1;
    } else {
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_BLACK);
      tft.setTextSize(4);
      tft.fillRoundRect(tft.width() - 55, int(tft.height() / 2 - 7), 50, 40, 5, ST77XX_BLACK);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
      //-------
      tft.setCursor(0, uint16_t(tft.height() / 2));
      tft.setTextColor(ST77XX_CYAN);
      tft.setTextSize(4);
      tft.fillRoundRect(0, int(tft.height() / 2 - 7), 50, 40, 5, c);
      tft.println(String(saat[3]));
      tft.setCursor(tft.width() - 50, uint16_t(tft.height() / 2));
      tft.println(String(dakka[3]));
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2 + 20), 5, ST77XX_CYAN);
      tft.fillCircle(uint16_t(tft.width() / 2), uint16_t(tft.height() / 2), 5, ST77XX_CYAN);
      M4_1 = 0;
    }
    MB3 = 0;
  }
}
void M5Draw(int r5, int satir, int COLOR) {
  int Y5 = 0;
  switch (satir) {
    case 1: Y5 = 1;  break;
    case 2: Y5 = 16; break;
    case 3: Y5 = 28; break;
  }
  tft.fillRoundRect(79, Y5, r5 * 4, r5 * 4, r5, COLOR);
}
void M5YAZ(int sa, int r6, int COLOR, int COLOR2) {
  M5Draw(5, sa, COLOR2);
  tft.setTextColor(COLOR);
  tft.setTextSize(r6);
  tft.setCursor(0, 0);
  tft.print("Sabah: ");
  tft.println(KS[0]);
  tft.print("Oglen: ");
  tft.println(KS[1]);
  tft.print("Aksam: ");
  tft.println(KS[2]);
}
void Menu5() {
  if (!M5) {
    M5YAZ(1, 2, ST77XX_CYAN, c);
    M5 = 1;
    M5Say = 1;
  }
  if (MB4) {
    M5Say++;
    if (M5Say > 3)M5Say = 1;
    if (M5Say == 1) {
      M5YAZ(5, 2, ST77XX_BLACK, ST77XX_BLACK);
      M5YAZ(1, 2, ST77XX_CYAN, c);
    } else if (M5Say == 2) {
      M5YAZ(1, 2, ST77XX_BLACK, ST77XX_BLACK);
      M5YAZ(2, 2, ST77XX_CYAN, c);
    } else if (M5Say == 3) {
      M5YAZ(2, 2, ST77XX_BLACK, ST77XX_BLACK);
      M5YAZ(3, 2, ST77XX_CYAN, c);
    }
    MB4 = 0;
  }
}
void NO_C() {
  if (saat[0] == saat[1]) {
    if (dakka[0] == dakka[1]) {
      if (KS[0] == 1)NO = NO1;
      if (KS[0] == 2)NO = NO2;
      if (KS[0] == 3)NO = NO3;
    }
  }
  if (saat[0] == saat[2]) {
    if (KS[1] == 1)NO = NO1;
    if (KS[1] == 2)NO = NO2;
    if (KS[1] == 3)NO = NO3;
  }
  if (saat[0] == saat[3]) {
    if (KS[2] == 1)NO = NO1;
    if (KS[2] == 2)NO = NO2;
    if (KS[2] == 3)NO = NO3;
  }
}
boolean NO_D() {
  int a = 0, b = 0, c = 0;
  bool d = false;
  if (saat[0] == saat[1] && dakka[0] == dakka[1])a = 1;
  if (saat[0] == saat[2] && dakka[0] == dakka[2])b = 1;
  if (saat[0] == saat[3] && dakka[0] == dakka[3])c = 1;
  if (a == 1 or b == 1 or c == 1)d = true;
  else d = false;
  return d;
}
void loop() {
  CONTROL();
  if (Alarm) {
    NO_C();
    if (NO_D()) {
      MOD = 0;
      //Ilac Saati
      tft.setTextColor(ST77XX_RED);
      tft.fillScreen(ST77XX_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(3);
      tft.println("Ilac");
      tft.setCursor(0, 30);
      tft.println("Saati");
      tft.setCursor(0, 60);
      tft.println("Geldi!");
      digitalWrite(7, HIGH);
      while (digitalRead(SWT)) {
        if (millis() - e_z2 > 60000) {
          dakka[0]++;
          if (dakka[0] == dakka[1] + 5 or dakka[0] == dakka[2] + 5 or dakka[0] == dakka[3] + 5) {
            Ser.print("2");
          }
          if (dakka[0] >= 60) {
            dakka[0] = 0;
            saat[0]++;
          }
          if (saat[0] > 23) {
            saat[0] = 0;
          }
          e_z2 = millis();
        }
      }
      digitalWrite(7, LOW);
      Ser.println("1");
      tft.fillScreen(ST77XX_BLACK);
      tft.setTextColor(ST77XX_YELLOW);
      tft.setCursor(0, tft.height() / 2 - 40);
      tft.setTextSize(2);
      tft.println("Ilac");
      tft.println("Veriliyor");
      tft.println("...");
      Servo_1.write(NO);
      Degis();
      delay(500);
      Degis();
      delay(500);
      Degis();
      delay(500);
      Degis();
      delay(500);
      Servo_2.write(0);
      Degis();
      delay(250);
      Degis();
      Servo_2.write(150);
      Degis();
      delay(500);
      Degis();
      delay(500);
      tft.fillScreen(ST77XX_BLACK);
      delay(1000);
      //DS();
      MOD = 0;
      say = 1;
      yaz();
      K = 1;
      //tft.fillCircle(X(13), Y(1), r2, ST77XX_BLACK);
      saatV(false);
      Alarm = false;
    }
  }
  if (MOD == 1)Menu1();
  if (MOD == 2)Menu2();
  if (MOD == 3)Menu3();
  if (MOD == 4)Menu4();
  if (MOD == 5)Menu5();
  if (millis() - e_z2 > 60000) {
    if (MOD == 0)saatV(true);
    dakka[0]++;
    if (dakka[0] == dakka[1] + 1 or dakka[0] == dakka[2] + 1 or dakka[0] == dakka[3] + 1) {
      if (saat[0] == saat[1] or saat[0] == saat[2] or saat[0] == saat[3])Alarm = true;
    }
    if (dakka[0] == dakka[1] + 5 or dakka[0] == dakka[2] + 5 or dakka[0] == dakka[3] + 5) {
      if (saat[0] == saat[1] or saat[0] == saat[2] or saat[0] == saat[3])Ser.println("0");
    }
    if (MOD == 0)saatV(false);
    if (dakka[0] >= 60) {
      if (MOD == 0)saatV(true);
      dakka[0] = 0;
      saat[0]++;
      if (MOD == 0)saatV(false);
    }
    if (saat[0] > 23) {
      if (MOD == 0)saatV(true);
      saat[0] = 0;
      if (MOD == 0)saatV(false);
    }
    e_z2 = millis();
  }

  if (Serial.available() > 0) {
    String a = Serial.readString();
    int b = a.toInt();
    if (SM == 0) {
      if (MOD == 0)saatV(true);
      saat[0] = b;
      SM = 1;
      if (MOD == 0)saatV(false);
    } else if (SM == 1) {
      if (MOD == 0)saatV(true);
      dakka[0] = b;
      SM = 0;
      if (MOD == 0)saatV(false);
    }
  }
  if (Ser.available() > 0) {
    String a = Ser.readString();
    int b = a.toInt();
    if (B_MOD == 1) {
      saat[1] = b;
      B_MOD = 2;
    } else if (B_MOD == 2) {
      dakka[1] = b;
      B_MOD = 0;
    } else if (B_MOD == 3) {
      saat[2] = b;
      B_MOD = 4;
    } else if (B_MOD == 4) {
      dakka[2] = b;
      B_MOD = 0;
    } else if (B_MOD == 5) {
      saat[3] = b;
      B_MOD = 6;
    } else if (B_MOD == 6) {
      dakka[3] = b;
      B_MOD = 0;
    } else if (B_MOD == 7) {
      KS[0] = b;
      B_MOD = 0;
    } else if (B_MOD == 8) {
      KS[1] = b;
      B_MOD = 0;
    } else if (B_MOD == 9) {
      KS[2] = b;
      B_MOD = 0;
    }
    //-------------------------
    if (b == 254) {
      B_MOD = 1;
    } if (b == 253) {
      B_MOD = 3;
    } if (b == 252) {
      B_MOD = 5;
    }
    //------------------------
    if (b == 251) {
      B_MOD = 7;
    } if (b == 250) {
      B_MOD = 8;
    } if (b == 249) {
      B_MOD = 9;
    }
  }
}
void DS() {
  if (AA) {
    tft.drawCircle(x, y, r, ST77XX_BLACK);
    tft.drawLine(x - 16, (y + r) - 42, x2 + 16, (y2 - r) + 42, ST77XX_BLACK);
    tft.drawLine((x - r) + 42, (y + r) - 42, (x2 + r) - 42, (y2 - r) + 42, ST77XX_BLACK);
  } else {
    tft.drawCircle(x, y, r, ST77XX_BLACK);
    tft.drawLine(x - r, y, x2 + r, y2, ST77XX_BLACK);
    tft.drawLine(x, y - r, x2, y2 + r, ST77XX_BLACK);
  }
}
void Degis() {
  if (AA) {
    tft.drawCircle(x, y, r, ST77XX_BLACK);
    tft.drawLine(x - r, y, x2 + r, y2, ST77XX_BLACK);
    tft.drawLine(x, y - r, x2, y2 + r, ST77XX_BLACK);
    //**************************************
    tft.drawCircle(x, y, r, c);
    tft.drawLine(x - 16, (y + r) - 42, x2 + 16, (y2 - r) + 42, c);
    tft.drawLine((x - r) + 42, (y + r) - 42, (x2 + r) - 42, (y2 - r) + 42, c);
    AA = false;
  } else {
    tft.drawCircle(x, y, r, ST77XX_BLACK);
    tft.drawLine(x - 16, (y + r) - 42, x2 + 16, (y2 - r) + 42, ST77XX_BLACK);
    tft.drawLine((x - r) + 42, (y + r) - 42, (x2 + r) - 42, (y2 - r) + 42, ST77XX_BLACK);
    //**************************************
    tft.drawCircle(x, y, r, c);
    tft.drawLine(x - r, y, x2 + r, y2, c);
    tft.drawLine(x, y - r, x2, y2 + r, c);
    AA = true;
  }
}
