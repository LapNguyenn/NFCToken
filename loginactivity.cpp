#include "loginactivity.h"
#include "./ui_widget.h"
#include <QDebug>
LoginActivity::LoginActivity(QWidget *parent)
    : QWidget(parent)
{
    loginButton = findChild<QPushButton*>("btLogin");

    connect(loginButton, &QPushButton::clicked, this, [this](){
        //process login
        emit LoginSuccess();
    });
}

LoginActivity::~LoginActivity()
{

}
