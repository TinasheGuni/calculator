#include "operationfactory.h"
#include "addition.h"
#include "division.h"
#include "multiplication.h"
#include "subtraction.h"

OperationFactory *OperationFactory::onlyInstance = NULL;

Operation *OperationFactory::createOperation(QString type) const {
  if (type == "+")
    return new Addition();
  if (type == "-")
    return new Subtraction();
  if (type == "*")
    return new Multiplication();
  if (type == "/")
    return new Division();
  else
    return NULL;
}

OperationFactory *OperationFactory::getInstance() {
  if (onlyInstance == NULL)
    onlyInstance = new OperationFactory();
  return onlyInstance;
}

void OperationFactory::deleteInstance() { delete onlyInstance; }

OperationFactory::OperationFactory() {}
