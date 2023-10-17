/*За програмски јазик да се употреби C.


Да се креира структура Engine во која што ќе се чуваат податоци за коњска сила / horsepower (int) и вртежен момент / torque (int).


Потоа, да се креира структура Car во која што ќе  се чуваат податоци името на производителот (char array) , која година е произведена колата (int) и кој мотор / engine (Engine) која што го користи.


На почетокот се внесува број N што озналува колку коли ќе се читаат од влез.


Да се направи функцијата:


void printCars(...)


која што ќе ги земе двете коли кои имаат најмала коњска сила, и од нив две, ќе ја испечати колата што има поголем вртежен момент.
*/
#include <stdio.h>

typedef struct Engine {
    int hp;
    int torq;
}Engine;

typedef struct Car{
    char ImeKola[100];
    int godina;
    Engine motor;
}Car;

void printCar(Car koli[],int n){
    int a,b,i,j,min,nextmin;
    min = koli[0].motor.hp;
    nextmin = koli[0].motor.hp;
    
    for(i = 0; i < n; i++){
        if(koli[i].motor.hp < min){
            min = koli[i].motor.hp;
            a = i;
        }
    }
    
    
    for(i = 0; i < n; i++){
        if((koli[i].motor.hp < nextmin) && (i != a))
        {
            nextmin = koli[i].motor.hp;
            b = i;
        }
    }
   
    if(koli[a].motor.torq > koli[b].motor.torq)
    {
        printf("Manufacturer: %s\n",koli[a].ImeKola);
        printf("Horsepower: %d\n",koli[a].motor.hp);
        printf("Torque: %d\n",koli[a].motor.torq);
    }
    else
    {
        printf("Manufacturer: %s\n",koli[b].ImeKola);
        printf("Horsepower: %d\n",koli[b].motor.hp);
        printf("Torque: %d\n",koli[b].motor.torq);
    }
}

int main(){
    
    int j,n,i;
    scanf("%d", &n);
    Car koli[n];
    for(i = 0; i < n; i++){
        scanf("%s\n%d\n%d\n%d", koli[i].ImeKola, &koli[i].godina, &koli[i].motor.hp, &koli[i].motor.torq);
    }
    printCar(koli,n);
    
}