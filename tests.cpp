//
// Created by Chris Hartman on 3/5/21.
//
#include <catch2/catch.hpp>
#include "Shape.hpp"
using namespace Catch::literals; //NOLINT

TEST_CASE("Polygon width and height") {
   auto triangle = makePolygon(3,1);
   REQUIRE(triangle->getWidth() == 1.0_a);
   REQUIRE(triangle->getHeight() == Approx(sqrt(3.0)/2.0));
   auto square = makePolygon(4,1);
   REQUIRE(square->getWidth() == 1.0_a);
   REQUIRE(square->getHeight() == 1.0_a);
   auto hexagon = makePolygon(6,1);
   REQUIRE(hexagon->getWidth() == 2.0_a);
   REQUIRE(hexagon->getHeight() == Approx(sqrt(3.0)));
}