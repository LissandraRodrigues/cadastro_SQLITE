#include "fm_pesquisa.h"
#include "ui_fm_pesquisa.h"

#include <QtSql>
//Include necessário para interagir com o Banco de Dados, e só acessível após mudar o .pro
// OBS, no ProjetoSQLITE.pro é necessário modificar para += core gui sql

fm_pesquisa::fm_pesquisa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_pesquisa)
{
    ui->setupUi(this);

    QSqlQuery query;
    // Criação de um variável do tipo QSqlQuery, poderia ter qualquer nome
    // É o que faz a interação com o banco de dados, por meio de comandos, como insert, select, update etc.

    if(query.exec("select * from cadastro")){
        int cont = 0;

        ui -> tableWidget -> setColumnCount(3);

        while(query.next()){

            ui -> tableWidget -> insertRow(cont);

            ui -> tableWidget -> setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui -> tableWidget -> setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui -> tableWidget -> setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));

            ui -> tableWidget -> setRowHeight(cont,20);

            cont++;
        }

        ui -> tableWidget -> setColumnWidth(0,5);
        ui -> tableWidget -> setColumnWidth(1,150);
        ui -> tableWidget -> setColumnWidth(2,50);

        QStringList cabecalhos = {"ID", "Nome", "Senha"};

        ui -> tableWidget -> setHorizontalHeaderLabels(cabecalhos);

        ui -> tableWidget -> setEditTriggers(QAbstractItemView :: NoEditTriggers);

        ui -> tableWidget -> setSelectionBehavior(QAbstractItemView :: SelectRows);

        ui -> tableWidget -> verticalHeader() -> setVisible(false);

        ui -> tableWidget -> setStyleSheet("QTableView {selection-background-color:grey}");

    }else {

        QMessageBox :: critical(this, "Erro", "Erro no processo de pesquisa");
    }
}

fm_pesquisa::~fm_pesquisa()
{
    delete ui;
}

void fm_pesquisa::on_pushButton_3_clicked()
{
    close();
}

void fm_pesquisa::on_pushButton_4_clicked()
{
    int linha = ui -> tableWidget -> currentRow();
    QString iden = ui -> tableWidget -> item(linha, 0) -> text();

    QSqlQuery query("delete from cadastro where id='"+iden+"'");

    if(!query.exec()){
        QMessageBox :: critical (this, "Remove", "Item não excluído");
    }else{
        ui -> tableWidget -> removeRow(linha);
        QMessageBox :: information (this, "Remove", "Item excluído com sucesso");
    }

}

void fm_pesquisa::on_pushButton_2_clicked()
{
    int linha = ui -> tableWidget -> currentRow();
    int id = ui -> tableWidget -> item(linha, 0) -> text().toInt();
    fm_editar f_editar(this, id);
    f_editar.exec();

    QSqlQuery query("select * from cadastro where id='"+QString :: number(id)+"'");

    if(query.exec()){
        query.first();
        ui -> tableWidget -> setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
        ui -> tableWidget -> setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
    }
}
