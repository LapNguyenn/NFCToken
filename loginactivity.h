#ifndef LOGINACTIVITY_H
#define LOGINACTIVITY_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "./ui_widget.h"

class LoginActivity : public QWidget
{
    Q_OBJECT
public:
    explicit LoginActivity( Ui::Widget *ui, QWidget *parent = nullptr);
    ~LoginActivity();

signals:
    void LoginSuccess();
    void LoginFailed();
    void LoginError();

private slots:
    void handleLoginFailed();
    void handleLoginError();
private:
    Ui::Widget *xUi;
};

#endif // LOGINACTIVITY_H
