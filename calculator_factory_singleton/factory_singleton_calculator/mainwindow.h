#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>

#include "operationfactory.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void resetGUI();
  void handleClicks(QString op);

private:
  Ui::MainWindow *ui;
  QSignalMapper *signalMap = nullptr;
  OperationFactory *opFactory;
};
#endif // MAINWINDOW_H
