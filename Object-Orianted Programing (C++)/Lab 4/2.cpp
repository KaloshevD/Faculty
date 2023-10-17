/*За потребите на апликациите за нарачка и доставување на храна (пр. Корпа, Кликни Јади и сл.) потребно е да се имплементира модул за управување со доставувачите.

Да се имплементира класа DeliveryPerson во која ќе се чуваат информации за:

ИД на доставувачот (низа од најмногу 5 знаци)
Име на доставувачот (динамички алоцирана низа од знаци)
Локација - реон во кој моментално се наоѓа доставувачот (цел број)
Број на извршени достави (цел број, иницијално е 0)
За класата да се имплементираат потребните конструктори, оператор = и методи за да функционира решението. (10 поени). Дополнително за класата да се имплементира метод void print() за печатење на информациите за доставувачот. (5 поени)

Да се имплементира класа DeliveryApp во која ќе се чуваат информации за:

Име на апликацијата (низа од најмногу 20 знаци)
Листа на доставувачи кои работат за оваа компанија (динимички алоцирана низа од објекти од класата DeliveryPerson, иницијално без елементи)
Број на доставувачи (број на елементи во низата од доставувачи - цел број, иницијално е 0)
За класата да се имплементираат потребните конструктори и методи со цел да функционира решението. (5 поени) Дополнително во класата да се имплементираат:

метод void addDeliveryPerson (const DeliveryPerson & person) - за додавање нов доставувач во апликацијата. (10 поени) Да не се дозволи додавање на доставувач со веќе постоечко ИД. (5 поени)
метод void assignDelivery (int restaurantArea, int customerArea) - за доделување на нарачка на доставувачот кој е најблиску до реонот на ресторанот restaurantArea од кој треба да се подигне нарачката. При доделување на нарачка на доставувач важат следните правила:

Просторот на кој функционира апликацијата е поделен на 10 соседни реони. Пример доколку ресторанот е во реон 5, прво се проверува дали има достапен доставувач во самиот тој реон (5), па потоа дали има доставувачи во првите соседни реони (4 и 6), па во вторите соседни реони (3 и 7) итн.
Доколку има повеќе доставувачи во реонот што е најблиску до посакуваниот реон, се избира доставувачот кој има извршено најмалку доставувања досега.
Откако нарачката е доделена на доставувачот, се менува неговата локација на реонот во кој се доставува нарачката (customerArea) и се зголемува бројот на извршени достави за доставувачот. (15 поени)
метод void print() - за печатење на информации за сите доставувачи кои работат за компанијата (формат во тест примери). (10 поени)
/*
#include<iostream>
#include<cstring>
using namespace std;

class DeliveryPerson {
    
private:
    char ID[5];
    char *ime;
    int lokacija;
    int Dostavi;
    
public:

    DeliveryPerson (char *ID=" ",char *ime=" ",int lokacija=0,int Dostavi=0)
    {
        strcpy(this->ID,ID);
        this->lokacija=lokacija;
        this->Dostavi=Dostavi;
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
    }

    DeliveryPerson (const DeliveryPerson &Dperson)
    {
        strcpy(this->ID,Dperson.ID);
        this->lokacija=Dperson.lokacija;
        this->Dostavi=Dperson.Dostavi;
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,Dperson.ime);
    }

    DeliveryPerson &operator=(const DeliveryPerson &DPerson)
    {
        if (this!=&DPerson)
        {
            delete[]ime;
            strcpy (this->ID,DPerson.ID);
            this->lokacija=DPerson.lokacija;
            this->Dostavi=DPerson.Dostavi;
            this->ime=new char[strlen(ime)+1];
            strcpy(this->ime,DPerson.ime);
        }
        return *this;
    }

    ~DeliveryPerson()
    {
        delete [] ime;
    }

    void print()
    {
        cout<<"ID: "<<ID<<" Name: "<<ime<<" Current location: "<<lokacija<<" # of deliveries: "<<Dostavi<<endl;
    }

    void setLokacija (int n)
    {
        lokacija=n;
    }

    void setDostavi(int n)
    {
        Dostavi=n;
    }

    int const getLokacija ()
    {
        return lokacija;
    }

    int const getDostaveni()
    {
        return Dostavi;
    }


    bool SporediID(const DeliveryPerson &person)
    {
        return strcmp(ID, person.ID) == 0;
    }

};


class DeliveryApp {
    
private:
    char ime[20];
    DeliveryPerson *niza;
    int Dostavuvaci;
    
public:
    DeliveryApp(char *ime=" ", DeliveryPerson *niza = nullptr, int Dostavuvaci=0)
    {
        strcpy(this->ime,ime);
        this->Dostavuvaci=Dostavuvaci;
        this->niza=new DeliveryPerson[Dostavuvaci];
        for(int i=0; i<Dostavuvaci; i++)
        {
            this->niza[i]=niza[i];
        }
    }

    DeliveryApp(const DeliveryApp &DApp)
    {
        strcpy(this->ime,DApp.ime);
        this->Dostavuvaci=DApp.Dostavuvaci;
        this->niza=new DeliveryPerson[DApp.Dostavuvaci];
        for(int i=0; i<Dostavuvaci; i++)
        {
            this->niza[i]=DApp.niza[i];
        }
    }

    DeliveryApp &operator=(const DeliveryApp &DApp)
    {
        if(this!=&DApp)
        {
            strcpy (this->ime,DApp.ime);
            this->Dostavuvaci=DApp.Dostavuvaci;
            this->niza=new DeliveryPerson[DApp.Dostavuvaci];
            for(int i=0; i<Dostavuvaci; i++)
            {
                this->niza[i]=DApp.niza[i];
            }
        }
        return *this;
    }
    ~DeliveryApp()
    {
        delete[]niza;
    }

    void print()
    {
        cout<<ime<<endl;
        if(Dostavuvaci==0)
            cout<<"EMPTY"<<endl;
        for(int i=0; i<Dostavuvaci; i++)
        {
            niza[i].print();
        }
    }

    void addDeliveryPerson(const DeliveryPerson &person)
    {
        for(int i=0; i<Dostavuvaci; i++)
        {
            if (niza[i].SporediID(person))
                return;
        }
        DeliveryPerson *tmp=new DeliveryPerson[Dostavuvaci+1];
        for (int i=0; i<Dostavuvaci; i++)
        {
            tmp[i]=niza[i];
        }
        tmp[Dostavuvaci]=person;
        Dostavuvaci++;
        delete[]niza;
        niza=tmp;
    }

    void assignDelivery(int restaurantArea, int customerArea){
        int maxDistance;
        int maxDeliveries;
        int deliveryPersonIndex = -1;
    
        for (int i = 0; i < Dostavuvaci; i++) {
            if (niza[i].getLokacija() == restaurantArea) {
                int distance = abs(niza[i].getLokacija() - customerArea);
                int deliveries = niza[i].getDostaveni();
                if (distance < maxDistance || (distance == maxDistance && deliveries < maxDeliveries)) {
                    maxDistance = distance;
                    maxDeliveries = deliveries;
                    deliveryPersonIndex = i;
                }
            }
        }
    
        if (deliveryPersonIndex == -1) {
            for (int i = 0; i < Dostavuvaci; i++) {
                int distance = abs(niza[i].getLokacija() - restaurantArea);
                int deliveries = niza[i].getDostaveni();
                if (distance < maxDistance || (distance == maxDistance && deliveries < maxDeliveries)) {
                    maxDistance = distance;
                    maxDeliveries = deliveries;
                    deliveryPersonIndex = i;
                }
            }
        }
    
        niza[deliveryPersonIndex].setLokacija(customerArea);
        niza[deliveryPersonIndex].setDostavi(niza[deliveryPersonIndex].getDostaveni() + 1);
    }

};



int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person("12345", "Stefan", 5);
        person.print();
        cout << "CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person = DeliveryPerson("12345", "Stefan", 5);
        person.print();
        cout << "COPY-CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson" << endl;
        DeliveryPerson person;
        DeliveryPerson person2("12345", "Stefan", 5);
        person = person2;
        person.print();
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR DeliveryApp" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        app.print();
        cout << "CONSTRUCTOR DeliveryApp OK" << endl;
    } else if (testCase == 5) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        app.print();
    } else if (testCase == 6) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        cin >> n; //read assign deliveries
        for (int i = 0; i < n; i++) {
            int restaurantArea, customerArea;
            cin >> restaurantArea >> customerArea;
            app.assignDelivery(restaurantArea, customerArea);
        }
        app.print();
    }
    return 0;
}