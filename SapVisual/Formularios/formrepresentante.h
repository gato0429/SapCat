#ifndef FORMREPRESENTANTE_H
#define FORMREPRESENTANTE_H

#include <QWidget>

namespace Ui {
class FormRepresentante;
}

class FormRepresentante : public QWidget
{
    Q_OBJECT

public:
    explicit FormRepresentante(QWidget *parent = 0);
    ~FormRepresentante();

private:
    Ui::FormRepresentante *ui;
};

#endif // FORMREPRESENTANTE_H
