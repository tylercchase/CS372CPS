//
// Created by Chris Hartman on 3/5/21.
//

#ifndef CS372CPS_SHAPE_HPP
#define CS372CPS_SHAPE_HPP

#include <memory>
#include <string>
#include <vector>

class Shape;
using ShapePtr = std::shared_ptr<Shape>;

class Shape {
private:
public:
   [[nodiscard]] virtual double getHeight() const = 0;
   [[nodiscard]] virtual double getWidth() const = 0;
   [[nodiscard]] virtual std::string getPostScript() const = 0;
};

class Circle : public Shape {
private:
   double _radius;

public:
   explicit Circle(double radius);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
};

class Rectangle : public Shape {
private:
   double _width;
   double _height;

public:
   explicit Rectangle(double width, double height);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
};

class Spacer : public Shape {
private:
   double _width;
   double _height;

public:
   explicit Spacer(double width, double height);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
};

class Polygon : public Shape {
private:
   int _numSides;
   double _sideLength;

public:
   Polygon(int numSides, double sideLength);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
};

class Triangle : public Polygon {
public:
   explicit Triangle(double sideLength);
};

class Square : public Polygon {
public:
   explicit Square(double sideLength);
};

class ScaledShape : public Shape {
public:
   explicit ScaledShape(ShapePtr shape, double xScale, double yScale);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
private:
   ShapePtr _shape;
   double _xScale;
   double _yScale;
};

enum class Rot {R90,R180,R270};

class RotatedShape : public Shape {
public:
   explicit RotatedShape(ShapePtr shape, Rot rotation);
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   [[nodiscard]] std::string getPostScript() const override;
private:
   ShapePtr _shape;
   Rot _rotation;
};
class MultipleShape: public Shape {
   public:
      MultipleShape(const std::initializer_list<ShapePtr> shapes);
      std::string getPostScript() const;
   protected:
      std::vector<ShapePtr> getShapes() const {return _shapes;};
      virtual std::string moveToPositionForShape(int i) const = 0;
      std::vector<ShapePtr> _shapes;
};
class LayeredShape : public MultipleShape {
public:
   using MultipleShape::MultipleShape;
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   std::string moveToPositionForShape(int i) const;
};

class VerticalShape : public MultipleShape {
public:
   using MultipleShape::MultipleShape;
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   // [[nodiscard]] std::string getPostScript() const override;
   std::string moveToPositionForShape(int i) const;
};

class HorizontalShape : public MultipleShape {
public:
   using MultipleShape::MultipleShape;
   [[nodiscard]] double getHeight() const override;
   [[nodiscard]] double getWidth() const override;
   // [[nodiscard]] std::string getPostScript() const override;
   std::string moveToPositionForShape(int i) const;
};

ShapePtr makeCircle(double radius);
ShapePtr makeRectangle(double width, double height);
ShapePtr makeSpacer(double width, double height);
ShapePtr makePolygon(int numSides, double sideLength);
ShapePtr makeTriangle(double sideLength);
ShapePtr makeSquare(double sideLength);
ShapePtr makeScaledShape(ShapePtr shape, double xScale, double yScale);
ShapePtr makeRotatedShape(ShapePtr shape, Rot rotation);
ShapePtr makeLayeredShape(std::initializer_list<ShapePtr> shapes);
ShapePtr makeVerticalShape(std::initializer_list<ShapePtr> shapes);
ShapePtr makeHorizontalShape(std::initializer_list<ShapePtr> shapes);
#endif//CS372CPS_SHAPE_HPP
