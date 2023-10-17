/*Во рамките на еден телекомуникациски оператор, СМС пораките се делат на регуларни и специјални. За секојa СМС порака се знае:

основна цена за една порака до 160 знаци (реален број)
претплатнички број на кој е испратена (низа од знаци со должина 12)
Класата за опишување на СМС пораки е апстрактна (5 поени).

За секоја Регуларна СМСдополнително се чуваат податоци за текстот на пораката и тоа дали е користена роаминг услуга (bool променлива). За секоја Специјална СМС дополнително се чуваат податоци за тоа дали е наменета за хуманитарни цели (bool променлива). (5 поени)

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

Метод SMS_cena(), за пресметување на цената на испратена СМС порака на следниот начин: (10 поени)

За регуларна СМС - цената се зголемува за 300% од основната цена ако е испратена од странство, а 18% од дома и цената се формира врз база на тоа во колку СМС пораки ќе го собере текстот што сакаме да го испратиме. Една регуларна порака може да собере најмногу 160 знаци. Притоа, доколку се надмине 160-от знак, се започнува нова порака и цената се пресметува како за две или повеќе пораки (пр. за 162 знаци, цената на СМС е иста како и за 320 знаци).
За специјална СМС - цената се зголемува за 150% од основната цена ако пораката HE е наменета за хуманитарни цели. Доколку е наменета за тоа, данокот од 18% не се пресметува на цената.
Пресметувањето 18% данок на цената на сите СМС пораки е фиксен и не се менува, додека пак процентот од 300% за регуларни и 150% за специјални СМС е променлив и во зависност од операторот може да се менува. Да се обезбеди механизам за можност за нивно менување. (5 поени)
Преоптоварен оператор << за печатење на податоците за СМС пораките во формат: (5 поени)

Тел.број: цена
Да се имплементира функција vkupno_SMS со потпис:

void vkupno_SMS(SMS** poraka, int n)
во која се печати вкупниот број на регуларни СМС пораки и нивната вкупна цена, како и бројот на специјални СМС пораки и нивната вкупна цена во проследената низа посебно. (15 поени)

Да се обезбедат сите потребни функции за правилно функционирање на програмата (5 поени).*/
#include <iostream>
#include <cstring>

using namespace std;

class Oglas{
private:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float evra;
public:
    Oglas(){
        strcpy(naslov, "");
        strcpy(kategorija, "");
        strcpy(opis, "");
        evra = 0;
    }
    Oglas(char const *naslov, char const *kategorija, char const *opis, float evra){
        strcpy(this->naslov, naslov);
        strcpy(this->kategorija, kategorija);
        strcpy(this->opis, opis);
        this->evra = evra;
    }
    Oglas(Oglas const &o){
        strcpy(naslov, o.naslov);
        strcpy(kategorija, o.kategorija);
        strcpy(opis, o.opis);
        evra = o.evra;
    }

    bool operator>(Oglas const &o) const{
        if(evra > o.evra){
            return true;
        }
        return false;
    }

    const char *getNaslov() const {
        return naslov;
    }

    const char *getOpis() const {
        return opis;
    }

    float getEvra() const {
        return evra;
    }

    Oglas& operator=(const Oglas &o)  {
        if(this==&o)
        return *this;
        strcpy(naslov, o.naslov);
        strcpy(kategorija, o.kategorija);
        strcpy(opis, o.opis);
        evra = o.evra;
        return *this;
    }

    friend ostream &operator<<(ostream &o,const Oglas &og){
        o << og.naslov<<endl<<og.opis<<endl<<og.evra<<" evra"<<endl;
    }

    ~Oglas(){}
};


class Oglasnik {
private:
    char ime[20];
    Oglas * oglasi;
    int broj;

public:
    Oglasnik(const char *ime = ""){
        strcpy(this->ime, ime);
        broj = 0;
        oglasi = new Oglas[broj];
    }

    Oglasnik(const Oglasnik &og){
        strcpy(this->ime, og.ime);
        this->broj = og.broj;
        this->oglasi = new Oglas[this->broj];
        for(int i = 0; i < this->broj; i++){
            this->oglasi[i] = og.oglasi[i];
        }
    }

    Oglasnik & operator = (const Oglasnik &og){
        if(this!=&og){
            delete[] oglasi;
            strcpy(this->ime, og.ime);
            this->broj = og.broj;
            this->oglasi = new Oglas[this->broj];
            for(int i = 0; i < this->broj; i++){
                this->oglasi[i] = og.oglasi[i];
            }
        }
        return *this;
    }

    ~Oglasnik(){
        delete [] oglasi;
    }

    Oglasnik & operator+=(const Oglas &og){
        Oglas * tmp = new Oglas [broj+1];
        for(int i = 0; i < broj; i++){
            tmp[i] = oglasi[i];
        }
        tmp[broj++] = og;
        delete [] oglasi;
        oglasi = tmp;
    }

    friend ostream &operator<<(ostream& os, const Oglasnik& oglasnik) {
        os << oglasnik.ime << endl;
        for(int i = 0; i < oglasnik.broj; i++){
            os << oglasnik.oglasi[i];
        }
    }
};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<ogl;
    }


    return 0;
}
