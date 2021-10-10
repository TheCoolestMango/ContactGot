#include "session.h"
#include "ui_session.h"
#include "mainwindow.h"

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

//The on_fioLineEdit_textEdited, on_emailLineEdit_textEdited and on_additionalInfo_textChanged methods are to receive text fields if the user changes them
void Session::on_fioLineEdit_textEdited(const QString &arg1)
{
    this->fio = arg1;
}

void Session::on_emailLineEdit_textEdited(const QString &arg1)
{
    this->email = arg1;
}

void Session::on_additionalInfo_textChanged()
{
    this->additionalInfo = ui->additionalInfo->toPlainText();
}

//all stateChanged methods are to get the state of the QCheckBox when the user's states change.
//since the boxes (Абитуриент and Родитель) or (Бакалавриат and Магистратура) cannot be clicked at the same time,
//if a conflict occurs, the user's last selection is retained while another QCheckBox becomes visually unselected
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

//get the file name from the main window and define to the class responsible for handling the files
void Session::setEventName(QString name)
{
    this->db.define_name(name);
}

//clearing all fields after the session is over
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

//sending to record the values received from the user and clearing the fields for the new user
void Session::on_saveButton_clicked()
{
    db.add_record(QStringList{fio, email, status, degree, apply, olimp, additionalInfo});
    toDefault();
}

//saving user fields, hiding the session window and calling up the main window
void Session::on_finishButton_clicked()
{
    on_saveButton_clicked();
    this->hide();
    emit firstWindow();
}
