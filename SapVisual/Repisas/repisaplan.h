#ifndef REPISAPLAN_H
#define REPISAPLAN_H

#include "repisa.h"
#include "../Formularios/formplan.h"
#include "../Fabricas/fabricaplan.h"

class RepisaPlan: public Repisa
{
private:
    FabricaPlan*       FabricaLocal;
    FormPlan*          Dialogo;
public:
    RepisaPlan();

    // Repisa interface
protected:
    void ConsultarBusqueda();

private slots:
    void GrupoBotonesClick(QAbstractButton *buttonID);

public slots:
    void NuevoClick();
    void BuscarClick();

public:
    void ObtenerConsulta();
    void ObjetosIndependientes();
    void ActualizarConsulta();
};

#endif // REPISAPLAN_H
