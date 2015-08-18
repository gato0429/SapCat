#ifndef PGPLAN_H
#define PGPLAN_H
#include "../Fabricas/fabricaplan.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgPlan : public FabricaPlan
{
public:
    PgPlan();

    // FabricaPlan interface
public:
    bool Borrar(Plan valor);
    bool Insertar(Plan valor);
    bool Actualizar(Plan Antiguo, Plan Nuevo);
    Plan Buscar(Plan valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Plan valor, QString Extra, CONSULTA tipo);
    QMap<QString, ObjetoMaestro *> *BuscarClave();
};

#endif // PGPLAN_H
