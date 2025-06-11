#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Paciente {
    string nome;
    int prioridade;
};

void imprimirLista(vector<Paciente>& lista) {
    for (Paciente p : lista) {
        cout << p.nome << " (Prioridade: " << p.prioridade << ")\n";
    }
    cout << endl;
}

void bubbleSort(vector<Paciente>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j].prioridade > lista[j + 1].prioridade) {
                swap(lista[j], lista[j + 1]);
                trocou = true;
            }
        }
        
        if (!trocou) break;
    }
}

int main() {
    
    vector<Paciente> pacientes = {
        {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1}, {"Mariana", 3},
        {"Fernanda", 5}, {"Rafael", 2}, {"Beatriz", 4}, {"Guilherme", 1}, {"Sofia", 3}
    };

    

    cout << "=== Lista Original de Pacientes ===\n";
    imprimirLista(pacientes);

    
    bubbleSort(pacientes);
    cout << "== Ordenada ==\n";
    imprimirLista(pacientes);

    return 0;

}