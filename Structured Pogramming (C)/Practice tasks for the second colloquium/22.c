/*Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци, а секоја од нив не е поголема од 50 знаци.

Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати (пр. A1c01АA1c92, 12A1cwwA1cxy, аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот. При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви.

Пример

Влез:

6

Ekjqh!!lkjsdh 

 A1c01АA1c92

12A1cwwA1cxy 

12A1cwwA1bxy 

аA1cwA1cA1ccA1cxab

nemaA1c_povekjepati


Излез

а1c01аа1c92

12а1cwwа1cxy 

аа1cwа1cа1ccа1cxab


*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int f(char *a)
{
    int i, n=strlen(a),b=0;
    for(i=0;i<n;i++)
    {
        if(*(a+i)=='A' || *(a+i)=='a')
        {
            if(*(a+i+1)=='1')
            {
                if(*(a+i+2)=='c' || *(a+i+2)=='C')
                {
                    b++;
                }
            }
        }
    }
    if(b>=2)
        return 1;
    else
        return 0;
}

void lower(char *a)
{
    int i, n=strlen(a);
    for(i=0;i<n;i++)
    {
        if((*(a+i)=='A') && (*(a+i+1)=='A'))
        {
            tolower(a+i+1);
        }
        else
        {
            a[i]=tolower(a[i]);
        }
    }
    puts(a);
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char a[50];
    for(i=0;i<n;i++)
    {
        scanf("%s", a);
        if(f(a))
        {
            lower(a);
        }
    }
    return 0;
}