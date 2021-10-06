#include "scv_work.h"
#include <QFile>
#include <QTextStream>
#include <fstream>

SCV_work::SCV_work(){}


void SCV_work::define_name(QString filename)
{
    this->name = "D:\\data\\" + filename + ".csv";
}

void SCV_work::delete_name(){
    name = "";
}

void SCV_work::checkFile(){
    file.setFileName(name);
    if (!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}

void SCV_work::add_request(QStringList strList){
//    QString line = strList[0];
//    for (int i = 1; i < strList.size(); i++)
//        line.append(',' + strList[i]);
//    line.append('\n');
    file.setFileName(name);
    checkFile();

    if (file.open(QIODevice::Append))
    {
//        std::string str = line.toStdString();
//        const char* p = str.c_str();
//        file.write(line.toUtf8());
        QTextStream out(&file);
        out << strList[0];
        for (int i = 0; i < strList.size(); i++)
            out << "," << "фывфыв";
        out << "\n";
        file.close();
    }
}
