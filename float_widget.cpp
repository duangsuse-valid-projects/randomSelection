#include "float_widget.h"
#include "name_window.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QLabel>
#include <QBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QPalette>

#define LABEL_TEXT "点名"

QTextStream out(stdout);

Widget::Widget(QWidget *parent, int fontSize): QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint)
{
  QLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
  QLabel *label = new QLabel;

  QPalette plat = label->palette();
  plat.setColor(label->backgroundRole(), QColor(0x3f, 0x51, 0xb5, 150));
  plat.setColor(label->foregroundRole(), Qt::white);
  label->setPalette(plat);

  label->setFrameStyle(QFrame::Sunken);
  label->setAlignment(Qt::AlignCenter);

  auto font = label->font();
  font.setPointSize(fontSize);
  label->setFont(font);
  label->setText(LABEL_TEXT);

  layout->addWidget(label);
  setLayout(layout);

  adjustSize();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    relativePos = this->pos() - event->globalPos();
  }
  else if (event->button() == Qt::RightButton)
  {
    emit exitRequested();
  }

  pressedTime = event->timestamp();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton && (event->timestamp() - pressedTime) < 100)
  {
    int select_index = rand() % names->length() - 1;
    auto selection = names->at(select_index);
    out << "Make choice: " << selection << " (at " << select_index << ")" << endl;

    bool is_ok;
    int wid = qgetenv("RS_NAMEWIDTH").toInt(&is_ok);
    if (!is_ok)
      wid = 941;
    int hei = qgetenv("RS_NAMEHEIGTH").toInt(&is_ok);
    if (!is_ok)
      hei = 561;

    NameDialog nd(0, &selection, wid, hei);
    nd.exec();
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
  this->move(event->globalPos() + relativePos);
}

void Widget::setNames(QVector<QString> *names)
{
  this->names = names;
}

Widget::~Widget()
{
  delete names;
}
