#include "testpython.h"
#include <QApplication>

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    TestPython w;
    w.show();

    return a.exec();
}
