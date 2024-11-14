#include <iostream>
#include <fstream> // Lectura de archivos
#include <algorithm> // Manejo de vectores y ordenamiento
#include <vector> // Vectores
#include <sstream>
#include <cstdlib>
using namespace std;

void scan(const vector<int>& numeros, int head) {
    int time = 0, temp = head;
    int tam = numeros.size();
    vector<int> recorrido, left, right;
    for (int i = 0; i < tam; ++i) {
        // Dividimos la lista en 2 direcciones, los menores y mayores que el head
        if (head > numeros[i]){left.push_back(numeros[i]);}
        else{right.push_back(numeros[i]);}
    }
    //Ordema de menor a mayor los numeros mayores que el Head
    sort(right.begin(),right.end());
    //Ordema de mayor a menor los numeros menores que el Head
    sort(left.begin(), left.end(), greater<int>());
    // Define la direccion en la que empieza (hacia abajo o hacia arriba) segun el elemento mas cercano
    if (abs(head - left[0]) <= abs(head - right[0])){
        for(int l = 0; l < left.size(); ++l){
            time += abs(temp - left[l]);
            temp = left[l];
            recorrido.push_back(left[l]);
        }
        for(int r = 0; r < right.size(); ++r){
            time += abs(temp - right[r]);
            temp = right[r];
            recorrido.push_back(right[r]);
        }
    }else{
        for(int r = 0; r < right.size(); ++r){
            time += abs(temp - right[r]);
            temp = right[r];
            recorrido.push_back(right[r]);
        }
        for(int l = 0; l < left.size(); ++l){
            time += abs(temp - left[l]);
            temp = left[l];
            recorrido.push_back(left[l]);
        }
    }
    cout << "El recorrido es: ";
    for (int i = 0; i < recorrido.size(); ++i){
        cout << recorrido[i] << " ";
    }
    cout << endl;
    cout << "El tiempo que demora en hacer el recorrido es: " << time << endl;
}
void cscan(const vector<int>& numeros, int head) {
    int time = 0, temp = head;
    int tam = numeros.size();
    vector<int> recorrido, left, right;
    for (int i = 0; i < tam; ++i) {
        // Dividimos la lista en 2 direcciones, los menores y mayores que el head
        if (head > numeros[i]){left.push_back(numeros[i]);}
        else{right.push_back(numeros[i]);}
    }
    //Ordema de menor a mayor los numeros mayores que el Head
    sort(right.begin(),right.end());
    //Ordema de mayor a menor los numeros menores que el Head
    sort(left.begin(), left.end(), greater<int>());
    // Define la direccion en la que empieza (hacia abajo o hacia arriba) segun el elemento mas cercano
    if (abs(head - left[0]) <= abs(head - right[0])){
        for(int l = 0; l < left.size(); ++l){
            time += abs(temp - left[l]);
            temp = left[l];
            recorrido.push_back(left[l]);
        }
        // Despues de recorrida una direccion, vuelve a 0 y inicia el siguiente escaneo
        recorrido.push_back(0);
        time += left[left.size()-1];
        temp = 0;
        for(int r = 0; r < right.size(); ++r){
            time += abs(temp - right[r]);
            temp = right[r];
            recorrido.push_back(right[r]);
        }
    }else{
        for(int r = 0; r < right.size(); ++r){
            time += abs(temp - right[r]);
            temp = right[r];
            recorrido.push_back(right[r]);
        }
        // Despues de recorrida una direccion, vuelve a 0 y inicia el siguiente escaneo
        recorrido.push_back(0);
        time += right[right.size()-1];
        temp = 0;
        for(int l = 0; l < left.size(); ++l){
            time += abs(temp - left[l]);
            temp = left[l];
            recorrido.push_back(left[l]);
        }
    }
    cout << "El recorrido es: ";
    for (int i = 0; i < recorrido.size(); ++i){
        cout << recorrido[i] << " ";
    }
    cout << endl;
    cout << "El tiempo que demora en hacer el recorrido es: " << time << endl;
}

int main() {
    int head, numCasos, temp;
    string linea;
    vector<int> numeros;
    // Abrir el archivo
    ifstream archivo("numeros2.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    archivo >> numCasos;
    
    // Leer los números de cada línea y almacenarlos en el arreglo
    getline(archivo, linea);
    stringstream num(linea);
    for (int i = 0; i < numCasos; ++i) {
        cout << "Cual es el Head(Numero entre 0 y 100): " << endl;
        cin >> head;
        getline(archivo, linea);
        stringstream num(linea);
        while (num >> temp) {
            numeros.push_back(temp);
        }
        //scan(numeros,head); // funcion scan o cscan (descomentar)
        cscan(numeros,head);
        numeros.clear();
    }
    archivo.close();
    return 0;
}
