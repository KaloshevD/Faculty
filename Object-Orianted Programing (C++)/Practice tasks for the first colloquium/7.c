/*Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот). Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот. Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.*/
#include<stdio.h>
#include<string.h>

typedef struct Skilift Skilift;
typedef struct SkiCenter SkiCenter;

struct Skilift{
    char ime[15];
    int korisnici;
    int on;
};

struct SkiCenter{
    char ime[20];
    char drzava[20];
    Skilift niza[20];
    int brojSkilift;
};

void najgolemKapacitet(SkiCenter *sc, int n){
    int max = 0;
    int index;
    int skiliftovi;
    int maxSkiliftovi = 0;
    for(int i = 0; i < n; i++){
        int tmpMax = 0;
        for(int j = 0; j < sc[i].brojSkilift; j++){
            if(sc[i].niza[j].on == 1){
                tmpMax += sc[i].niza[j].korisnici;

            }
            if(max <= tmpMax)
            {
                index = i;
                max = tmpMax;
            }

        }
    }
    printf("%s\n%s\n%d",sc[index].ime, sc[index].drzava, max);
}

int main()
{
    int n,i;
	scanf("%d", &n);
    SkiCenter sc[20];
	for (i = 0; i < n; i++){
		//vnesi ime
        scanf("%s",sc[i].ime);
		//vnesi drzava
        scanf("%s",sc[i].drzava);

		//vnesi broj na liftovi
        scanf("%d",&sc[i].brojSkilift);

        for(int j = 0; j < sc[i].brojSkilift; j++){
            scanf("%s", sc[i].niza[j].ime);
            scanf("%d", &sc[i].niza[j].korisnici);
            scanf("%d", &sc[i].niza[j].on);

        }

	}
    najgolemKapacitet(sc, n);

	return 0;
}