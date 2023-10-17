/*Од тастатура се внесува низа од целобројни елементи А со должина N ( N <= 100). Дополнително се внесува и број К. Да се трансформира низата така што на почеток ќе се преместат сите елементи помали од K, а после нив ќе следуваат броевите поголеми или еднакви на K. Редоследот на елементите да не се менува.

Испечатете ги елементите на трансформираната низа во еден ред на стандарден излез разделени со празно место.

Пример:
A[] = {1, 3, 2, 5, 9, 0, 8, 10}, K=6
Трансформираната низа ќе биде:
A[] = {1, 3, 2, 5, 0, 9, 8, 10}

A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, K=6
Трансформираната низа ќе биде:
A[] = {5, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6}

A[]={2, 4, 6, 8, 10}, K = 5
Трансформираната низа ќе биде:
A[] = {2, 4, 6, 8, 10}

A[]={1, 3, 5, 7, 9} K = 5
Трансформираната низа ќе биде:
A[] = {1, 3, 5, 7, 9} */

#include <stdio.h>
int main()
{
    int N,K;
    scanf("%d",&N);
    int A[N];
    if(N<=100)
    {
        for (int i=0; i<N; i++)
        {
            scanf("%d", &A[i]);
        }
        scanf("%d",&K);
        for (int i=0; i<N; i++)
        {
            if(K>A[i])
            printf("%d ",A[i]);
        }
        for (int i=0; i<N; i++)
        {
            if(K<=A[i])
            {
                printf("%d ",A[i]);
            }
        }
    }
    else
    {
        return 1;
    }
    return 0;
}