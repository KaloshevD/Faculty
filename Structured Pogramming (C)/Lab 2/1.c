/* Од тастатура се внесува четирицифрен број n што во себе содржи барем 2 цифри со вредност 5.

КОЛЕГА на тој број е бројот кој на позициите на кои има петки во првиот број ќе има шестка во бројот КОЛЕГА. (Пр. колега на 5551 е 6661).

На екран да се испечати за колку проценти едниот број е поголем/помал од другиот број. Да се има во предвид дека некогаш може да биде поголем бројот n , а некогаш неговиот колега.

Доколку бројот n не содржи најмалку 2 цифри петки, да се испечати порака за грешка како во тест примерите. */

#include <stdio.h>
int main(){
    int n, kolega=0;
    float novbroj;
    scanf("%d",&n);
    int c1,c2,c3,c4;
    c4=n%10;
    c3=(n/10)%10;
    c2=(n/100)%10;
    c1=(n/1000)%10;
    if(c1%5==0 || c2%5==0 || c3%5==0 || c4%5==0)
    {
        
        if(c1 == 5)
        {
            c1++;
        }
        if(c2 == 5)
        {
            c2++;
        }
        if(c3 == 5)
        {
            c3++;
        }
         if(c4 == 5)
        {
            c4++;
        }
        kolega=((c1*1000)+(c2*100)+(c3*10)+c4);
        novbroj=kolega-n;
        novbroj=novbroj*100/n ;            
        printf("%.4f%%",novbroj);
        
    }
    else {
        printf("Error");
    }
    
    return 0;
}