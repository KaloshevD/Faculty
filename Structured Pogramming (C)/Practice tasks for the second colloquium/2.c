/*
Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1) што означува колку броеви следуваат по него во тој ред. Да се напише програма која на СИ за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита 0.
*
/#include <stdio.h>
#include <string.h>
#define MAX 100

void wtf() {
    FILE *f = fopen("broevi.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int digit(int n) {
    while(n >= 10) {
        n /= 10;
    }
    return n;
}

int main()
{
    wtf();
    
    FILE* f = fopen("broevi.txt", "r");
    int i;
    while(!feof(f)) {
        int n, x;
        fscanf(f, "%d", &n);
        if(n == 0) break;
        int max = 0;
        int maxN = 0;
        for(i = 0; i < n; ++i) {
            fscanf(f, "%d", &x);
            int y = digit(x);
            if(y > max) {
                max = y;
                maxN = x;
            }
        }
        printf("%d\n", maxN);
    }   
    
    fclose(f);
    return 0;
	
}