#include <iostream>
#include <limits>
//libreria que detecta fallos en la funcion "cin", para facilitar validaciones
#include <iomanip>
//libreria para fijar solo dos decimales en los numeros.
#include <locale>
//libreria que usa la coma como separador de miles
using namespace std;

int main(){
    string divisa_base="";
    string divisa_cotizada="";
    int repetir=0;
    //se crea la variable "repetir" para crear un ciclo de repeticion hasta que el usuario desee lo contrario
    while (repetir==0) {
        cout<<"Ingrese un codigo para la divisa base (puede ingresar USD,EUR, JPY): \n";
        cin>>divisa_base;
        //[IA STARTED] por problemas de interpretacion de operadores (confundí las acciones del or con las del and), la validación no estaba funcionando
        if(divisa_base!= "USD" and divisa_base!= "EUR" and divisa_base!= "JPY"){ //[IA FINISHED]
            cout<<"POR FAVOR INGRESE UNO DE LOS CODIGOS VALIDOS\n";
            continue;//si el usuario ingresa un codigo no válido, vuelve a pedir el codigo de divsa
        }
        cout<<"Ingrese un codigo para la divisa cotizada (puede ingresar USD,EUR, JPY): \n";
        cin>>divisa_cotizada;
        //si el usuario ingresa un codigo no válido, vuelve a pedir el codigo de divsa
        if(divisa_cotizada!= "USD" and divisa_cotizada!= "EUR" and divisa_cotizada!= "JPY"){
            cout<<"POR FAVOR INGRESE UNO DE LOS CODIGOS VALIDOS\n";
            continue;
        }
        cout<<"USTED VA A TRANSFORMAR DE "<<divisa_base<<" A "<<divisa_cotizada;
        double tasa_cambio;
        cout<<"\nPOR FAVOR INGRESE LA TASA DE CAMBIO: ";
        cin>>tasa_cambio;
        //[IA STARTED] para detectar fallos en la funcion "cin", y  si hay un fallo pide al usuario ingresar nuevamente el dato hasta que no haya error
        while(cin.fail() or tasa_cambio<=0)//no se puede escribir un string en un double (no sabia) por eso la libreria #include <limits>
        {
                cin.clear(); // limpia el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // borra basura

                cout << "ENTRADA INVALIDA. INGRESE UNA TASA NUMERICA POSITIVA: ";
                cin >> tasa_cambio;
        }//[IA FINISHED]
        double monto;
        cout<<"\nPOR FAVOR INGRESE EL MONTO INICIAL: ";
        cin>>monto;//[IA STARTED]
        while(cin.fail() or monto<=0)
        {
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // borra basura [IA FINISHED]
            
            cout<<"POR FAVOR, INGRESE UN MONTO VALIDO (MAYOR A 0"<<"\nINGRESE NUEVAMENTE EL MONTO: ";
            cin>>monto;
            
        }
        double conversion;
        conversion=monto*tasa_cambio;//se hace la conversion normal
        //[IA STARTED]
        cout.imbue(locale("en_US.UTF-8"));//separar los miles con una coma
        cout<<"\nLA CONVERSION ES: "<<fixed<<setprecision(2)<<conversion;//poner solo dos decimales aproximados [IA END]
        //proceso para crear el timestamp
        string fecha;
        string hora;
        cout<<"\nPOR FAVOR, INGRESE LA FECHA Y HORA ACTUAL CON EL FORMATO INDICADO"<<"\nFECHA(YY/MM/DD): ";
        cin>>fecha;
        cout<<"\nHORA(HH:MM:SS): ";
        cin>>hora;
        string salida="";
        
        cout<<"-----------------------------------"<<"\n          Market Snapshot         ";
        cout<<"\n-----------------------------------";
        cout<<"\nPar de divisas: "<<divisa_base<<"/"<<divisa_cotizada;
        cout<<"\nTIMESTAMP: "<<fecha<<" "<<hora;
        cout.imbue(locale("en_US.UTF-8"));
        cout<<"\nTASA: "<<fixed<<setprecision(2)<<tasa_cambio;
        cout<<"\nMONTO BASE: "<<fixed<<setprecision(2)<<monto<<" "<<fixed<<setprecision(2)<<divisa_base;
        cout<<"\nMONTO TRANSFORMADO: "<<fixed<<setprecision(2)<<conversion;//todas las finciones para mostrar solo 2 decimales aprox.
        cout<<"\n-----------------------------------";
        cout<<"\nDESEA REALIZAR OTRA CONVERSION? (SI/NO)";
        //ahora se pregunta al usuario si desea continuar en el programa
        cin>>salida;
        if (salida == "No" or salida == "no" or salida == "NO"){//comparacion para acctivar la salida del programa
            cout<<"\nHA SIDO UN GUSTO ATENDERLE, BUEN DIA!";
            repetir=1;
        }
    }
        
}

