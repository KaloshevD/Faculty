/*Од стаднарден влез се читаат N низи од знаци (стрингови) не подолги од 80 знаци. На почетокот на програмата се читаат два цели броеви:

N - бројот на низи од знаци кои ќе се читаат и
X - поместување.
Секоја од вчитаните низи од знаци треба да се трансформира на тој начин што секоја од малите и големите букви (a-z, A-Z) се заменува со истата буква поместена X места понапред во азбуката (a-z). Ако се надмине опсегот на буквите во азбуката, се продолжува циклично од почетокот на азбуката. Трансформираната низа да се отпечати на СИ.

Трансформацијата да се имплементира со посебна рекурзивна функција.

Пример:

Welcome -> трансформирано со поместување 5 -> Bjqhtrj
*/
#include <stdio.h>

void cipher(char *word, int x) {
    if(*word == 0) return;
    if(isalpha(*word)) {
        char first = 'a';
        if(isupper(*word))
            first = 'A';
        *word = first + (*word + x -first) % 26;    
    }
    cipher(++word, x);
}

int main() {
    int n, x;
    scanf("%d %d\n", &n, &x);
    int i;
    char word[80];
    for(i = 0; i < n; ++i) {
        gets(word);
        cipher(word, x);
        printf("%s\n", word);
    }
    return 0;
}


    else 
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == n/2 && j == n/2)
                {
                    B[i][j]= zbirX + zbirY;
                    printf("%.1lf ",B[i][j]);
                }
                else if(i==j)
                {
                    B[i][j]=zbirX;
                    printf("%.1lf ",B[i][j]);
                }
                else if(i+j==n-1)
                {
                    B[i][j]=zbirY;
                    printf("%.1lf ",B[i][j]);
                }
                else
                {
                    B[i][j]=0;
                    printf("%.1lf ",B[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}