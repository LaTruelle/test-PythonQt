#include <PythonQt.h>
#include "testpython.h"
#include "ui_testpython.h"

TestPython::TestPython(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestPython)
{
    // Initialize Python
    PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut);
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
    mainModule.evalScript("import time;");
    mainModule.evalScript("import sys;");
    mainModule.evalScript("def ttime():\n  return time.ctime(time.time());\n");
    mainModule.evalScript("def pyVersion():\n  return sys.version;\n");
    QVariant out = mainModule.call("ttime");
    ui->textBrowser->append(out.toString());
    out = mainModule.call("pyVersion");
    ui->textBrowser->append(out.toString());
    mainModule.evalScript("print(ttime())\n");
    mainModule.evalScript("print(pyVersion())\n");
}

void TestPython::pythonStdOut(QString pythonStdOut)
{
    qDebug() << pythonStdOut;
}
