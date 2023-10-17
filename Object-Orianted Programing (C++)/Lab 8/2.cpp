/*Да се имплементира апстрактна класа Vehicle за која се чува:
модел - низа од знаци од максимум 40 знаци
сила на мотор - децимален број
максимум брзина - децимален број
ефикасност на гориво - децимален број
Во класата да се имплементира виртуелна функција void displayInfo() која на екран печати информации за возилото и виртуелна функција float power() која ја враќа моќта на возилото.

Потребно е да се имплементира класите LuxaryVehicle и SportsVehicle кои што ќе наследуваат од класата Vehicle.

За класата LuxaryVehicle дополнително се чуваат:

број седишта- број на седишта во возилото(цел број)
Функцијата power() се пресметува со формулата (0.2*сила на мотор*број на седишта)+(0.55*максимум брзина*број на седишта)+(0.25*ефикасност на гориво*број на седишта)

Функцијата displayInfo() печати во формат:

LuxuryVehicle: [model]

Number of seats: [number of seats]

Engine power: [engine power]

Maximum speed: [maximum speed]

Fuel efficiency: [fuel efficiency]

Power: [power]

За класата SportsVehicle дополнително се чуваат:

isConvertible - bool
Функцијата power() се пресметува со формулата сила на мотор+максимум брзина+ефикасност на гориво. Доколку е convertible, тогаш неговата моќ се намалува за два пати.

Функцијата displayInfo() печати во формат:

SportsVehicle: [model]

Convertible: [Yes/No]

Engine power: [engine power]

Maximum speed: [maximum speed]

Fuel efficiency: [fuel efficiency]

Power: [power]


Потребно е да се имплементира класата LuxurySportsVehicle која што ќе наследува од класите LuxuryVehicle и SportsVehicle.

Моќта е пресметана на следниот начин: (LuxuryVehicle's power + SportsVehicle's power)/2

Функцијата displayInfo() печати во формат:

LuxurySportsVehicle: [model]

Engine power: [engine power]

Maximum speed: [maximum speed]

Fuel efficiency: [fuel efficiency]

Power: [power]


Да се направи глобална функција Vehicle* mostPowerfulLuxuryVehicle(Vehicle** vehicles, int n) што ќе врати покажувач до најмоќнoто луксузно возило.*/
#include <iostream>
#include <cstring>
using namespace std;

class Vehicle{
protected:
    char model[40];
    float enginePower;
    float MaxSpeed;
    float fuelEfficiency;
public:
    Vehicle(){}
    Vehicle(const char *model, float enginePower, float MaxSpeed, float fuelEfficiency){
        strcpy(this->model, model);
        this->enginePower = enginePower;
        this->MaxSpeed = MaxSpeed;
        this->fuelEfficiency = fuelEfficiency;
    }
    ~Vehicle(){}

    const char *getModel() const {
        return model;
    }

    float getEnginePower() const {
        return enginePower;
    }

    float getMaxSpeed() const {
        return MaxSpeed;
    }

    float getFuelEfficiency() const {
        return fuelEfficiency;
    }

    virtual void displayInfo() = 0;
    virtual double power() = 0;
};
class LuxuryVehicle : public Vehicle{
protected:
    int sedishta;
public:
    LuxuryVehicle(){}

    LuxuryVehicle(const char *model, float enginePower, float maxSpeed, float fuelEfficiency, int sedishta) : Vehicle(
            model, enginePower, maxSpeed, fuelEfficiency), sedishta(sedishta) {
        strcpy(this->model, model);
        this->enginePower = enginePower;
        this->fuelEfficiency = fuelEfficiency;
        this->sedishta = sedishta;
    }
    double power(){
        return (0.2*enginePower*sedishta)+(0.55*MaxSpeed*sedishta)+(0.25*fuelEfficiency*sedishta);
    }
    void displayInfo(){
        cout<<"LuxuryVehicle: "<<model<<endl;
        cout<<"Number of seats: "<<sedishta<<endl;
        cout<<"Engine power: "<<enginePower<<endl;
        cout<<"Maximum speed: "<<MaxSpeed<<endl;
        cout<<"Fuel efficiency: "<<fuelEfficiency<<endl;
        cout<<"Power: "<<LuxuryVehicle::power()<<endl;
    }
};

class SportsVehicle : public Vehicle{
protected:
    int isConvert;
public:
    SportsVehicle(){}

    SportsVehicle(const char *model, float enginePower, float maxSpeed, float fuelEfficiency, int isConvert) : Vehicle(
            model, enginePower, maxSpeed, fuelEfficiency), isConvert(isConvert) {
        strcpy(this->model, model);
        this->enginePower = enginePower;
        this->fuelEfficiency = fuelEfficiency;
        this->isConvert = isConvert;
    }

    double power(){
        return enginePower + MaxSpeed + fuelEfficiency;
    }
    void displayInfo(){
        cout<<"SportsVehicle: "<<model<<endl;
        cout<<"Convertible ";
        if(isConvert == 1){
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        cout<<"Engine power: "<<enginePower<<endl;
        cout<<"Maximum speed: "<<MaxSpeed<<endl;
        cout<<"Fuel efficiency: "<<fuelEfficiency<<endl;
        cout<<"Power: "<<SportsVehicle::power()<<endl;
    }
};

class LuxurySportsVehicle : public LuxuryVehicle, public SportsVehicle{
public:
    LuxurySportsVehicle(const char *model, float enginePower, float maxSpeed, float fuelEfficiency, int sedishta,
                        const char *model1, float enginePower1, float maxSpeed1, float fuelEfficiency1, int isConvert)
            : LuxuryVehicle(model, enginePower, maxSpeed, fuelEfficiency, sedishta),
              SportsVehicle(model1, enginePower1, maxSpeed1, fuelEfficiency1, isConvert) {

        model = nullptr;
        model1 = nullptr;
        enginePower = 0;
        enginePower1 = 0;
        fuelEfficiency = 0;
        fuelEfficiency1 = 0;
        sedishta = 0;
        isConvert = 0;
    }

    double power(){
        return ( LuxuryVehicle::power() + SportsVehicle::power())/ 2;
    }
    void displayInfo(){
        cout<<"LuxurySportsVehicle: "<<endl;
    }
};

int main() {
    int model;
    double enginePower;
    double maximumSpeed;
    double fuelEfficiency;
    int numberOfSeats;
    bool isConvertible;
    int n;
    int choice;


    cin >> choice;
    if (choice == 1) {
        cin >> model;
       // LuxurySportsVehicle luxurySportsVehicle(reinterpret_cast<int>(model), reinterpret_cast<const char *>(740), 355, 13, 2, false);
        //luxurySportsVehicle.displayInfo();
    }
    else {
        cin >> n;

        Vehicle** v = new Vehicle*[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> model >> enginePower >> maximumSpeed >> fuelEfficiency >> numberOfSeats;
                v[i] = new LuxuryVehicle(reinterpret_cast<const char *>(model), enginePower, maximumSpeed, fuelEfficiency, numberOfSeats);
            }
            else {
                cin >> model >> enginePower >> maximumSpeed >> fuelEfficiency >> isConvertible;
                v[i] = new SportsVehicle(reinterpret_cast<const char *>(model), enginePower, maximumSpeed, fuelEfficiency, isConvertible);
            }
        }

        mostPowerfulLuxuryVehicle(v, n)->displayInfo();
    }

    return 0;
}
