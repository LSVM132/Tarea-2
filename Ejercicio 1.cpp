#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

struct Empleado {
    int cedula;
    string nombre;
    int tipo;
    double precioHora;
    double horasLaboradas;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

int main() {
    const double PORCENTAJE_CCSS = 0.0917;
    const int MAX_EMPLEADOS = 100;

    Empleado empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;

    char deseaContinuar;
          //Menú
    do {
        cout << "Ingrese el numero de cedula: ";
        cin >> empleados[numEmpleados].cedula;
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore(); // Limpiar el buffer del teclado
        getline(cin, empleados[numEmpleados].nombre);
        cout << "Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
        cin >> empleados[numEmpleados].tipo;
        cout << "Ingrese la cantidad de horas laboradas: ";
        cin >> empleados[numEmpleados].horasLaboradas;
        cout << "Ingrese el precio por hora: ";
        cin >> empleados[numEmpleados].precioHora;

        // Calcular salario ordinario
        empleados[numEmpleados].salarioOrdinario = empleados[numEmpleados].horasLaboradas * empleados[numEmpleados].precioHora;

        // Calcular aumento
        switch (empleados[numEmpleados].tipo) {
            case 1:
                empleados[numEmpleados].aumento = empleados[numEmpleados].salarioOrdinario * 0.15;
                break;
            case 2:
                empleados[numEmpleados].aumento = empleados[numEmpleados].salarioOrdinario * 0.10;
                break;
            case 3:
                empleados[numEmpleados].aumento = empleados[numEmpleados].salarioOrdinario * 0.05;
                break;
            default:
                empleados[numEmpleados].aumento = 0;
        }

        //  salario bruto
        empleados[numEmpleados].salarioBruto = empleados[numEmpleados].salarioOrdinario + empleados[numEmpleados].aumento;

        //  deducción CCSS
        empleados[numEmpleados].deduccionCCSS = empleados[numEmpleados].salarioBruto * PORCENTAJE_CCSS;

        //  salario neto
        empleados[numEmpleados].salarioNeto = empleados[numEmpleados].salarioBruto - empleados[numEmpleados].deduccionCCSS;

        // Datos del empleado
        cout << "\n---Datos del empleado---\n";
        cout << "Cedula: " << empleados[numEmpleados].cedula << endl;
        cout << "Nombre Empleado: " << empleados[numEmpleados].nombre << endl;
        cout << "Tipo Empleado: " << empleados[numEmpleados].tipo << endl;
        cout << "Salario por Hora: " << empleados[numEmpleados].precioHora << endl;
        cout << "Cantidad de Horas: " << empleados[numEmpleados].horasLaboradas << endl;
        cout << "Salario Ordinario: " << empleados[numEmpleados].salarioOrdinario << endl;
        cout << "Aumento: " << empleados[numEmpleados].aumento << endl;
        cout << "Salario Bruto: " << empleados[numEmpleados].salarioBruto << endl;
        cout << "Deducción CCSS: " << empleados[numEmpleados].deduccionCCSS << endl;
        cout << "Salario Neto: " << empleados[numEmpleados].salarioNeto << endl;

        numEmpleados++;

        cout << "\nDesea registrar otro empleado? (s/n): ";
        cin >> deseaContinuar;

    } while (deseaContinuar == 's' || deseaContinuar == 'S');

    // Estadística
    int contadorOperarios = 0, contadorTecnicos = 0, contadorProfesionales = 0;
    double acumuladoSalarioNetoOperarios = 0, acumuladoSalarioNetoTecnicos = 0, acumuladoSalarioNetoProfesionales = 0;

    for (int i = 0; i < numEmpleados; i++) {
        switch (empleados[i].tipo) {
            case 1:
                contadorOperarios++;
                acumuladoSalarioNetoOperarios += empleados[i].salarioNeto;
                break;
            case 2:
                contadorTecnicos++;
                acumuladoSalarioNetoTecnicos += empleados[i].salarioNeto;
                break;
            case 3:
                contadorProfesionales++;
                acumuladoSalarioNetoProfesionales += empleados[i].salarioNeto;
                break;
        }
    }

    cout << "\n---Estadísticas---\n";
    cout << "1) Cantidad Empleados Tipo Operarios: " << contadorOperarios << endl;
    cout << "2) Acumulado Salario Neto para Operarios: " << acumuladoSalarioNetoOperarios << endl;
    cout << "3) Promedio Salario Neto para Operarios: " << acumuladoSalarioNetoOperarios / contadorOperarios << endl;
    cout << "4) Cantidad Empleados Tipo Tecnico: " << contadorTecnicos << endl;
    cout << "5) Acumulado Salario Neto para Tecnicos: " << acumuladoSalarioNetoTecnicos << endl;
    cout << "6) Promedio Salario Neto para Tecnicos: " << acumuladoSalarioNetoTecnicos / contadorTecnicos << endl;
    cout << "7) Cantidad Empleados Tipo Profesional: " << contadorProfesionales << endl;
    cout << "8) Acumulado Salario Neto para Profesionales: " << acumuladoSalarioNetoProfesionales << endl;
    cout << "9) Promedio Salario Neto para Profesionales: " << acumuladoSalarioNetoProfesionales / contadorProfesionales << endl;

    return 0;
}

