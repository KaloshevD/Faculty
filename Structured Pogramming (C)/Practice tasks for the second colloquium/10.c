/*Во датотеката podatoci.txt се запишани редови со низи од знаци (секој не подолг од 80 знаци).

Од стандарден влез се читаат два знака z1 и z2. Да се напише програма со која на стандарден излез ќе се испечатат поднизите од секој ред од датотеката составени од знаците што се наоѓаат меѓу z1 и z2 (без нив). Секоја подниза се печати во нов ред.

Се смета дека секој ред од датотеката точно еднаш ги содржи знаците z1 и z2, знакот z1 секогаш се наоѓа пред знакот z2, а меѓу z1 и z2 секогаш има барем еден знак.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("podatoci.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

void substring(char *x, char z1, char z2) {
    
    char *c1, *c2, newS[80];
    c1 = strchr(x, z1);
    c2 = strchr(x, z2);
    strncpy(newS, c1+1, c2-c1-1);
    newS[c2-c1-1] = '\0';
    
    /*int i, i1, i2;
    for(i=0; i<strlen(x); i++)
    {
        if(*(x+i)==z1)
          i1 = i;  
        if(*(x+i)==z2)
          i2 = i;  
    }
    strncpy(newS, x+i1+1, i2-i1-1);
    newS[i2-i1-1] = '\0';*/
    
	printf("%s\n", newS);
    
}

int main() {
    wtf();
    getchar();
	char z1, z2;
	char row[80];
    FILE* f;
    
    z1 = getchar();    
    z2 = getchar();
    
    if ((f = fopen("podatoci.txt", "r")) == NULL) {
   		printf("Datotekata %s ne se otvora.\n", "podatoci.txt");
   		return -1;
   	}
    
    while(fgets(row, 80,f)!=NULL) {
        substring(row, z1, z2);
    }
    
    fclose(f);
  
    return 0;
}