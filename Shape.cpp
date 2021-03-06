//
// Created by Chris Hartman on 3/5/21.
//

#include "Shape.hpp"
#include <cmath>
#include <numbers>
using std::numbers::pi;

double Polygon::getHeight() const {
   if (_numSides % 4 == 0)//TODO same as next case?
      return _sideLength*cos(pi/_numSides)/(sin(pi/_numSides));
   if (_numSides % 2 == 0)
      return _sideLength*cos(pi/_numSides)/sin(pi/_numSides);
   return _sideLength*(1+cos(pi/_numSides))/(2*sin(pi/_numSides));
}

double Polygon::getWidth() const {
   if (_numSides % 4 == 0)
      return _sideLength*cos(pi/_numSides)/sin(pi/_numSides);
   if (_numSides % 2 == 0)
      return _sideLength/sin(pi/_numSides);
   return _sideLength*sin(pi*(_numSides-1)/(2*_numSides))/sin(pi/_numSides);
}

std::string Polygon::getPostScript() const {
   return std::string();
}

Polygon::Polygon(int numSides, double sideLength) : _numSides(numSides), _sideLength(sideLength) {
}

std::shared_ptr<Shape> makePolygon(int numSides, double sideLength) {
   return std::make_shared<Polygon>(numSides,sideLength);
}
