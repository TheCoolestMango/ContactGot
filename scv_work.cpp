#include "scv_work.h"
#include <QFile>
#include <QTextStream>

//qt6 does not support writing to a russian language file due to the utf-8 encoding, which is why transliteration is used for stable operation
SCV_work::SCV_work(){
    QList<QString> rus = {" ", "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я", "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"};
    QList<QString> eng = {" ", "a", "b", "v", "g", "d", "e", "yo", "zh", "z", "i", "j", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "c", "ch", "sh", "shh", "\'\'", "y", "\'", "e\'", "ju", "ja", "A", "B", "V", "G", "D", "E", "YO", "ZH", "Z", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "H", "C", "CH", "SH", "SHH", "\'\'", "Y", "\'", "E\'", "JU", "JA"};
    for (int i = 0; i < rus.length(); i++)
        toTranslit[rus[i]] = eng[i];
}

//retrieve a file name from the main window
void SCV_work::define_name(QString filename)
{
    this->name = "D:\\data\\" + filename + ".csv";
}

//clearing the filename after the session has ended
void SCV_work::delete_name(){
    name = "";
}

//check that the file has been created and, if necessary, create a file
void SCV_work::checkFile(){
    file.setFileName(name);
    if (!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}

//adding a record to a csv file
void SCV_work::add_record(QStringList strList){
    file.setFileName(name);
    checkFile();

    if (file.open(QIODevice::Append)){
        QTextStream out(&file);

        out << SCV_work::translate(strList[0]);
        for (int i = 1; i < strList.size(); i++)
            out << "," << translate(strList[i]);
        out << "\n";
        file.close();
    }
}

//transliteration of russian letters
QString SCV_work::translate(QString s){
    QString res = "";
    for (int i = 0; i < s.length(); i++){
        if (toTranslit.contains(s[i]))
            res += toTranslit[s[i]];
        else
            res += s[i];
    }
    return res;
}
