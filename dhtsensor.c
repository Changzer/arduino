#include <LiquidCrystal.h>
#include <dht.h>

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

#define DHT22_PIN 2

float hum;
float temp;

int setHUM;
int setTEMP;

const char chars[] = {'0','1','2','3','4','5','6','7','8','9'};
int charindex = 0;
int charsSize = 0;

void setup(){
	lcd.begin(16,2);
	}

void loop(){
	
	hum = DHT.humidity;
	temp = DHT.temperature;
	
	sensorREAD();
	
	sensorALARM();

	sensorSET();

	}

void sensorREAD(){

	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Umidade: ");
	lcd.print(hum);
	lcd.print("%";

	lcd.setCursor(0,1);
	lcd.print("Temp: ");
	lcd.print(temp);
	lcd.print("C");

	delay(2000);
	}

void sensorALARM(){
	if (hum > setHUM){
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("UMIDADE ALTA ");
		lcd.print(hum);
		lcd.print("%");
			}
	if (temp > setTEMP){
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("TEMPERATURA ALTA ");
		lcd.print(temp);
		lcd.print("C");
			}
	}

void sensorSET(){

	}