/*
Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.

На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).

Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:

ab12 1 1.25
Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).

Ваша задача е да се испечати типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.

Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.
*
#include <stdio.h>
#include <string.h>

void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
	float uplata;
	scanf("%f", &uplata);
    wf();
	// vasiot kod pocnuva od ovde
	FILE *pok = fopen("livce.txt", "r");
	char niza[10],nizaF[10];
	int tip,tipF;
	double koef;
	double max_koef=0;
	double sum_koef=1;
	while(!feof(pok)){
	    
	        fscanf(pok, "%s\n  %d\n %lf", niza,&tip,&koef);
	        if(max_koef < koef)
	        {
	            strcpy(nizaF,niza);
	            tipF = tip;
	            max_koef = koef;
	        }
	        sum_koef *= koef;
	}
	
	printf("%s %d %.2f\n",nizaF,tipF,max_koef);
	printf("%.2lf", uplata * (sum_koef/koef));
    
    fclose(pok);
	return 0;    

}