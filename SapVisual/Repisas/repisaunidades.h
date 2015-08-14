#ifndef REPISAUNIDADES_H
#define REPISAUNIDADES_H

#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaunidades.h"
#include "../Formularios/formunidad.h"
#include "../Busqueda/busquedaunidad.h"

class RepisaUnidades:public Repisa
{

private:
    FabricaUnidades*         FabricaLocal;
    FormUnidad*       Dialogo;


public:
    RepisaUnidades();

    // Repisa interface
public slots:

    void GrupoBotonesClick(QAbstractButton *buttonID);
    void NuevoClick();
    void BuscarClick();

public:
    void ObjetosIndependientes();
    void ActualizarConsulta();


public:
    void ObtenerConsulta();

    // Repisa interface
protected:
    void ConsultarBusqueda();
};

#endif // REPISAUNIDADES_H
