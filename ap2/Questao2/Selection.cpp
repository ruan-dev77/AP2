#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Paciente {
    string nome;
    int prioridade;
};

void imprimirLista(vector<Paciente>& lista) {
    for (Paciente paciente : lista) {
        cout << paciente.nome << " (Prioridade: " << paciente.prioridade << ")\n";
    }
    cout << endl;
}


void selectionSort(vector<Paciente>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j].prioridade < lista[minIdx].prioridade) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(lista[i], lista[minIdx]);
        }
    }
}

int main() {
    
    vector<Paciente> pacientes = {
        {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1}, {"Mariana", 3},
        {"Fernanda", 5}, {"Rafael", 2}, {"Beatriz", 4}, {"Guilherme", 1}, {"Sofia", 3}
    };

    cout << "Lista Original de Pacientes\n";
    imprimirLista(pacientes);
    
    selectionSort(pacientes);
    cout << "Ordenada com Selection: \n";
    imprimirLista(pacientes);
    

    return 0;
}