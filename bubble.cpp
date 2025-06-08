#include <iostream>
#include <vector>
#include <random>   
#include <ctime>    
#include <algorithm> 
#include <chrono>   

using namespace std;

vector<int> array_original;


std::random_device rd;
std::mt19937 gerador(rd()); 
std::uniform_int_distribution<int> numall(0, 100000); 


void preenche() { 
    for (int i = 0; i < 100000; i++) {
        array_original.push_back(numall(gerador));
    }
}


void imprimir(const vector<int>& arr) { 
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



// Bubble Sort
void bubbleSort(vector<int>& arr) { 
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) { 
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[min_idx], arr[i]);
    }
}


int main() {
    
    cout << "Preenchendo o vetor original com 100.000 elementos aleatórios..." << endl;
    preenche();
    cout << "Vetor original preenchido." << endl << endl;

    vector<int> copia_bubble = array_original;
    cout << "Executando Bubble Sort..." << endl;
    auto start_bubble = chrono::high_resolution_clock::now();
    bubbleSort(copia_bubble);
    auto end_bubble = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_bubble = end_bubble - start_bubble;
    cout << "Bubble Sort concluído em: " << duration_bubble.count() << " segundos." << endl << endl;

    
    vector<int> copia_insertion = array_original;
    cout << "Executando Insertion Sort..." << endl;
    auto start_insertion = chrono::high_resolution_clock::now();
    insertionSort(copia_insertion);
    auto end_insertion = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_insertion = end_insertion - start_insertion;
    cout << "Insertion Sort concluído em: " << duration_insertion.count() << " segundos." << endl << endl;

   
    vector<int> copia_selection = array_original;
    cout << "Executando Selection Sort..." << endl;
    auto start_selection = chrono::high_resolution_clock::now();
    selectionSort(copia_selection);
    auto end_selection = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_selection = end_selection - start_selection;
    cout << "Selection Sort concluído em: " << duration_selection.count() << " segundos." << endl << endl;

    return 0; 
}
