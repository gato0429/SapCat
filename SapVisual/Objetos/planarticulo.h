#ifndef PLANARTICULO_H
#define PLANARTICULO_H
#include "objetomaestro.h"

class PlanArticulo: public ObjetoMaestro
{
private:
    QString CodigoPlan;
    QString CodigoArticulo;
    DOUBLE Precio;
public:
    PlanArticulo();
    QString getCodigoPlan() const;
    void setCodigoPlan(const QString &value);
    QString getCodigoArticulo() const;
    void setCodigoArticulo(const QString &value);
    DOUBLE getPrecio() const;
    void setPrecio(const DOUBLE &value);
};

#endif // PLANARTICULO_H
