#ifndef FABRICAPLAN_H
#define FABRICAPLAN_H
#include "../Objetos/plan.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaPlan
{
public:
    FabricaPlan();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Plan valor)=0;
    virtual     bool Insertar(Plan valor)=0;
    virtual     bool Actualizar(Plan Antiguo, Plan Nuevo)=0;
    virtual     Plan Buscar(Plan valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Plan valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,ObjetoMaestro *>* BuscarClave()=0;

};

#endif // FABRICAPLAN_H
