# Hakkında
Geliştirdiğimiz projemiz verilen anahtara göre giriş metnini kriptolayabilir veya kriptolanmış bir metni çözebilir. Çözmek için bir kilit dosyasına ihtiyaç duyar. Bu kilit dosyası Huffman Ağacı ile oluşmuş olmalıdır. Projemiz harici kütüphane olarak libfdr kütüphanesine bağımlıdır.

# Kurulum

### Projenin İndirilmesi
```
git clone https://github.com/burakyzn/sistem-programlama-proje.git
```
### Derleme
```
make
```
### Çalıştırma
Şifrelemek için 
```
./output -e giris_metni cikis_metni
```
Şifreyi çözmek için
```
./output -d giris_metni cikis_metni
```

# Kod Standartları

### Genel Kurallar

Her kelime grubu küçük harfle yazılmalı birden fazla kelime içeren değişken/fonksiyon isimleri _ ile ayrılmalıdır.
```c
int yeni_sayi;
```
Her değişken kendi satırında tanımlanmalıdır.
```c
// olmamasi gereken
int benim_x, benim_y; 

// olmasi gereken
int benim_x; 
int benim_y;
```
Her girinti bir tab uzunluğundadır. 
Süslü parantezler için ekstra satır kullanılmaz.

```c
for (i = 0; i < sayi_uzunluk; i++) { // suslu parantezler ekstra yer kaplamaz
  if (sayilar[i] < 5)
    printf("5 den kucuk");
}
```

### Global Değişken
Global değişken kullanımından kaçınılmalıdır. 
Kullanılması gerekiyorsa 
```c
int g_global_degisken;
```
şeklinde yazılmalıdır.

### Sabit Değişken
Sabit değişkenler her zaman büyük harfler ile yazılmalıdır.
```c
#define KELIME_UZUNLUK 10   
```

### Pointer
Pointer için kullanılan * işareti her zaman pointer ismine yakın yazılmalıdır.

```c
int  *benim_pointerim; // olmasi gereken
int*  benim_pointerim; // olmamasi gereken 
```

### Koşullu İfadeler
Koşullu ifadeler (if-else if-else) aşağıdaki şekilde yazılmalıdır.

```c
if (kosul) {
} else if (kosul) {
} else {
}
```

Tekli ifadeler için süslü parantez kullanılmamalıdır.
```c
if (kosul)
  tekli_ifade();
else
  diger_tekli_ifade();
```
Koşul içindeki boolean ifadeler == kullanılarak kontrol edilmemelidir.
```c
if (kosul)
	yap();
if (!kosul)
	yapma();
```
Bunun dışında kalan diğer veri tipleri için bu karşılaştırma her zaman == ile yapılmalıdır.
```c
if (benim_pointer == NULL)
	yap_bir();
if (sayi == 0)
	yap_iki();
if (str != NULL && *str != '\0')
	yap_uc();
```

### Fonksiyonlar
Void dönüş tipindeki fonksiyonlara da return yazılmalıdır.
```c
void fonksiyon(){
  return;
}
```
Fonksiyon parametreleri her zaman p_parametre_adı şeklinde yazılmalıdır.
```c
int kare_al(int p_sayi){
  return p_sayi * p_sayi;
}
```
Birden fazla parametre bulunduğunda parametreler satır satır sola dayalı şekilde yazılmalıdır.
```c
void fonksiyon(double   p_sayi1
               int      p_sayi2)
  return;
}
```
Her fonksiyon üzerine yorum satırı olarak fonksiyonun ne yaptığı iyi bir şekilde açıklanmalıdır.
```c
/*
@description : fonksiyonun gorevi kisaca tanımlanmalıdır.
@author: fonksiyon yazarı tanımlanmalıdır.
@param: parametrelerin neler olduğu tanımlanmalıdır.
@return: döndürülen değer tanımlanmalıdır.
@todo: yapılacak bir şey varsa buraya not düşülmelidir.
*/
```
Fonksiyon çağırımlarında tek satır kod yazmak için boşluklar kaldırılmamalıdır.
```c
if (kosul) // olmasi gereken
  return sayi;
  
if (kosul) return sayi; // yanlis olan
```

### Switch 
Olması gereken switch kullanımı aşağıdaki gibidir. 
Her blok içeri girintili şekilde yazılmalıdır ve bloklar arasi bir satır boşluk bırakılmalıdır.
```c
switch (kosul) {
case pazartesi:
	yap_bir();
	break;

case sali:
	yap_iki();
	break;
}
```
Switch koşulu her durum için işlem yapılmasa bile yazılmalıdır.
```c
switch (kosul) {
case pazartesi:
	yap_bir();
	break;

case sali:
	yap_iki();
	break;

case carsamba:
case persembe:
case cuma:
case cumartesi:
case pazar:
default:
	yap_varsayilan();
}
```

### Başlık Dosyası
Başlık dosyalarında belirtilen tum fonksiyon imzaları fonksiyon dönüş tipi fonksiyon adı ve parametreler olarak bir tablo şeklinde alt alta hizalı olarak sıralanmalıdır.

```c
void   fonskiyon1   (int   p_parametre1
                     int   p_parametre2);
int    fonskiyon2   (int   p_parametre1);
```
