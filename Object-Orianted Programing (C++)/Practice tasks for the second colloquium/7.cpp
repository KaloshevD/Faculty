/*За потребите на електронскиот огласник ФИНКИ-Огласи треба да се развие класа Oglas со информации за наслов (текстуална низа од максимум 50 знаци), категорија (текстуална низа од максимум 30 знаци), опис (текстуална низа од максимум 100 знаци) и цена изразена во евра (реален број). (5 поени)

За оваа класа да се обезбедат:

Оператор > за споредба на двa огласи според цената (5 поени)
Оператор << за печатење на податоците за огласот во форма: (5 поени)
[наслов]

[опис]

[цена] evra

Да се развие класа Oglasnik во која се чуваат податоци за име на огласникот (текстуална низа од максимум 20 знаци), низа од огласи (динамички резервирана низа од објекти од класата Oglas) и број на огласи во низата (цел број) (5 поени)

За оваа класа да се обезбедат:

Оператор += за додавање нов оглас во низата од огласи. (5 поени) Ако цената на огласот што се внесува е негативна, треба да се генерира исклучок NegativnaVrednost (објект од класата NegativnaVrednost што посебно треба да се дефинира). Во ваков случај се печати порака “Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!“ и не се додава во низата. (5 поени)
Оператор << за печатење на огласите во огласникот. (5 поени) Печатењето треба да биде во следниот формат:
[Име на огласникот]

[наслов1] [опис1] [цена1]

[наслов2] [опис2] [цена2]

...

Функција void oglasOdKategorija(const char *k) со која се печатат сите огласи од категоријата k што е проследена како влезен аргумент на методот. (5 поени)

Функција void najniskaCena() со која се печати огласот што има најниска цена. Ако има повеќе огласи со иста најниска цена, да се испечатат податоците за првиот од нив. (5 поени)

Сите променливи во класите се приватни.

Да се обезбедат сите потребни методи за правилно функционирање на програмата. (5 поени)*/
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

    const char *getKategorija() const {
        return kategorija;
    }

    ~Oglas(){}
};

class NegativnaVrednost{
public:
    static void print(){
        cout << "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
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


    ~Oglasnik(){
        delete [] oglasi;
    }

    Oglasnik & operator+=(const Oglas &og){
        if(og.getEvra() < 0){
            NegativnaVrednost::print();
        }
        else{
            Oglas * tmp = new Oglas [broj+1];
            for(int i = 0; i < broj; i++){
                tmp[i] = oglasi[i];
            }
            tmp[broj++] = og;
            delete [] oglasi;
            oglasi = tmp;
        }
    }

    friend ostream &operator<<(ostream& os, const Oglasnik& oglasnik) {
        os << oglasnik.ime << endl;
        for(int i = 0; i < oglasnik.broj; i++){
            os << oglasnik.oglasi[i]<<endl;
        }
        return os;
    }
    void oglasiOdKategorija(const char *k){
        for(int i = 0; i < broj; i++){
            if(strcmp(k, oglasi[i].getKategorija()) == 0)
            {
                cout << oglasi[i] << endl;
            }

        }
    }

    void najniskaCena(){
        float min = oglasi[0].getEvra();
        int index = 0;
        for(int i = 0; i < broj; i++){
            if(oglasi[i].getEvra() < min){
                min = oglasi[i].getEvra();
                index = i;
            }
        }
        cout << oglasi[index];
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
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
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
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
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
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
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
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
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

        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }



    return 0;
}
