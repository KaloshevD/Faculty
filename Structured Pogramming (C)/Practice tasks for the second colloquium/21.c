/*
Од тастатура се чита природен број N (N < 400).

Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на следниот начин: во првата колона во правец од горе надолу, па продолжува во втората колона од долу нагоре, па продолжува во третата колона од горе надолу итн. Да се избере најмалата димензија на матрицата во која ќе ги собере сите броеви до N. Доколку има преостанати празни места, тие да се пополнат со нули.

Формираната матрица да се запише во датотека "shema.txt".


Пример.

Влез

22


Излез во датотеката "shema.txt"

1 10 11 20 21

2 9 12 19 22

3 8 13 18 0

4 7 14 17 0

5 6 15 16 0
*/#include <stdio.h>
#include <math.h>
void printFile() {

    FILE *f=fopen("shema.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main(){
    int n, i = -1, j, broj = 1;
    scanf("%d", &n);
    int m = ceil(sqrt(n));
    int matrica[m][m];
    for(j = 0; j < m; j++)
    {
        if(i == -1)
            for(i = 0; i < m; i++){
                if(broj <= n)
                    matrica[i][j] = broj++;
                else
                    matrica[i][j] = 0;
            }
        else if(i == m)
            for(i = m - 1; i >= 0; i--){
                if(broj <= n)
                    matrica[i][j] = broj++;
                else
                    matrica[i][j] = 0;
            }
    }
    FILE *pok = fopen("shema.txt", "w");
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++)
            fprintf(pok, "%d ", matrica[i][j]);
        fprintf(pok, "\n");
    }
    fclose(pok);
    printFile();
    return 0;
}