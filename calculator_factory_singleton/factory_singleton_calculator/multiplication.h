#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : public Operation {
public:
  Multiplication();
  ~Multiplication();
  double compute(double x, double y);
};

#endif // MULTIPLICATION_H
