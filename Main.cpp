#include <iostream>
#include <fstream>

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(std::ofstream& file) const = 0;
    virtual void Load(std::ifstream& file) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    double x, y; // координати лівого верхнього кута
    double side; // довжина сторони

public:
    Square(double x, double y, double side) : x(x), y(y), side(side) {}

    void Show() const override {
        std::cout << "Square: Left-top corner at (" << x << ", " << y << "), Side length: " << side << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    double x, y; // координати лівого верхнього кута
    double width, height; // розміри

public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        std::cout << "Rectangle: Left-top corner at (" << x << ", " << y << "), Width: " << width << ", Height: " << height << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    double x, y; // координати центра
    double radius; // радіус

public:
    Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    void Show() const override {
        std::cout << "Circle: Center at (" << x << ", " << y << "), Radius: " << radius << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Circle " << x << " " << y << " " << radius << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
private:
    double x, y; // координати верхнього кута описаного прямокутника
    double width, height; // розміри прямокутника

public:
    Ellipse(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        std::cout << "Ellipse: Top corner at (" << x << ", " << y << "), Width: " << width << ", Height: " << height << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

int main() {
    const int numShapes = 4; // Задайте кількість фігур
    Shape* shapes[numShapes];

    shapes[0] = new Square(1, 2, 3);
    shapes[1] = new Rectangle(0, 0, 4, 2);
    shapes[2] = new Circle(5, 5, 2);
    shapes[3] = new Ellipse(2, 3, 4, 2);

    // Збереження фігур в файл
    std::ofstream outFile("shapes.txt");
    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->Save(outFile);
    }
    outFile.close();

    // Завантаження фігур з файлу
    Shape* loadedShapes[numShapes];
    std::ifstream inFile("shapes.txt");
    std::string shapeType;
    for (int i = 0; i < numShapes; ++i) {
        inFile >> shapeType;
        if (shapeType == "Square") {
            loadedShapes[i] = new Square(0, 0, 0);
        }
        else if (shapeType == "Rectangle") {
            loadedShapes[i] = new Rectangle(0, 0, 0, 0);
        }
        else if (shapeType == "Circle") {
            loadedShapes[i] = new Circle(0, 0, 0);
        }
        else if (shapeType == "Ellipse") {
            loadedShapes[i] = new Ellipse(0, 0, 0, 0);
        }

        loadedShapes[i]->Load(inFile);
    }
    inFile.close();

    // Виведення інформації про кожну фігуру
    for (int i = 0; i < numShapes; ++i) {
        loadedShapes[i]->Show();
    }

    // Вивільнення пам'яті
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
        delete loadedShapes[i];
    }

    return 0;
}
