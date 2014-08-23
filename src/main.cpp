
#include <QApplication>
#include "../includes/Launcher.h"

int main(int argc, char **argv)
{
   QApplication app(argc, argv);

   Launcher *launcher = new Launcher();
   launcher->linkQttoQml();

   return app.exec();
}
