/*Треба да се напише класа FoodItem која што ги има овие две чисти виртуелни функции:

getPrice() - цена на храната
getTime() - време за подготвување на храната
Исто така, треба класата да ги има следните информации:

type (динамички алоцирана низа од карактери) - типот на храната
num(int)- количина на храната
Понатаму, треба да креирате 2 подкласи на FoodItem наречени:

Pizza
Steak
Класата Pizza треба да ги има овие информации:

dough (динамички алоцирана низа од карактери) - какво тесто е пицата
Цана на едно тесто:
- "wholeWheat" : 250
- "glutenFree" : 350

Време на правење на пица е 25 минути, независно од колку пици има.
Ако се прават n пици потребна е n количина на тесто.
Класата Steak треба да ги има овие информации:

bool cooked (дали е well done или medium rare)
Време на правење, независно колку steaks има:

-  well done : 20 min

-  medium rare: 15 min

Цена на еден стек е 1300 ден.



Треба исто така да напишете глобална функција:

getMaxFoodItem(FoodItem *pItem[], int n) , која што ќе враќа покажувач до најскапиот FoodItem*/
#include <iostream>
#include <cstring>
using namespace std;

class FoodItem{
protected:
    char * type;
    int num;
public:
    FoodItem(){}
    FoodItem(char* type, int num){
        this->type= new char[strlen(type+1)];
        strcpy(this->type, type);
        this->num=num;
    }
    char * getType()
    {
        return type;
    }
    virtual int getPrice()=0;
    virtual int getTime()=0;
    
    virtual ~FoodItem(){
        delete [] type;
    }
};

class Pizza : public FoodItem{
private:
    char * dough;
public:
    Pizza () : FoodItem(){
        this->dough = nullptr;
        strcpy(this->dough, "wholeWheat");
    }
    Pizza(char * type, int num, char * dough) : FoodItem (type, num){
        this->dough = new char[strlen(dough)+1];
        strcpy(this->dough, dough);
    }
    
    int getPrice(){
        if(strcmp(this->dough, "wholeWheat")==0)
            return 250*num;
        else if(strcmp(this->dough, "glutenFree")==0)
            return 350*num;
        else
            return 0;
    }
    int getTime(){
        return 25;
    }
    ~Pizza (){
        delete [] dough;
    }
};

class Steak : public FoodItem{
private:
    bool cooked;
public:
    Steak() : FoodItem(){
        this->cooked=false;
    }
    Steak(char * type, int num, bool cooked) : FoodItem(type, num){
        this->cooked=cooked;
    }
    
    int getPrice(){
        return 1300*num;
    }
    int getTime(){
        if(cooked==false)
            return 15;
        else if(cooked==true)
            return 20;
        else return 0;
    }
    ~Steak(){}
};

FoodItem * getMaxFoodItem(FoodItem * pItem[], int n)
{
    FoodItem * item = pItem[0];
    int max=pItem[0]->getPrice();
    
    for(int i=0;i<n;i++)
    {
        if(pItem[i]->getPrice()>max){
            max=pItem[i]->getPrice();
            item=pItem[i];
        }
    }
    return item;
}

int main() {
    FoodItem *p;
    int n;
    cin>>n;

    char type[30];
    char dough[30];
    bool cooked;
    int size;

    FoodItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type;
        cin>>size;


        if(strcmp(type, "pizza")==0 ) {
            cin>>dough;
            items[i] = new Pizza(type, size, dough);
        }else{
            cin>>cooked;
            items[i] = new Steak(type, size, cooked);
        }


    }

    FoodItem *it = getMaxFoodItem(items, n);
    cout<<"Type: "<<it->getType()<<endl;
    cout<<"The max price is: "<<it->getPrice()<<endl;
    cout<<"Time to cook: "<<it->getTime();
    return 0;
}