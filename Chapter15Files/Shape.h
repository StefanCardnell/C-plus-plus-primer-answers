#ifndef SHAPE
#define SHAPE

#include <string>
#include <cmath> //sqrt needed

class Shape{
public:
    Shape() = default;
    Shape(const Shape&) = default;
    Shape(Shape&&) = default;
    Shape& operator=(const Shape&) = default;
    Shape& operator=(Shape&&) = default;
    virtual ~Shape() = default;

    virtual unsigned get_dimension() const = 0; //feature common to the derived Dimension classes and Geometrical shapes.
    virtual void draw() const = 0; //feature common to all Geometrical shapes: draws the object.
protected:
    static constexpr double pi = 3.14159;
};





class DimensionOne : public Shape {
public:
    unsigned get_dimension() const override final { return 1; }
    virtual double length() const = 0;
};


class DimensionTwo : public Shape {
public:

    unsigned get_dimension() const override final { return 2; }
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

class DimensionThree : public Shape {
public:

    unsigned get_dimension() const override final { return 3; }
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;
};







//2D SHAPES

class Rectangle : public DimensionTwo {
public:
    Rectangle() = default;
    Rectangle(double a): DimensionTwo(), length(a), width(a) { }
    Rectangle(double x, double y): DimensionTwo(), length(x), width(y) { }

    void draw() const override { }
    double perimeter() const override { return 2 * (length + width);}
    double area() const override { return length * width;}
private:
    double length = 0, width = 0;
};

class Circle : public DimensionTwo {
public:
    Circle() = default;
    Circle(double r): DimensionTwo(), radius(r) { }

    void draw() const override { }
    double perimeter() const override { return 2 * pi * radius;}
    double area() const override { return pi* radius * radius;}
private:
    double radius = 0;
};




//3D SHAPES

class Box : public DimensionThree {
public:
    Box() = default;
    Box(double a): DimensionThree(), length(a), width(a), height(a) { }
    Box(double x, double y, double z): DimensionThree(), length(x), width(y), height(z) { }

    void draw() const override { }
    double surfaceArea() const override { return (2 * length * height) + (2 * width * height) + (2 * length * width);}
    double volume() const override { return length * width * height;}
private:
    double length = 0, width = 0, height = 0;
};

class Sphere : public DimensionThree {
public:
    Sphere() = default;
    Sphere(double r): DimensionThree(), radius(r) { }

    void draw() const override { }
    double surfaceArea() const override { return (4 * pi * radius * radius); }
    double volume() const override { return (4 * pi * radius * radius * radius)/3;}
private:
    double radius = 0;
};

class Cone: public DimensionThree {
public:
    Cone() = default;
    Cone(double b, double h): DimensionThree(), base(b), height(h) { }

    void draw() const override { }
    double surfaceArea() const override { return pi * base * (base + sqrt(base * base + height * height)); }
    double volume() const override { return (pi * base * base * height)/3;}
private:
    double base = 0, height = 0;
};


#endif // SHAPE
