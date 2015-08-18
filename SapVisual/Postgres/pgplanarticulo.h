#ifndef PGPLANARTICULO_H
#define PGPLANARTICULO_H
#include "../Fabricas/fabricaplanarticulo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgPlanArticulo : public FabricaPlanArticulo
{
public:
    PgPlanArticulo();

    // FabricaPlanArticulo interface
public:
    bool Borrar(PlanArticulo valor);
    bool Insertar(PlanArticulo valor);
    bool Actualizar(PlanArticulo Antiguo, PlanArticulo Nuevo);
    PlanArticulo Buscar(PlanArticulo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(PlanArticulo valor, QString Extra, CONSULTA tipo);
    QMap<QString, ObjetoMaestro *> *BuscarClave();
};

#endif // PGPLANARTICULO_H
