#include <LiquidCrystal.h>

#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(8,9,4,5,6,7);
int lcd_key = 0;
int adkey = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

int read_LCD_buttons(){
  adkey = analogRead(0);
  if (adkey > 1000) return btnNONE;
  if (adkey < 50) return btnRIGHT;
  if (adkey < 250) return btnUP;
  if (adkey < 450) return btnDOWN;
  if (adkey < 650) return btnLEFT;
  if (adkey < 850) return btnSELECT;
  
  return btnNONE;
  }




const char chars[] = {'0','1','2','3','4','5','6','7','8','9'};
int charindex = 0;
int charsSize = 0;

void setup(){
  lcd.begin(16,2);
  dht.begin();
  }

void loop(){
float t = dht.readTemperature();
float h = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Umidade: ");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  delay(500);

  sensorAlarme();
  }


void sensorAlarme(){
float t = dht.readTemperature();
float h = dht.readHumidity();

  if(h > 70){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("UMIDADE ALTA");
  lcd.setCursor(0,1);
  lcd.print("Umidade: ");
  lcd.print(h);
  delay(2000);
  }
}
