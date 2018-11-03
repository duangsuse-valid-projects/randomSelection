#include "float_widget.h"

#include <QApplication>
#include <QMessageBox>
#include <QTextStream>

#define ITEMS_FILE_NAME "randomItems.txt"

const QString *fileName = new QString(ITEMS_FILE_NAME);
QVector<QString> *names = new QVector<QString>;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QFile file(*fileName);

  if (argc == 2)
  {
    file.setFileName(QString(argv[1]));
  }

  if (!file.open(QIODevice::ReadOnly))
  {
    QMessageBox::information(0, file.errorString(), QString("读取名册文件 ").append(file.fileName()).append(" 失败")
                             .append("\nNOTE：你可以以文件路径为第一个参数启动本程序\nNOTE：在 Windows 上你可以将花名册文件拖动到本程序 exe 文件上执行"));
    app.exit(1);
    return 1;
  }

  QTextStream stream(&file);

  while (!stream.atEnd()) names->push_back(stream.readLine());

  file.close();

  bool is_ok;
  int fsize = qgetenv("RS_FLOATSIZE").toInt(&is_ok);

  if (!is_ok)
    fsize = 30;

  Widget main_float(0, fsize);
  main_float.setNames(names);
  main_float.show();

  QObject::connect(&main_float, SIGNAL(exitRequested()), &app, SLOT(closeAllWindows()));

  return app.exec();
}
