#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    // Read and store all integers from standard input
    cout << "Enter integers separated by spaces or newlines (end input with Ctrl+D):" << endl;
    while (cin >> num) {
        numbers.push_back(num);  // Store each integer in the vector
    }

    // Check if the input vector has enough elements
    if (numbers.size() < 3) {
        cerr << "Error: Not enough input data!" << endl;
        return 1;
    }

    int n_diasSinClase = numbers[0];
    int d_dias = numbers[1];
    int f_faltas = numbers[2];
    vector<int> feriados(numbers.begin() + 3, numbers.end());
    vector<int> dias_con_feriados(d_dias, 1);

    // Set the days with holidays to 0
    for (int i = 0; i < feriados.size(); i++) {
        if (feriados[i] < d_dias) {
            dias_con_feriados[feriados[i]] = 0;
        }
    }

    int left = 0;
    int right = f_faltas;
    int maxDias = f_faltas;

    for (int i = 0; i < dias_con_feriados.size(); i++) {
        while (right < dias_con_feriados.size() && dias_con_feriados[right] == 0) {
            right++;
        }

        if (right - i > maxDias) {
            maxDias = right - i +1;
        }
        right++;
    }

    // Output the maximum number of continuous days
    cout << maxDias << endl;

    return 0;
}
