#include <LiquidCrystal.h>
LiquidCrystal lcd(8,7,6,5,4,3);               // 16*2 LCD ekranımızın kütüphanesi ve seçmiş olduğumuz arduino giriş pinleri

#define gasPin A1
#define buzzerPin 11                          // Tanımladığımız MQ7 Gaz Sensörü ve buzzer elemanının sabit pinleri



void setup()                                  // Arduino başlatıldığında veya yeniden başlatıldığında ilk çalıştırılan kısım
{   
 Serial.begin(9600);                          // Seri haberleşme portunun hızının ayarlanması        
 
 lcd.begin(16, 2);                            // Kullandığımız LCD'nin 16x2 boyutlarında olduğunu belirtir.
 
 pinMode(buzzerPin,OUTPUT);                   // Buzzerın çıkış modu olarak kodlanması 
 
 lcd.setCursor(0, 0);                         // Bu fonksiyon ekran imlecinin pozisyonunun ayarlanması için kullanılır.
  lcd.print("YUKLENIYOR");                    // LCD ekrana veri yazdırmak için kullanılır.      
    for(int i = 0; i <10; i++){             
      if (i==4)
      { 
         lcd.setCursor(0, 1);               //  Sütun ve Satır başlangıç   
         lcd.print(".");
        }
       else  lcd.print(".");
      delay(500);                           //  Kod arasındaki bekleme süresi
      }
    lcd.setCursor(5, 1);
    lcd.print("Tamam");
    delay(1000);                            // Kod arasındaki bekleme süresi
    lcd.clear(); 
    lcd.setCursor(1, 0);
    lcd.print("SENSOR AKTIF");
    delay(1500);                            // Kod arasındaki bekleme süresi
    lcd.clear();

}

void loop() {                                   // Setup fonksiyonu çalıştırıldıktan sonra sonsuz döngüye girilen kısım 
  
int gasSensor = analogRead(gasPin);             // Gaz sensörünün analog pininin bağlandığı gösterirlir

  if (gasSensor > 200)                          // Ölçülen değer eğer 100 den büyük ise :  
  {
     
     
     digitalWrite(buzzerPin,HIGH);              // Buzzer'ın en yüksek konumda olduğunu belirtir
     
     lcd.setCursor(0, 0);                       //
     lcd.print("DEGER : ");                     // LCD ekranda okunan değeri gösterir
     lcd.print(gasSensor);
     Serial.print(gasSensor);
     Serial.print("\t");
     lcd.setCursor(0, 1);
     Serial.println("GAZ ALARMI");               // Serial port ekranda parantez içindeki tanım devreye girer
     lcd.print("GAZ ALARMI");                   // LCD ekranda parantez içindeki tanım devreye girer
     delay(300);                               //  Kod arasındaki bekleme süresi
     lcd.clear();
  }
  else if (100< gasSensor < 200)                   // Ölçülen değer eğer 100'den küçük ise :
 
   {

    
     digitalWrite(buzzerPin,LOW);             // Buzzer'ın en düşük konumda olduğunu belirtir
    
    
     lcd.setCursor(0, 0);                      // LCD'için 0. satır 0. sütünda lcd.print içindeki yazı yazması
     lcd.print("DEGER : ");
     lcd.print(gasSensor/10);
     Serial.print(gasSensor);                 // seri port gaz senörünün kendi değeri ve zamanlayıcı
     Serial.print("\t");
     lcd.setCursor(0, 1);
     Serial.println("GAZ NORMAL");          // Seri Port Ekranında parantez içindeki tanım devreye girer
     lcd.print("GAZ NORMAL");              // LCD ekranda parantez içindeki tanım devreye girer
     delay(300);       
     else if ( gasSensor < 200)       // Kod arasındaki bekleme süresi
    }
  
 
                 
