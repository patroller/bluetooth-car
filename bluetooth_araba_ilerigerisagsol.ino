int Harekethizi = 0;
int Donushizi = 0;
/* bu değişken ile motorların dönme hızı kontrol edilebilir */

/* motor sürücüsüne bağlanacak INPUT ve ENABLE pinleri belirleniyor */
const int sagileri = 9;
const int saggeri = 8;
const int solileri = 12;
const int solgeri = 13;
const int solenable = 11;
const int sagenable = 10;
const int far = 3;
const int park = 4;
const int korna = 5;
const int dortlu = 6;

void ileri(int hiz) {
  /* ilk değişkenimiz sag motorun ikincisi sol motorun hızını göstermektedir.
     motorlarımızın hızı 0-255 arasında olmalıdır.
     Fakat bazı motorların torkunun yetersizliğiniden 60-255 arasında çalışmaktadır.
     Eğer motorunuzdan tiz bir ses çıkıyorsa hızını arttırmanız gerekmektedir.
  */
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(saggeri, LOW); /* ileri dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(solgeri, LOW); /* ileri dönme sağlanıyor */
}
void sagaDon(int hiz) {
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, LOW); /* geri dönme sağlanıyor */
  digitalWrite(saggeri, HIGH); /* geri dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(solgeri, LOW); /* ileri dönme sağlanıyor */
}
void solaDon(int hiz) {
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(saggeri, LOW); /* ileri dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, LOW); /* geri dönme sağlanıyor */
  digitalWrite(solgeri, HIGH); /* geri dönme sağlanıyor */
}
void geri(int hiz) {
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(saggeri, HIGH); /* geri yönde dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(solgeri, HIGH); /* geri yönde dönme sağlanıyor */
}
int ilerisag(int hiz, int hiz2) {
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(saggeri, LOW); /* ileri dönme sağlanıyor */

  analogWrite(solenable, hiz2); /* sol motorun hız verisi */
  digitalWrite(solileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(solgeri, LOW); /* ileri dönme sağlanıyor */
}
int ilerisol (int hiz, int hiz2) {
  analogWrite(sagenable, hiz2); /* sağ motorun hız verisi */
  digitalWrite(sagileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(saggeri, LOW); /* ileri dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, HIGH); /* ileri dönme sağlanıyor */
  digitalWrite(solgeri, LOW); /* ileri dönme sağlanıyor */
}

int gerisag(int hiz, int hiz2) {
  analogWrite(sagenable, hiz); /* sağ motorun hız verisi */
  digitalWrite(sagileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(saggeri, HIGH); /* geri yönde dönme sağlanıyor */

  analogWrite(solenable, hiz2); /* sol motorun hız verisi */
  digitalWrite(solileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(solgeri, HIGH); /* geri yönde dönme sağlanıyor */
}

int gerisol(int hiz, int hiz2) {
  analogWrite(sagenable, hiz2); /* sağ motorun hız verisi */
  digitalWrite(sagileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(saggeri, HIGH); /* geri yönde dönme sağlanıyor */

  analogWrite(solenable, hiz); /* sol motorun hız verisi */
  digitalWrite(solileri, LOW); /* geri yönde dönme sağlanıyor */
  digitalWrite(solgeri, HIGH); /* geri yönde dönme sağlanıyor */
}

void dur()
{
  /* Tüm motorlar kitlenerek durma sağlanıyor */
  digitalWrite(sagileri, HIGH);
  digitalWrite(saggeri, HIGH);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri, HIGH);
}

void setup() {
  /* Bluetooth için port açılıyor */
  Serial.begin(9600);

  /* motorları kontrol eden pinler çıkış olarak ayarlanıyor */
  pinMode(sagileri, OUTPUT);
  pinMode(saggeri, OUTPUT);
  pinMode(solileri, OUTPUT);
  pinMode(solgeri, OUTPUT);
  pinMode(sagenable, OUTPUT);
  pinMode(solenable, OUTPUT);
  pinMode(far, OUTPUT);
  pinMode(park, OUTPUT);
  pinMode(korna, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {   /*Bluetooth’tan veri bekliyoruz */
    char tus = (char)Serial.read();

    if ( tus == 'F' )
      ileri(Harekethizi);

    else if ( tus == 'L' )
      solaDon(Harekethizi);

    else if ( tus == 'R' )
      sagaDon(Harekethizi);

    else if ( tus == 'B' )
      geri(Harekethizi);

    else if ( tus == 'G' )
      ilerisol(Harekethizi, Donushizi);

    else if ( tus == 'I' )
      ilerisag(Harekethizi, Donushizi);
    else if ( tus == 'H' )
      gerisol(Harekethizi, Donushizi);

    else if ( tus == 'J' )
      gerisag(Harekethizi, Donushizi);

      else if (tus == 'W')
        digitalWrite(far, HIGH);

      else if (tus == 'w')
        digitalWrite(far, LOW);

      else if (tus == 'V')
        digitalWrite(korna, HIGH);

      else if (tus == 'v')
        digitalWrite(korna, LOW);

      else if (tus == 'U')
        digitalWrite(park, HIGH);

      else if (tus == 'u')
        digitalWrite(park, LOW);

      else if (tus == '0') {
        Harekethizi = 0;
        Donushizi = 0;
      }
      else if (tus == '1') {
        Harekethizi = 60;
        Donushizi = 20;
      }
      else if (tus == '2') {
        Harekethizi = 80;
        Donushizi = 27;
      }
      else if (tus == '3') {
        Harekethizi = 100;
        Donushizi = 33;
      }
      else if (tus == '4') {
        Harekethizi = 120;
        Donushizi = 40;
      }
      else if (tus == '5') {
        Harekethizi = 140;
        Donushizi = 46;
      }
      else if (tus == '6') {
        Harekethizi = 160;
        Donushizi = 53;
      }
      else if (tus == '7') {
        Harekethizi = 180;
        Donushizi = 60;
      }
      else if (tus == '8') {
        Harekethizi = 205;
        Donushizi = 68;
      }
      else if (tus == '9') {
        Harekethizi = 230;
        Donushizi = 76;
      }
      else if (tus == 'q') {
        Harekethizi = 255;
        Donushizi = 85;
      }


      else
        dur();





      delay(1);
    }
  }






