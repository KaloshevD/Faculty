/*Од стандарден влез се читаат непознат број на хексадецимални цифри се додека не се внесе точка (.). Ваша задача е да го пресметате декадниот збир на внесените хексадецимални цифри. Доколку добиениот декаден збир е делив со 16 се печати Pogodok. Доколку истиот тој збир покрај што е делив со 16 плус завршува на 16 (последните цифри му се 1 и 6), се печати Poln pogodok инаку се печати самиот збир.

Пример:

влез: A 7 F 2 0 c A 5

излез: 61

(61 = 10 + 7 + 15 + 2 + 0 + 12 + 10 + 5, бројот не е делив со 16, ниту пак последните цифри му се 1,6)*/
#include <stdio.h>
int main(){
    int rezultat=0;
    int broj=0;
    char a;
    while(1)
    {
        scanf("%c",&a);
        if(a == '.')
        {
            break;
        }
        if(a == 'a' || a == 'A')
        {
            broj = 10;
            rezultat = rezultat + broj;
           
        }
        if(a == 'b' || a == 'B')
        {
            broj = 11;
            rezultat = rezultat + broj;
            
        }
        if(a == 'c' || a == 'C')
        {
            broj = 12;
            rezultat = rezultat + broj;
            
        }
        if(a == 'd' || a == 'D')
        {
            broj = 13;
            rezultat = rezultat + broj;
           
        }
        if(a == 'e' || a == 'E')
        {
            broj = 14;
            rezultat = rezultat + broj;
        }
        if(a == 'f' || a == 'F')
        {
            broj = 15;
            rezultat = rezultat + broj;
          
        }
        if(a >= '0' && a <= '9')
        {
            broj= a-48;
            rezultat = rezultat + broj;
            
        }
        
    }
    
    if(rezultat % 16 == 0)
    {
        if(rezultat%10 == 6 && rezultat/10%10 == 1)
        {
            printf("Poln pogodok");
        }
        else{
            printf("Pogodok");
        }
    }
    else{
        printf("%d", rezultat);
    }
    return 0;
}