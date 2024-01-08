#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  //    one approach to handling the sinals in one slot
  signalMap = new QSignalMapper(this);

  connect(ui->add, SIGNAL(clicked()), signalMap, SLOT(map()));
  signalMap->setMapping(ui->add, "+");

  connect(ui->subtract, SIGNAL(clicked()), signalMap, SLOT(map()));
  signalMap->setMapping(ui->subtract, "-");

  connect(ui->multiply, SIGNAL(clicked()), signalMap, SLOT(map()));
  signalMap->setMapping(ui->multiply, "*");

  connect(ui->divide, SIGNAL(clicked()), signalMap, SLOT(map()));
  signalMap->setMapping(ui->divide, "/");

  connect(signalMap, SIGNAL(mappedString(QString)), this,
          SLOT(handleClicks(QString)));
  connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::resetGUI);
}

MainWindow::~MainWindow() {
  delete ui;
  delete signalMap;
  opFactory->deleteInstance();
}

void MainWindow::resetGUI() {
  ui->x->setValue(0.00);
  ui->y->setValue(0.00);
  ui->result->display(0.00);
}

void MainWindow::handleClicks(QString op) {
  ui->result->clearMask();

  Operation *tempOpr;
  tempOpr = opFactory->createOperation(op);
  if (tempOpr != NULL) {
    double answer = tempOpr->compute(ui->x->value(), ui->y->value());
    if (isnanf(answer)) // division by 0
      ui->result->display("Err1");
    else if (QString::number(answer).size() > ui->result->digitCount())
      ui->result->display("Err2");
    else
      ui->result->display(answer);
    delete tempOpr;
  } else
    ui->result->display("Err3");
}
