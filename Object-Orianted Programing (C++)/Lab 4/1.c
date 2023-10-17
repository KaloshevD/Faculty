/*Во програмскиот јазик C да се креира структура UmetnickoDelo за опишување на уметничко дело во дадена галерија. Структурата треба да содржи: (5 поени)

Автор (низа од 100 знаци)
Цена(реален број)
Тип на уметничко дело (цел број со вредност 1 за слика, 2 за скулптура)
Да се креира структура Galerija, што содржи: (5 поени)

Име на галеријата (низа од 50 знаци)
Низа од достапни уметнички дела (низа од максимум 30 елементи од структурата UmetnickoDelo)
Број на елементи во низата (цел број)
Да се креира глобална функција print за печатење на информациите за дадена галерија во следниот формат: (10 поени)

[Ime na galerijata]

[Avtor1] [Cena1] [Tip1]

[Avtor2] [Cena2] [Tip2]

[Avtor3] [Cena3] [Tip3]

...

Да се креира функција najdobra_ponuda, што прима низа од променливи од типот Galerija, и променлива tipNaDelo. Оваа функција треба да го испечати името на галеријата која ја нуди најевтината уметничка слика (за променлива со вредност 1) и името на галеријата која ја нуди најевтината скулптура (за променлива со вредност 2). Најевтино уметничко дело е уметничкото дело кое има најнска цена. Ако има повеќе такви галерии со најевтино уметничко дело, се печати последната.(15 поени)
/*
#include <stdio.h>

typedef struct UmetnickoDelo UmetnickoDelo;
typedef struct Galerija Galerija;

struct UmetnickoDelo{
    char avtor[100];
    float cena;
    int tip;
};

struct Galerija{
    char ime[50];
    UmetnickoDelo niza[30];
    int broj;
};


void print(Galerija *g, int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", g[i].ime);
        for(int j = 0; j < g[i].broj; j++){
            printf("%s %.2f %d\n",g[i].niza[j].avtor, g[i].niza[j].cena, g[i].niza[j].tip);
        }
    }
}
void najdobra_ponuda(Galerija *g, int n, int SentTip){
    float min = 80000;
    int index = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].broj; j++){
            if(g[i].niza[j].tip == SentTip){
                if(min >= g[i].niza[j].cena){
                    min = g[i].niza[j].cena;
                    index = i;
                }
            }
        }
    }
    if(index >= 0){
            if(SentTip == 1){
                printf("Najevtino umetnicko delo tip slika go nudi galerijata: %s so cena: %.2f", g[index].ime, min);
            }
            else{
                printf("Najevtino umetnicko delo tip skulptura go nudi galerijata: %s so cena: %.2f", g[index].ime, min);
            }
        }

        else{
            printf("Ne e pronajdeno umetnicko delo od tip skulptura");
        }
    }

int main() {
    int n;
    scanf("%d",&n); //broj na Galerii
    Galerija g[n];
    for(int i = 0; i < n; i++){
        scanf("%s", g[i].ime);
        scanf(" %d", &g[i].broj);
        for(int j = 0; j < g[i].broj; j++){
            scanf("%s", g[i].niza[j].avtor);
            scanf("%f", &g[i].niza[j].cena);
            scanf("%d",&g[i].niza[j].tip);
        }
    }
    //vnesuvanje na galeriite, zaedno so raspolozlivite podatoci



    //pecatenje na prodazni saloni
    print(g, n);



    //povik na glavnata metoda
    int tipNaDelo;
    scanf("%d",&tipNaDelo);
    najdobra_ponuda(g, n, tipNaDelo);

    return 0;
}