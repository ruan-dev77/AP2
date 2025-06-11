#include <iostream>
using namespace std;
#include <vector>
#include <chrono>

vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    srand(time(0));  // Inicializar a semente
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand() % (max - min + 1) + min);
    }
    return vetor;
};

int partition(vector<int>& vetor, int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);
    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i + 1], vetor[alto]);
    return (i + 1);
}

void quickSort(vector<int>& vetor, int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(vetor, baixo, alto);
        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}


void imprimirVetor(vector<int>& vetor) {
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {

    vector<int> numerosAleatorios = gerarVetorAleatorio(50, 1, 500);

    cout << "Vetor Original:" << endl;
    imprimirVetor(numerosAleatorios);

    auto inicio = std::chrono::high_resolution_clock::now();

    quickSort(numerosAleatorios, 0, numerosAleatorios.size() - 1);

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    

    cout << "Vetor Ordenado:" << endl;
    imprimirVetor(numerosAleatorios);

    cout << "Tempo de Execucao: " << duracao.count() << " microsegundos" << endl;




    return 0;
}