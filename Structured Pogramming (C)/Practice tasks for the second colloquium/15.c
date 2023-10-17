/*За еден природен број а велиме дека е порамнување на друг природен број b ако и само ако цифрите еднакви на 9 во бројот b се заменети со цифрата 7 во бројот а.

Пример. Бројот 734775 е порамнување на бројот 934795.

Од стандарден влез се внесуваат непознат број на цели броеви (не повеќе од 100), се додека не се внесе нешто што не може да се интерпретира како цел број.

Ваша задача е да ги отпечатите најмалите 5 од порамнувањата на сите внесени броеви, по редослед од најмалиот кон најголемиот.

Забелешка: Доколку се внесат помалку од 5 броеви, тогаш печатите толку броеви колку што се соодветно внесени.

Наоѓањето на порамнувањето на даден број треба да се реализира во посебна рекурзивна функција poramnet(int a).

Пример.

За броевите: 9592, 69403, 100007, 6, 987, 6977, 33439,

треба да се најдат нивните порамнувања ( тоа се: 7572, 67403, 100007, 6, 787, 6777 и 33437, соодветно),

и да се отпечатат најмалите 5 од нив по овој редослед: 6 787 6777 7572 33437.

ЗАБРАНЕТО е користење на глобални променливи.
*/
#include<stdio.h>

int poramni(int a){
    if (a<=0)
        return 0;

    int retval = a%10;

    if (retval==9)
        retval = 7;

    return poramni(a/10) *10 + retval;
}

int komplement(int a){
    if (a < 10)
        return 9-a;

    int c = a%10;

    return komplement(a/10) * 10 + 9-c;
}

int min_index(int *a, int n){
    int min_i = 0;
    int i;
    for (i=0;i<n;++i){
        if (a[i]<a[min_i]){
            min_i = i;
        }
    }

    return min_i;
}

int max_index(int *a, int n){
    int max_i = 0;
    int i;
    for (i=0;i<n;++i){
        if (a[i]>a[max_i]){
            max_i = i;
        }
    }

    return max_i;
}

void sort_desc(int *a, int n){
    int i, j, tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if( a[j] < a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void sort_asc(int *a, int n){
    int i, j, tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if( a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}


void print_arr(int *a, int n){
    int i;
    for (i=0; i<n; ++i){
        printf("%d ", a[i]);
    }
}

int main()
{
    int x, k, n, min_i;

    int a[5];

    n=0;

    while (scanf("%d", &x)){
        //k = komplement(x);
        k = poramni(x);

        if (n>=5){
            min_i = max_index(a, 5);

            //if (a[min_i] < k){
            if (a[min_i] > k){
                a[min_i] = k;
            }
        }
        else {
            a[n] = k;
            n++;
        }
    }

    //sort_desc(a, n);
    sort_asc(a,n);
    print_arr(a, n);

    return 0;

}
