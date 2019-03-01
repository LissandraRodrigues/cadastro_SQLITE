#ifndef JANELA_LOGIN_H
#define JANELA_LOGIN_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
//Include necessário para interagir com o Banco de Dados, e só acessível após mudar o .pro
// OBS, no ProjetoSQLITE.pro é necessário modificar para += core gui sql

namespace Ui {
class janela_login;
}

class janela_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit janela_login(QWidget *parent = nullptr);
    ~janela_login();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::janela_login *ui;
};

#endif // JANELA_LOGIN_H
