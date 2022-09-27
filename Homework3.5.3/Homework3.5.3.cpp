// Homework3.5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure
{
protected:
    std::string name = "Фигура";
    int sides_count = 0;
    bool accuracy;
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
    int get_side_a()
    {
        return a;
    }
    int get_side_b()
    {
        return b;
    }
    int get_side_c()
    {
        return c;
    }
    int get_side_d()
    {
        return d;
    }
    int get_angle_A()
    {
        return A;
    }
    int get_angle_B()
    {
        return B;
    }
    int get_angle_C()
    {
        return C;
    }
    int get_angle_D()
    {
        return D;
    }
    virtual bool check()
    {
        if (sides_count == 0)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
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
    Triangle() : Figure()
    {
        name = "Треугольник";
        sides_count = 3;
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }
    bool check() override
    {
        if (sides_count == 3 && (A+B+C == 180))
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c();
        if (get_side_d() != 0)
        {
            std::cout << " d=" << get_side_d() << std::endl;
        }
        else { std::cout << std::endl; }
        std::cout << "Углы: A=" << get_angle_A() << " B=" << get_angle_B() << " C=" << get_angle_C();
        if (get_angle_D() != 0)
        {
            std::cout << " D=" << get_angle_D() << std::endl;
        }
        else { std::cout << std::endl; }
        std::cout << std::endl;
    }
};
class Right_triangle : public Triangle
{
public:
    Right_triangle() : Triangle()
    {
        name = "Прямоугольный треугольник";
        sides_count = 3;
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 90;
    }
    bool check() override
    {
        if (C == 90)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Isosceles_triangle : public Triangle
{
public:
    Isosceles_triangle() : Triangle()
    {
        name = "Равнобедренный треугольник";
        sides_count = 3;
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 50;
    }
    bool check() override
    {
        if (a == c && A == C)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Equilateral_triangle : public Triangle
{
public:
    Equilateral_triangle() : Triangle()
    {
        name = "Равносторонний треугольник";
        sides_count = 3;
        a = 30;
        b = 30;
        c = 30;
        A = 60;
        B = 60;
        C = 60;
    }
    bool check() override
    {
        if (a == b && b == c && a == c && A == 60 && B == 60 && C == 60)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Triangle::print_info();
    }
};
class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure()
    {
        name = "Четырёхугольник";
        sides_count = 4;
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
    bool check() override
    {
        if (sides_count == 4 && (A + B + C + D == 360))
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c();
        if (get_side_d() != 0)
        {
            std::cout << " d=" << get_side_d() << std::endl;
        }
        else { std::cout << std::endl; }
        std::cout << "Углы: A=" << get_angle_A() << " B=" << get_angle_B() << " C=" << get_angle_C();
        if (get_angle_D() != 0)
        {
            std::cout << " D=" << get_angle_D() << std::endl;
        }
        else { std::cout << std::endl; }
        std::cout << std::endl;
    }
};
class Square : public Quadrangle
{
public:
    Square() : Quadrangle()
    {
        name = "Квадрат";
        sides_count = 4;
        a = 20;
        b = 20;
        c = 20;
        d = 20;
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }
    bool check() override
    {
        if (a == b && b == c && c == d && a == c && a == d && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Quadrangle::print_info();
    }
};
class Parallelogram : public Quadrangle
{
public:
    Parallelogram() : Quadrangle()
    {
        name = "Параллелограмм";
        sides_count = 4;
        a = 20;
        b = 30;
        c = 20;
        d = 30;
        A = 30;
        B = 40;
        C = 30;
        D = 40;
    }
    bool check() override
    {
        if (a == c && b == d && A == C && B == D)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Quadrangle::print_info();
    }
};
class Rectangle : public Parallelogram
{
public:
    Rectangle() : Parallelogram()
    {
        name = "Прямоугольник";
        sides_count = 4;
        a = 10;
        b = 20;
        c = 10;
        d = 20;
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }
    bool check() override
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
    }
    void print_info() override
    {
        Parallelogram::print_info();
    }
};
class Rhomb : public Parallelogram
{
public:
    Rhomb() : Parallelogram()
    {
        name = "Ромб";
        sides_count = 4;
        a = 30;
        b = 30;
        c = 30;
        d = 30;
        A = 30;
        B = 40;
        C = 30;
        D = 40;
    }
    bool check() override
    {
        if (a == b && b == c && c == d && a == c && a == d && b == d && A == C && B == D)
        {
            accuracy = true;
        }
        else { accuracy = false; }
        return accuracy;
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
    Triangle triangle;
    Right_triangle right_triangle;
    Isosceles_triangle isosceles_triangle;
    Equilateral_triangle equilateral_triangle;
    Quadrangle quadrangle;
    Square square;
    Parallelogram parallelogram;
    Rectangle rectangle;
    Rhomb rhomb;

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
