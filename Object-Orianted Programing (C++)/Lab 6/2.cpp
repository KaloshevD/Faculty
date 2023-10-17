/*Потребно е да имплементирате класа Course. Таа треба да ги содржи следниве информации:

име - динамички алоцирана низа од знаци
цена по лекција - цел број
рејтинг - цел број
број на лекции - цел број
За оваа класа потребно е да креирате:

Default constructor
Constructor со параметри
Copy constructor
Оператор =
Destructor
Getters и setters
Функција getTotalPrice() што ја враќа вкупната цена на курсот. Доколку курсот има рејтинг помал од 7 има попуст од 10% на вкупната цена.
Функција print() што ги печати информациите за курсот:
Course: [име]
Price: [вкупна цена]
Rating: [рејтинг]

Треба да ја имплементирате и класата ProgrammingCourse која треба да наследува од класата Course и дополнително да ги има следниве информации:

програмски јазик - динамички алоцирана низа од знаци
премиум - bool
ниво на тежина - цел број
За оваа класа потребно е да креирате:

Default constructor
Constructor со параметри
Copy constructor
Оператор =
Destructor
Функција getTotalPrice() што ја враќа вкупната цена на програмскиот курс, со тоа што доколку курсот е премиум, ќе има додатно 20% попуст на веќе пресметаната цена(каде што е земен предвид рејтингот соодветно). 
Оператор ++ кој што ќе го инкрементира нивото на тежина. 
Функција print() што ги печати информациите за програмскиот курс:
Course: [име]
Price: [вкупна цена]
Rating: [рејтинг]
Programming language: [програмски јазик]
Difficulty level: [ниво на тежина]

/*
#include <iostream>
#include <cstring>

using namespace std;

// YOUR CODE STARTS HERE
class Course{
    char *name;
    int cena;
    int rating;
    int brLekcii;
public:
    Course(){}
    Course(const char *name, int cena, int rating, int brLekcii){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->cena = cena;
        this->rating = rating;
        this->brLekcii = brLekcii;
    }
    Course(const Course &c){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, c.name);
        this->cena = cena;
        this->rating = rating;
        this->brLekcii = brLekcii;
    }

    bool operator==(const Course &rhs) const {
        return name == rhs.name &&
               cena == rhs.cena &&
               rating == rhs.rating &&
               brLekcii == rhs.brLekcii;
    }

    bool operator!=(const Course &rhs) const {
        return !(rhs == *this);
    }
    ~Course(){}

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        Course::name = name;
    }

    int getCena() const {
        return cena;
    }

    void setCena(int cena) {
        Course::cena = cena;
    }

    int getRating() const {
        return rating;
    }

    void setRating(int rating) {
        Course::rating = rating;
    }

    int getBrLekcii() const {
        return brLekcii;
    }

    void setBrLekcii(int brLekcii) {
        Course::brLekcii = brLekcii;
    }
    int getTotalPrice(){
        if (rating < 7){
            int save = cena * brLekcii / 10;
            return cena * brLekcii - save;
        }
        else{
            return cena * brLekcii;
        }

    }
    void print(){
        cout<<"Course: "<<getName()<<endl<<"Price: "<<getTotalPrice()<<endl<<"Rating: "<<getRating()<<endl;
    }
};

class ProgrammingCourse : public Course{
    char *name;
    bool premium;
    int tezina;
public:
    ProgrammingCourse(){}

    ProgrammingCourse(const Course &c, char *name, bool premium, int tezina) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->premium = premium;
        this->tezina = tezina;
    }

    ProgrammingCourse(const ProgrammingCourse &pc){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, pc.name);
        premium = pc.premium;
        tezina = pc.tezina;
    }

    bool operator==(const ProgrammingCourse &rhs) const {
        return name == rhs.name &&
               premium == rhs.premium &&
               tezina == rhs.tezina;
    }

    bool operator!=(const ProgrammingCourse &rhs) const {
        return !(rhs == *this);
    }


    ~ProgrammingCourse(){

    }

    int getTotalPricePC(){
        if(premium == 1){
            return Course::getTotalPrice() * 20 / 100;
        }
        else{
            return Course::getTotalPrice();
        }
    }

   
    void print(){
        cout<<"Course: "<< Course::getName()<<endl;
        cout<<"Price: "<< getTotalPricePC()<<endl;
        cout<<"Rating: "<< Course::getRating()<<endl;
        cout<<"Programming language: " << name<<endl;
        cout<<"Difficulty level: " << tezina<<endl;

    }

};

//DO NOT EDIT THE MAIN FUNCTION

int main() {

    char name[100];
    int lecturePrice;
    int rating;
    int numLectures;

    char programmingLanguage[100];
    bool isPremium;
    int difficulty;

    Course * courses = new Course[5];
    ProgrammingCourse * programmingCourses = new ProgrammingCourse[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> lecturePrice >> rating >> numLectures;
            courses[i] = Course(name, lecturePrice, rating, numLectures);
            courses[i].print();
            cout<<endl;
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> lecturePrice >> rating >> numLectures;
            cin >> programmingLanguage >> isPremium >> difficulty;
            courses[i] = Course(name, lecturePrice, rating, numLectures);
            programmingCourses[i] = ProgrammingCourse(courses[i], programmingLanguage, isPremium, difficulty);
        }

        cout << "COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            courses[i].print();
            cout<<endl;
        }


        cout << "PROGRAMMING COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            programmingCourses[i].print();
            cout<<endl;
        }

    }

    delete [] courses;
    delete [] programmingCourses;
    

}
