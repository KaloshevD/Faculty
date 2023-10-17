/*За програмски јазик да се употреби C.

Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen
*/
#include <stdio.h>

typedef struct Transaction{
    int id;
    int sum;
    int prvz;
    int plateno;
    
}Transaction;

int main() {
    int i,n,l=0;
    Transaction t;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &t.id, &t.sum, &t.prvz, &t.plateno);
        if(t.plateno > 0){
            l = 1;
            printf("%d %d\n", t.id, t.sum+t.prvz);
        }
    }
    if(l == 0){
        printf("No credit card transaction");
    }
    return 0;
}