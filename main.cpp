#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool automatoPilha(string palavra) {
    stack<char> pilha;
    int i = 0;

    // Empilha para cada 'a'
    while (i < palavra.length() && palavra[i] == 'a') {
        pilha.push('A');
        i++;
    }

    // Deve existir pelo menos um 'a'
    if (pilha.empty()) {
        return false;
    }

    // Desempilha para cada 'b'
    while (i < palavra.length() && palavra[i] == 'b') {
        if (pilha.empty()) {
            return false;
        }

        pilha.pop();
        i++;
    }

    // Aceita somente se terminou a palavra
    // e a pilha ficou vazia
    return (i == palavra.length() && pilha.empty());
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