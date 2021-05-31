//13. Створити шаблонний клас – впорядкований одновимірний масив.
//Тип елементів масиву визначається параметром шаблона(цілі числа, дійсні числа, символи або символьні рядки).
//Передбачити функції для виконання таких операцій : введення елементів у масив, бінарний пошук заданого елемента у масиві 
//і виведення його номера, виведення масиву на екран.

#include <iostream>
using namespace std;

template<typename T>
class OneDim_Array {
private:
	T* arr;
	int size;


public:
	OneDim_Array(int vsize) {
		size = vsize;
		arr = new T[size];
	}
	~OneDim_Array() {
		delete[] arr;
	}

	void InputArr() {
		int i, j;
		for (i = 0; i < size; i++) {
			cin >> arr[i];
		}

		T temp;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (arr[i] > arr[j]) {
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}

	int BinarySearch(T x){
		int l = 0, r = size;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (arr[m] == x)
				return m;
			if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

	void OutputArr() {
		int i;
		for (i = 0; i < size; i++) {
			cout << arr[i]<<"   ";
		}
		cout << endl;
	}
	template <typename T> friend class Iterator;
};

template<typename T>
class Iterator {
private:
	const OneDim_Array<T>& itarr;
	int id;
public:
	Iterator(const OneDim_Array<T>& ar) : itarr(ar) {
		id = 0;
	}
	~Iterator() {}

	void operator++(int) {
		id++;
	}

	bool operator() (){
		return (id < itarr.size);
	}

	T& operator *() {
		return itarr.arr[id];
	}
};

int main() {
	
	int size = 0;
	cout << "\nEnter size of double array: ";
	cin >> size;


	OneDim_Array<double> D_array(size);
	cout << "\nEnter elements of array:" << endl;
	D_array.InputArr();

	Iterator<double> itrd(D_array);

	double delem;
	cout << "\nEnter element you search: ";
	cin >> delem;
	int id = D_array.BinarySearch(delem);
	if (id != -1) {
		cout << "Element exists in this array. It's number is " << id + 1 << endl;
	}
	else {
		cout << "  Element doesn't exist in this array." << endl;
	}

	cout << "\nSorted array:   ";
	while (itrd()) {
		cout << *itrd << "   ";
		itrd++;
	}


	cout << "\n\nEnter size of string array: ";
	cin >> size;

	OneDim_Array<string> S_array(size);
	cout << "\nEnter elements of array:" << endl;
	S_array.InputArr();
	Iterator<double> itrs(D_array);

	string selem;
	cout << "\nEnter element you search: ";
	cin >> selem;
	id = S_array.BinarySearch(selem);
	if (id != -1) {
		cout << "Element exists in this array. It's number is " << id + 1 << endl;
	}
	else {
		cout << "  Element doesn't exist in this array." << endl;
	}
	
	cout << "\nSorted array:   ";
	while (itrs()) {
		cout << *itrs << "   ";
		itrs++;
	}

	return 0;
}

/* 
9
24.387
13.242
19.93
0.234
16.298
0.111
1.245
73.28
19.99

8
cloud
mum
dad
honey
cereals
apple
juice
glass
*/