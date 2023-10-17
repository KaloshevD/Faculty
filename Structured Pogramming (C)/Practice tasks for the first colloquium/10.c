/*Цик-цак е број за кој што важи дека за секој пар соседни цифри, тие се наизменично поголеми односно помали една во однос на друга. На пример, ако бројот x е составен од цифрите a, b, c, d и е, тогаш за нив важи:

a>b, b<c, c>d, d<e или a<b, b>c, c<d, d>e

Пр. 343, 4624, 6231209
Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.*/
#include <stdio.h>#include <stdio.h>

int main() {
    int x, br = 0, tmp, cifra1, cifra2, p, f;

    while(scanf("%d", &x))
    {
        f=1;
        if(x>=10){
            tmp = x;
            cifra1 = tmp%10;
            tmp/=10;
            cifra2 = tmp%10;
            tmp/=10;
            if(cifra1 > cifra2)
            {
                p=1;
            }
            else if(cifra1 < cifra2)
            {
                p=0;
            }
            else
                f = 0;
            cifra1 = cifra2;
            if(f)
            {
                while(tmp) {
                    cifra2 = tmp%10;
                    if(p){
                        if(cifra1>=cifra2){
                            f=0;
                            break;
                        }
                        else
                            p = 0;
                    }
                    else{
                    	if(cifra1<=cifra2){
                            f=0;
                            break;
                        }
                        else
                            p = 1;
                    }
                    tmp /= 10;
                    cifra1 = cifra2;
                }
            }
            if(f)
                printf("%d\n", x);
        }

    }

    return 0;
}
