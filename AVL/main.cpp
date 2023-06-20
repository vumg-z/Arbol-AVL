#include "AVL.H"

int main() {
    AVLTree arbol;

    // Mostrar árbol
    std::cout << "Arbol AVL:" << std::endl;
    arbol.mostrar();

    // Ejemplo de otras operaciones
    int opcion;
    do {
        std::cout << "\nOpciones:\n";
        std::cout << "1. Agregar hoja\n";
        std::cout << "2. Eliminar hoja\n";
        std::cout << "3. Eliminar todo\n";
        std::cout << "4. Mostrar arbol\n";
        std::cout << "5. Mostrar en orden\n";
        std::cout << "6. Mostrar en preorden\n";
        std::cout << "7. Mostrar en postorden\n";
        std::cout << "8. Contar hojas\n";
        std::cout << "9. Calcular altura\n";
        std::cout << "10. Buscar hoja\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int registro;
            std::string nombre, fechaNacimiento;
            std::cout << "Ingrese el registro: ";
            std::cin >> registro;
            std::cout << "Ingrese el nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la fecha de nacimiento: ";
            std::getline(std::cin, fechaNacimiento);
            arbol.agregar(registro, nombre, fechaNacimiento);
            std::cout << "Hoja agregada correctamente." << std::endl;
            break;
        }
        case 2: {
            int registro;
            std::cout << "Ingrese el registro de la hoja a eliminar: ";
            std::cin >> registro;
            arbol.eliminar(registro);
            std::cout << "Hoja eliminada correctamente." << std::endl;
            break;
        }
        case 3:
            arbol.eliminarTodo();
            std::cout << "Se han eliminado todas las hojas." << std::endl;
            break;
        case 4:
            std::cout << "Arbol AVL:" << std::endl;
            arbol.mostrar();
            break;
        case 5:
            std::cout << "Mostrando en orden:" << std::endl;
            arbol.orden();
            break;
        case 6:
            std::cout << "Mostrando en preorden:" << std::endl;
            arbol.preorden();
            break;
        case 7:
            std::cout << "Mostrando en postorden:" << std::endl;
            arbol.postorden();
            break;
        case 8:
            std::cout << "Cantidad de hojas: " << arbol.contar() << std::endl;
            break;
        case 9:
            std::cout << "Altura del arbol: " << arbol.calcularAltura() << std::endl;
            break;
        case 10: {
            int registro;
            std::cout << "Ingrese el registro de la hoja a buscar: ";
            std::cin >> registro;
            Node* hoja = arbol.buscar(registro);
            if (hoja != nullptr) {
                std::cout << "Hoja encontrada:" << std::endl;
                std::cout << "Registro: " << hoja->registro << ", Nombre: " << hoja->nombre << ", Fecha de nacimiento: " << hoja->fechaNacimiento << std::endl;
            }
            else {
                std::cout << "Hoja no encontrada." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}
