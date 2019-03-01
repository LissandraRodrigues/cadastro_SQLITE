#include "janela_login.h"
#include "ui_janela_login.h"

#include "fm_pesquisa.h"

static QSqlDatabase banco = QSqlDatabase :: addDatabase("QSQLITE");
// Faz a conexão entre o Banco de Dados e o Qt

// OBS, no ProjetoSQLITE.pro é necessário modificar para += core gui sql

janela_login::janela_login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::janela_login)
{
    ui->setupUi(this);

    banco.setDatabaseName("C:/Users/luiza/Desktop/Programação/Projeto_SQL/ProjetoSQLITE/Banco_de_Dados/Banco_De_Dados.db");
    // Informa o caminho para o Banco de Dados que tem como formato .db

    if(!banco.open()){
        // Abertura do Banco de Dados e verificação de erro
        qDebug() << "Não foi possível abrir o Banco de Dados";
    }else{
        qDebug() << "Banco de Dados aberto com sucesso";
    }
}

janela_login::~janela_login()
{
    delete ui;
}

void janela_login::on_pushButton_3_clicked()
{
    close();
}

void janela_login::on_pushButton_clicked()
{
    QString nome = ui -> lineEdit -> text();
    QString senha = ui -> lineEdit_2 -> text();

    if(!banco.isOpen()){
        // Verificação para saber se o banco está aberto ou não
        QMessageBox :: warning (this, "Erro","Erro interno");
        return;
    }

    QSqlQuery query;
    // Criação de um variável do tipo QSqlQuery, poderia ter qualquer nome
    // É o que faz a interação com o banco de dados, por meio de comandos, como insert, select, update etc.

    if(query.exec("select nome, senha from cadastro where nome='"+nome+"' and senha='"+senha+"'")){
       // Seleciona verificando na tabela "cadastro", criada no banco de dados, se o nome e a senha da tabela corresponde ao nome e a senha inserida

       int cont = 0;

       while(query.next()){
        // query executa tentando achar o nome e a senha inserida, e, caso ache, modifica a variável cont
        cont++;
       }

        if(cont > 0){
            // Caso cont seja maior que zero, significa que o usuário foi encontrado no banco de dados
             QMessageBox :: information(this, "Login", "Login efetuado com sucesso");
             ui -> lineEdit -> clear();
             ui -> lineEdit_2 -> clear();
             ui -> lineEdit -> setFocus();
        }else{
             QMessageBox :: warning (this, "Login", "Os dados inseridos não constam no sistema");
             ui -> lineEdit -> clear();
             ui -> lineEdit_2 -> clear();
             ui -> lineEdit -> setFocus();
        }
    }
}

void janela_login::on_pushButton_2_clicked()
{
    QString nome = ui -> lineEdit -> text();
    QString senha = ui -> lineEdit_2 -> text();

    if(!banco.isOpen()){
     // Verificação para saber se o banco está aberto ou não
        QMessageBox :: warning (this, "Erro", "Erro interno");
    }

    QSqlQuery query;
    // Criação de um variável do tipo QSqlQuery, poderia ter qualquer nome
    // É o que faz a interação com o banco de dados, por meio de comandos, como insert, select, update etc.

    if(query.exec("insert into cadastro (nome, senha) values ('"+nome+"','"+senha+"')")){
        // insert é utilizado para cadastrar usuários na tabela cadastro criado no banco de dados
       // Registra o nome e a senha do usuário e no próximo login ele já será identificado
        QMessageBox :: information(this, "Register", "Registro efetuado com sucesso");
        ui -> lineEdit -> clear();
        ui -> lineEdit_2 -> clear();
        ui -> lineEdit -> setFocus();
    }else{
        QMessageBox :: information(this, "Register", "Registro não efetuado");
        ui -> lineEdit -> clear();
        ui -> lineEdit_2 -> clear();
        ui -> lineEdit -> setFocus();
    }
}

void janela_login::on_pushButton_4_clicked()
{
    fm_pesquisa pesquisa;
    pesquisa.exec();
}
