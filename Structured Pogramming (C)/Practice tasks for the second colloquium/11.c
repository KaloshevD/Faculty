/*Да се напише програма во која од дадена датотека со име "input.txt" за секој ред ќе се отпечати бројот на цифри во тој ред, знакот :, па самите цифри подредени според ASCII кодот во растечки редослед. Редовите во датотеката не се подолги од 100 знаци.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

void sort(char a[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp; 
            }
        }
    }
}

int main() {
    wtf();
    FILE *pok = fopen("input.txt","r");
    char nizaChar[100];
    char nizaChar2[100];
    int i,j;
    while((fgets(nizaChar,100,pok)) != NULL)
    {
        j = 0;
        for(int i = 0; i < strlen(nizaChar); i++)
        {
            if(nizaChar[i] >= '0' && nizaChar[i] <= '9')
            {
                nizaChar2[j] = nizaChar[i];
                j++;
            }
        }
        sort(nizaChar2,j);
        printf("%d:", j);
        for(int i = 0; i < j; i++)
        {
            printf("%c",nizaChar2[i]);
        }
        printf("\n");
    }
    fclose(pok);
    return 0;
}
