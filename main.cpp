#include "mainwindow.h"
#include <QApplication>
#include "Ressources/chantier.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("General Visual Inspector");
    a.setApplicationVersion("0.1");
    a.setApplicationDisplayName("General Visual Inspector " + a.applicationVersion());
    MainWindow w;
    w.show();
    return (a.exec());
}
