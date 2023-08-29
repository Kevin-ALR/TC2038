//Kevin Arturo Alvarado Rosales A01424864 CVA
#include <iostream>

using namespace std;
 
// Fusiona dos subarreglos de array[].b   
// El primer subarreglo es arr[begin..mid]
// El segundo subarreglo es arr[mid+1..end]
template <typename T>
void merge(T array[], int const izq, int const mid, int const der)
{
    int const subArrayUno = mid - izq + 1;
    int const subArrayDos = der - mid;
 
    // Creamos arreglos temporales
    auto *IzqArray = new T[subArrayUno],
    *DerArray = new T[subArrayDos];
 
    // Copia los datos a los arreglos temporales IzqArray[] y DerArray[]
    for (auto i = 0; i < subArrayUno; i++)
        IzqArray[i] = array[izq + i];
  
    for (auto j = 0; j < subArrayDos; j++)
        DerArray[j] = array[mid + 1 + j];
 
    auto indexDelSubArrayUno = 0, indexDelSubArrayDos = 0;
    int indexDelMergedArray = izq;
 
    // Fusionamos los arreglos temporales de nuevo en array[left..right]
    while (indexDelSubArrayUno < subArrayUno && indexDelSubArrayDos < subArrayDos) 
      {
        if (IzqArray[indexDelSubArrayUno] <= DerArray[indexDelSubArrayDos]) 
          {
            array[indexDelMergedArray] = IzqArray[indexDelSubArrayUno];
            indexDelSubArrayUno++;
          }
        else 
          {
            array[indexDelMergedArray] = DerArray[indexDelSubArrayDos];
            indexDelSubArrayDos++;
          }
        indexDelMergedArray++;
      }
 
    // Copia los elementos restantes de Izq[], si existen...
    while (indexDelSubArrayUno < subArrayUno) 
      {
        array[indexDelMergedArray] = IzqArray[indexDelSubArrayUno];
        indexDelSubArrayUno++;
        indexDelMergedArray++;
      }
 
    // Copia los elementos restantes de Der[], si existen...
    while (indexDelSubArrayDos < subArrayDos) 
      {
        array[indexDelMergedArray] = DerArray[indexDelSubArrayDos];
        indexDelSubArrayDos++;
        indexDelMergedArray++;
      }
  
    delete[] IzqArray;
    delete[] DerArray;
}
 
// begin es el índice izquierdo y end es el índice derecho del subarreglo de arr que será ordenado
template<typename T>
void mergeSort(T array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
// Funciones extras
// Función para imprimir el arreglo
template<typename T>
void printArray(T A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
// Codigo base
int main()
{
    string arrname[] = {"Raul", "Pablo" ,"Andres" ,"Armando", "Arenita", "Charlotte", "Julian"};
    float arrnum[] = {17.08, 17.08 ,17.08 ,17.12, 17.06, 17.08, 17.01, 16.92};
    int arr_size_name = sizeof(arrname) / sizeof(arrname[0]), arr_size_num = sizeof(arrnum) / sizeof(arrnum[0]);
    cout << "Merge Sort algoritm: \n" << endl;
    
    cout << "Precios del dolar esta semana: \n";
    printArray(arrnum, arr_size_num);
    
    mergeSort(arrnum, 0, arr_size_num - 1);
 
    cout << "\nPrecios del dolar ordenados:  \n";
    printArray(arrnum, arr_size_num);
  
    cout << endl << endl;

    cout << "Lista de nombres sin ordenar: \n";
    printArray(arrname, arr_size_name);
    
    mergeSort(arrname, 0, arr_size_name - 1);
 
    cout << "\nLista de nombres ordenados:  \n";
    printArray(arrname, arr_size_name);
    return 0;
}