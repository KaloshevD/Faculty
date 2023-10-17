/*Да се дефинира класа Employee во која се чуваат информации за:

име (низа од максимум 20 знаци)
ID (низа од максимум 14 знаци)
плата (float)
За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.

Да се дефинира класа Department, во која се чуваат информации за:

id на department (int),
име (низа од 50 знаци),
поле од 3 вработени (објекти од класата Employee)
Во класата Department да се додаде метод кој ќе проверува дали постојат двajца вработени кои имаат ист ID број.


*/#include <iostream>
#include <cstring>

using namespace std;


class Employee{
private:
    char name[20];
    char id[14];
    float plata;
public:
    Employee (){}
    Employee (const char *name, const char *id, const float plata){
        strcpy(this->name,name);
        strcpy(this->id,id);
        this->plata = plata;
    }
    Employee (const Employee &emp){
        strcpy(name, emp.name);
        strcpy(id, emp.id);
        plata = emp.plata;
    }
    ~Employee(){}

     const char *getId(){
        return id;
    }
};

class Department{
private:
    int idDepartment;
    char name[50];
    Employee *employee;
public:
    Department (){}
    Department ( int idDepartment, const char *name, Employee *employee){
        this->idDepartment = idDepartment;
        strcpy(this->name,name);
        this->employee = employee;
    }
    Department (const Department &dmp){
      idDepartment = dmp.idDepartment;
      strcpy(name,dmp.name);
      employee = dmp.employee;
    }
    ~Department(){}

    int getId(){
        return idDepartment;
    }
    
    bool hasDuplicateID(){
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i != j){
                    if(strcmp(employee[i].getId(), employee[j].getId()) == 0)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



//ne smee da se menuva main funkcijata
int main()
{
    char ID[14], ime[20], name[50];
    int broj, n, numEmployees,id1;
    float salary;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> ID >> ime >> salary;
    	Employee p1(ime, ID, salary);
    	cin >> ID >> ime >> salary;
    	Employee p2(ime, ID, salary);
    	cin >> ID >> ime >> salary;
    	Employee p3(ime, ID, salary);
    	cin >> id1 >> name;
    	Employee p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Department d(id1, name, p);
        cout << "Department " << d.getId() << ":" << endl;
    	if(d.hasDuplicateID() == true)
    	    cout << "Postojat vraboteni so ist ID" << endl;
    	else
    	    cout << "Ne postojat vraboteni so ist ID" << endl;
    }
    return 0;
}
