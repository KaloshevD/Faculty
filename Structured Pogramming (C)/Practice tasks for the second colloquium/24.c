/*Еден елемент се заматува ако се најде аритметичка средина на елементот и сите негови соседи. Сосед на еден елемент се сите елементи кои припаѓаат на матрицата и се  околу истиот елемент (хоризонтално, вертикално и дијагонално). 

Во датотеката input.txt е сместена матрица од реални броеви (3 < n,m < 50). Во првиот ред се дефинирани бројот на редици и колони на матрицата и во секој преостанат ред е внесен еден ред од матрицата (види пример).По читањето на матрицата, од стандарден влез се внесуваат и 2 пара координати на матрицата (ред и колона) кои го репрезентираат горниот-лев и долниот-десен елемент од регионот. Потребно е да генеирате нова матрица во која ќе ги заматите сите елементи кои припаѓаат на регионот. 
Новодобиената матрица, во истиот формат, треба да се запише во датотеката output.txt.

Пример:
датотека: input.txt

3 4
1.00 2.00 3.00 4.00
5.00 6.00 7.00 8.00
9.00 0.00 1.00 2.00

Стандарден влез:

0 1
2 2
Резултат:

датотека: output.txt
3 4
1.00 4.00 5.00 4.00
5.00 3.78 3.67 8.00
9.00 4.67 4.00 2.00

*/
#include <stdio.h>
#include <math.h>

#define MAX 50

void printFile() {

    FILE *f=fopen("output.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

void wtf(){
    FILE *f=fopen("input.txt","w");

    int row,column,i,j;
    float el;
    scanf("%d %d", &row, &column);

    fprintf(f,"%d %d\n",row, column);

    for (i=0; i<row; ++i){
        for (j=0; j<column; ++j){
            scanf("%f", &el);
            fprintf(f, "%.2f ", el);
        }
        fputc('\n',f);
    }
    fclose(f);

    return;
}

int main(){
    wtf();

    FILE *f = fopen("input.txt","r");

    int i,j, row, column;

    if (f==NULL){
        printf("Can't open the file");
        return -1;
    }

    float a[MAX][MAX];
    float b[MAX][MAX];

    fscanf(f,"%d %d\n",&row, &column);

    for (i=0; i<row; ++i){
        for (j=0; j<column; ++j){
            fscanf(f,"%f", &a[i][j]);
            b[i][j] = a[i][j];
        }
    }

    int br,bc;
    int er, ec;
    scanf ("%d %d", &br, &bc);
    scanf ("%d %d", &er, &ec);

    int count = 0;
    for(i = br; i <= er; i++){
        for(j = bc; j <= ec; j++){
            count=0;
            if (i==0 && j==0 ){

                b[i][j] +=  a[i+1][j] +
                        a[i+1][j+1] +
                        a[i][j+1];

                count = 4;
            }
            else if (i==0 && j==(column-1) ){
                b[i][j] +=   a[i+1][j] +
                        a[i+1][j-1] +
                        a[i][j-1];

                count = 4;
            }
            else if (i==(row-1) && j==0 ){
                b[i][j] +=   a[i-1][j] +
                        a[i-1][j+1] +
                        a[i][j+1];

                count = 4;
            }
            else if (i==(row-1) && j==(column-1) ){
                b[i][j] +=   a[i-1][j] +
                        a[i-1][j-1] +
                        a[i][j+-1];

                count = 4;
            }
            else if (i==0) {
                b[i][j] += a[i][j-1] +
                        a[i][j+1] +
                        a[i+1][j-1] +
                        a[i+1][j] +
                        a[i+1][j+1];

                count = 6;
            }
            else if (i==(row-1)) {
                b[i][j] += a[i][j-1] +
                        a[i][j+1] +
                        a[i-1][j-1] +
                        a[i-1][j] +
                        a[i-1][j+1];

                count = 6;
            }
            else if (j==0) {
                b[i][j] += a[i-1][j] +
                        a[i+1][j] +
                        a[i-1][j+1] +
                        a[i+1][j+1] +
                        a[i][j+1];

                count = 6;
            }
            else if (j==(column-1)) {
                b[i][j] += a[i-1][j] +
                        a[i+1][j] +
                        a[i-1][j-1] +
                        a[i+1][j-1] +
                        a[i][j-1];

                count = 6;
            }
            else {
                b[i][j] +=
                        a[i-1][j-1] +
                        a[i-1][j] +
                        a[i-1][j+1] +
                        a[i][j-1] +
                        a[i][j+1] +
                        a[i+1][j-1] +
                        a[i+1][j] +
                        a[i+1][j+1];

                count = 9;
            }

            b[i][j]/=count;

        }
    }

    FILE *pok = fopen("output.txt", "w");
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++)
            fprintf(pok, "%.2f ", b[i][j]);
        fprintf(pok, "\n");
    }
    fclose(pok);

    //
    printFile();

    return 0;
}
