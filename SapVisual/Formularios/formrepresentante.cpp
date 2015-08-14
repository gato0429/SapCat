#include "formrepresentante.h"
#include "ui_formrepresentante.h"

FormRepresentante::FormRepresentante(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRepresentante)
{
    ui->setupUi(this);
}

FormRepresentante::~FormRepresentante()
{
    delete ui;
}
