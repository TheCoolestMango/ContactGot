#include "session.h"
#include "ui_session.h"
#include "mainwindow.h"
#include <QTextStream>
#include <QFile>

Session::Session(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Session)
{
    ui->setupUi(this);
}

Session::~Session()
{
    delete ui;
}

void Session::on_fioLineEdit_textEdited(const QString &arg1)
{
    this->fio = arg1;
}


void Session::on_emailLineEdit_textEdited(const QString &arg1)
{
    this->email = arg1;
}


void Session::on_phoneLineEdit_textEdited(const QString &arg1)
{
    this->phone = arg1;
}


void Session::setEventName(QString name){
    this->file_name = "D:\\data\\" + name + ".csv";
    QFile file(this->file_name);
    file.open(QIODevice::WriteOnly);
    file.close();
}

void Session::on_saveButton_clicked()
{
    QFile file(file_name);
    QStringList strList;
    /*Считываем исходный файл в контейнер*/
    if (file.open(QIODevice::ReadOnly))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        }
        file.close();
    }
    strList.append(fio + "," + email + "," + phone + "\n");
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        foreach(QString s, strList)
        {
            stream<<s;
        }
        file.close();
    }
    ui->fioLineEdit->setText("");
    ui->emailLineEdit->setText("");
    ui->phoneLineEdit->setText("");
    fio = "";
    phone = "";
    email = "";
}


void Session::on_finishButton_clicked()
{
    on_saveButton_clicked();
    file_name = "";
    this->hide();
    emit firstWindow();
}
