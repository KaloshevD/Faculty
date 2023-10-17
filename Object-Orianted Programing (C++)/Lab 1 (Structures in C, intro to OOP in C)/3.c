/*За програмски јазик да се употреби C.

Да се напише програма во која од стандарден влез се внесува бројот N (бројот на фудбалски тимови) и информациите за N-те фудбалски тимови.

Една структура за Фудбалски тим (FootballTeam) треба да ги чува следните информации:
- Името на тимот (низа од карактери)
- Низа од играчи (претставени преку структурата FootballPlayer, при што еден тим секогаш ќе има 11 играчи)

Во структурата Фудбалски играч (FootballPlayer) треба да се чуваат следните информации:
- Името на играчот (низа од карактери)
- Број на дресот (int)
- Број на дадени голови (int)

Ограничување: 0 < N < 100

Ваша задача е да направите функција void bestTeam(FootballTeam * teams, int n) која ќе го печати тимот со најмногу дадени голови (во случај да има повеќе тима со ист број на голови треба да се печати првиот што е внесен). Внесувањето на податоците да се направи во main-от, при што редоследот на влезните податоци ќе е следниот:

N
team_name_1
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
team_name_2
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11

...

team_name_n
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
*/
#include <stdio.h>

typedef struct FootballPlayer{
    char NameOfPlayer[100];
    int KitNumber;
    int Goals;
}FootballPlayer;


typedef struct FootballTeam{
    char NameOfTeam[100];
    FootballPlayer igraci[100];
}FootballTeam;

void bestTeam(FootballTeam * teams, int n){
    int max,i,j,fin = 0 ,a;
    for(i = 0; i < n; i++){
        max = 0;
        for(j = 0; j < 11; j++){
            max += teams[i].igraci[j].Goals;
        }
        if(max > fin){
            fin = max;
            a = i;
        }
    }
    printf("Najdobar tim e: %s", teams[a].NameOfTeam);
}

int main(){
    
    int n;
    scanf("%d", &n);
    FootballTeam teams[100];
    for(int i = 0; i < n; i++){
        scanf("%s",teams[i].NameOfTeam);
        for(int j = 0; j < 11; j++){
            scanf("%s", teams[i].igraci[j].NameOfPlayer);
            scanf("%d", &teams[i].igraci[j].KitNumber);
            scanf("%d", &teams[i].igraci[j].Goals);
        }
    }
    bestTeam(teams,n);
    return 0;
}