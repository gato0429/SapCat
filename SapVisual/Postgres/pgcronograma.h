#ifndef PGCRONOGRAMA_H
#define PGCRONOGRAMA_H
#include "../Fabricas/fabricacronograma.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgCronograma : public FabricaCronograma
{
public:
    PgCronograma();

    // FabricaCronograma interface
public:
    bool Borrar(Cronograma valor);
    bool Insertar(Cronograma valor);
    bool Actualizar(Cronograma Antiguo, Cronograma Nuevo);
    Cronograma Buscar(Cronograma valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Cronograma valor, QString Extra, CONSULTA tipo);
    QMap<QString, ObjetoMaestro *> *BuscarClave();
};

#endif // PGCRONOGRAMA_H
