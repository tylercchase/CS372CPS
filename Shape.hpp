//
// Created by Chris Hartman on 3/5/21.
//

#ifndef CS372CPS_SHAPE_HPP
#define CS372CPS_SHAPE_HPP

#include <memory>
#include <string>

class Shape {
private:
public:
   [[nodiscard]] virtual double getHeight() const = 0;
   [[nodiscard]] virtual double getWidth() const = 0;
   [[nodiscard]] virtual std::string getPostScript() const = 0;
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

std::shared_ptr<Shape> makePolygon(int numSides, double sideLength);
std::shared_ptr<Shape> makeTriangle(double sideLength);
std::shared_ptr<Shape> makeSquare(double sideLength);

#endif//CS372CPS_SHAPE_HPP
