#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCore/QDateTime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "DataReader.h"

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QCandlestickSeries *acmeSeries = new QCandlestickSeries();
    acmeSeries->setName("Acme Ltd");
    acmeSeries->setIncreasingColor(QColor(Qt::green));
    acmeSeries->setDecreasingColor(QColor(Qt::red));

    QFile acmeData(":acme");
    if (!acmeData.open(QIODevice::ReadOnly | QIODevice::Text))
        return 1;

    QStringList categories;

    DataReader dataReader(&acmeData);
    while (!dataReader.atEnd()) {
        QCandlestickSet *set = dataReader.readCandlestickSet();
        if (set) {
            acmeSeries->append(set);
            categories << QDateTime::fromMSecsSinceEpoch(set->timestamp()).toString("dd");
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(acmeSeries);
    chart->setTitle("Acme Ltd Historical Data (July 2015)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);

    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.show();

    return a.exec();
}
