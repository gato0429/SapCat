#include "pgcronograma.h"

PgCronograma::PgCronograma()
{

}

bool PgCronograma::Borrar(Cronograma valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM cronograma WHERE codigo_cliente='"+valor.getCodigoCliente()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;

}

bool PgCronograma::Insertar(Cronograma valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO cronograma("
                    "codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato)"
            "VALUES (?, ?);");

      query.addBindValue(valor.getCodigoCliente());
      query.addBindValue(valor.getFechaPago());
      query.addBindValue(valor.getFechaVencimiento());
      query.addBindValue(valor.getMonto());
      query.addBindValue(valor.getEstado());
      query.addBindValue(valor.getCodigoContrato());
      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;
}

bool PgCronograma::Actualizar(Cronograma Antiguo, Cronograma Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE cronograma SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigoCliente().isNull())
    {
        consulta=consulta+", codigo_cliente='"+Nuevo.getCodigoCliente()+"'";
    }

   /* if(!Nuevo.getFechaPago().isNull())
    {
        consulta=consulta+", fecha_pago='"+Nuevo.getFechaPago()+"'";
    }
    if(!Nuevo.getFechaVencimiento().isNull())
    {
        consulta=consulta+", fecha_vencimiento='"+Nuevo.getFechaVencimiento()+"'";
    }
    if(!Nuevo.getMonto().isNull())
    {
        consulta=consulta+", monto='"+Nuevo.getMonto()+"'";
    }*/
    if(!Nuevo.getEstado().isNull())
    {
        consulta=consulta+", estado='"+Nuevo.getEstado()+"'";
    }
    if(!Nuevo.getCodigoContrato().isNull())
    {
        consulta=consulta+", codigo_contrato='"+Nuevo.getCodigoContrato()+"'";
    }
    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(c,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/
    if(!Antiguo.getCodigoCliente().isNull())
    {
        consulta=consulta+", codigo_cliente='"+Antiguo.getCodigoCliente()+"'";
    }

   /* if(!Antiguo.getFechaPago().isNull())
    {
        consulta=consulta+", fecha_pago='"+Antiguo.getFechaPago()+"'";
    }
    if(!Antiguo.getFechaVencimiento().isNull())
    {
        consulta=consulta+", fecha_vencimiento='"+Antiguo.getFechaVencimiento()+"'";
    }
    if(!Antiguo.getMonto().isNull())
    {
        consulta=consulta+", monto='"+Antiguo.getMonto()+"'";
    }*/
    if(!Antiguo.getEstado().isNull())
    {
        consulta=consulta+", estado='"+Antiguo.getEstado()+"'";
    }
    if(!Antiguo.getCodigoContrato().isNull())
    {
        consulta=consulta+", codigo_contrato='"+Antiguo.getCodigoContrato()+"'";
    }

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

Cronograma PgCronograma::Buscar(Cronograma valor)
{
    QString consulta;

        consulta="SELECT codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato "
                "FROM vista_detalle_cronograma WHERE ";


    if(!valor.getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+valor.getCodigoCliente()+"%' AND ";
    }
   /* if(!valor.getFechaPago().isNull())
    {
        consulta=consulta+" fecha_pago ilike '%"+valor.getFechaPago()+"%' AND ";
    }
    if(!valor.getFechaVencimiento().isNull())
    {
        consulta=consulta+" fecha_vencimiento ilike '%"+valor.getFechaVencimiento()+"%' AND ";
    }
    if(!valor.getMonto().isNull())
    {
        consulta=consulta+" monto ilike '%"+valor.getMonto()+"%' AND ";
    }*/
    if(!valor.getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+valor.getEstado()+"%' AND ";
    }
    if(!valor.getCodigoContrato().isNull())
    {
        consulta=consulta+" codigo_contrato ilike '%"+valor.getCodigoContrato()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    Cronograma* resp=new Cronograma();
      while (query.next()&&flag ) {

          resp->setCodigoCliente(query.value(0).toString());
          resp->setFechaPago(query.value(1).toDate());
          resp->setFechaVencimiento(query.value(2).toDate());
          resp->setMonto(query.value(3).toDouble());
          resp->setEstado(query.value(4).toString());
          resp->setCodigoContrato(query.value(5).toString());
          flag=false;
      }

       return *resp;

}

QMap<QString, ObjetoMaestro *> *PgCronograma::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Cronograma* val=(Cronograma*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato "
                "FROM vista_detalle_cronograma";

    }
    else
    {
        consulta="SELECT codigo_cliente, fecha_cliente, fecha_vencimiento, monto, estado, codigo_contrato "
                "FROM vista_detalle_cronograma WHERE ";

    if(!val->getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+val->getCodigoCliente()+"%' AND ";
    }

  /*  if(!val->getFechaPago().isNull())
    {
        consulta=consulta+" fecha_pago ilike '%"+val->getFechaPago()+"%' AND ";
    }
    if(!val->getFechaVencimiento().isNull())
    {
        consulta=consulta+" fecha_vencimiento ilike '%"+val->getFechaVencimiento()+"%' AND ";
    }
    if(!val->getMonto().isNull())
    {
        consulta=consulta+" monto ilike '%"+val->getMonto()+"%' AND ";
    }*/
    if(!val->getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+val->getEstado()+"%' AND ";
    }
    if(!val->getCodigoContrato().isNull())
    {
        consulta=consulta+" codigo_contrato ilike '%"+val->getCodigoContrato()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          Cronograma* resp=new Cronograma();
          resp->setCodigoCliente(query.value(0).toString());
          resp->setFechaPago(query.value(1).toDate());
          resp->setFechaVencimiento(query.value(2).toDate());
          resp->setMonto(query.value(3).toDouble());
          resp->setEstado(query.value(4).toString());
          resp->setCodigoContrato(query.value(5).toString());


          salida->insert(resp->getCodigoCliente(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;


    }
qint64 PgCronograma::Contar()
{
    QString consulta="SELECT count(*) FROM cronograma";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgCronograma::ContarConsulta(ObjetoMaestro *valor)
{
    Cronograma* val=(Cronograma*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_cronograma WHERE ";

    if(!val->getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+val->getCodigoCliente()+"%' AND ";
    }
/*
    if(!val->getFechaPago().isNull())
    {
        consulta=consulta+" fecha_pago ilike '%"+val->getFechaPago()+"%' AND ";
    }
    if(!val->getFechaVencimiento().isNull())
    {
        consulta=consulta+" fecha_vencimiento ilike '%"+val->getFechaVencimiento()+"%' AND ";
    }
    if(!val->getMonto().isNull())
    {
        consulta=consulta+" monto ilike '%"+val->getMonto()+"%' AND ";
    }*/
    if(!val->getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+val->getEstado()+"%' AND ";
    }
    if(!val->getCodigoContrato().isNull())
    {
        consulta=consulta+" codigo_contrato ilike '%"+val->getCodigoContrato()+"%' AND ";
    }
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

QSqlQueryModel *PgCronograma::BuscarTabla(Cronograma valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato "
                     "FROM vista_detalle_cronograma";
         }
         else
         {
             consulta="SELECT codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato "
                           "FROM vista_detalle_cronograma where";

         if(!valor.getCodigoCliente().isNull())
         {
             consulta=consulta+" codigo_cliente ilike '%"+valor.getCodigoCliente()+"%' AND ";
         }
/*
         if(!valor.getFechaPago().isNull())
         {
             consulta=consulta+" fecha_pago ilike '%"+valor.getFechaPago()+"%' AND ";
         }
         if(!valor.getFechaVencimiento().isNull())
         {
             consulta=consulta+" fecha_vencimiento ilike '%"+valor.getFechaVencimiento()+"%' AND ";
         }
         if(!valor.getMonto().isNull())
         {
             consulta=consulta+" monto ilike '%"+valor.getMonto()+"%' AND ";
         }*/
         if(!valor.getEstado().isNull())
         {
             consulta=consulta+" estado ilike '%"+valor.getEstado()+"%' AND ";
         }
         if(!valor.getCodigoContrato().isNull())
         {
             consulta=consulta+" codigo_contrato ilike '%"+valor.getCodigoContrato()+"%' AND ";
         }

         consulta.replace(consulta.size()-5,5," ");
         }
         consulta=consulta+Extra;

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery(consulta);

         qDebug()<<consulta;
         return model;

}

QMap<QString, ObjetoMaestro *> *PgCronograma::BuscarClave()
{
    QString consulta;

        consulta="SELECT codigo_cliente, fecha_pago, fecha_vencimiento, monto, estado, codigo_contrato "
                "FROM vista_detalle_cronograma order by nombre asc";



        QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
        QSqlQuery query(consulta);

          while (query.next() ) {

              Cronograma* resp=new Cronograma();
              resp->setCodigoCliente(query.value(0).toString());
              resp->setFechaPago(query.value(1).toDate());
              resp->setFechaVencimiento(query.value(2).toDate());
              resp->setMonto(query.value(3).toDouble());
              resp->setEstado(query.value(4).toString());
              resp->setCodigoContrato(query.value(5).toString());


              salida->insert(query.value(1).toString(),(ObjetoMaestro*)resp);
          }




        return salida;

}

