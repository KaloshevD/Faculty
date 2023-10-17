/*Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место), а секоја од нив не е подолга од 80 знаци.

Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром (се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!". Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.

Влез:

9

a!bcdedcb!a

Kfd?vsvv98_89vvsv?dfK

Ccsvsdvdfv

342425vbbcb

352!2353696969625

gdg??dfg!!

5336346644747

8338736767867

12344321

Излез:

Kfd?vsvv98_89vvsv?dfK

*/
#include<stdio.h>
#include<string.h>
#include <ctype.h>

int palindrom(char *a)
{
    int br=0,i=0, n=strlen(a);
    for(i=0;i<=n;i++)
    {
        if(isdigit(a[i]))
        {
            return 0;
        }
        else if((a[i])==(a[n-i]))
        {
            br++;
        }
        else
        {
            return -1;
        }
    }
    if(br == n-1)
    {
        return 1;
    }
}

int punct(char *a)
{
    int i, br=0, n=strlen(a);
    for(i=0;i<n;i++)
    {
        if((ispunct(a[i])))
        br++;
    }
    if(br)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char a[80];
    int max=0, z=0, br=0;
    char najdolga[80];
    for(i=0;i<n;i++)
    {
        scanf("%s", a);
        if(max<strlen(a))
        {
            if(punct(a))
            {
                if(palindrom(a))
                {
                    if(strlen(a)>max) 
                    {
                        max=strlen(a);
                        strcpy(najdolga,a);
                        br++;
                    }
                }
                
            }
            
        }
    }
    if(br)
        printf("%s",najdolga);
    else
        printf("Nema!");
        
    return 0;
}