#ifndef FABRICAPLANARTICULO_H
#define FABRICAPLANARTICULO_H
#include "../Objetos/planarticulo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaPlanArticulo
{
public:
    FabricaPlanArticulo();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(PlanArticulo valor)=0;
    virtual     bool Insertar(PlanArticulo valor)=0;
    virtual     bool Actualizar(PlanArticulo Antiguo, PlanArticulo Nuevo)=0;
    virtual     PlanArticulo Buscar(PlanArticulo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(PlanArticulo valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,ObjetoMaestro *>* BuscarClave()=0;

};

#endif // FABRICAPLANARTICULO_H
