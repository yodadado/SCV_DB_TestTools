#ifndef CSVTOOLS_H
#define CSVTOOLS_H

#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include <QStringList>


class CsvTools
{
public:
    CsvTools(const QString &fileName);

    bool convertFile();
    bool saveFileToDBFirmy();

private:
        QString convertLine(const QString &line);

        enum{columnsNumbers = 14};
    QString fileName;
    QTextStream out;

};

#endif // CSVTOOLS_H
