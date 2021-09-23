#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "session.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString get_event_name();

private:
    Ui::MainWindow *ui;
    Session *event;
    QString event_name;

private slots:
    void on_create_session_button_clicked();
    void on_event_name_textEdited(const QString &arg1);
};
#endif // MAINWINDOW_H
