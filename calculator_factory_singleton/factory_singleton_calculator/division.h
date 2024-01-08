#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

class Division : public Operation {
public:
  Division();
  ~Division();
  double compute(double x, double y);
};

#endif // DIVISION_H
