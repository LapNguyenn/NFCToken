#ifndef LOGINACTIVITY_H
#define LOGINACTIVITY_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class LoginActivity : public QWidget
{
    Q_OBJECT
public:
    explicit LoginActivity(QWidget *parent = nullptr);
    ~LoginActivity();

signals:
    void LoginSuccess();
    void LoginFailed();

private:
    QPushButton *loginButton;
    QLineEdit *username, *password;
};

#endif // LOGINACTIVITY_H
