#include <iostream>
#include <stdexcept>

using namespace std;

class Clever_array
{
public:
	Clever_array(int p_size) : size(p_size), current_size(0) {
		if (size <= 0) {
			throw invalid_argument("Размер массива должен быть больше нуля.");
		}
		array = new int[size];
	}

	Clever_array(const Clever_array& other) : size(other.size), current_size(other.current_size) {
		array = new int[size];
		for (int i = 0; i < current_size; ++i) {
			array[i] = other.array[i];
		}
	}

	Clever_array& operator=(const Clever_array& other) {
		if (this == &other) { 
			return *this;
		}
		delete[] array;

		size = other.size;
		current_size = other.current_size;

		array = new int[size];
		for (int i = 0; i < current_size; ++i) {
			array[i] = other.array[i];
		}

		return *this;
	}

	void append(int value) {
		if (current_size >= size) {
			throw out_of_range("Превышен размер массива.");
		}
		array[current_size++] = value;
	}

	int get_element(int ind) {
		if (ind < 0 || ind >= current_size) {
			throw out_of_range("Некорректный индекс.");
		}
		return array[ind];
	}

	~Clever_array() {
		delete[] array;
	}

private:
	int* array;
	int size;
	int current_size;
};

int main()
{
	setlocale(LC_ALL, "rus");
	try {
		Clever_array arr(5);
		arr.append(1);
		arr.append(4);
		arr.append(155);

		Clever_array new_array(2);
		new_array.append(44);
		new_array.append(34);

		cout << "Элементы массива arr до присваивания:" << endl;
		for (int i = 0; i < 3; ++i) {
			cout << arr.get_element(i) << endl;
		}

		arr = new_array;

		cout << "Элементы массива arr после присваивания:" << endl;
		for (int i = 0; i < 2; ++i) {
			cout << arr.get_element(i) << endl;
		}
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}