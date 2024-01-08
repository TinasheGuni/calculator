#include "division.h"
#include "math.h"

Division::Division() {}

Division::~Division() {}

double Division::compute(double x, double y) {
  if (y == 0)
    return NAN;
  return (x / y);
}
