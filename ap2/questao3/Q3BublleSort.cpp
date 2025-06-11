#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    srand(time(0));  // Inicializar a semente
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand() % (max - min + 1) + min);
    }
    return vetor;
};

void bubbleSort(vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                swap(numeros[j], numeros[j + 1]);
            }
        }
    }
}


void imprimirVetor(vector<int>& vetor) {
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numeros = gerarVetorAleatorio(50, 1, 500);

    cout << "Vetor Original:" << endl;
    imprimirVetor(numeros);

    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(numeros);
    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    cout << "Vetor Ordenado:" << endl;
    imprimirVetor(numeros);
    cout << "Duracao do Bubble Sort: " << duracao.count() << " microsegundos" << endl;

    return 0;
}
