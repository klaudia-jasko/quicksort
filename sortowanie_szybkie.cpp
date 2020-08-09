// sortowanie_szybkie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
clock_t start, stop;
double czas;

void quicksort(int* tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tablica[i] > v) i++;
		while (tablica[j] < v) j--;
		if (i <= j)
		{
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > lewy) quicksort(tablica, lewy, j);
	if (i < prawy) quicksort(tablica, i, prawy);
}

	int main()
	{
		srand(time(NULL));
		int n=10;
		int* tablica = new int[n];
		for (int i = 0; i < n; i++)
		{
			tablica[i] = rand() % 100;
		};
			for (int i = 0; i < n; i++)
			{
				cout << tablica[i] << endl;
			}

			cout << endl << "Sortuje teraz algorytmem quicksort. Prosze czekac!" << endl;
			start = clock();
			quicksort(tablica, 0, n - 1);
			stop = clock();
			czas = (double)(stop - start) / CLOCKS_PER_SEC;
			cout << endl << "Czas sortowania quicksort: " << czas << " s" << endl;

		for (int i = 0; i < n; i++)
		{
			cout << tablica[i] << endl;
		}
		
	}

