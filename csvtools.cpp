#include "csvtools.h"

// constructor
CsvTools::CsvTools(const QString &fileName)
{
    this->fileName = fileName;
    qDebug() << "CsvTools for file: " << fileName;
}

// convertFile
bool CsvTools::convertFile()
{
    // open file
    if(fileName.isEmpty()){
        //out << "Error: FileName is empty" << endl;
        qDebug() << "Error: FileName is empty" << endl;
        return false;
    }
    // prepare output fileName
    QFileInfo fileInfo(fileName);
    QString outFileName = fileInfo.absolutePath() + "/" + fileInfo.completeBaseName() + "_converted." + fileInfo.suffix();

    //openfiles
    QFile fileIn(fileName);
    QFile fileOut(outFileName);

    if(fileIn.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream fileOutStream(&fileOut);

            fileOutStream.setCodec("UTF-8"); // ...
            fileOutStream.setGenerateByteOrderMark(false);

            long long counter = 0;
            //read & convert each line
            while(!fileIn.atEnd())
            {

                //QString line = QString::fromUtf8(fileIn.readLine());

                //fileOutStream << convertLine(line);

                fileOutStream << counter << ',' << QString::fromUtf8(fileIn.readLine());
                counter++;

                if(counter % 1000 == 0){
                    qDebug() <<  counter ;
                }
            }
            qDebug() <<  "DONE" ;

            // close Files
            fileOut.close();
        }
        fileIn.close();
    }
    else {
        qDebug() << fileName << " - not Exist" ;
        return false;
    }
    return true;
}

// convertLine
QString  CsvTools::convertLine(const QString &line)
{
    QString outLine = line;
    bool inStr = false;

    int length = outLine.length();
    for (int i = 0; i < length; i++){

        if (outLine.at(i) == '"'){
            inStr = !inStr;
        }
        else if ((!inStr) && outLine.at(i) == ','){
            outLine[i] = ';';
        }
        else if (outLine.at(i) == ';'){
            outLine[i] = ',';
        }
    }


    return outLine;
}

// saveFileToDBFirmy
bool CsvTools::saveFileToDBFirmy()
{
    // open file
    if(fileName.isEmpty()){
        //out << "Error: FileName is empty" << endl;
        qDebug() << "Error: FileName is empty" << endl;
        return false;
    }

    //openfiles
    QFile fileIn(fileName);

    if(fileIn.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        long long counter = 1;
        //read
        while(!fileIn.atEnd())
        {

            QString line = fileIn.readLine();
            QStringList row = line.split(';');

            if(row.length() != columnsNumbers){
                qDebug() << counter << row.length() << " -> " << line ;
            }
            // do something... sure that each line has fixed columns

            counter++;
            if(counter % 100000 == 0){
                qDebug() <<  counter ;
            }
        }
        qDebug() <<  "DONE" ;

        // close Files
        fileIn.close();
    }
    else {
        qDebug() << fileName << " - not Exist" ;
        return false;
    }
    return true;
}
