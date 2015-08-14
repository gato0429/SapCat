#include "formunidad.h"
#include "ui_formunidad.h"



FormUnidad::FormUnidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormUnidad)
{
    ui->setupUi(this);

    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    Fab=Bd->Fabrica->CrearUnidad();

    ui->guardar->setIcon(QIcon(BotonGuardar));
    ui->modificar->setIcon(QIcon(BotonModificar));
    ui->eliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->modificar->setEnabled(false);
    ui->eliminar->setEnabled(false);
    ui->guardar->setEnabled(true);

}

void FormUnidad::SetObjeto(Unidad valor)
{
    ui->LineNombre->setText(valor.getNombre());
    ui->LineCodigo->setText(valor.getCodigo());
    ui->LineSimbolo->setText(valor.getSimbolo());
    ui->LineImagen->setText(valor.getRutaImagen());
    CodigoImagen=valor.getCodigoImagen();
    QPixmap pix;
    pix.load(RutaImagenes+valor.getRutaImagen());
    ui->imagenlabel->setPixmap(pix.scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->guardar->setEnabled(false);
    ui->modificar->setEnabled(true);
    ui->eliminar->setEnabled(true);
    ui->LineNombre->setEnabled(false);
    ui->LineSimbolo->setEnabled(false);
    ui->BotonArchivo->setEnabled(false);
}

FormUnidad::~FormUnidad()
{
    delete ui;
}

void FormUnidad::Ruta(QString Codigo, QString Cadena)
{
    QString fileName = Cadena;
    CodigoImagen=Codigo;
   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(RutaImagenes+fileName);

       ui->imagenlabel->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       ui->LineImagen->setText(fileName);
    }
}


bool FormUnidad::Guardar()
{
    if(!ValidarCampos())
    {
        return false;
    }

    /*------------*/
    AsignarCampos();
    /*------------*/

    if(Bd->Fabrica->Conectar())
    {
    /*Las validaciones de errores dentro de la Bd se realizan con la propia Bd en la clase Pg*/
        if(Fab->Insertar(Objeto))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Nueva Unidad Insertada",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
    Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormUnidad::Modificar()
{
    if(!ValidarCampos())
    {
        return false;
    }
    AsignarCampos();

    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Actualizar(Antiguo,Objeto))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Tipo Articulo Modificado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
      Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormUnidad::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Unidad Eliminada",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
      Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;

}

bool FormUnidad::ValidarCampos()
{
    if(ui->LineNombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineSimbolo->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Simbolo Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineImagen->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Imagen Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

void FormUnidad::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setSimbolo(ui->LineSimbolo->text());
   Objeto.setCodigoImagen(CodigoImagen);
   qDebug()<<"PAse"+CodigoImagen;
}

void FormUnidad::Habilitar()
{

}

void FormUnidad::Deshabilitar()
{

}

void FormUnidad::Limpiar()
{

}

void FormUnidad::on_guardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new Unidad());
    }
    if(Estados==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->guardar->setEnabled(false);
        ui->modificar->setEnabled(true);
        ui->eliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new Unidad());
    }

}

void FormUnidad::on_modificar_clicked()
{
    Estados=MODIFICAR;
    /*--Habilitacion Botones-*/
    ui->modificar->setEnabled(false);
    ui->eliminar->setEnabled(false);
    ui->guardar->setEnabled(true);
    ui->BotonArchivo->setEnabled(true);
    /*---Desabilitar Campos--*/
    Habilitar();
}

void FormUnidad::on_eliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Unidad());
        this->close();
        this->destroy();
    }

}

void FormUnidad::on_tabWidget_tabBarClicked(int index)
{
if(index==1)
{
    this->close();
    this->destroy();
}
}

void FormUnidad::on_BotonArchivo_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}


void FormUnidad::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
}
