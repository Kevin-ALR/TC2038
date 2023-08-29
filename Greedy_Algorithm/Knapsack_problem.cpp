// C++ programa para encontrar el número mínimo de denominaciones A01424864 Kevin Arturo Alvarado Rosales Tec CVA 18/08/23
#include <iostream>
#include <bits/stdc++.h>
#include <vector>


using namespace std;


//Función que encuentra el menor número de denominaciones de acuerdo al valor otorgado
template <typename T>
void findMin(float V, T deno[], int n)
{
	int cont = 0;
    	sort(deno, deno + n);
	// Inicializar resultado
    	vector<T> ans;
    	for (int i = n - 1; i >= 0; i--) 
	{
    		// Buscar denominaciones
      		while (V >= deno[i]) 
        		{
          			V -= deno[i];
         			ans.push_back(deno[i]);
        		}
     	}

	// Imprimir resultado
    	/*for (int i = 0; i < ans.size(); i++)
       	{
            		cout << ans[i] << " ";
        	}*/
        
    	for (int i = 0; i < ans.size(); i++)
        	{
            		if(ans[i] == ans[i+1])
                		cont++;
            		else
                	{
                    		cont++;
                    		cout << "[$" << ans[i] << "] = " << cont << endl;
                    		cont = 0;
                	}
            
        	}
  }//Complejidad O(N^2)


//Función que solicita los datos al usuario
void reqAlgor()
 {
    	int num = 0, P = 0 ,Q = 0, A = 0, M = 0, C = 0;
    	float real;
    	
    
    	cout << "-°- Programación dinamica: Argoritmos Avaros -°-\n" << endl;
    	do
      	{
                cout << "Ingrese la cantidad de divisas a utilizar: ";
    		cin >> num;
        		if(num <= 0)
          			cout << "Ingrese un número mayor a 0!" << endl << endl;
      	}while(num <= 0);
        
        //Creamos el array con el numero de divisas
        float arrnum[num];
    
    	for(auto i=0; i < num; i++)
      	{
       		 cout << "Dame la divisa #" << i+1 << ": ";
        		cin >> real;
        		while(real <= 0)
            		{
                		cout << "Ingrese un valor para la divisa #" << i+1 << " mayor a 0: "; cin >> real;
            		}
        		arrnum[i] = real;
      	}
    
    	cout << endl << "Ingrese el costo del producto: "; cin >> P ;
    	cout << "Ingrese el monto con el que paga: "; cin >> Q ; cout << endl << endl;

    
    	while(Q < P)
      	{
        		cout << "Falta dinero para realizar la transacción, ingrese una opción: \n1.-Agregar dinero al monto actual \n2.-Cancelar la compra. \nOpción: ";
          		cin >> A;
          		if(A == 1)
            		{
              			cout << "Monto a agregar: "; cin >> M;
              			C = Q + M;
              			Q = C;
            		}
          		else if(A == 2)
            		{
              			cout << "Adios, que tenga un excelente día!!!" << endl;
              			break;
            		}
          		else
            		{
              			cout << "Porfavor, ingrese una opción valida" << endl << endl; 
            		}
      	}

    	if(Q >= P)
      	{
        		cout << "Lo siguiente es el mínimo" << " numero de cambio por $" << Q - P << ": " << endl;
        		findMin(Q - P, arrnum,num);
      	}
  }//Complejidad O(N^2)


//Función main
int main()
 {
    	reqAlgor();
    	return 0;
  }//Complejidad O(1)