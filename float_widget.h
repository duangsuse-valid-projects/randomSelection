#ifndef FLOAT_WIDGET_H
#define FLOAT_WIDGET_H

#include <QWidget>

#include <QMouseEvent>

#include <QPoint>
#include <QPixmap>

#include <QDesktopServices>
#include <QUrl>

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0, int fontSize = 30);
  void setNames(QVector<QString> *names);
  ~Widget();

private:
  QPoint relativePos;
  ulong pressedTime;
  QVector<QString> *names;

protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

signals:
  void exitRequested();
};

#endif // FLOAT_WIDGET_H
