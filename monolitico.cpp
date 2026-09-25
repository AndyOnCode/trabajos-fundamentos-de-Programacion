#include <iostream>
#include <string>

// Módulo de Inventario
class InventarioService {
public:
    bool verificarStock(const std::string& productoId) {
        std::cout << "[Inventario] Verificando stock para: " << productoId << "...\n";
        return true; // Simulación: siempre hay stock
    }
};

// Módulo de Pagos
class PagoService {
public:
    bool procesarPago(double monto) {
        std::cout << "[Pagos] Procesando pago de $" << monto << "...\n";
        return true; // Simulación: pago exitoso
    }
};

// Sistema Monolítico que junta todo en un solo flujo
class SistemaMonolitico {
private:
    InventarioService inventario;
    PagoService pagos;

public:
    void realizarCompra(const std::string& productoId, double precio) {
        std::cout << "--- Inicio de transacción en Monolito ---\n";
        
        if (inventario.verificarStock(productoId)) {
            if (pagos.procesarPago(precio)) {
                std::cout << "[Orden] Compra completada con éxito.\n";
            }
        }
        
        std::cout << "-----------------------------------------\n";
    }
};

int main() {
    SistemaMonolitico app;
    app.realizarCompra("PROD-123", 49.99);
    return 0;
}