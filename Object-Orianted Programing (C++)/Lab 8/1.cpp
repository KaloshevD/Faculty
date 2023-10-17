/*Да се имплементира класа Employee за која се чува:
име (низа од карактери)
години (цел број)
Во класата да се имплементира виртуелна функција displayInfo() која на екран печати информации за вработениот.

Потоа да се имплементира класа Payable за која се чува:

плата (децимален број)
За класата да се креира чисто виртуелна функција calculateSalary()

Од овие класи потребно е да се изведат Developer и Manager. 

За класата Developer дополнително се чува и програмскиот јазик (низа од карактери). Потребно е да се препокријат соодветните функции. Платата се пресметува така што од основната плата се одзема данок од 10%.

За класата Manager дополнително се чува и број на оддели за кои е одговорен. Потребно е да се препокријат соодветните функции. Платата се пресметува така што на основната плата се додава бонус од 5% за секој еден оддел. */
#include <iostream>
#include <cstring>
using namespace std;

class Employee{
protected:
    char name[100];
    int age;
public:
    Employee(){
        strcpy(this->name, "");
        this->age=0;
    }
    Employee(char * name, int age){
        strcpy(this->name, name);
        this->age=age;
    }
    virtual void displayInfo()=0;
    virtual ~Employee(){};
};

class Payable{
protected:
    double salary;
public:
    Payable(){
        this->salary=0.0;
    }
    Payable(double salary){
        this->salary=salary;
    }
    virtual double calculateSalary()=0;
    virtual ~Payable(){};
};

class Developer : public Employee, public Payable{
private:
    char programmingLanguage[100];
public:
    Developer(){
        strcpy(this->programmingLanguage, "");
    }
    Developer(char * name, int age, double salary, char * programmingLanguage) : Employee(name, age), Payable(salary){
        strcpy(this->programmingLanguage, programmingLanguage);
    }
    void displayInfo(){
        cout<<"-- Developer Information --"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Programming Language: "<<programmingLanguage<<endl;
    }
    double calculateSalary(){
        double sum;
        sum=salary-(salary/10);
        return sum;
    }
    ~Developer(){}
};

class Manager : public Employee, public Payable{
private:
    int numberOfDepartments;
public:
    Manager(){
        this->numberOfDepartments=0;
    }
    Manager(char * name, int age, double salary, int numberOfDepartments) : Employee(name, age), Payable(salary){
        this->numberOfDepartments=numberOfDepartments;
    }
    void displayInfo(){
        cout<<"-- Manager Information --"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Number of Departments: "<<numberOfDepartments<<endl;
    }
    double calculateSalary(){
        double sum;
        sum=salary+(salary/20)*numberOfDepartments;
        return sum;
    }
    ~Manager(){}
};

double biggestSalary(Payable * payable [], int n)
{
    Payable * max = payable[0];
    for(int i=1;i<n;i++)
    {
        if(payable[i]->calculateSalary()>max->calculateSalary())
            max=payable[i];
    }
    return max->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}
