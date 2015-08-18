#include "pgplanarticulo.h"

PgPlanArticulo::PgPlanArticulo()
{

}

bool PgPlanArticulo::Borrar(PlanArticulo valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM plan_articulo WHERE codigo_plan='"+valor.getCodigoPlan()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgPlanArticulo::Insertar(PlanArticulo valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO plan_articulo("
                    "codigo_plan, codigo_articulo, precio)"
            "VALUES (?, ?);");

      query.addBindValue(valor.getCodigoPlan());
      query.addBindValue(valor.getCodigoArticulo());
      query.addBindValue(valor.getPrecio());

      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;

}

bool PgPlanArticulo::Actualizar(PlanArticulo Antiguo, PlanArticulo Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE plan_articulo SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigoPlan().isNull())
    {
        consulta=consulta+", codigo_plan='"+Nuevo.getCodigoPlan()+"'";
    }

    if(!Nuevo.getCodigoArticulo().isNull())
    {
        consulta=consulta+", codigo_articulo='"+Nuevo.getCodigoArticulo()+"'";
    }
   /* if(!Nuevo.getPrecio().isNull())
    {
        consulta=consulta+", precio='"+Nuevo.getPrecio()+"'";
    }*/
    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(c,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/
    if(!Antiguo.getCodigoPlan().isNull())
    {
        consulta=consulta+"(codigo_plan='"+Antiguo.getCodigoPlan()+"') AND ";
    }

    if(!Antiguo.getCodigoArticulo().isNull())
    {
        consulta=consulta+"(codigo_articulo='"+Antiguo.getCodigoArticulo()+"') AND ";
    }
    /*if(!Antiguo.getPrecio().isNull())
    {
        consulta=consulta+"(precio='"+Antiguo.getPrecio()+"') AND ";
    }*/

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;

    bool flag=query.exec(consulta);

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return flag;
}

PlanArticulo PgPlanArticulo::Buscar(PlanArticulo valor)
{
    QString consulta;

        consulta="SELECT codigo_plan, codigo_articulo, precio "
                "FROM vista_detalle_plan_articulo WHERE ";


    if(!valor.getCodigoPlan().isNull())
    {
        consulta=consulta+" codigo_plan ilike '%"+valor.getCodigoPlan()+"%' AND ";
    }
    if(!valor.getCodigoArticulo().isNull())
    {
        consulta=consulta+" codigo_articulo ilike '%"+valor.getCodigoArticulo()+"%' AND ";
    }
    /*if(!valor.getPrecio().isNull())
    {
        consulta=consulta+" precio ilike '%"+valor.getPrecio()+"%' AND ";
    }*/

    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    PlanArticulo* resp=new PlanArticulo();
      while (query.next()&&flag ) {

          resp->setCodigoPlan(query.value(0).toString());
          resp->setCodigoArticulo(query.value(1).toString());
          //resp->setPrecio(query.value(2).toString());
          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgPlanArticulo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    PlanArticulo* val=(PlanArticulo*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo_plan, codigo_articulo, precio "
                "FROM vista_detalle_plan_articulo";

    }
    else
    {
        consulta="SELECT codigo_plan, codigo_articulo, precio "
                "FROM vista_detalle_plan_articulo WHERE ";

    if(!val->getCodigoPlan().isNull())
    {
        consulta=consulta+" codigo_plan ilike '%"+val->getCodigoPlan()+"%' AND ";
    }

    if(!val->getCodigoArticulo().isNull())
    {
        consulta=consulta+" codigo_articulo ilike '%"+val->getCodigoArticulo()+"%' AND ";
    }
    /*if(!val->getPrecio().isNull())
    {
        consulta=consulta+" precio ilike '%"+val->getPrecio()+"%' AND ";
    }*/


    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;



    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          PlanArticulo* resp=new PlanArticulo();
          resp->setCodigoPlan(query.value(0).toString());
          resp->setCodigoArticulo(query.value(1).toString());
          //resp->setPrecio(query.value(2).toString());


          salida->insert(resp->getCodigoPlan(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgPlanArticulo::Contar()
{
    QString consulta="SELECT count(*) FROM plan_articulo";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgPlanArticulo::ContarConsulta(ObjetoMaestro *valor)
{
    PlanArticulo* val=(PlanArticulo*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_plan_articulo WHERE ";

    if(!val->getCodigoPlan().isNull())
    {
        consulta=consulta+" codigo_plan ilike '%"+val->getCodigoPlan()+"%' AND ";
    }
    if(!val->getCodigoArticulo().isNull())
    {
        consulta=consulta+" codigo_articulo ilike '%"+val->getCodigoArticulo()+"%' AND ";
    }
    /*if(!val->getPrecio().isNull())
    {
        consulta=consulta+" precio ilike '%"+val->getPrecio()+"%' AND ";
    }*/
    consulta.replace(consulta.size()-5,5," ");


        QSqlQuery query(consulta);
        qint64 num;
        while(query.next())
        {
          num=query.value(0).toLongLong();
          return num;
        }

    return num;
}

QSqlQueryModel *PgPlanArticulo::BuscarTabla(PlanArticulo valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo_plan, codigo_articulo, precio "
                     "FROM vista_detalle_plan_articulo";
         }
         else
         {
             consulta="SELECT codigo_plan, codigo_articulo, precio "
                           "FROM vista_detalle_plan_articulo where";

         if(!valor.getCodigoPlan().isNull())
         {
             consulta=consulta+" codigo_plan ilike '%"+valor.getCodigoPlan()+"%' AND ";
         }
         if(!valor.getCodigoArticulo().isNull())
         {
             consulta=consulta+" codigo_articulo ilike '%"+valor.getCodigoArticulo()+"%' AND ";
         }
         /*if(!valor.getPrecio().isNull())
         {
             consulta=consulta+" precio ilike '%"+valor.getPrecio()+"%' AND ";
         }*/

         consulta.replace(consulta.size()-5,5," ");
         }
         consulta=consulta+Extra;

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery(consulta);

         qDebug()<<consulta;
         return model;
}

QMap<QString, ObjetoMaestro *> *PgPlanArticulo::BuscarClave()
{
    QString consulta;

        consulta="SELECT codigo_plan, codigo_articulo, precio"
                "FROM vista_detalle_plan_articulo order by nombre asc";



        QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
        QSqlQuery query(consulta);

          while (query.next() ) {

              PlanArticulo* resp=new PlanArticulo();
              resp->setCodigoPlan(query.value(0).toString());
              resp->setCodigoArticulo(query.value(1).toString());
            //  resp->setPrecio(query.value(2).toString());


              salida->insert(query.value(1).toString(),(ObjetoMaestro*)resp);
          }




        return salida;
}

