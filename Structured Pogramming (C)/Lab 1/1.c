/*
Да се прочитаат два цели броеви од тастатура и на екран да се испечатат // нивните сума и производ.
*/

#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d",&a, &b);
    printf("%d \n", a+b);
    printf("%d", a*b);
    return 0;
}