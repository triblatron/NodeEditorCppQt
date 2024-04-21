#include "nodeeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NodeEditor w;
    w.show();
    return a.exec();
}
