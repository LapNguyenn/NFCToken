#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    loginActivity = new LoginActivity(ui, this);
    connect(loginActivity, &LoginActivity::LoginSuccess, this, &Widget::handleLoginSuccess);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleLoginSuccess()
{
    qDebug() << "login successfully!";
    qDebug() << ui->le_username->text();
    qDebug() << ui->le_password->text();
}
