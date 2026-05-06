#include <iostream>
#include <cmath>

int main() {
    std::cout << "trapezoid\n";

    double a, b, c, d, h;

    auto input = [](const char* name) {
        double x;
        do {
            std::cout << name << " = ";
            std::cin >> x;
            if (std::cin.fail() || x <= 0) {
                std::cout << "ERROR\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                x = -1;
            }
        } while (x <= 0);
        return x;
        };

    a = input("Bottom base");
    b = input("Top base");
    c = input("Left side");
    d = input("Right side");
    h = input("Height");

    // основания должны быть разными
    if (a == b) {
        std::cout << "ERROR\n";
        return 0;
    }

    //стороны должны быть больше высоты
    if (c <= h || d <= h) {
        std::cout << "ERROR\n";
        return 0;
    }

    // p1 и p2 проекции боковых сторон
    double p1 = sqrt(c * c - h * h);
    double p2 = sqrt(d * d - h * h);
    if (a - b > p1 + p2) {
        std::cout << "ERROR\n";
        return 0;
    }

    std::cout << "Perimeter = " << a + b + c + d << "\n"
        << "Area = " << ((a + b) / 2) * h << "\n"
        << "Midline length = " << (a + b) / 2 << std::endl;
}
