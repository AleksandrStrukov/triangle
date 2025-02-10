#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x = 0.0;
    double y = 0.0;
};

struct Vector2D {
    double x = 0.0;
    double y = 0.0;
};

Point ReadPoint() {
    Point point;
    cin >> point.x >> point.y;
    return point;
}

void PrintPoint(Point p) {
    cout << "{" << p.x << ", " << p.y << "}";
}

Vector2D PointDifference(Point p1, Point p2) {
    Vector2D vector;
    vector.x = p1.x - p2.x;
    vector.y = p1.y - p2.y;
    return vector;
}

double FindLength(Vector2D v) {
    return hypot(v.x, v.y);
}

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

Triangle ReadTriangle() {
    Triangle tr;
    tr.p1 = ReadPoint();
    tr.p2 = ReadPoint();
    tr.p3 = ReadPoint();
    return tr;
}

double FindPerimeter(const Triangle& t) {
    double per = 0;
    per += FindLength(PointDifference(t.p1, t.p2));
    per += FindLength(PointDifference(t.p2, t.p3));
    per += FindLength(PointDifference(t.p3, t.p1));
    return per;
}

int main() {
    Point point = ReadPoint();

    std::cout << "Read point: ";
    PrintPoint(point);
    std::cout << std::endl;

    Point point_symm = {-point.x, -point.y};

    std::cout << "Symmetric point: ";
    PrintPoint(point_symm);
    std::cout << std::endl;

    // Пример работы с треугольником
    Triangle triangle = ReadTriangle();
    double perimeter = FindPerimeter(triangle);
    std::cout << "Perimeter of the triangle: " << perimeter << std::endl;

    return 0;
}
