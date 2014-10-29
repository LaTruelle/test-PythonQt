#include <PythonQt.h>
#include "testpython.h"
#include "ui_testpython.h"

TestPython::TestPython(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestPython)
{
    // Initialize Python
    PythonQt::init(PythonQt::RedirectStdOut);
    QObject::connect(PythonQt::self(), SIGNAL(pythonStdOut(QString)), this, SLOT(pythonStdOut(QString)));
    QObject::connect(PythonQt::self(), SIGNAL(pythonStdErr(QString)), this, SLOT(pythonStdOut(QString)));

    // Start ui
    ui->setupUi(this);
}

TestPython::~TestPython()
{
    delete ui;
}

void TestPython::on_pushButton_clicked()
{
    // Action on Start Button clicked
    ui->textBrowser->append("Python Démarré");
    this->executePythonScript();
    ui->textBrowser->append("Fini !");
}

void TestPython::executePythonScript()
{
    // Start Python Scripting
    ui->textBrowser->append("Python script started");
    PythonQtObjectPtr mainModule = PythonQt::self()->getMainModule();
    mainModule.evalScript("import patacrep");
    mainModule.evalScript("import sys");
    mainModule.evalScript("print(sys.path);");
    mainModule.evalScript("print(patacrep)");
    mainModule.evalScript("type(patacrep)");
}

void TestPython::pythonStdOut(QString pythonStdOut)
{
    qDebug() << pythonStdOut;
}
