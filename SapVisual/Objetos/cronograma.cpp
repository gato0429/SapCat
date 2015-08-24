#include "cronograma.h"


QString Cronograma::getCodigoCliente() const
{
    return CodigoCliente;
}

void Cronograma::setCodigoCliente(const QString &value)
{
    CodigoCliente = value;
}

QDate Cronograma::getFechaPago() const
{
    return FechaPago;
}

void Cronograma::setFechaPago(const QDate &value)
{
    FechaPago = value;
}

QDate Cronograma::getFechaVencimiento() const
{
    return FechaVencimiento;
}

void Cronograma::setFechaVencimiento(const QDate &value)
{
    FechaVencimiento = value;
}

DOUBLE Cronograma::getMonto() const
{
    return Monto;
}

void Cronograma::setMonto(const DOUBLE &value)
{
    Monto = value;
}

QString Cronograma::getEstado() const
{
    return Estado;
}

void Cronograma::setEstado(const QString &value)
{
    Estado = value;
}

QString Cronograma::getCodigoContrato() const
{
    return CodigoContrato;
}

void Cronograma::setCodigoContrato(const QString &value)
{
    CodigoContrato = value;
}
Cronograma::Cronograma()
{

}

