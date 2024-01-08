#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "operation.h"

class Subtraction : public Operation {
public:
  Subtraction();
  ~Subtraction();
  double compute(double x, double y);
};

#endif // SUBTRACTION_H
