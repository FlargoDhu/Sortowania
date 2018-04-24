// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using namespace std::chrono;


void fill_array(vector<int> &array, int size)
{

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++)
	{
		array.push_back((rand() % 100) + 1);

	}
	if (size < 100) 
	{
		for (vector<int>::size_type i = 0; i < array.size(); i++)
			cout << array.at(i) << " ";
		cout << endl;
	}
}

void quickSort(vector<int> &arr, int p, int r) {

	int i = p, j = r;
	int tmp;
	int q = arr[(p + r) / 2];

	while (i <= j) 
	{
		while (arr[i] < q)
			i++;

		while (arr[j] > q)
			j--;

		if (i <= j) 
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (p < j)
		quickSort(arr, p, j);
	if (i < r)
		quickSort(arr, i, r);

}
void reversing(vector<int> &arr, int size) {
		int temp;
		for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
		}
}

void Mmerge(vector<int> &p, vector<int> &r, vector<int> &bars)
{
	int nL = p.size();
	int nR = r.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (p[j] < r[k]) {
			bars[i] = p[j];
			j++;
		}
		else {
			bars[i] = r[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = p[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = r[k];
		k++; i++;
	}
}

void Msort(vector<int> &arr) {
	if (arr.size() <= 1) return;

	int mid = arr.size() / 2;
	vector<int> p;
	vector<int> r;

	for (size_t j = 0; j < mid; j++)
		p.push_back(arr[j]);
	for (size_t j = 0; j < (arr.size()) - mid; j++)
		r.push_back(arr[mid + j]);

	Msort(p);
	Msort(r);
	Mmerge(p, r, arr);
}

int partforintro(vector<int> &arr, int p, int r) {
	int i = p, j = r;
	int tmp;
	int q = arr[(p + r) / 2];

	while (i <= j)
	{
		while (arr[i] < q)
			i++;

		while (arr[j] > q)
			j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	return i;
}

void MaxHeapify(vector<int> &arr, int HSize, int index) {
	int p = (index + 1) * 2 - 1;
	int r = (index + 1) * 2;
	int largest = 0;

	if (p < HSize && arr[p] > arr[index])
		largest = p;
	else
		largest = index;

	if (r < HSize && arr[r] > arr[largest])
		largest = r;

	if (largest != index)
	{
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;

		MaxHeapify(arr, HSize, largest);
	}
}

void HeapSort(vector<int> &arr, int size) {
	int HSize = size;

	for (int p = (HSize - 1) / 2; p >= 0; --p)
		MaxHeapify(arr, HSize, p);

	for (int i = size - 1; i > 0; --i)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		--HSize;
		MaxHeapify(arr, HSize, 0);
	}
}

void InsertionSort(vector<int> &arr, int size) {
	for (int i = 1; i < size; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (arr[j - 1] > arr[j])
			{
				arr[j - 1] ^= arr[j];
				arr[j] ^= arr[j - 1];
				arr[j - 1] ^= arr[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

static void IntroSort(vector<int> &arr, int size) {
	int partitionSize = partforintro(arr, 0, size - 1);

	if (partitionSize < 16)
	{
		InsertionSort(arr, size);
	}
	else if (partitionSize >(2 * log(size)))
	{
		HeapSort(arr, size);
	}
	else
	{
		quickSort(arr, 0, size - 1);
	}
}


void sprawdz(vector<int> arr)
{
	int i;
	for (i = 0; i < ((arr).size())-1; i++) {
		if (arr[i]>arr[i+1]){
			cout << "Zle posortowane" << endl;
			break;
		}
	}
	if (i == (((arr).size()) - 1)) 
		cout << "Dobrze posortowane" << endl;
}
void sprawdzzly(vector<int> arr)
{
	int i;
	for (i = 0; i < ((arr).size()) - 1; i++) {
		if (arr[i]>arr[i + 1]) {
			cout << "Zle posortowane" << endl;
			break;
		}
	}

}

int main()
{
	vector<int> *array = new vector<int>;
	int a;
	int x;
	int size = 0;
	auto start= high_resolution_clock::now();
	auto stop= high_resolution_clock::now();
	auto duration= duration_cast<microseconds>(stop - start);
	float p;
	long double wynik = 0;
	double long dd = 0;
	{
		do
		{
			cout << endl;
			cout << "1. Stworz i wypelnij tablice i posortuj w procentach" << endl;
			cout << "2. Quick Sort" << endl;
			cout << "3. Merge Sort" << endl;
			cout << "4. Intro Sort" << endl;
			cout << "5. Usun tablice" << endl;
			cout << "6. Wyswietl tablice" << endl;
			cout << "7. Sprawdz tablice" << endl;
			cout << "8. Sprawdz sto razy dla danej w 1. tablicy. (wymaga recznej zmiany w kodzie metody sortowania)" << endl;
			cout << "0. Zakoncz dzialanie programu" << endl;

			cin >> a;
			switch (a)
			{
			case 1:
				if (size != 0)
				{
					cout << "Tablica juz istnieje prosze usunac najpierw tablice (funkcja 5)" << endl;
					break;
				}
				cout << "Podaj rozmiar tablicy." << endl;
				cin >> size;
				fill_array(*array, size);
				cout << "Podaj wartosc procetowa w jakiej ma byc tablica posortowana np. 55 oznacza ze 55% bedzie posortowane," << endl;
				cout << "Jeśli tablica ma być posortowana w odwrotnej kolejności podaj -100" << endl;
				cin >> p;
				if ((p>0)&&(p<=100))
				{
					x = round((size * p) / 100);
					quickSort((*array), 0, x-1);
				}
				if (p == -100) 
				{
					quickSort(*array, 0, size - 1);
					reversing(*array, size);
				}
				if (size < 100)
				{
					for (vector<int>::size_type i = 0; i < (*array).size(); i++)
						cout << (*array).at(i) << " ";
					cout << endl;
				}
				break;
			case 2:
				start = high_resolution_clock::now();
				quickSort((*array), 0, size-1);
				if (size < 100)
				{
					for (vector<int>::size_type i = 0; i < (*array).size(); i++)
						cout << (*array).at(i) << " ";
					cout << endl;
				}
				stop = high_resolution_clock::now();
				duration = duration_cast<microseconds>(stop - start);
				cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
				break;

			case 3:
				start = high_resolution_clock::now();
				Msort(*array);
				if (size < 100)
				{
					for (vector<int>::size_type i = 0; i < (*array).size(); i++)
						cout << (*array).at(i) << " ";
					cout << endl;
				}
				stop = high_resolution_clock::now();
				duration = duration_cast<microseconds>(stop - start);
				cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
				break;
			case 4:
				start = high_resolution_clock::now();
				IntroSort(*array, size);
				if (size < 100)
				{
					for (vector<int>::size_type i = 0; i < (*array).size(); i++)
						cout << (*array).at(i) << " ";
					cout << endl;
				}
				stop = high_resolution_clock::now();
				duration = duration_cast<microseconds>(stop - start);
				cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
				break;
			case 5:
				(*array).clear();
				size = 0;
				break;
			case 6:
				for (vector<int>::size_type i = 0; i < (*array).size(); i++)
					cout << (*array).at(i) << " ";
				cout << endl;
				break;
			case 7:
				sprawdz(*array);
				break;
				//Stworzone czysto dla ułatwienia procesu testowania
			case 8:
				for (int i = 0; i < 100; i++) 
				{
					(*array).clear();
					fill_array(*array, size);
					if ((p > 0) && (p <= 100))
					{
						x = round((size * p) / 100);
						quickSort((*array), 0, x - 1);
					}
					if (p == -100)
					{
						quickSort(*array, 0, size - 1);
						reversing(*array, size);
					}
					if (size < 100)
					{
						for (vector<int>::size_type i = 0; i < (*array).size(); i++)
							cout << (*array).at(i) << " ";
						cout << endl;
					}
					start = high_resolution_clock::now();
					Msort(*array);
					sprawdzzly(*array);
					stop = high_resolution_clock::now();
					duration = duration_cast<microseconds>(stop - start);
					dd = duration.count();
					wynik = dd + wynik;
					dd = 0;
				}
				cout << "Zajelo:" << wynik/100 << endl;
				wynik = 0;
				break;
				
			default:
				cout << "Bad choice! Please try again later.\n";
			}
		} while (a != 0);
		return a;
	}
}

