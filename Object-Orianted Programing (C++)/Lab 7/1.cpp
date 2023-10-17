/*Дизајнирате програма за систем за хотелски резервации. За ова ќе треба да креирате базична класа наречена Room што претставува генеричка хотелска соба и ги има овие две чисти виртуелни функции:

displayRoomInfo()
displayRoomPrice()
Понатаму, треба да креирате 2 подкласи на Room наречени:

StandardRoom
DeluxeRoom
Класата StandardRoom треба да ги има овие информации:

hasBathroom - bool променлива
и имплементирајте ги двете функции погоре со овие имплементации:
За displayRoomInfo() треба да се печати This is a standard room with a queen-sized bed. Ако собата има и бања, треба да додадете `and a bathroom` на крајот од пораката.
За displayRoomPrice() треба да се печати The price for a standard room is [price] per night. каде што цената се пресметува врз основа на тоа дали собата има бања или не. Ако има бања е 100$ а ако не е 80$.
Класата DeluxeRoom треба да ги има овие информации:

hasBalcony - bool променлива
и имплементирајте ги двете функции погоре со овие имплементации:

За displayRoomInfo() треба да печати This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge. Доколку собата дополнително има и балкон, додадете `and a balcony` на крајот од пораката.
За displayRoomPrice() треба да се печати The price for a deluxe room is [price] per night. каде цената се пресметува врз основа на тоа дали собата има балкон или не. Ако има балкон е 200$ а ако не е 160$.*/

#include <iostream>

using namespace std;

class Room{
public:
    Room (){}
    virtual void displayRoomInfo()=0;
    virtual void displayRoomPrice()=0;
    virtual ~Room (){}
};

class StandardRoom : public Room{
private:
    bool hasBathroom;
public:
    StandardRoom(){
    }
    StandardRoom(bool hasBathroom){
        this->hasBathroom=hasBathroom;
    }
    void displayRoomInfo()
    {
        if(hasBathroom==false)
            cout<<"This is a standard room with a queen-sized bed."<<endl;
        else
            cout<<"This is a standard room with a queen-sized bed and a bathroom."<<endl;
    }
    void displayRoomPrice()
    {
        cout<<"The price for a standard room is ";
        if(hasBathroom==true)
            cout<<"$100 ";
        else
            cout<<"$80 ";
        cout<<"per night."<<endl;
    }
    ~StandardRoom(){}
};

class DeluxeRoom : public Room{
private:
    bool hasBalcony;
public:
    DeluxeRoom()
    {
        this->hasBalcony=false;
    }
    DeluxeRoom(bool hasBalcony)
    {
        this->hasBalcony=hasBalcony;
    }
    void displayRoomInfo()
    {
        if(hasBalcony==false)
            cout<<"This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge."<<endl;
        else
            cout<<"This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge and a balcony."<<endl;
    }
    void displayRoomPrice()
    {
        cout<<"The price for a deluxe room is ";
        if(hasBalcony==true)
            cout<<"$200 ";
        else
            cout<<"$160 ";
        cout<<"per night."<<endl;
    }
    ~DeluxeRoom(){}
};

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    Room* rooms[5];

    int testCase;
    
    cin >> testCase;

    if (testCase == 1) {
        cout << "TEST CASE 1: TESTING STANDARD ROOM CLASS" << endl;
        
        for (int i = 0; i < 5; i++) {
            rooms[i] = new StandardRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else if (testCase == 2) {
        cout << "TEST CASE 2: TESTING DELUXE ROOM CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            rooms[i] = new DeluxeRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else {
        cout << "TEST CASE 3: TESTING BOTH CLASSES" << endl;
        for (int i = 0; i < 5; i++) {
            if (i % 2) {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new DeluxeRoom(hasBalcony);
            }
            else {
                bool hasBathroom;
                cin >> hasBathroom;
                rooms[i] = new StandardRoom(hasBathroom);
            }
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    }

    return 0;
}
