/*Да се креира структура Proizvod во која се чуваат податоци за кодот напрозиводот (низа од 20 знаци), единична цена на производ (цел број), бројот на достапни производи кои ги има во еден магацин (цел број) .

Потоа да се креирa структура Narachka во која се чуваат податоци за името лицето кое ја прави нарачката (низи од 15 знаци), низа од Proizvodi (максимум 10) кои ги има во нарачката, низа од бројот на нарачани производи за секоја производ посебно (максимум10) и бројот на производи во нарачката .

Треба да се направи функција со потпис

void pecatiFaktura(Narachka n)

која што ќе ги отпечати една фактура за една нарачка (n) .

Во фактурата во првиот ред се печати: Faktura za XXXXX, каде XXXXX е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат печатат нарачаните производи, подредени по азбучен ред според кодот на производот. Во следните редови, во секој ред посебно се печати кодот на производот, единична цена на производот, број на нарачани производи и вкупната цена на производот (сите се одделени со едно празно место) . Исто така бројот на достапни производи од тој производ да се ажурира (да се намали за бројот на нарачани производи од тој производ). Во последниот ред да се отпечати: Vkupnata suma na fakturata e XXX, каде XXX е вкупната сума за цените за сите нарачани производи.

Ако постои производ кој не може да биде нарачан затоа што во магацинот не се достапни нарачаниот број производи тогаш не може да се изготви фактура за нарачката. На екранот да се отпечати: Fakturata ne moze da se izgotvi.*/
#include <stdio.h>
#include <string.h>

typedef struct Proizvod Proizvod;
typedef struct Narachka Narachka;

struct Proizvod{
    char kod[20];
    int cena;
    int dostapniProizvodi;
};

struct Narachka{
    char ime[15];
    Proizvod proizvodi[10];
    int nizaNaracki[10];
    int brojNaracki;
};

void pecatiFaktura(Narachka n)
{
    printf("Faktura za %s\n",n.ime);
    for(int i = 0; i < n.brojNaracki; i++){
        if(n.proizvodi[i].dostapniProizvodi < n.nizaNaracki[i]){
            printf("Fakturata ne moze da se izgotvi");
            return ;
        }
    }

    for(int i = 0; i < n.brojNaracki-1; i++){
        Proizvod tmp;
            if(strcmp(n.proizvodi[i].kod, n.proizvodi[i+1].kod) > 0){
                tmp = n.proizvodi[i];
                n.proizvodi[i] = n.proizvodi[i+1];
                n.proizvodi[i+1] = tmp;
            }
    }

    int fullcena = 0;
    for(int i = 0; i < n.brojNaracki; i++){
        int sobir = n.proizvodi[i].cena * n.nizaNaracki[i];
        printf("%s %d %d %d\n",n.proizvodi[i].kod, n.proizvodi[i].cena, n.nizaNaracki[i], sobir);
        fullcena = fullcena + sobir;
    }
    printf("Vkupnata suma na fakturata e %d",fullcena);
}



int main() {

    Narachka narachka;

    // внеси го името лицето кое ја прави нарачката
    scanf("%s",narachka.ime);
    // внеси го бројот на порачани производи во нарачката
    scanf("%d",&narachka.brojNaracki);
    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.brojNaracki; ++i) {
        scanf("%s",narachka.proizvodi[i].kod);
        // внеси единицчна цена
        scanf("%d",&narachka.proizvodi[i].cena);
        // внеси број на производи во магацин
        scanf("%d",&narachka.proizvodi[i].dostapniProizvodi);
    }
    //за секој производ се внесува колку такви производи се порачани во нарачката
    int j;
    for (j = 0; j < narachka.brojNaracki; ++j) {
       //се внесува број на производи во нарачката
       scanf("%d",&narachka.nizaNaracki[j]);
    }

    pecatiFaktura(narachka);
    // повик на функцијата pecatiFaktura


    return 0;
}