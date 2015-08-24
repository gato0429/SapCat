#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include "objetomaestro.h"


class Cronograma: public ObjetoMaestro
{
private:
    QString CodigoCliente;
    QDate FechaPago;
    QDate FechaVencimiento;
    DOUBLE Monto;
    QString Estado;
    QString CodigoContrato;
public:
    Cronograma();
    QString getCodigoCliente() const;
    void setCodigoCliente(const QString &value);
    QDate getFechaPago() const;
    void setFechaPago(const QDate &value);
    QDate getFechaVencimiento() const;
    void setFechaVencimiento(const QDate &value);
    DOUBLE getMonto() const;
    void setMonto(const DOUBLE &value);
    QString getEstado() const;
    void setEstado(const QString &value);
    QString getCodigoContrato() const;
    void setCodigoContrato(const QString &value);
};

#endif // CRONOGRAMA_H
