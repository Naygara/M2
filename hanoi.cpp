#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Hastes como pilhas globais 
stack<int> A, B, C;
int total_movimentos = 0;

// Aux para imprimir o estado de uma pilha do fundo ao topo
void imprimir_haste(stack<int> s, const string& nome, bool quebra_linha) {
    vector<int> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    
    cout << nome << ": [";
    for (int i = temp.size() - 1; i >= 0; --i) {
        cout << temp[i];
        if (i > 0) cout << ", ";
    }
    cout << "]";
    if (quebra_linha) cout << endl;
    else cout << " ";
}

void imprimir_estado() {
    imprimir_haste(A, "A", true);
    imprimir_haste(B, "B", false);
    imprimir_haste(C, "C", true);
}

void mover_disco(stack<int>& origem, stack<int>& destino, char nome_origem, char nome_destino) {
    int disco = origem.top();
    origem.pop();
    destino.push(disco);
    total_movimentos++;
    
    cout << "Mover disco " << disco << " de " << nome_origem << " para " << nome_destino << endl;
    imprimir_estado();
    cout << "-----------------------" << endl;
}

void hanoi(int n, stack<int>& origem, stack<int>& destino, stack<int>& auxiliar, char no_origem, char no_destino, char no_auxiliar) {
    if (n == 0) return;
    
    // Move n-1 discos de o para a aux
    hanoi(n - 1, origem, auxiliar, destino, no_origem, no_auxiliar, no_destino);
    
    // Move o disco atual para o destino
    mover_disco(origem, destino, no_origem, no_destino);
    
    // Move n-1 discos aux -> destino
    hanoi(n - 1, auxiliar, destino, origem, no_auxiliar, no_destino, no_origem);
}

int main() {
    int n;
    cout << "Digite o numero de discos n (1 a 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Numero invalido!" << endl;
        return 1;
    }
//inicializa com A
    for (int i = n; i >= 1; --i) {
        A.push(i);
    }

    cout << "Estado inicial:" << endl;
    imprimir_estado();
    cout << "-----------------------" << endl;

    hanoi(n, A, C, B, 'A', 'C', 'B');

    cout << "Total de movimentos: " << total_movimentos << endl;

    return 0;
}
