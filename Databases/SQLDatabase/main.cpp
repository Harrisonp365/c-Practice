#include <QApplication>

#include "ImageDialog.h"

int main( int argc, char **argv )
{
  QApplication app( argc, argv );

  ImageDialog dlg;
  dlg.show();

  return app.exec();
}
