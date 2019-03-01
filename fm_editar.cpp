#include "fm_editar.h"
#include "ui_fm_editar.h"

static int id;
// Variável criada para associar o id criado no SQLite ao Qt, sendo utilizado como um identificador

fm_editar::fm_editar(QWidget *parent, int idcontato):
    QDialog(parent),
    ui(new Ui::fm_editar)
{
    ui->setupUi(this);

    id = idcontato;
    // id contato é criada no construtor, e id recebe idcontato que no .h é inicializada com 0

    // QSqlQuery é utilizado para fazer a comunicação com o SQLite
    // É preciso fazer um #include <QtSql>, coloquei no fm_editar.h
    QSqlQuery query("select * from cadastro where id='"+QString :: number (idcontato)+"'");
    // "query" é o nome da variável e entre parênteses está o que ela irá fazer no banco de dados
    // O comando "select * from cadastro" se refere a tudo da tabela "cadastro" criada no SQLite
    // where id='"+QString :: number(idcontato)"'"+ diz o que será selecionado na tabela, que no caso é onde o id da tabela seja igual ao idcontato do Qt

    if(query.exec()){
        // Executa o comando da variável query
        query.first();
        //
        ui -> label_2 -> setText(query.value(0).toString());
        ui -> lineEdit -> setText(query.value(1).toString());
        ui -> lineEdit_2 -> setText(query.value(2).toString());
    }else {
        QMessageBox :: critical (this, "Erro", "Erro interno no processo");
    }
}

fm_editar::~fm_editar()
{
    delete ui;
}

void fm_editar::on_pushButton_2_clicked()
{
    close();
}

void fm_editar::on_pushButton_clicked()
{
    QString nome = ui -> lineEdit -> text();
    QString senha = ui -> lineEdit_2 -> text();

    QSqlQuery query("update cadastro set nome='"+nome+"', senha='"+senha+"' where id='"+QString :: number (id)+"'");
    // query criada para editar os dados de um usuário, fazendo um update, atualização, mudando a senha e o nome

    if(query.exec()){
        QMessageBox :: information (this, "", "Alteração realizada com sucesso");
        close();
    }else{
        QMessageBox :: critical (this, "", "Erro no processo de alteração");
    }

}
