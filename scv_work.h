#ifndef SCV_WORK_H
#define SCV_WORK_H

#include <QString>
#include <QFile>

class SCV_work
{
public:
    SCV_work();
    void define_name(QString);
    void add_request(QStringList);
    void delete_name();

private:
    void checkFile();
    QFile file;
    QString name;
};

#endif // SCV_WORK_H
