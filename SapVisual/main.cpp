
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
#include "Repisas/repisaunidades.h"
#include "Repisas/repisaimagenes.h"

#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
#include "Repisas/repisavehiculorubro.h"
#include "Repisas/repisaclientetipo.h"
#include "Repisas/repisaestado.h"


#include "Repisas/repisaarticulo.h"
#include "Repisas/repisacliente.h"

#include "Repisas/repisaoperaciones.h"
#include "Repisas/repisaempleadoarea.h"
#include "Repisas/repisaempleadocargo.h"
#include "Repisas/repisaplan.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

    //RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
//    RepisaUnidades* w=new RepisaUnidades();
 //  RepisaMoneda* w=new RepisaMoneda();
  // RepisaImagenes* w=new RepisaImagenes();

  // RepisaVehiculoRubro* w=new RepisaVehiculoRubro();

//    RepisaMoneda* w=new RepisaMoneda();

  //  RepisaClienteTipo* w=new RepisaClienteTipo();
    //   RepisaEstado* w=new RepisaEstado();
    //RepisaCliente* w=new RepisaCliente();
    RepisaPlan* w=new RepisaPlan();

    // RepisaClienteTipo* w=new RepisaClienteTipo();
       //RepisaEstado* w=new RepisaEstado();
   // RepisaOperaciones* w=new RepisaOperaciones();
   // RepisaEmpleadoArea* w=new RepisaEmpleadoArea();
   // RepisaEmpleadoCargo* w=new RepisaEmpleadoCargo();

    w->show();



    return a.exec();
}
