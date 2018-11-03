#ifndef NAME_WINDOW_H
#define NAME_WINDOW_H

#include <ui_namedialog.h>
class NameDialog: public QDialog, Ui::Dialog
{
public:
  NameDialog(QWidget *parent = 0, QString *name = nullptr, int width = 941, int height = 561);
};

#endif // NAME_WINDOW_H
