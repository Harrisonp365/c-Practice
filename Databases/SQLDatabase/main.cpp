#include "ImageDialog.h"
#include "ImageCollection.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ImageDialog iD;
    iD.show();

    return app.exec();
}

