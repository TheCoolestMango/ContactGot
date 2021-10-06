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

void Session::on_isApplicant_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->status = "Абитуриент";
        ui->isParent->setCheckState(Qt::Unchecked);
    }else{
        this->status = "";
    }
}

void Session::on_isParent_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->status = "Родитель";
        ui->isApplicant->setCheckState(Qt::Unchecked);
    }else{
        this->status = "";
    }
}

void Session::on_isBachelor_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->degree = "Бакалавриат";
        ui->isMaster->setCheckState(Qt::Unchecked);
    }else{
        this->degree = "";
    }
}

void Session::on_isMaster_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->degree = "Магистратура";
        ui->isBachelor->setCheckState(Qt::Unchecked);
    }else{
        this->degree = "";
    }
}

void Session::on_isApply_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->apply = "Подготовка к поступлению";
    }else{
        this->apply = "";
    }
}

void Session::on_isOlimp_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        this->olimp = "Подготовка к олимпиадам";
    }else{
        this->olimp = "";
    }
}

void Session::on_additionalInfo_textChanged()
{
    this->additionalInfo = ui->additionalInfo->toPlainText();
}

void Session::setEventName(QString name)
{
    this->db.define_name(name);
}

void Session::toDefault(){
    fio = "";
    email = "";
    status = "";
    degree = "";
    apply = "";
    olimp = "";
    additionalInfo = "";
    ui->fioLineEdit->setText("");
    ui->emailLineEdit->setText("");

    ui->isApplicant->setCheckState(Qt::Unchecked);
    ui->isParent->setCheckState(Qt::Unchecked);
    ui->isBachelor->setCheckState(Qt::Unchecked);
    ui->isMaster->setCheckState(Qt::Unchecked);
    ui->isApply->setCheckState(Qt::Unchecked);
    ui->isOlimp->setCheckState(Qt::Unchecked);
    ui->additionalInfo->setText("");
}

void Session::on_saveButton_clicked()
{
    db.add_request(QStringList{fio, email, status, degree, apply, olimp, additionalInfo});
    toDefault();
}


void Session::on_finishButton_clicked()
{
    on_saveButton_clicked();
    this->hide();
    emit firstWindow();
}
