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


void preenche1() { 
    for (int i = 0; i < 1000; i++) {
        array_original.push_back(numall(gerador));
    }
}

void preenche2() { 
    for (int i = 0; i < 10000; i++) {
        array_original.push_back(numall(gerador));
    }
}
void preenche3() { 
    for (int i = 0; i < 100000; i++) {
        array_original.push_back(numall(gerador));
    }
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

int main() {

    //array com 1000 elementos;
    cout << "Preenchendo o vetor original com 1000 elementos aleatórios..." << endl;
    preenche1();
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

    array_original.clear();
    copia_bubble.clear();
    copia_insertion.clear();

   //array com 10000 elementos;
    cout << "Preenchendo o vetor original com 10000 elementos aleatórios..." << endl;
    preenche2();
    cout << "Vetor original preenchido." << endl << endl;

    copia_bubble = array_original;
    cout << "Executando Bubble Sort..." << endl;
    start_bubble = chrono::high_resolution_clock::now();
    bubbleSort(copia_bubble);
    end_bubble = chrono::high_resolution_clock::now();
    duration_bubble = end_bubble - start_bubble;
    cout << "Bubble Sort concluído em: " << duration_bubble.count() << " segundos." << endl << endl;

    copia_insertion = array_original;
    cout << "Executando Insertion Sort..." << endl;
    start_insertion = chrono::high_resolution_clock::now();
    insertionSort(copia_insertion);
    end_insertion = chrono::high_resolution_clock::now();
    duration_insertion = end_insertion - start_insertion;
    cout << "Insertion Sort concluído em: " << duration_insertion.count() << " segundos." << endl << endl;

    array_original.clear();
    copia_bubble.clear();
    copia_insertion.clear();

    //array com 100000 elementos;
    cout << "Preenchendo o vetor original com 100000 elementos aleatórios..." << endl;
    preenche3();
    cout << "Vetor original preenchido." << endl << endl;

    copia_bubble = array_original;
    cout << "Executando Bubble Sort..." << endl;
    start_bubble = chrono::high_resolution_clock::now();
    bubbleSort(copia_bubble);
    end_bubble = chrono::high_resolution_clock::now();
    duration_bubble = end_bubble - start_bubble;
    cout << "Bubble Sort concluído em: " << duration_bubble.count() << " segundos." << endl << endl;
    
    copia_insertion = array_original;
    cout << "Executando Insertion Sort..." << endl;
    start_insertion = chrono::high_resolution_clock::now();
    insertionSort(copia_insertion);
    end_insertion = chrono::high_resolution_clock::now();
    duration_insertion = end_insertion - start_insertion;
    cout << "Insertion Sort concluído em: " << duration_insertion.count() << " segundos." << endl << endl;

    array_original.clear();
    copia_bubble.clear();
    copia_insertion.clear();
    return 0; 
}