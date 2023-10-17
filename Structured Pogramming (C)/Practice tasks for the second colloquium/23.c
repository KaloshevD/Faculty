/*Од тастатура се внесуваат димензиите m и n на матрица од цели броеви, Аmxn, ( 0 < m, n < 30 ) и нејзините елементи. Потоа се внесуваат два цели броја r и k  (индекси на редица/колона од матрицата, т.е. 0 <= r < m и 0 <= k < n).

Да се напише програма која ja трансформира матрицата А така што елементите над редицата r и лево од колоната k се заменуваат со минималната вредност од матрицата А.

Новодобиената матрица да се запише во датотека "matrica.txt".

Пример

Влез

4 6 // m и n

2 3 // r и k

1 2 3 4 5 1             

2 9 4 5 1 3

4 5 6 7 3 2

1 2 3 3 2 8

 

Излез во датотека "matrica.txt"

1 1 1 4 5 1   

1 1 1 5 1 3

4 5 6 7 3 2

1 2 3 3 2 8

*/
#include <stdio.h>
void printFile() {

    FILE *f=fopen("matrica.txt","r");
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
    int n, i, j, m, r, k, mini;
    int mat[30][30];
    scanf("%d%d", &m, &n);
    scanf("%d%d", &r, &k);
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if(i == 0 && j == 0)
                mini = mat[i][j];
            else if(mat[i][j] < mini)
                mini = mat[i][j];
        }
    for(i = 0; i < r; i++)
        for(j = 0; j < k; j++)
            mat[i][j] = mini;
    FILE *pok = fopen("matrica.txt", "w");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            fprintf(pok, "%d ", mat[i][j]);
        fprintf(pok, "\n");
    }
    fclose(pok);
    printFile();
    return 0;
}
