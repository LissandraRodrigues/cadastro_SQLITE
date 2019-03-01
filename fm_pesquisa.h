#ifndef FM_PESQUISA_H
#define FM_PESQUISA_H

#include <QDialog>
#include <QtSql>
//Include necessário para interagir com o Banco de Dados, e só acessível após mudar o .pro
// OBS, no ProjetoSQLITE.pro é necessário modificar para += core gui sql

#include "janela_login.h"
#include "fm_editar.h"

namespace Ui {
class fm_pesquisa;
}

class fm_pesquisa : public QDialog
{
    Q_OBJECT

public:
    explicit fm_pesquisa(QWidget *parent = nullptr);
    ~fm_pesquisa();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fm_pesquisa *ui;
};

#endif // FM_PESQUISA_H
