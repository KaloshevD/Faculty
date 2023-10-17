/*Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.
 */
#include<iostream>
#include <cstring>

using namespace std;

typedef struct Voz Voz;
typedef struct ZeleznickaStanica ZeleznickaStanica;

struct Voz{
    char relacija[50];
    int kilometri;
    int patnici;
};

struct ZeleznickaStanica {
    char podatoci[20];
    Voz vozovi[30];
    int BrojVozovi;
};

void najkratkaRelacija(ZeleznickaStanica *zStanica, int n, char* grad){
    int indexJ;
    int indexI;
    int minKilometri;
    for(int i = 0; i < n; i++){
        if(strcmp(grad, zStanica[i].podatoci) == 0)
        {
            minKilometri = zStanica[i].vozovi[0].kilometri;
            indexJ = 0;
            indexI = i;
            for(int j = 0; j < zStanica[i].BrojVozovi; j++) {
                if (minKilometri >= zStanica[i].vozovi[j].kilometri) {
                    minKilometri = zStanica[i].vozovi[j].kilometri;
                    indexJ = j;

                }
            }
        }
    }

    cout<<"Najkratka relacija: "<<zStanica[indexI].vozovi[indexJ].relacija<<" "<<"("<< zStanica[indexI].vozovi[indexJ].kilometri <<" km)"<<endl;

}

int main(){

    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        cin>>zStanica[i].podatoci;
        cin>>zStanica[i].BrojVozovi;
        for(int j=0; j<zStanica[i].BrojVozovi; j++){
            cin>>zStanica[i].vozovi[j].relacija;
            cin>>zStanica[i].vozovi[j].kilometri;
            cin>>zStanica[i].vozovi[j].patnici;
        }
    }

    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
