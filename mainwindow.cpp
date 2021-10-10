#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "session.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    event = new Session();
    connect(event, &Session::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//clearing the field, hiding the main window and displaying the session window
void MainWindow::on_create_session_button_clicked()
{
    this->ui->event_name->setText("");
    this->hide();
    this->event->setEventName(this->event_name);
    this->event->show();
}

//obtain the name of the file in which the records will be placed
void MainWindow::on_event_name_textEdited(const QString &arg1)
{
    this->event_name = arg1;
}

