#include <iostream>
#include <queue>//Colas
#include <string>//Cadenas
using namespace std;

//PRIMERA PARTE DEL CÓDIGO

//Estructuras 
struct Mascotas{
    string animal;
    string nombremascota;
    string genero;
    float peso;
    int edad;
    string nombreencargado;
    string servicio;
    int precio;
};
struct Mascotas mascota; //VARIABLE GLOBAL

//FUNCION DEL MENU DE INICIO
void menu(queue<Mascotas>consulta, queue<Mascotas>cyg,queue<Mascotas>grooming, queue<Mascotas>reservacion);

//OPCION VETERINARIO
void veterinario(queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming); 
void ingresarinfo(queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming);

//FUNCIONES PARA OBSERVAR EXPEDIENTES
void mostrarConsulta(queue<Mascotas>consulta);
void mostrarCyG(queue<Mascotas>cyg);
void mostrarGrooming(queue<Mascotas>grooming);

//FUNCIONES PARA ELIMINAR 1 EXPEDIENTE
void borrarc(queue<Mascotas>consulta);
void borrarcyg(queue<Mascotas>cyg);
void borrarg(queue<Mascotas>grooming);

//SEGUNDA PARTE DEL CÓDIGO

//OPCION DE RECEPCIONISTA
void recepcionista( queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming,queue<Mascotas>reservacion);

//COBRAR
void chargeconsul(queue<Mascotas> consulta);
void chargecyg(queue<Mascotas> cyg);
void chargegroo(queue<Mascotas> grooming);

//CITAS
void ingresarCITAS(queue<Mascotas>reservacion);
void mostrarCitas(queue<Mascotas>reservacion);

//MOSTRAR NOMBRE Y PRECIO DE LOS SERVICIOS
void mostrarservicios();


//MAIN FUNCION PRINCIPAL
int main(){
    queue<Mascotas>consulta;
    queue<Mascotas>cyg; //ambos servicios
    queue<Mascotas>grooming;
    queue<Mascotas>reservacion;

    menu(consulta,cyg,grooming, reservacion);
}

void menu(queue<Mascotas>reservacion, queue<Mascotas>consulta, queue<Mascotas>cyg,queue<Mascotas>grooming){
int estado=true;
while (estado) //Repeticion el menu hasta que no se utilice más
{
        int opcion;
        cout<<endl<<endl;
        cout<<"-----VETERINARIA PELO LINDO-----"<<endl; // menu general, opciones de roles
        cout<<"1)Veterinario/a"<<endl;
        cout<<"2)Recepcionista"<<endl;
        cout<<"3)Salir"<<endl;
        cout<<"Ingrese el numero de la opcion deseada: ";
        cin>>opcion;
        switch (opcion)
        {
            case 1:
            veterinario(consulta,cyg,grooming);
            break;
            case 2:
            recepcionista(reservacion,consulta,cyg,grooming);
            break;
            case 3:
            cout<<endl;
            cout<<"FIN DEL MENU"<<endl;
            estado=false;
            break;
            default:
            cout<<"ERROR! El dato digitado no es una opcion.";
            break;
        }
}
}
//VETERINARIO
void veterinario(queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming){ // funcion para mostrar las opciones del veterinario
    bool estadoVet=true;
    int opcion2;
    while (estadoVet)
    {
        cout<<endl<<endl;
        cout<<"-----VETERINARIA PELO LINDO-----"<<endl; //MENU DEL VETERINARIO 
        cout<<"1)Crear Expediente Nuevo"<<endl;
        cout<<"2)Visualizar Expedientes"<<endl;
        cout<<"3)Eliminar Expediente"<<endl;
        cout<<"4)Volver a usuarios"<<endl;
        cout<<"Ingrese el numero de la opcion deseada: ";
        cin>>opcion2;
        switch (opcion2)
        {
        case 1: //DATOS DE EXPEDIENTE
        int opcion;
        cout<<"Que servicio desea: "<<endl; 
        cout<<"1) Consulta"<<endl;
        cout<<"2) CyG"<<endl;
        cout<<"3) Grooming"<<endl;
        cout<<"Escriba el numero del servicio que desea: ";
        cin>>opcion;

        switch(opcion){
            case 1: //SUB DATOS DE EXPEDIENTE
            ingresarinfo(consulta,cyg,grooming);
            mascota.precio = 15;
            consulta.push(mascota);
            break; //Break rellenado de expediente de consultas
            case 2:// SUB DATOS DE EXPEDIENTE
            ingresarinfo(consulta,cyg,grooming);
            mascota.precio = 25;
            cyg.push(mascota);
            break; //Break rellenado de expediente de consulta y grooming
            case 3://SUB DATOS DE EXPEDIENTE
            ingresarinfo(consulta,cyg,grooming);
            mascota.precio = 10;
            grooming.push(mascota);
            break; // Break de rellenado de expediente de grooming
        }//SWITCH DE COLAS
    break; 
    case 2: //MOSTRAR LOS SERVICIOS 
        int opc;
        cout<<"Que expedientes desea ver: "<<endl;
        cout<<"1) Consulta"<<endl;
        cout<<"2) CyG"<<endl;
        cout<<"3) Grooming"<<endl;
        cout<<"Escriba el numero del servicio que desea: ";
        cin>>opc;
        
    switch(opc){
    case 1:
        mostrarConsulta(consulta);//SUB MOSTRAR
    break; // Break mostrar consulta    
    case 2:
        mostrarCyG(cyg); //SUB MOSTRAR
    break;// Brake Mostrar cyg
    case 3:
        mostrarGrooming(grooming);//SUB MOSTRAR
    break; //Brake Grooming
        }
    break;
    case 3: //BORRAR UN EXPEDIENTE
    int s;
            cout << "Donde desea eliminar un expediente?" << endl;
            cout << "1) Consulta" << endl;
            cout << "2) CyG" << endl;
            cout << "3) Grooming" << endl;
            cout << "Ingrese el numero de cola: " << endl;
            cin >> s;
            switch (s)
            {
            case 1:
                borrarc(consulta); //ELIMINAR 1 EXPEDIENTE
                consulta.pop();
                break;  
            case 2:
                borrarcyg(cyg); // ELIMINAR 1 EXPEDIENTE
                cyg.pop();
                break;
            case 3:
                borrarg(grooming); // ELIMINAR 1 EXPEDIENTE
                grooming.pop();
                break;
            }
        break;
    case 4: //para regresar al menu
            cout<<"Regresando al menu principal..."<<endl;
            estadoVet=false;
        break;
    default:
        break;
        }
        
    }
}

//INGRESAR LOS DATOS DE MASCOTAS
void ingresarinfo(queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming){
    bool v;
    cin.ignore();
    cout<<"Ingrese el tipo de animal: ";//no encontramos problema en el ingreso de este dato
    getline(cin,mascota.animal);
    cout<<"Ingrese el nombre de la mascota: ";
    getline(cin,mascota.nombremascota);
    //delimitacion
    do
    {
        if (mascota.nombremascota.empty() || mascota.nombremascota== " " || mascota.nombremascota== "  ")
        {
            cout<<"Este dato es obligatorio, porfavor ingrese el nombre de la mascota: ";
            getline(cin,mascota.nombremascota); 
            v=true;
        }
        else
        {
            v=false;
        }
        
    } while (v);
    
    cout<<"Ingrese el genero de la mascota (M-F): ";
    getline(cin,mascota.genero);
    //delimitacion
    do
    {
        if (mascota.genero!= "M" && mascota.genero!= "F")
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese el genero (M-Masculino, F-Femenino): ";
            getline(cin,mascota.genero); 
            v=true;
        }
        else
        {
            v=false;
        }
    } while (v);    
    cout<<"Ingrese la edad de la mascota: ";
    cin>>mascota.edad;
    //delimitacion
    do
    {
        if (mascota.edad<=0 && mascota.edad>160) // 160 ya que la tortuga que es la que alcanza mayor edad llega a esa edad
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese nuevamente la edad: ";
            cin>>mascota.edad;
            v=true;
        }
        else
        {
            v=false;
        }  
    } while (v);
    cout<<"Ingrese el peso en libras de la mascota: ";
        cout<<"Ingrese el peso en libras de la mascota: ";
    cin>>mascota.peso;
    //delimitacion
    do
    {
        if (mascota.peso<=0)
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese nuevamente el peso: ";
            cin>>mascota.peso; 
            v=true;
        }
        else
        {
            v=false;
        }
        
    } while (v);
    cout<<"Ingrese el nombre del encargado: ";
    cin.ignore();
    getline(cin,mascota.nombreencargado);
    //delimitacion
    do
    {
        if (mascota.nombreencargado.empty() || mascota.nombreencargado== " " || mascota.nombreencargado== "  ")
        {
            cout<<"Este dato es obligatorio, porfavor ingrese el nombre del encargado: ";
            getline(cin,mascota.nombreencargado);
            v=true;
        }
        else
        {
            v=false;
            } 
    } while (v);
    cout<<"CONFIRME EL SERVICIO (Consulta-CyG-Grooming): "<<endl;
    getline(cin,mascota.servicio);  
    do
    {
        if (mascota.servicio!= "Consulta"&& mascota.servicio!="consulta"&& mascota.servicio!="cyg"&& mascota.servicio!= "CyG" && mascota.servicio!="Grooming" && mascota.servicio!="grooming")
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese el servicio que desea: ";
            getline(cin,mascota.servicio);
            v=true;
        }
        else
        {
            v=false;
        }        
    } while (v);
}

void mostrarConsulta(queue<Mascotas>consulta){
    if(!consulta.empty()){
        while(!consulta.empty()){
            cout<<"----VETERINARIA PELO LINDO---- "<<endl;
            cout<<"----EXPEDIENTE MEDICO---- "<<endl;
            cout <<"Raza:" <<consulta.front().animal<<endl;
            cout<<"Nombre:"<<consulta.front().nombremascota<<endl;
            cout<<"Genero:"<<consulta.front().genero<<endl; 
            cout<<"Edad: "<<consulta.front().edad<<endl;
            cout<<"Peso: "<<consulta.front().peso<<endl;
            cout<<"Duenio: "<<consulta.front().nombreencargado<<endl;
            cout<<"Servicio: "<<consulta.front().servicio<<endl;
            consulta.pop();
            
        }
    } 
    else
    {
        cout<<"Este expediente esta vacio."<<endl;
    }
    
}

void mostrarCyG(queue<Mascotas>cyg){
    if(!cyg.empty()){
        while(!cyg.empty()){
            cout<<"----VETERINARIA PELO LINDO---- "<<endl;
            cout<<"----EXPEDIENTE MEDICO---- "<<endl;
            cout<<"Raza:" << cyg.front().animal<<endl;
            cout<<"Nombre:"<<cyg.front().nombremascota<<endl;
            cout<<"Genero:"<<cyg.front().genero<<endl; 
            cout<<"Edad: "<<cyg.front().edad<<endl;
            cout<<"Peso: "<<cyg.front().peso<<endl;
            cout<<"Duenio: "<<cyg.front().nombreencargado<<endl;
            cout<<"Servicio: "<<cyg.front().servicio<<endl;
            cyg.pop();
            
        }
    } 
    else
    {
        cout<<"Este expediente esta vacio."<<endl;
    }
}

void mostrarGrooming(queue<Mascotas>grooming){
    if(!grooming.empty()){
        while(!grooming.empty()){
            cout<<"----VETERINARIA PELO LINDO---- "<<endl;
            cout<<"----EXPEDIENTE MEDICO---- "<<endl;
            cout<<"Raza:" << grooming.front().animal<<endl;
            cout<<"Nombre:"<<grooming.front().nombremascota<<endl;
            cout<<"Genero:"<<grooming.front().genero<<endl; 
            cout<<"Edad: "<<grooming.front().edad<<endl;
            cout<<"Peso: "<<grooming.front().peso<<endl;
            cout<<"Duenio: "<<grooming.front().nombreencargado<<endl;
            cout<<"Servicio: "<<grooming.front().servicio<<endl;
            grooming.pop();
            
        }
    } 
    else
    {
        cout<<"Este expediente esta vacio."<<endl;
    }
}

void borrarc(queue<Mascotas>consulta){
    if(!consulta.empty()){
        consulta.pop();
        cout << "Se ha borrado un expediente" << endl;
    } else {
        cout << "NO HAY EXPEDIENTES" << endl;
    }
}
void borrarcyg(queue<Mascotas>cyg){
    if(!cyg.empty()){
        cyg.pop();
        cout << "Se ha borrado un expendiente" << endl;
    } else {
        cout << "NO HAY EXPEDIENTES" << endl;
    }
}
void borrarg(queue<Mascotas>grooming){
    if(!grooming.empty()){
        grooming.pop();
        cout << "Se ha borrado un expediente" << endl;
    } else {
        cout << "NO HAY EXPEDIENTES" << endl;
    }
}
//SEGUNDA PARTE DE FUNCIONES
void recepcionista( queue<Mascotas>consulta, queue<Mascotas>cyg, queue<Mascotas>grooming,queue<Mascotas>reservacion){
    bool estadoR=true;
    int opcion3;
    while (estadoR)
    {
        cout<<endl<<endl;
        cout<<"-----VETERINARIA PELO LINDO-----"<<endl;
        cout<<"1) Agendar cita"<<endl;
        cout<<"2) Ver citas"<<endl;
        cout<<"3) Cobrar servicios"<<endl;
        cout<<"4) Regresar a usuarios"<<endl;
        cout<<"Ingrese el numero de la opcion deseada: ";
        cin>>opcion3;
    switch (opcion3)
        {
        case 1: //LISTA DE PRECIOS
        int on;
        cout<<"Que servicio desearia: "<<endl; 
        cout<<"1) Consulta"<<endl;
        cout<<"2) CyG"<<endl;
        cout<<"3) Grooming"<<endl;
        cout<<"Escriba el numero del servicio que desearia: ";
        cin>>on;
        switch(on){
            case 1: //SUB DATOS DE EXPEDIENTE
            ingresarCITAS(reservacion);
            reservacion.push(mascota);
            break; //Break rellenado de expediente de consultas CITAS
            case 2:// SUB DATOS DE EXPEDIENTE
            ingresarCITAS(reservacion);
            reservacion.push(mascota);
            break; //Break rellenado de expediente de consulta y grooming CITAS
            case 3://SUB DATOS DE EXPEDIENTE
            ingresarCITAS(reservacion);
            reservacion.push(mascota);
            break; // Break de rellenado de expediente de grooming CITAS
            default:
            cout<<"ERROR! El dato digitado no es una opcion.";
            break;
        }
    break;
        case 2: 
        mostrarCitas(reservacion);  
    break;
        case 3: //COBRO
        int r;
        cout << endl;
        cout << "Que servicio desea cobrar?" << endl;
        cout << "1)Consulta" << endl;
        cout << "2)Consulta y Grooming" << endl;
        cout << "3)Grooming" << endl;
        cout << "Seleccione el servicio a cobrar:";
        cin >> r;
        switch (r)
        {
            case 1:
            chargeconsul(consulta);
            break;
            case 2:
            chargecyg(cyg);
            break;
            case 3:
            chargegroo(grooming);
            break;
            default:
            cout<<"ERROR! El dato digitado no es una opcion.";
            break;
        }
    case 4:
    cout<<"Regresando al menu principal..."<<endl;
    estadoR=false;
    break;
    default:
    cout<<"ERROR! El dato digitado no es una opcion.";
    break;
    break;
    }
    }
}

void chargeconsul(queue<Mascotas> consulta){
    int total = 15;
    do
    {
       
        consulta.pop();
        cout << "Se le ha cobrado un total de $" << total << endl;
        
    }
    while(consulta.empty());
} 

void chargecyg(queue<Mascotas> cyg){
    int Tot2 = 25;
    do
    {
        
        cyg.pop();
        cout << "Se le ha cobrado un total de $" << Tot2 << endl;
        
    }
    while(cyg.empty());
} 

void chargegroo(queue<Mascotas>grooming){
    int Tot3 = 10;
    do
    {
       
        grooming.pop();
        cout << "Se le ha cobrado un total de $" << Tot3 << endl;
       
    }
    while(grooming.empty());
    
} 

void mostrarCitas(queue<Mascotas>reservacion){
    queue<Mascotas> aux = reservacion;
    if(!aux.empty()){
        do{
            cout<<"----VETERINARIA PELO LINDO---- "<<endl;
            cout<<"----EXPEDIENTE MEDICO---- "<<endl;
            cout<<"Raza:" << aux.front().animal<<endl;
            cout<<"Nombre:"<<aux.front().nombremascota<<endl;
            cout<<"Genero:"<<aux.front().genero<<endl; 
            cout<<"Edad: "<<aux.front().edad<<endl;
            cout<<"Peso: "<<aux.front().peso<<endl;
            cout<<"Duenio: "<<aux.front().nombreencargado<<endl;
            cout<<"Servicio: "<<aux.front().servicio<<endl;
            aux.pop();
        }while(!aux.empty());
    }
}
void ingresarCITAS(queue<Mascotas>reservacion){
    bool v;
    cin.ignore();
    cout<<"Ingrese el tipo de animal: "; //no encontramos problema en el ingreso de este dato
    getline(cin,mascota.animal);
    cout<<"Ingrese el nombre de la mascota: ";
    getline(cin,mascota.nombremascota);
    //delimitacion
    do
    {
        if (mascota.nombremascota.empty() || mascota.nombremascota== " " || mascota.nombremascota== "  ")
        {
            cout<<"Este dato es obligatorio, porfavor ingrese el nombre de la mascota: ";
            getline(cin,mascota.nombremascota); 
            v=true;
        }
        else
        {
            v=false;
        }
        
    } while (v);
    
    cout<<"Ingrese el genero de la mascota (M-F): ";
    getline(cin,mascota.genero);
    //delimitacion
    do
    {
        if (mascota.genero!= "M" && mascota.genero!= "F")
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese el genero (M-Masculino, F-Femenino): ";
            getline(cin,mascota.genero); 
            v=true;
        }
        else
        {
            v=false;
        }
    } while (v);    
    cout<<"Ingrese la edad de la mascota: ";
    cin>>mascota.edad;
    //delimitacion
    do
    {
        if (mascota.edad<=0 && mascota.edad>160) // hasta 160 ya que segun investigaos el animal que mas eda alcanza es la tortuga con 160
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese nuevamente la edad: ";
            cin>>mascota.edad;
            v=true;
        }
        else
        {
            v=false;
        }  
    } while (v);
    cout<<"Ingrese el peso en libras de la mascota: ";
    cin>>mascota.peso;
    //delimitacion
    do
    {
        if (mascota.peso<=0)
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese nuevamente el peso: ";
            cin>>mascota.peso; 
            v=true;
        }
        else
        {
            v=false;
        }
        
    } while (v);
    
    cout<<"Ingrese el nombre del encargado: ";
    cin.ignore();
    getline(cin,mascota.nombreencargado);
    //delimitacion
    do
    {
        if (mascota.nombreencargado.empty() || mascota.nombreencargado== " " || mascota.nombreencargado== "  ")
        {
            cout<<"Este dato es obligatorio, porfavor ingrese el nombre del encargado: ";
            getline(cin,mascota.nombreencargado);
            v=true;
        }
        else
        {
            v=false;
            } 
    } while (v);
    cout<<"CONFIRME EL SERVICIO (Consulta-Grooming-CyG): "<<endl;
    getline(cin,mascota.servicio);  
    do
    {
        if (mascota.servicio!= "Consulta"&& mascota.servicio!="consulta"&& mascota.servicio!="cyg"&& mascota.servicio!= "CyG" && mascota.servicio!="Grooming" && mascota.servicio!="grooming")
        {
            cout<<"El dato ingresado no esta permitido, porfavor ingrese el servicio que desea: ";
            getline(cin,mascota.servicio);
        }
        else
        {
            v=false;
        }        
    } while (v);
}
