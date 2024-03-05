#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "loginactivity.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void handleLoginSuccess();
private:
    Ui::Widget *ui;
    LoginActivity *loginActivity;

};
#endif // WIDGET_H
