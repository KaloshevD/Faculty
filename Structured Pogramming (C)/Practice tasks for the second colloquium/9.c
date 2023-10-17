/*Да се имплементира рекурзивна функција која за низа од цели броеви $[a{0}, a{1}, ..., a_{n-1}]$ ќе ја пресмета вредноста на непрекинатата дропка дефинирана како:

v=a0+1a1+...1an−2+1an−1

Да се напише програма во која се чита цел број N, по што се читаат елементите на низа од N цели броеви (не повеќе од 100). Потоа се повикува рекурзивната функција и се печати резултатот во нов ред.

For example:
*/
#include <stdio.h>

double fraction(int *niza, int n) 
{
  if (n == 1) 
  {
    return niza[0];
  }
  return niza[0] + 1 / fraction(niza + 1, n - 1);
}

int main() 
{
  int n;
  scanf("%d", &n);

  int niza[n];
  for (int i = 0; i < n; i++) 
  {
    scanf("%d", &niza[i]);
  }

  double v = fraction(niza, n);
  printf("%.6f\n", v);

  return 0;
}
