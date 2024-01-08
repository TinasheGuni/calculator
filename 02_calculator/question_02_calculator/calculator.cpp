#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), x(new QDoubleSpinBox), y(new QDoubleSpinBox),
      displayAnswer(new QLCDNumber), add(new QPushButton(tr("Add"))),
      subtract(new QPushButton(tr("Subtract"))),
      divide(new QPushButton(tr("Divide"))),
      multiply(new QPushButton(tr("Multiply"))),
      clear(new QPushButton(tr("Clear"))) {
  setWindowTitle(tr("Calculator"));

  x->setMinimum(-9999);
  x->setMaximum(9999);
  y->setMinimum(-9999);
  y->setMaximum(9999);

  auto layout = new QGridLayout;
  layout->addWidget(x, 0, 0);
  layout->addWidget(y, 1, 0);
  layout->addWidget(add, 0, 1);
  layout->addWidget(subtract, 1, 1);
  layout->addWidget(multiply, 2, 1);
  layout->addWidget(divide, 3, 1);
  layout->addWidget(clear, 3, 0);
  layout->addWidget(displayAnswer, 2, 0);
  setLayout(layout);
  this->adjustSize();
}
