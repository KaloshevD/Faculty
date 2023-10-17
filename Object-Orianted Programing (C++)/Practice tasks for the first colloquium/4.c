Во програмскиот јазик C да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

Фирма која го произведува ( низа од 100 знаци)
Големина на монитор во инчи (реален број)
Дали е со touch или не (булова променлива)
Цена (цел број)
Да се креира структура ITStore, што содржи: (5 поени)

Име на продавницата (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)

[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
Да се креира функција najeftina_ponuda, што прима низа од променливи од типот /*ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*

Да се дополни функцијата main (10 поени).

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.*/
#include "stdio.h"
#include "string.h"

typedef struct Laptop Laptop;
typedef struct ITStore ITStore;

struct Laptop{
    char firma[100];
    float golemina;
    int touch;
    int cena;
};
struct ITStore{
    char ime[100];
    char lokacaija[100];
    Laptop niza[100];
    int broj;
};


void print(ITStore *s, int n)
{
    for(int i = 0; i < n; i++){
        printf("%s %s\n",s[i].ime, s[i].lokacaija);
        for(int j = 0 ; j < s[i].broj; j++){
            printf("%s %g %d\n", s[i].niza[j].firma, s[i].niza[j].golemina, s[i].niza[j].cena);
        }
    }
}
void najeftina_ponuda(ITStore *s, int n){
    int cena=90000;
    int index;
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].broj; j++){
            if(s[i].niza[j].cena < cena && s[i].niza[j].touch == 1){
                cena = s[i].niza[j].cena;
                index = i;
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n",s[index].ime, s[index].lokacaija);
    printf("Najniskata cena iznesuva: %d", cena);
}

int main() {
    ITStore s[100];
    int n;
    scanf("%d",&n); //broj na IT prodavnici
        for(int i = 0; i < n; i++){
            scanf("%s",s[i].ime);
            scanf("%s",s[i].lokacaija);
            scanf("%d",&s[i].broj);
            for(int j = 0; j < s[i].broj; j++){
                scanf("%s",s[i].niza[j].firma);
                scanf("%f",&s[i].niza[j].golemina);
                scanf("%d",&s[i].niza[j].touch);
                scanf("%d",&s[i].niza[j].cena);
            }
    }
    print(s, n);
    najeftina_ponuda(s, n);

    return 0;
}