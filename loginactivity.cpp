#include "loginactivity.h"
#include <QDebug>
LoginActivity::LoginActivity(Ui::Widget *ui, QWidget *parent)
    : QWidget(parent), xUi(ui)
{
    xUi->lb_notice_login->setVisible(false);
    connect(this, &LoginActivity::LoginFailed, this, &LoginActivity::handleLoginFailed);
    connect(this, &LoginActivity::LoginError, this, &LoginActivity::handleLoginError);
    connect(ui->bt_login, &QPushButton::clicked, this, [ui, this](){
        xUi->le_username->setStyleSheet("");
        xUi->le_password->setStyleSheet("");
        xUi->lb_notice_login->setVisible(false);
        QString username = xUi->le_username->text();
        QString password = xUi->le_password->text();
        // //process login
        if(username.length() == 0 || password.length() == 0){
            emit LoginError();
        } else if (username.compare("lappro") != 0 || password.compare("1") != 0) {
            emit LoginFailed();
        } else {
            emit LoginSuccess();
        }
    });
}

LoginActivity::~LoginActivity()
{

}

void LoginActivity::handleLoginFailed()
{
    xUi->lb_notice_login->setVisible(true);
    xUi->lb_notice_login->setStyleSheet("color: crimson;");
    xUi->lb_notice_login->setText("Wrong username or password");
}

void LoginActivity::handleLoginError()
{
    xUi->le_username->setStyleSheet("border: 1px solid crimson;");
    xUi->le_password->setStyleSheet("border: 1px solid crimson;");
    xUi->lb_notice_login->setVisible(true);
    xUi->lb_notice_login->setStyleSheet("color: crimson;");
    xUi->lb_notice_login->setText("Please fill all required field!");
    qDebug() << "error";
}
