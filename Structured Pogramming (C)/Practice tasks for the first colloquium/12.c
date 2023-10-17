/*Од тастатура се читаат непознат број на позитивни цели броеви (со максимум 5 цифри) се додека не се внесе нешто различно од број. За секој број треба да се најде позицијата (од десно на лево) на првото појавување на најголемата цифра во составот на бројот (цифрата на единици се наоѓа на позиција 0). Потоа, да се испечати статистика за позициите на најдените цифри со максимална вредност во следниот формат:

[позиција]: [вкупно броеви чија максимална цифра се наоѓа на таа позиција]

0: 2

1: 3

2: 1

3: 1

4: 1


за броевите 97654 48654 12345 12343 1263 12443 12643 12777

 */
#include <stdio.h>
int main()
{
    int VnesenBroj,cifra=0,broj,max=0,brojA;
    int broj1=0,broj2=0,broj3=0,broj4=0,broj0=0;
    while(scanf("%d",&VnesenBroj))
    {
        int b=VnesenBroj;
        if(VnesenBroj>=100000)
        {
            break;
        }
        while(b!=0)
        {
            broj=b%10;
            if(broj>max)
            {
                max=broj;
                brojA=cifra;
            }
            b=b/10;
            cifra++;
        }
        
        if(brojA == 0)
        {
            broj0++;
        }
        if(brojA == 1)
        {
            broj1++;
        }
        if(brojA == 2)
        {
            broj2++;
        }
        if(brojA == 3)
        {
            broj3++;
        }
        if(brojA == 4)
        {
            broj4++;
        }
        max=0;
        cifra=0;
    }
    printf("0: %d\n", broj0);
    printf("1: %d\n", broj1);
    printf("2: %d\n", broj2);
    printf("3: %d\n", broj3);
    printf("4: %d\n", broj4);
    return 0;
}