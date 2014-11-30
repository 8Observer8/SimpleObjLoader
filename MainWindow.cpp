#include <QFileDialog>
#include <QDir>
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( this, SIGNAL( signalSetObject( QString ) ),
             ui->sceneWidget, SLOT( slotSetObject( QString ) ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Select File"),
                                QDir::currentPath(),
                                tr("Object Files (*.obj)"));
    if (fileName.isEmpty())
        return;

    emit signalSetObject( fileName );
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
