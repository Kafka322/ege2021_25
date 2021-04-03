#include<iostream>

/*Напишите программу, которая ищет среди целых чисел, принадлежащих числовому отрезку [2422000; 2422080], 
простые числа. Выведите все найденные простые числа в порядке возрастания, слева от каждого числа выведите его номер по порядку.*/

using namespace std;

int main() {
	bool test = true;
	int count = 0;
	for (int i = 2422000; i <= 2422080; i++) {
		int val = sqrt(i);
		test = true;
		for (int divider = 2; divider <= val; divider++) {
			if (i % divider == 0) {
				test = false;
				break;
			}
		}
		if (test) {
			count += 1;
			cout << count << " " << i << endl;
		}

	}
}
