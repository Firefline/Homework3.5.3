// Homework3.5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure
{
protected:
    std::string name = "Фигура";
    int sides_count = 0;
    int a = 0, b = 0, c = 0, d = 0;
    int A = 0, B = 0, C = 0, D = 0;
public:
    std::string get_name()
    {
        return name;
    }
    int get_sides_count()
    {
        return sides_count;
    }
    int get_a()
    {
        return a;
    }
    int get_b()
    {
        return b;
    }
    int get_c()
    {
        return c;
    }
    int get_d()
    {
        return d;
    }
    int get_A()
    {
        return A;
    }
    int get_B()
    {
        return B;
    }
    int get_C()
    {
        return C;
    }
    int get_D()
    {
        return D;
    }
    virtual bool check()
    {
        if (sides_count == 0)
        {
            return true;
        }
        else { return false; }
    }
    virtual void print_info()
    {
        std::cout << get_name() << ": " << std::endl;
        if (check() == true)
        {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
    }
};
class Triangle : public Figure
{
public:
    Triangle(int a, int b, int c, int A, int B, int C) : Figure()
    {
        name = "Треугольник";
        sides_count = 3;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    bool check() override
    {
        if (sides_count == 3 && (A+B+C == 180))
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    }
};
class Right_triangle : public Triangle
{
public:
    Right_triangle(int a, int b, int c, int A, int B) : Triangle(0, 0, 0, 0, 0, 0)
    {
        name = "Прямоугольный треугольник";
        sides_count = 3;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        C = 90;
    }
    bool check() override
    {
        if (C == 90)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Isosceles_triangle : public Triangle
{
public:
    Isosceles_triangle(int a, int b, int A, int B) : Triangle(0, 0, 0, 0, 0, 0)
    {
        name = "Равнобедренный треугольник";
        sides_count = 3;
        this->a = a;
        this->b = b;
        c = a;
        this->A = A;
        this->B = B;
        C = A;
    }
    bool check() override
    {
        if (a == c && A == C)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Equilateral_triangle : public Triangle
{
public:
    Equilateral_triangle(int a) : Triangle(0, 0, 0, 0, 0, 0)
    {
        name = "Равносторонний треугольник";
        sides_count = 3;
        this->a = a;
        b = a;
        c = a;
        A = 60;
        B = A;
        C = A;
    }
    bool check() override
    {
        if (a == b && b == c && a == c && A == 60 && B == 60 && C == 60)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Quadrangle : public Figure
{
public:
    Quadrangle(int a, int b) : Figure()
    {
        name = "Четырёхугольник";
        sides_count = 4;
        this->a = a;
        this->b = b;
        c = a;
        d = b;
        A = 90;
        B = A;
        C = A;
        D = A;
    }
    bool check() override
    {
        if (sides_count == 4 && (A + B + C + D == 360))
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
    }
};
class Square : public Quadrangle
{
public:
    Square(int a) : Quadrangle(0, 0)
    {
        name = "Квадрат";
        sides_count = 4;
        this->a = a;
        b = a;
        c = a;
        d = a;
        A = 90;
        B = A;
        C = A;
        D = A;
    }
    bool check() override
    {
        if (a == b && b == c && c == d && a == c && a == d && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Quadrangle::print_info();
    }
};
class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(0, 0)
    {
        name = "Параллелограмм";
        sides_count = 4;
        this->a = a;
        this->b = b;
        c = a;
        d = b;
        this->A = A;
        this->B = B;
        C = A;
        D = B;
    }
    bool check() override
    {
        if (a == c && b == d && A == C && B == D)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Quadrangle::print_info();
    }
};
class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b) : Parallelogram(0, 0, 0, 0)
    {
        name = "Прямоугольник";
        sides_count = 4;
        this->a = a;
        this->b = b;
        c = a;
        d = b;
        A = 90;
        B = A;
        C = A;
        D = A;
    }
    bool check() override
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Parallelogram::print_info();
    }
};
class Rhomb : public Parallelogram
{
public:
    Rhomb(int a, int A, int B) : Parallelogram(0, 0, 0, 0)
    {
        name = "Ромб";
        sides_count = 4;
        this->a = a;
        b = a;
        c = a;
        d = a;
        this->A = A;
        this->B = B;
        C = A;
        D = B;
    }
    bool check() override
    {
        if (a == b && b == c && c == d && a == c && a == d && b == d && A == C && B == D)
        {
            return true;
        }
        else { return false; }
    }
    void print_info() override
    {
        Parallelogram::print_info();
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle(10, 20, 30, 50, 60);
    Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
    Equilateral_triangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhomb rhomb(30, 30, 40);

    figure.print_info();
    std::cout << std::endl;
    triangle.print_info();
    right_triangle.print_info();
    isosceles_triangle.print_info();
    equilateral_triangle.print_info();
    quadrangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rectangle.print_info();
    rhomb.print_info();
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
