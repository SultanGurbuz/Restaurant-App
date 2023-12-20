#include "login.h"
#include <QSqlDatabase>
#include "./ui_login.h"
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("SQLITE");
    sqlitedb.setDatabaseName("../restaurant.db");
    if (!sqlitedb.isOpen()) {
        ui->statusLabel->setText("Database is not connected.");
    } else
        ui->statusLabel->setText("Database is connected.");
}
