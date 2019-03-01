#include "janela_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    janela_login w;
    w.show();

    return a.exec();
}
