#include <iostream>
#include <string>

using namespace std;

// Nó da pilha implementada com lista encadeada
struct No {
    char valor;
    No* proximo;
};

// Pilha com ponteiros
struct Pilha {
    No* topo;

    Pilha() : topo(nullptr) {}

    bool vazia() {
        return topo == nullptr;
    }

    void empilhar(char c) {
        No* novo = new No();
        novo->valor = c;
        novo->proximo = topo;
        topo = novo;
    }

    void desempilhar() {
        if (vazia()) return;
        No* temp = topo;
        topo = topo->proximo;
        delete temp;
    }

    // Libera toda a memória alocada
    void limpar() {
        while (!vazia()) {
            desempilhar();
        }
    }
};

bool automatoPilha(string palavra) {
    Pilha pilha;
    int i = 0;

    // Empilha para cada 'a'
    while (i < (int)palavra.length() && palavra[i] == 'a') {
        pilha.empilhar('A');
        i++;
    }

    // Deve existir pelo menos um 'a'
    if (pilha.vazia()) {
        return false;
    }

    // Desempilha para cada 'b'
    while (i < (int)palavra.length() && palavra[i] == 'b') {
        if (pilha.vazia()) {
            pilha.limpar();
            return false;
        }

        pilha.desempilhar();
        i++;
    }

    // Aceita somente se terminou a palavra
    // e a pilha ficou vazia
    bool aceita = (i == (int)palavra.length() && pilha.vazia());
    pilha.limpar();
    return aceita;
}

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (automatoPilha(palavra)) {
        cout << "Palavra ACEITA!" << endl;
    } else {
        cout << "Palavra REJEITADA!" << endl;
    }

    return 0;
}