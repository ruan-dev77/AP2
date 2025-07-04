#include <iostream>
#include <vector>
using namespace std;

int buscaBinaria(vector<string>& livros,string& tituloBuscado) {
    int inicio = 0;
    int fim = livros.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (livros[meio] == tituloBuscado) {
            return meio; 
        } else if (livros[meio] < tituloBuscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; 
}

void imprimirResultado(int indice, vector<string>& livros) {
    if (indice != -1) {
        cout << "\"O Hobbit\" encontrado na posicao " << indice << endl;
    } else {
        cout << "\"O Hobbit\" nao encontrado." << endl;
    }
}

int main() {
    vector<string> livros = {
        "A Culpa é das Estrelas", "A Droga da Obediência", "A Estrada", "A Fera de Gaia",
        "A Menina que Roubava Livros", "A Montanha Mágica", "A Revolução dos Bichos", "A Sombra do Vento",
        "A Teia de Charlotte", "1984", "Admirável Mundo Novo", "Alice no País das Maravilhas",
        "O Alquimista", "Cem Anos de Solidão", "A Hora da Estrela", "A Metamorfose",
        "As Crônicas de Nárnia: O Leão, a Feiticeira e o Guarda-Roupa", "Assassinato no Expresso do Oriente",
        "Corte de Espinhos e Rosas", "Crepúsculo", "Dom Casmurro", "Duna", "Ensaio sobre a Cegueira",
        "Fahrenheit 451", "Frankenstein", "O Grande Gatsby", "Harry Potter e a Pedra Filosofal",
        "Jogos Vorazes", "Memórias Póstumas de Brás Cubas", "O Código Da Vinci", "O Cortiço",
        "O Guia do Mochileiro das Galáxias", "O Iluminado", "O Ladrão de Raios", "O Pequeno Príncipe",
        "O Poder do Hábito", "O Silmarillion", "O Sol é Para Todos", "O Senhor dos Anéis: A Sociedade do Anel",
        "Onde Vivem os Monstros", "Orgulho e Preconceito", "O Retrato de Dorian Gray",
        "Percy Jackson e o Ladrão de Raios", "Sapiens: Uma Breve História da Humanidade",
        "O Hobbit", "Um Estudo em Vermelho", "Vidas Secas"
    };

    string tituloBuscado = "O Hobbit";

    imprimirResultado(buscaBinaria(livros, tituloBuscado), livros);

    return 0;
}

