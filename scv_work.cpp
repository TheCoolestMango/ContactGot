#include "scv_work.h"
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QTextCodec>
#include <QMap>

SCV_work::SCV_work(){
    toTranslit[" "] = " ";
    toTranslit["а"] = 'a';
    toTranslit["б"] = 'b';
    toTranslit["в"] = 'v';
    toTranslit["г"] = 'g';
    toTranslit["д"] = 'd';
    toTranslit["е"] = 'e';
    toTranslit["ё"] = "yo";
    toTranslit["ж"] = "zh";
    toTranslit["з"] = 'z';
    toTranslit["и"] = 'i';
    toTranslit["й"] = 'j';
    toTranslit["к"] = 'k';
    toTranslit["л"] = 'l';
    toTranslit["м"] = 'm';
    toTranslit["н"] = 'n';
    toTranslit["о"] = 'o';
    toTranslit["п"] = 'p';
    toTranslit["р"] = 'r';
    toTranslit["с"] = 's';
    toTranslit["т"] = 't';
    toTranslit["у"] = 'u';
    toTranslit["ф"] = 'f';
    toTranslit["х"] = 'h';
    toTranslit["ц"] = 'c';
    toTranslit["ч"] = "ch";
    toTranslit["ш"] = "sh";
    toTranslit["щ"] = "shh";
    toTranslit["ъ"] = "\'\'";
    toTranslit["ы"] = 'y';
    toTranslit["ь"] = '\'';
    toTranslit["э"] = "e\'";
    toTranslit["ю"] = "ju";
    toTranslit["я"] = "ja";
    toTranslit["А"] = 'A';
    toTranslit["Б"] = 'B';
    toTranslit["В"] = 'V';
    toTranslit["Г"] = 'G';
    toTranslit["Д"] = 'D';
    toTranslit["Е"] = 'E';
    toTranslit["Ё"] = "YO";
    toTranslit["Ж"] = "ZH";
    toTranslit["З"] = 'Z';
    toTranslit["И"] = 'I';
    toTranslit["Й"] = 'J';
    toTranslit["К"] = 'K';
    toTranslit["Л"] = 'L';
    toTranslit["М"] = 'M';
    toTranslit["Н"] = 'N';
    toTranslit["О"] = 'O';
    toTranslit["П"] = 'P';
    toTranslit["Р"] = 'R';
    toTranslit["С"] = 'S';
    toTranslit["Т"] = 'T';
    toTranslit["У"] = 'U';
    toTranslit["Ф"] = 'F';
    toTranslit["Х"] = 'H';
    toTranslit["Ц"] = 'C';
    toTranslit["Ч"] = "CH";
    toTranslit["Ш"] = "SH";
    toTranslit["Щ"] = "SHH";
    toTranslit["Ъ"] = "\'\'";
    toTranslit["Ы"] = 'Y';
    toTranslit["Ь"] = '\'';
    toTranslit["Э"] = "E\'";
    toTranslit["Ю"] = "JU";
    toTranslit["Я"] = "JA";
}


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
//        QTextCodec *codec = QTextCodec::codecForName("CP866");

        QTextStream out(&file);

        out << SCV_work::translate(strList[0]);
        for (int i = 0; i < strList.size(); i++)
            out << "," << translate(strList[i]);
        out << "\n";
        file.close();
    }
}

QString SCV_work::translate(QString s){
    QString res = "";
    for (int i = 0; i < s.length(); i++){
        res += toTranslit[s[i]];
    }
    return res;
}
