/*
 * tp10.c
 *
 *  Created on: 28 Ara 2021
 *      Author: pinar
 */

#include <stdio.h>
#define N 10 //Ogrenci isim max karakter sayisi
#define M 3  //Ogrencilerin not sayisi
#define S 5  //sinif mevcudu
#define bulundugumuzYil 2021

// Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklindeki tarih bilgilerini tutmak icin bir struct tanimlayalim
typedef struct
{
    int gun;
    char ay[10];
    int yil;
} Tarih;
// Bir Ogrencinin adini, dogum tarihini ve odevlerden aldigi M adet notu tutmak icin bir struct yapisi tanimlayalim
typedef struct
{
    char ad[40];
    Tarih dogumTarihi;
    float notlar[M];
} Ogr;

// yazacagimiz fonksiyonlarin basliklari
Tarih tarihiAl(void);                                     // kullanicidan gerekli bilgileri alip bir tarih struct'ini dondurur
void tarihiAlPointer(Tarih *);                            // alternatif
void tarihiBastir(Tarih);                                 // parametre olarak aldigi tarih struct'ini duzgun bir sekilde ekrana bastirir
Ogr ogrBilgileriniAl(void);                               // kullanicidan gerekli bilgileri alip bir Ogr struct'i dondurur
void ogrBilgileriniBastir(Ogr);                           // parametre olarak aldigi Ogr struct'ini duzgun bir sekilde ekrana bastirir
float ogrOrtalamasiHesapla(Ogr);                          // parametre olarak aldigi Ogr struct'indaki notlarin ortalamasini hesaplayip dondurur
float snfOrtalamasiHesapla(Ogr snf[S], float agirlik[M]); // parametre olarak aldigi dizideki Ogrencilerin notlarinin agirlik tablosunda verilen degerlere gore genel ortalamasini hesaplayip dondurur
float snfYasOrtalamasiHesapla(Ogr snf[S]);                // parametre olarak aldigi dizideki Ogrencilerin yas ortalamasini hesaplayip dondurur

int main(void)
{

    // ---------------- TARIH ----------------
    // tarih yapisinda bir degisken tanimlayalim
    Tarih tarih;

    // tarihiAl fonksiyonunu cagirarak kullanicidan tarih alalim
    tarih = tarihiAl();

    // yazdigimiz fonksiyonu kullanarak bu tarihi ekrana bastiralim
    tarihiBastir(tarih);

    // M adet tarihi tutmak icin bir dizi tanimlayalim
    Tarih tarihler[M];

    // Dizinin ilk elemanina, elimizde mevcut olan tarih bilgisini atayalim
    tarihler[0] = tarih;

    // Geri kalan elemanlari doldurmak i�in tarihiAl ile kullanicidan giris alalim
    for (int i = 1; i < M; i++)
    {
        tarihler[i] = tarihiAl();
    }

    // Dizinin tum elemanlarini ekrana bastiralim
    for (int i = 0; i < M; i++)
    {
        tarihiBastir(tarihler[i]);
    }
    

    // ----------------- Ogr -----------------
    // Ogr yapisinda bir degisken tanimlayalim
    Ogr ogr;

    // ogrBilgileriniAl fonksiyonunu cagirarak, icini dolduralim
    ogr = ogrBilgileriniAl();

    // bilgileri ekrana bastiralim
    ogrBilgileriniBastir(ogr);

    // ortalamasini ekrana bastiralim
    printf("Ortalamasi: %f\n", ogrOrtalamasiHesapla(ogr));

    // ----------------- SNF -----------------
    // S adet Ogrenciden olusan bir sinifi temsil etmek icin bir dizi tanimlayalim
    Ogr snf[S];

    // Bu siniftaki Ogrencilerin bilgilerini kullanicidan alalim
    for (int i = 0; i < S; i++)
    {
        snf[i] = ogrBilgileriniAl();
    }
    

    float agirlik[M] = {0.3, 0.3, 0.4};
    // Ogrencilerin genel ortalamasini hesaplayan fonksiyonu cagirip sinifin ortalamasini bastiralim
    printf("Sinif agirlikli ortalama: %f", snfOrtalamasiHesapla(snf, agirlik));

    // Sinifin yas ortalamasini ekrana bastiralim
    printf("Sinif yas ortalamasi: %f", snfYasOrtalamasiHesapla(snf));

    return 0;
}

// kullanicidan gerekli bilgileri alip bir tarih struct'ini dondurur
Tarih tarihiAl(void)
{
    Tarih tarih;
    printf("Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklinde tarih bilgisi giriniz: ");
    scanf("%d %s %d", &tarih.gun, tarih.ay, &tarih.yil);
    return tarih;
}

// alternatif cozum
void tarihiAlPointer(Tarih *t)
{
    printf("Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklinde tarih bilgisi giriniz: ");
    scanf("%d %s %d", &(*t).gun, (*t).ay, &(*t).yil);
}

// parametre olarak aldigi tarih struct'ini duzgun bir sekilde ekrana bastirir
void tarihiBastir(Tarih temp)
{
    printf("%d/%s/%d\n", temp.gun, temp.ay, temp.yil);
}

// kullanicidan gerekli bilgileri alip bir Ogr struct'i dondurur
Ogr ogrBilgileriniAl(void)
{
    Ogr ogr;
    printf("ad not1 not2 not3 seklinde ogrenci bilgilerini giriniz: ");
    scanf("%s %f %f %f", ogr.ad, &ogr.notlar[0], &ogr.notlar[1], &ogr.notlar[2]);
    printf("Ogrencinin dogum tarihini ");
    ogr.dogumTarihi = tarihiAl();
    return ogr;
}

// parametre olarak aldigi Ogr struct'ini duzgun bir sekilde ekrana bastirir
void ogrBilgileriniBastir(Ogr o)
{
    printf("Ogrencinin;\nAdi: %s\nDogum tarihi: ", o.ad);
    tarihiBastir(o.dogumTarihi);
    printf("1. notu: %f\n2. notu: %f\n3. notu: %f\n", o.notlar[0], o.notlar[1], o.notlar[2]);
}

// parametre olarak aldigi Ogr struct'indaki notlarin ortalamasini hesaplayip dondurur
float ogrOrtalamasiHesapla(Ogr o)
{
    float toplam = 0;
    for (int i = 0; i < M; i++)
    {
        toplam += o.notlar[i];
    }
    return toplam / (float)M;
}

// parametre olarak aldigi dizideki Ogrencilerin notlarinin agirlik tablosunda verilen degerlere gore genel ortalamasini hesaplayip dondurur
float snfOrtalamasiHesapla(Ogr snf[S], float agirlik[M])
{
    float genelToplam = 0;
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < M; j++)
        {
            genelToplam += snf[i].notlar[j] * agirlik[j];
        }
    }
    return genelToplam / (float)S;
}

// parametre olarak aldigi dizideki Ogrencilerin yas ortalamasini hesaplayip dondurur
float snfYasOrtalamasiHesapla(Ogr snf[S])
{
    float toplam = 0;
    for (int i = 0; i < S; i++)
    {
        toplam += bulundugumuzYil - (float)snf[i].dogumTarihi.yil;
    }
    return toplam / (float)S;
}