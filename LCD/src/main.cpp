#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D4;
int SCL_pin = D3;
int Li          = 17;
int Lii         = 1; 
int Ri          = -1;
int Rii         = -1;

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  // Output diam
  lcd.setCursor(0,0);
  lcd.print("Prak PST Shift D");
  lcd.setCursor(0,1);
  lcd.print("5 Mei 2024");
}

void loop(){
  //Output dugem
  // lcd.setCursor(0,0);
  // lcd.print("Prak PST Shift D");
  // lcd.scrollDisplayRight ();         // untuk menampilkan tulisan berjalan dari arah kanan
  // delay (1000);                              // delay saat tulisan berjalan
  // lcd.clear ();
  // lcd.setCursor(0,1);
  // lcd.print("5 Mei 2024");
  // lcd.scrollDisplayRight ();         // untuk menampilkan tulisan berjalan dari arah kanan
  // delay (1000);                              // delay saat tulisan berjalan
  // lcd.clear ();

  //Output bergerak
//   for (int i = 0; i <= 12; i++) {
//     lcd.setCursor(0, 0);
//     lcd.print(Scroll_LCD_Right("Prak PST Shift D"));
//     delay(350);
//   }
//   for (int i = 0; i <= 50; i++) {                                                                         
//     lcd.setCursor(0, 1);                                                
//     lcd.print(Scroll_LCD_Left("5 Mei 2024...."));   
//     delay(350);
//   }
//   Clear_Scroll_LCD_Left();
  
}

// String Scroll_LCD_Left(String StrDisplay){
//   String result;
//   String StrProcess = "                " + StrDisplay + "                ";
//   result = StrProcess.substring(Li,Lii);
//   Li++;
//   Lii++;
//   if (Li>StrProcess.length()){
//     Li=16;
//     Lii=0;
//   }
//   return result;
// }

// String Scroll_LCD_Right(String StrDisplay){
//   String result;
//   String StrProcess = "                " + StrDisplay + "                ";
//   if (Rii<1){
//     Ri  = StrProcess.length();
//     Rii = Ri-16;
//   }
//   result = StrProcess.substring(Rii,Ri);
//   Ri--;
//   Rii--;
//   return result;
// }

// void Clear_Scroll_LCD_Right(){
//   Ri=-1;
//   Rii=-1;
// }

// void Clear_Scroll_LCD_Left(){
//   Li=16;
//   Lii=0;
// }