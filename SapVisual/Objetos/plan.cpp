#include "plan.h"


QString Plan::getCodigo() const
{
    return Codigo;
}

void Plan::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Plan::getNombre() const
{
    return Nombre;
}

void Plan::setNombre(const QString &value)
{
    Nombre = value;
}

QString Plan::getCodigoImagen() const
{
    return CodigoImagen;
}

void Plan::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Plan::getRutaImagen() const
{
    return RutaImagen;
}

void Plan::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Plan::Plan()
{

}

