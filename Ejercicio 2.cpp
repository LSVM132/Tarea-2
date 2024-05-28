#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables para estadísticas
    int entradasSol = 0, entradasSombra = 0, entradasPreferencial = 0;
    int acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;

    // Ciclo para ingresar ventas
    char continuar;
    do {
        // Variables para cada venta
        int numeroFactura, cedula, localidad, cantidad;
        string nombre;

        // Ingreso de datos de la venta
        cout << "Numero de factura: ";
        cin >> numeroFactura;
        cout << "Cedula: ";
        cin >> cedula;
        cout << "Nombre del comprador: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
        cin >> localidad;
        cout << "Cantidad de entradas (máximo 4): ";
        cin >> cantidad;

        // Validar cantidad de entradas
        if (cantidad <= 0 || cantidad > 4) {
            cout << "La cantidad de entradas debe ser entre 1 y 4." << endl;
            continue;
        }

        // Procesar datos de la venta
        int precioEntrada, cargosServicios;
        string nombreLocalidad;
        switch (localidad) {
            case 1:
                precioEntrada = 10500;
                nombreLocalidad = "Sol Norte/Sur";
                entradasSol += cantidad;
                acumuladoSol += cantidad * precioEntrada;
                break;
            case 2:
                precioEntrada = 20500;
                nombreLocalidad = "Sombra Este/Oeste";
                entradasSombra += cantidad;
                acumuladoSombra += cantidad * precioEntrada;
                break;
            case 3:
                precioEntrada = 25500;
                nombreLocalidad = "Preferencial";
                entradasPreferencial += cantidad;
                acumuladoPreferencial += cantidad * precioEntrada;
                break;
            default:
                cout << "Localidad invalida." << endl;
                continue;
        }

        // El subtotal y total a pagar
        int subtotal = cantidad * precioEntrada;
        cargosServicios = cantidad * 1000;
        int totalPagar = subtotal + cargosServicios;

        // Mostrar información de la venta
        cout << "---------------------------" << endl;
        cout << "Numero de Factura: " << numeroFactura << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Nombre del comprador: " << nombre << endl;
        cout << "Localidad: " << nombreLocalidad << endl;
        cout << "Cantidad de Entradas: " << cantidad << endl;
        cout << "Subtotal: " << subtotal << " colones" << endl;
        cout << "Cargos por Servicios: " << cargosServicios << " colones" << endl;
        cout << "Total a pagar: " << totalPagar << " colones" << endl;

        // Preguntar si desea continuar
        cout << "¿Desea ingresar otra venta? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    // Estadísticas
    cout << "Estadisticas:" << endl;
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << entradasSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << acumuladoSol << " colones" << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << entradasSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << acumuladoSombra << " colones" << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << entradasPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << acumuladoPreferencial << " colones" << endl;

    return 0;
}
