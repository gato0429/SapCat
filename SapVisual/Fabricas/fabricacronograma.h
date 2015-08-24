#ifndef FABRICACRONOGRAMA_H
#define FABRICACRONOGRAMA_H
#include "../Objetos/cronograma.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;


class FabricaCronograma
{
public:
    FabricaCronograma();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Cronograma valor)=0;
    virtual     bool Insertar(Cronograma valor)=0;
    virtual     bool Actualizar(Cronograma Antiguo, Cronograma Nuevo)=0;
    virtual     Cronograma Buscar(Cronograma valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Cronograma valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,ObjetoMaestro *>* BuscarClave()=0;

};

#endif // FABRICACRONOGRAMA_H
