/*
ADI SOYADI:Emir Taþdemir
ÖÐRENCÝ NO:02210224024
ÖDEV-1
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *sonraki;
};

struct Node* ilk=NULL;

int boyut=0;

void ElemanEkle(int veri,int siraNo) { //kullanicin istedigi siraya ekleme yapilacak
    int sayac=0;
    struct Node *yeni;//yeni dugum atadik
    yeni=(struct Node*)malloc(sizeof(struct Node));//yer ayirdik
    yeni->data=veri;
    yeni->sonraki=NULL;

    if(siraNo==1) { //1. sira girme durumu ele alindi
        if(ilk==NULL) { 
            ilk=yeni;
        }
        else {
            yeni->sonraki=ilk;//listede 1. sira doluyken 1 girilirse
            ilk=yeni;
        }
    }
    else if(boyut>=siraNo) {
        struct Node *gecici=ilk;
        sayac=2;
        while(sayac<siraNo) {//siranin sayactan buyuk girilmesi
            gecici=gecici->sonraki;
            sayac++;
        }
        yeni->sonraki = gecici->sonraki;//baglantilar yapildi
        gecici->sonraki=yeni;
    }
    else {
        if(ilk==NULL) {
            ilk=yeni;
        }
        else {
            struct Node *gecici2=ilk;
            while(gecici2->sonraki!=NULL) {
                gecici2=gecici2->sonraki;
            }
            gecici2->sonraki=yeni;
        }
    }
    boyut++;
}
void ElemanSil(int siraNo) {
    struct Node*gecici2;
    int i=1;

    if(ilk==NULL) { //liste bos ise
        printf("\n!..Liste Bos..!\n");
    }
    else {
        if(siraNo==1) { //ilk eleman silinirse
            struct Node* gecici=ilk;
            ilk=ilk->sonraki;
            free(gecici);
        }
        else {
            struct Node*silinecek;

            gecici2=ilk;
            while(i<siraNo ) { //diger elemanlari silme islemi
                gecici2=gecici2->sonraki;
                i++;
            }
            silinecek=gecici2->sonraki;
            gecici2->sonraki=silinecek->sonraki;
            free(silinecek);
        }
    }
}
void ElemanAra(int siraNo) {
    int ara;
    int i=1;

    if(ilk==NULL) {
        printf("!..Liste Bos..!");
    }
    else
    {
        struct Node* gecici=ilk;//geciciyi ilk elemana atadik

        while(i<siraNo) {
            if(gecici->sonraki==NULL) {
                printf("Eleman bulunamadi.\n");
                return;
            }
            else {
                gecici=gecici->sonraki;
                i++;
            }
        }
        ara=gecici->data;
        printf("%d\n",ara);
    }
}
void Yazdir() {
    printf("\nLÝSTE:");
    if(ilk==NULL) {
        printf("!..Liste Bos..!");
    }
    else {
        struct Node* gecici=ilk;
        while(gecici!=NULL) {
            printf("%d-->",gecici->data);
            gecici=gecici->sonraki;
        }
    }
    printf("NULL");
    printf("\n");
}
void OrtadakiEleman() {
    struct Node *q=ilk;
    int elemanSayisi=0;
    while(q) { //listeyi gezdir eleman sayisi bul
        q=q->sonraki;
        elemanSayisi++;
    }
    int orta;
    orta=elemanSayisi/2;//eleman sayisinin yarisini alip ortayi bul
    q=ilk;

    int i;
    for(i=1; i<orta+1; i++)
        q=q->sonraki;

    printf("Listenin Ortasindaki Eleman:\n");
    printf("%d\n",q->data);
}
int TamSayiyaDonustur() {
    struct Node* gecici=ilk;
    int a=1,b=0;
    //eleman sayisi kadar basamak degeri eklendi
    while(gecici->sonraki!=NULL) {
        gecici=gecici->sonraki;
        a=a*10;
    }
    gecici=ilk;
    while(gecici->sonraki!=NULL) {
        int toplam=gecici->data;
        if (a>=10) {
            toplam=toplam*a;//10 ile carp
            b=b+toplam;
            a=a/10;
        }
        gecici=gecici->sonraki;
    }
    b=b+gecici->data;
    return b;
}
int main() {
    int secim;
    int rakam;
    int birlestir;
    int sira;
    do {
        printf("\n----------------\n");
        printf("~~~MENU~~~\n");
        printf("----------------\n");
        printf("(1)EKLEME YAPMAK ÝCÝN.\n");
        printf("(2)SILME YAPMAK ÝCÝN.\n");
        printf("(3)ELEMAN ARAMAK ÝCÝN.\n");
        printf("(4)LISTEYI YAZDIRMAK ÝCÝN.\n");
        printf("(5)ORTADAKI SAYIYI BULMAK ÝCÝN.\n");
        printf("(6)TAM SAYIYA DONUSTURMEK ÝCÝN.\n");
        printf("(-1)CIKIS.\n");
        printf("LUtfen Islem Seciniz:");
        scanf("%d",&secim);
        int sayi,sira2;
        switch(secim) {
        case 1:
            printf("Eklemek Ýstediginiz Sayiyi Giriniz:");
            scanf("%d",&rakam);
            printf("Eklemek Ýstediginiz Sirayi Giriniz:");
            scanf("%d",&sira);
            ElemanEkle(rakam,sira);
            Yazdir();
            break;

        case 2:
            printf("Silmek Ýstediginiz Sirayi Seciniz:");
            scanf("%d",&sira2);
            ElemanSil(sira2);
            Yazdir();
            break;

        case 3:
            printf("Aradiginiz Elemanin Sirasini Giriniz:");
            scanf("%d",&sira);
            ElemanAra(sira);
            break;

        case 4:
            Yazdir();
            break;

        case 5:
            OrtadakiEleman();
            break;

        case 6:
            birlestir=TamSayiyaDonustur();
            printf("%d\n",birlestir);
            break;
        case -1:
          printf("Cikis");
		  return;
          
     
        }
    }
    while(secim=-1);
}
