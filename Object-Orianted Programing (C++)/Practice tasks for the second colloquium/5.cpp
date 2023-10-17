/*Да се креира класа Customer за опишување на купувачи на една книжара. За секој купувач се чуваат податоци за:

името (низа од 50 знаци),
електронска адреса (низа од 50 знаци),
вид на купувач (стандардни, лојални или вип),
основен попуст (цел број изразен во проценти),
дополнителен попуст (цел број изразен во проценти) и
број на купени производи. (5 поени)
Сите лојални купувачи со покажување на клуб картичка имаат право на основниот попуст при купување од книжарата. Основниот попуст е ист за сите лојални купувачи и изнесува 10%. Оваа вредност може да се смени со одлука на раководството на книжарата. Дополнителниот попуст е фиксен и може да го користат само вип купувачите и изнесува 20%. Стандардните купувачи немаат право на попуст (5 поени).

За оваа класа да се имплементира оператор << за печатење на купувач во формат:

[ime_na_kupuvac]
[email_na_kupuvac]
[broj_na_proizvodi]
[vid_na_kupuvac] [popust_sto_moze_da_go_koristi]
каде попустот е 0% ако купувачот е стандарден, вредноста на основниот попуст, ако е лојален или збир од основниот и дополнителниот попуст, ако купувачот е вип. (5 поени)

Да се креира класа за онлајн книжара FINKI-bookstore во која се чува низа од регистрирани купувачи (динамички алоцирана низа) и број на купувачи. (5 поени) За класата да се обезбедат:

operator+= (10 поени) за додавање купувач во листата од купувачи, но само ако веќе не е дел од неа (ако во листата нема купувач со иста електронска адреса). Ако во листата постои корисник со иста електронска адреса, треба да се генерира исклучок UserExistsException. Потребно е да се обезбеди справување со исклучокот во функцијата main на означеното место. Во ваква ситуација се печати порака "The user already exists in the list" (5 поени).
Функција update со која сите стандардни купувачи со купени повеќе од 5 производи стануваат лојални, а сите лојални купувачи со над 10 купени производи, стануваат вип (5 поени).
Оператор << за печатење на информациите за сите регистрирани купувачи (5 поени).
Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. (10 поени)*/
#include <iostream>
#include <cstring>
using namespace std;

enum typeC{
    standard,
    loyal,
    vip
};

class Customer{
protected:
    char ime[50];
    char email[50];
    typeC tip;
    float popust;
    float popust2;
    int proizvodi;
public:
    Customer() {
        strcpy(this->ime,"");
        strcpy(this->email,"");
        this->tip = standard;
        this->popust = 0.0;
        this->popust2 = 0;
        this->proizvodi = 0;
    }

    Customer(char const *ime, char const *email, typeC tip, int proizvodi){
        strcpy(this->ime,ime);
        strcpy(this->email,email);
        this->tip = tip;
        this->popust = popust;
        this->popust2 = popust2;
        this->proizvodi = proizvodi;
    }

    Customer(const Customer &c){
        strcpy(this->ime,c.ime);
        strcpy(this->email,c.email);
        this->tip = c.tip;
        this->popust = c.popust;
        this->popust2 = c.popust2;
        this->proizvodi = c.proizvodi;
    }

    friend ostream &operator<<(ostream &os, const Customer &c) {
        os << c.ime<<endl;
        os << c.email<<endl;
        os << c.proizvodi<<endl;
        if(c.tip == 1){
            os << "loyal " << 10 << endl;
        }
        else if(c.tip == 2){
            os << "vip " << 30 << endl;
        }
        else{
            os << "standard " << 0 << endl;
        }
        return os;
    }

    Customer &operator =(const Customer &c){
        if(this!=&c){
            strcpy(this->ime,c.ime);
            strcpy(this->email,c.email);
            this->tip = c.tip;
            this->popust = c.popust;
            this->popust2 = c.popust2;
            this->proizvodi = c.proizvodi;
        }
        return *this;
    }

    void setDiscount1(float popust) {
        this->popust = popust;
    }

    void setTip(typeC tip) {
        this->tip = tip;
    }

    int getProizvodi() const {
        return proizvodi;
    }

    const char *getEmail() const {
        return email;
    }

    typeC getTip() const {
        return tip;
    }

    ~Customer() {}

};

class UserExistsException : public std::exception {
public:
    const char* what() const noexcept  {
        return "The user already exists in the list";
    }
};

class FINKI_bookstore{
    Customer *customers;
    int numCustomers;
public:
    FINKI_bookstore(){
        numCustomers = 0;
        customers = new Customer[numCustomers];
    }

    void setCustomers(Customer *customers1, int n) {
        numCustomers = n;
        customers = new Customer[numCustomers];
        for(int i = 0; i < numCustomers; i++){
            customers[i] = customers1[i];
        }
    }

    friend ostream &operator<<(ostream &os, const FINKI_bookstore &bookstore) {
        for(int i = 0; i < bookstore.numCustomers; i++){
            os << bookstore.customers[i];
        }
        return os;
    }

    FINKI_bookstore & operator +=(const Customer &c){
        for(int i = 0; i < numCustomers; i++){
            if(strcmp(customers[i].getEmail(), customers->getEmail()) == 0){
            }
        }
        Customer *temp = new Customer[numCustomers+1];
        for(int i = 0; i < numCustomers; i++){
            temp[i] = customers[i];
        }
        temp[numCustomers] = c;
        delete [] customers;
        customers = temp;
        numCustomers++;
        return *this;

    }

    void update(){
        for(int i = 0; i < numCustomers;  i++){
            if(customers[i].getProizvodi() > 5 && customers[i].getProizvodi() < 10){
                customers[i].setTip(loyal);
            }
            else if(customers[i].getTip() == 1 && customers[i].getProizvodi() > 10){
                customers[i].setTip(vip);
            }
            if(customers[i].getTip() == 0 && customers[i].getProizvodi() > 5){
                customers[i].setTip(loyal);
            }
        }
    }

    ~FINKI_bookstore() {
        delete [] customers;
    }
};

int main(){
    int testCase;
    cin >> testCase;
    int MAX = 100;
    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception!!!) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;

        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
