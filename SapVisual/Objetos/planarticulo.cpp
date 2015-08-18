#include "planarticulo.h"


QString PlanArticulo::getCodigoPlan() const
{
    return CodigoPlan;
}

void PlanArticulo::setCodigoPlan(const QString &value)
{
    CodigoPlan = value;
}

QString PlanArticulo::getCodigoArticulo() const
{
    return CodigoArticulo;
}

void PlanArticulo::setCodigoArticulo(const QString &value)
{
    CodigoArticulo = value;
}

DOUBLE PlanArticulo::getPrecio() const
{
    return Precio;
}

void PlanArticulo::setPrecio(const DOUBLE &value)
{
    Precio = value;
}
PlanArticulo::PlanArticulo()
{

}

