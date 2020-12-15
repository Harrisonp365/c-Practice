#ifndef DATAREADER_H
#define DATAREADER_H

#include <QtCharts/QCandlestickSet>
#include <QtCore/QTextStream>

QT_CHARTS_USE_NAMESPACE

class DataReader : public QTextStream
{
public:
    explicit DataReader(QIODevice *device);
    ~DataReader();

    void readFile(QIODevice *device);
    QCandlestickSet *readCandlestickSet();
};

#endif // DATAREADER_H
