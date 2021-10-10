#ifndef SCV_WORK_H
#define SCV_WORK_H

#include <QString>
#include <QFile>
#include <QMap>

class SCV_work
{
public:
    SCV_work();
    void define_name(QString);
    void add_record(QStringList);
    void delete_name();
    QString translate(QString);
    QMap<QString, QString> toTranslit;

private:
    void checkFile();
    QFile file;
    QString name;
};

#endif // SCV_WORK_H
