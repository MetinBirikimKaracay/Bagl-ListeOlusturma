#include<stdio.h>
#include<stdlib.h>

struct dugum{
    int veri;
    struct dugum *sonraki;
};

struct dugum* baslangic = NULL;
struct dugum *sonraki= NULL;
struct dugum *temp = NULL;

void sonaEkle(int sona){

    struct dugum* eklenecek = (struct dugum*)malloc(sizeof(struct dugum));

    eklenecek->veri = sona;
    eklenecek->sonraki = NULL;

    if(baslangic == NULL){
        baslangic = eklenecek;
    }
    else{
        temp = baslangic;
        while(temp->sonraki !=NULL){
            temp = temp-> sonraki;
        }
        temp-> sonraki = eklenecek;
    }
}

void basaEkle(int basa){
    struct dugum* basaGelecek = (struct dugum*)malloc(sizeof(struct dugum));
    basaGelecek-> veri = basa;
    basaGelecek-> sonraki = baslangic;
    baslangic = basaGelecek;
}

void arayaEkle(int x, int y){
    struct dugum* arayaEklenecek = (struct dugum*)malloc(sizeof(struct dugum));
    arayaEklenecek->veri = y;
    temp = baslangic;
    while(temp-> sonraki->veri != x){
        temp = temp->sonraki;
    }
    struct dugum* arkasina = (struct dugum*)malloc(sizeof(struct dugum));
    arkasina = temp-> sonraki;
    temp-> sonraki = arayaEklenecek;
    arayaEklenecek-> sonraki = arkasina;
}

void yazdir(){

    temp = baslangic;
    while(temp-> sonraki !=NULL){
        printf("%d => ", temp->veri);
        temp = temp-> sonraki;
    }
    printf("%d => ",temp->veri);
}

void sonSil(){

    temp = baslangic;
    while(temp->sonraki->sonraki != NULL){
        temp = temp->sonraki;
    }
    free(temp->sonraki);
    temp->sonraki = NULL;
}

void bastanSil(){

    temp = baslangic;
    baslangic = temp-> sonraki;
    free(temp);
}

void aradanSil(int a){

    struct dugum* onceki = (struct dugum*)malloc(sizeof(struct dugum));
    struct dugum* next = (struct dugum*)malloc(sizeof(struct dugum));
    temp = baslangic;
    while(temp-> sonraki->veri != a){
        temp = temp-> sonraki;
    }
    onceki = temp;
    next = temp->sonraki->sonraki;
    free(temp-> sonraki);
    onceki-> sonraki = next;

}

void tersCevir(){

    struct dugum* gecici;
    struct dugum* geri = NULL;
    temp = baslangic;

    while(temp != NULL){
        gecici = temp->sonraki;
        temp->sonraki = geri;
        geri = temp;
        temp = gecici;
    }
    baslangic = geri;

}

int main(){
    int girdi, sona, basa, x, y, a;
    while(1==1){
        printf("\n---------------------------------------");
        printf("\n1-) Basa Eklenecek Sayiyi Giriniz...\n");
        printf("\n2-) Sona Eklenecek Sayiyi Giriniz...\n");
        printf("\n3-) Araya Eklemek Icin Secininiz...\n");
        printf("\n4-) Sondan Eleman Silmek Icin Seciniz...\n");
        printf("\n5-) Bastan Eleman Silmek Icin Seciniz...\n");
        printf("\n6-) Aradan Eleman Silmek Icin Seciniz...\n");
        printf("\n7-) Listeyi Ters Cevirmek Icin Seciniz...\n");
        printf("---------------------------------------\n");
        scanf("%d", &girdi);

        switch(girdi){

        case 1:
            printf("Basa eklemek istediginiz sayiyi giriniz...");
            scanf("%d", &basa);
            basaEkle(basa);
            yazdir();
            break;
        case 2:
            printf("Sona eklemek istediginiz sayiyi giriniz...");
            scanf("%d", &sona);
            sonaEkle(sona);
            yazdir();
            break;
        case 3:
            printf("Hangi Sayidan Once Eklemek Istersiniz...\n");
            scanf("%d", &x);
            printf("Araya Eklemek istediginiz sayiyi giriniz...");
            scanf("%d", &y);
            arayaEkle(x,y);
            yazdir();
            break;
        case 4:
            printf("Son Elemani Sildiniz...\n");
            sonSil();
            yazdir();
            break;
        case 5:
            bastanSil();
            yazdir();
            break;
        case 6:
            printf("Hangi Sayiyi Silmek istersiniz?..");
            scanf("%d", &a);
            aradanSil(a);
            yazdir();
            break;
        case 7:
            tersCevir();
            yazdir();
            break;
        }

    }
}
