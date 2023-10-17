/*Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број на цифри. Обратен број е бројот составен од истите цифри, но во обратен редослед (на пример, 653 е обратен број на бројот 356). Од тастатура се внесува природен број n ( n > 9). Да се најде и отпечати најголемиот природен број помал од n кој што е „интересен“. Ако внесениот број не е валиден, да се отпечати соодветна порака (Brojot ne e validen). */
#include <stdio.h>
int main (){
    int broj,cifra;
    scanf("%d", &broj);
    if(broj>9){
        broj--;
        while(broj>0)
        {
            int n=broj, n2=broj, obraten=0,brojac=0;
            
            while(n!=0){
                cifra=n%10;
                obraten = obraten * 10 + cifra;
                n/=10;
            }
            do{
                brojac++;
                n2/=10;
            }while(n2!=0);
            
           
            
            if(obraten%brojac==0)
            {
                printf("%d", broj);
                break;
            }
            broj--;
        }
    }
    else {
        printf("Brojot ne e validen");
    }
    
    return 0;
}