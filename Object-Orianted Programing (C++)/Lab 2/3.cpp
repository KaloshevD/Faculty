/*Да се дефинира класа Circle во која ќе се чуваат информации за:

name(низа од максимум 100 карактери) -име на кругот

radius(децимален број) - презиме

x(децимален број) - х-координата

y(децимален број) - у - координата

методи кои што класата треба да ги има:

print() 

-Принта во формат:
Circle {name} with radius {radius} and center ({x}, {y})

Да се дефинира класа Canvas во која ќе се чуваат информации за:

name(низа од максимум 100 карактери) -име на канвасот

cirlces(низа од кругови) 

numOfCircles(цел број) - колку вработени има во фирмата 

методи кои што класата треба да ги има:

print() 

-Принта во формат:
Canvas {name} with {num_of_cirlces} circles:

//ги печати сите кругови во канвасот




Сите променливи внатре во класите треба да бидат приватни. Соодветно во рамките на класите да се дефинираат:

конструктор (без и со параметри)

деструктор

set методи

get методи

copy constructor

Функции надвор од класата:


void findCanvasWithLargestCircles(Canvas *canvases, int numCanvases)
- го принта канвасот чии кругови зимаат најголема површина.
*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Circle {
private:
    char name[100];
    double radius;
    double x;
    double y;

public:
    // Default constructor
    Circle() {
        name[0] = '\0';
        radius = 0.0;
        x = 0.0;
        y = 0.0;
    }

    Circle(const char* n, double r, double cx, double cy) : radius(r), x(cx), y(cy) {
        strcpy(name, n);
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* newName) {
        std::strncpy(name, newName, 100);
        name[99] = '\0';
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double newRadius) {
        radius = newRadius;
    }

    double getX() const {
        return x;
    }

    void setX(double newX) {
        x = newX;
    }
    double getY() const {
        return y;
    }

    void setY(double newY) {
        y = newY;
    }

    void print() const {
        std::cout << "Circle " << name << " with radius " << radius << " and center (" << x << ", " << y << ")" << std::endl;
    }

    ~Circle() {
    }

    // Copy constructor
    Circle(const Circle& other) {
        std::strncpy(name, other.name, 100);
        radius = other.radius;
        x = other.x;
        y = other.y;
    }
};

class Canvas {
private:
    char name[100];
    Circle circles[100];
    int numCircles;

public:
    Canvas() {
        name[0] = '\0';
        numCircles = 0;
    }
    const char* getName() const {
        return name;
    }

    void setName(const char* newName) {
        std::strncpy(name, newName, 100);
        name[99] = '\0';
    }

    void setNumCircles(int numCircles) {
        Canvas::numCircles = numCircles;
    }

    int getNumCircles() const {
        return numCircles;
    }

    // Method to add a new circle to the canvas
    void addCircle(const Circle& newCircle) {
        if (numCircles < 100) {
            circles[numCircles] = newCircle;
            numCircles++;
        }
    }

    void print() const {
        std::cout << "Canvas " << name << " with " << numCircles << " circles:" << std::endl;
        for (int i = 0; i < numCircles; i++) {
            circles[i].print();
        }
    }

    ~Canvas() {
    }
    Canvas(const Canvas& other) {
        std::strncpy(name, other.name, 100);
        name[99] = '\0';
        numCircles = other.numCircles;
        for (int i = 0; i < numCircles; i++) {
            circles[i] = other.circles[i];
        }
    }

    Circle& getCircle(int i) {
        return circles[i];
    }
};

void findCanvasWithLargestCircles(Canvas *canvases, int numCanvases) {
    double maxArea = 0;
    int maxCanvasIndex = -1;

    // Find canvas with circles that have the largest total area
    for (int i = 0; i < numCanvases; i++) {
        double totalArea = 0;
        for (int j = 0; j < canvases[i].getNumCircles(); j++) {
            totalArea += M_PI * pow(canvases[i].getCircle(j).getRadius(), 2);
        }
        if (totalArea > maxArea) {
            maxArea = totalArea;
            maxCanvasIndex = i;
        }
    }

    canvases[maxCanvasIndex].print();
}


int main() {
    int numCanvases;
    cin >> numCanvases;

    Canvas canvases[numCanvases];


    for (int i = 0; i < numCanvases; i++) {
        char name[100];
        cin >> name;
        canvases[i].setName(name);

        int numCircles;
        cin >> numCircles;

        canvases[i].setNumCircles(numCircles);

        for (int j = 0; j < numCircles; j++) {
            cin >> name;
            canvases[i].getCircle(j).setName(name);

            double radius;
            cin >> radius;
            canvases[i].getCircle(j).setRadius(radius);

            double x, y;
            cin >> x >> y;
            canvases[i].getCircle(j).setX(x);
            canvases[i].getCircle(j).setY(y);
        }
    }

    cout<<"Test copy constructors"<<endl;
    Canvas canvasCopy = Canvas(canvases[0]);
    canvasCopy.print();
    cout<<"Test function"<<endl;
    findCanvasWithLargestCircles(canvases, numCanvases);

    return 0;
}