/*Во програмскиот јазик C да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)

Функционалност (5 поени).*/
#include<stdio.h>
typedef struct Pacient Pacient;

typedef struct doktor  doktor;
struct Pacient{
    char ime[100];
    int zdrastveno;
    int pregledi;
};

struct doktor{
    char ime[100];
    int br_pac;
    Pacient pacienti[100];
    float cena;
};


void najuspesen_doktor(doktor *md, int n)
{
    float final;
    float maxFinal = 0;
    int preglediSave = 0;
    int index;
    int indexJ;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < md[i].br_pac; i++){
            if(md[i].pacienti[j].zdrastveno == 0){
                final = md[i].cena * md[i].pacienti[j].pregledi;
            }
        }
    }
    printf("%s %.2f %d",md[index].ime, final, preglediSave);

}
int main()
{
	int i, j, n, broj;
	doktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", md[i].pacienti[j].ime);
			scanf("%d", &md[i].pacienti[j].zdrastveno);
			scanf("%d", &md[i].pacienti[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
