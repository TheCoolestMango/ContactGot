#ifndef SESSION_H
#define SESSION_H

#include <QWidget>
#include <QString>
#include "scv_work.h"
#include <QStringList>

namespace Ui {
class Session;
}

class Session : public QWidget
{
    Q_OBJECT

public:
    explicit Session(QWidget *parent = nullptr);
    ~Session();
    void setEventName(QString);

signals:
    void firstWindow();

private slots:
    void on_fioLineEdit_textEdited(const QString &arg1);

    void on_saveButton_clicked();

    void on_finishButton_clicked();

    void on_emailLineEdit_textEdited(const QString &arg1);

    void on_isApplicant_stateChanged(int arg1);

    void on_isParent_stateChanged(int arg1);

    void on_isBachelor_stateChanged(int arg1);

    void on_isMaster_stateChanged(int arg1);

    void on_isApply_stateChanged(int arg1);

    void on_isOlimp_stateChanged(int arg1);

    void on_additionalInfo_textChanged();

private:
    void toDefault();
    Ui::Session *ui;
    SCV_work db;
    QString fio, email, status, degree, apply, olimp, additionalInfo;
//    QStringList personal_info;
};

#endif // SESSION_H
