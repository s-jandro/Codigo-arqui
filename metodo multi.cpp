#include <iostream>
#include <vector>

using namespace std;

void ComplementoUno(vector<int>& n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == 0) {
            n[i] = 1;
        } else {
            n[i] = 0;
        }
    }
}

void ComplementoDos(vector<int>& n) {
    for (int i = 7; i >= 0; i--) {
        if (n[i] == 0) {
            n[i] = 1;
            break;
        } else if (n[i] == 1) {
            n[i] = 0;
        }
    }
}

void MostrarN(const vector<int>& n) {
    for (int i = 0; i < n.size(); i++) {
        cout << n[i];
    }
    cout << endl;
}

int main() {
    string n1_str, n2_str;
    cout << "Ingrese el primer número binario (8 bits): ";
    cin >> n1_str;
    cout << "Ingrese el segundo número binario (8 bits): ";
    cin >> n2_str;

    vector<int> n1, n2;
    for (char bit : n1_str) {
        n1.push_back(bit - '0');
    }
    for (char bit : n2_str) {
        n2.push_back(bit - '0');
    }

    vector<int> Cn1(8, 0);
    for (int i = 0; i < 8; i++) {
        Cn1[i] = n1[i];
    }

    cout << "         ";
    MostrarN(n1);
    cout << "         ";
    MostrarN(n2);
    cout << "-----------------" << endl;

    ComplementoUno(Cn1);
    ComplementoDos(Cn1);

    vector<vector<int>> matriz(3, vector<int>(17, 0));

    for (int i = 0; i < 8; i++) {
        matriz[0][i] = n1[i];
    }
    for (int i = 0; i < 8; i++) {
        matriz[1][i] = Cn1[i];
    }
    for (int i = 8; i < 16; i++) {
        matriz[2][i] = n2[i - 8];
    }

    for (int f = 0; f < 8; f++) {
        if (matriz[2][15] == 0 && matriz[2][16] == 1) {
            for (int i = 16; i >= 0; i--) {
                matriz[2][i] = matriz[2][i] + matriz[0][i];
                if (matriz[2][i] == 2) {
                    matriz[2][i] = 0;
                    if (i != 0) {
                        matriz[2][i - 1] = matriz[2][i - 1] + 1;
                    }
                }
                if (matriz[2][i] == 3) {
                    matriz[2][i] = 1;
                    if (i != 0) {
                        matriz[2][i - 1] = matriz[2][i - 1] + 1;
                    }
                }
            }
            for (int i = 16; i >= 0; i--) {
                if (i != 0) {
                    matriz[2][i] = matriz[2][i - 1];
                }
            }
        } else if (matriz[2][15] == 1 && matriz[2][16] == 0) {
            for (int i = 16; i >= 0; i--) {
                matriz[2][i] = matriz[2][i] + matriz[1][i];
                if (matriz[2][i] == 2) {
                    matriz[2][i] = 0;
                    if (i != 0) {
                        matriz[2][i - 1] = matriz[2][i - 1] + 1;
                    }
                }
                if (matriz[2][i] == 3) {
                    matriz[2][i] = 1;
                    if (i != 0) {
                        matriz[2][i - 1] = matriz[2][i - 1] + 1;
                    }
                }
            }
            for (int i = 16; i >= 0; i--) {
                if (i != 0) {
                    matriz[2][i] = matriz[2][i - 1];
                }
            }
        } else {
            for (int i = 16; i >= 0; i--) {
                if (i != 0) {
                    matriz[2][i] = matriz[2][i - 1];
                }
            }
        }
    }

    for (int i = 16; i >= 0; i--) {
        if (i != 0) {
            matriz[2][i] = matriz[2][i - 1];
        }
    }

    for (int i = 0; i < 17; i++) {
        cout << matriz[2][i];
    }

    return 0;
}
