/*Од стандарден влез се внесуваат два цели броја N и Х.

Да се најде најблискот број помал од N коj е тотално различен од бројот Х.

Еден број е тотално различен од друг ако и само ако во него не се појавува ниту една од цифрите на другиот број.

Задачата да се реши без употреба на низи и матрици.*/
#include <stdio.h>
int main (){
    int n,x,i,j,check;
    scanf("%d %d",&n,&x);
    n--;
    for(n;n>0;n--)
    {
        check=0;
        for(i=n;i!=0;i/=10)
        {
            for(j=x;j!=0;j/=10)
            {
                if(i%10 == j%10)
                {
                    check=1;
                }
            }
        }
        if(!check){
            break;
        }
    }
    printf("%d",n);
    return 0;
}