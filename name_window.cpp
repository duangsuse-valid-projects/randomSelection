#include "ui_namedialog.h"

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QTimer>

class NameDialog: public QDialog, Ui::Dialog
{
public:
  NameDialog(QWidget *parent = 0, QString *name = nullptr, int width = 941, int height = 561);
};

NameDialog::NameDialog(QWidget *parent, QString *name, int width, int height): QDialog(parent)
{
  setupUi(this);
  setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  label->setText(*name);
  resize(width + 40, height + 20);
  label->setGeometry(QRect(30, 20, width, height));
  QTimer::singleShot(3000, this, SLOT(close()));
}
