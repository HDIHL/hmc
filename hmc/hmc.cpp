#include <iostream>   

using namespace std;


class Figure {
public:
    virtual double GetArea() const = 0;
    virtual ~Figure() {}
};


class Rectangle : public Figure {
private:
    double width, height; 
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double GetArea() const override {
        return width * height;
    }
};


class Circle : public Figure {
private:
    double radius; 
    static constexpr double PI = 3.14; 
public:
    Circle(double r) : radius(r) {}

    double GetArea() const override {
        return PI * radius * radius;
    }
};


class Triangle : public Figure {
private:
    double base, height; 
public:
    Triangle(double b, double h) : base(b), height(h) {}

    double GetArea() const override {
        return 0.5 * base * height;
    }
};

int main() {

    int choice;
    Figure* fig = nullptr; 

    
    cout << "Choose a figure:\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Triangle\n";
    cout << "Your choice: ";
    cin >> choice;

    
    switch (choice) {
    case 1: {
        double w, h;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;
        fig = new Rectangle(w, h); 
        break;
    }
    case 2: {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        fig = new Circle(r); 
        break;
    }
    case 3: {
        double b, h;
        cout << "Enter base: ";
        cin >> b;
        cout << "Enter height: ";
        cin >> h;
        fig = new Triangle(b, h); 
        break;
    }
    default:
        cout << "error" << endl;
        return 0;
    }

    
    if (fig) {
        cout << "Area of the figure: " << fig -> GetArea() << endl;
        delete fig;
    }

    return 0;
}

