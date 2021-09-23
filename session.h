#ifndef SESSION_H
#define SESSION_H

#include <QWidget>
#include <QString>

namespace Ui {
class Session;
}

class Session : public QWidget
{
    Q_OBJECT

public:
    explicit Session(QWidget *parent = nullptr);
    ~Session();
    QString getFio();
    QString getPhone();
    QString getEmail();
    void setEventName(QString);
signals:
    void firstWindow();
private slots:
    void on_fioLineEdit_textEdited(const QString &arg1);

    void on_emailLineEdit_textEdited(const QString &arg1);

    void on_phoneLineEdit_textEdited(const QString &arg1);

    void on_saveButton_clicked();

    void on_finishButton_clicked();

private:

    Ui::Session *ui;
    QString file_name;
    QString fio;
    QString phone;
    QString email;
};

#endif // SESSION_H
