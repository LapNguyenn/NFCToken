#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    loginActivity = new LoginActivity(this);
    connect(loginActivity, &LoginActivity::LoginSuccess, this, &Widget::handleLoginSuccess);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleLoginSuccess()
{
    qDebug() << ui->lineEditUsername->text();
    qDebug() << ui->lineEditPassword->text();
}
