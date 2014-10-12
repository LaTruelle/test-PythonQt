#ifndef TESTPYTHON_H
#define TESTPYTHON_H

#include <QMainWindow>

namespace Ui {
class TestPython;
}

class TestPython : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestPython(QWidget *parent = 0);
    ~TestPython();

private slots:
    void on_pushButton_clicked();
    void pythonStdOut(QString pythonStdOut);

private:
    Ui::TestPython *ui;
    void executePythonScript();
};

#endif // TESTPYTHON_H
