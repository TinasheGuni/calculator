#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QSignalMapper>
#include <QtWidgets>

class Calculator : public QWidget {
  Q_OBJECT
public:
  explicit Calculator(QWidget *parent = nullptr);

private:
  QDoubleSpinBox *x = nullptr;
  QDoubleSpinBox *y = nullptr;
  QLCDNumber *displayAnswer = nullptr;
  QPushButton *add = nullptr;
  QPushButton *subtract = nullptr;
  QPushButton *divide = nullptr;
  QPushButton *multiply = nullptr;
  QPushButton *clear = nullptr;
};

#endif // CALCULATOR_H
