#include <QCoreApplication>
#include <QDebug>

#include "csvtools.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "hello world!" << endl;

    //CsvTools csvTool("C://Users/Durcak/Downloads/xccc.csv");
    //CsvTools csvTool("C://Users/Durcak/Downloads/organisations-dump.csv");
    CsvTools csvTool("D:/csvSQLtest/vztahy.csv");

    //csvTool.saveFileToDBFirmy();

    csvTool.convertFile();

    return a.exec();
}
