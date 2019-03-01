#ifndef FM_EDITAR_H
#define FM_EDITAR_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
//Include necessário para interagir com o Banco de Dados, e só acessível após mudar o .pro
// OBS, no ProjetoSQLITE.pro é necessário modificar para += core gui sql

namespace Ui {
class fm_editar;
}

class fm_editar : public QDialog
{
    Q_OBJECT

public:
    explicit fm_editar(QWidget *parent = nullptr, int idcontato = 0);
    ~fm_editar();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::fm_editar *ui;
};

#endif // FM_EDITAR_H
