/*
Дадена е текстуална датотека text.txt.

Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во датотеката. Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран, секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки.

Пример: за датотеката:

IO is short for Input Output
medioio medIo song
излез:

io
ou
io
oi
io
io
6
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
  FILE *f = fopen("text.txt", "w");
  char c;
  while((c = getchar()) != '#') {
    fputc(c, f);
  }
  fclose(f);
}

int main() {
    
  writeToFile();
   
    FILE *pok = fopen("text.txt","r");
    char C;
    char niza[100];
    int i,brojac=0;
    while((fgets(niza,100,pok)) != NULL)
    {
        for(i=0; i<strlen(niza); i++)
        {
            niza[i]= tolower(niza[i]);
        }
        
        for(i=0; i<strlen(niza); i++)
        {
            if(niza[i] == 'a' || niza[i]  == 'e' || niza[i]  == 'i' || niza[i]  == 'o' || niza[i]  == 'u')
            {
                if(niza[i+1] == 'a' || niza[i+1]  == 'e' || niza[i+1]  == 'i' || niza[i+1]  == 'o' || niza[i+1]  == 'u')
                {
                    brojac++;
                    printf("%c%c\n",niza[i],niza[i+1]);
                }
            }
        }
    }
    printf("%d",brojac);
    fclose(pok);
  return 0;
}

 }
