#include <iostream>
#include <cmath>

class Equation {
public:
    virtual void calculateRoots() = 0; 

    virtual ~Equation() {
        std::cout << "Destructor of Equation" << std::endl;
    }
};

class LinearEquation : public Equation {
private:
    double a, b; 

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void calculateRoots() override {
        if (a != 0) {
            double root = -b / a;
            std::cout << "Linear equation root: " << root << std::endl;
        }
        else {
            std::cout << "Not a linear equation (a = 0)" << std::endl;
        }
    }

    ~LinearEquation() override {
        std::cout << "Destructor of LinearEquation" << std::endl;
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c; 

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void calculateRoots() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Quadratic equation roots: " << root1 << " and " << root2 << std::endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "Quadratic equation has a double root: " << root << std::endl;
        }
        else {
            std::cout << "Quadratic equation has complex roots" << std::endl;
        }
    }

    ~QuadraticEquation() override {
        std::cout << "Destructor of QuadraticEquation" << std::endl;
    }
};

int main() {
    Equation* linear = new LinearEquation(2, -3);
    linear->calculateRoots();
    delete linear;

    Equation* quadratic = new QuadraticEquation(1, -3, 2);
    quadratic->calculateRoots();
    delete quadratic;

    return 0;
}
