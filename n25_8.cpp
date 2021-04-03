#include<iostream>
#include<vector>
#include<algorithm>

/*Напишите программу, которая ищет среди целых чисел, принадлежащих числовому отрезку [95632; 95650], 
числа, имеющие ровно шесть различных нечётных натуральных делителей.
Для каждого найденного числа запишите эти шесть делителей в шесть соседних столбцов на экране с новой строки. 
Делители в строке должны следовать в порядке возрастания.

Например, в диапазоне [2; 48] ровно шесть нечётных различных натуральных делителей имеет число 45, 
поэтому для этого диапазона вывод на экране должна содержать следующие значения:

1 3 5 9 15 45
*/

using namespace std;

int main() {
	int count = 0;
	vector<int> data(6);

	

	for (int i = 95632; i <= 95650; i++) {
		count = 0;
		data.clear();
		int val = sqrt(i);

		if ((val * val) == i and (val % 2) != 0) {
			count++;
			data.push_back(val);
					
		}

		for (int divider = 1; divider <= val; divider++) {
			if ((i % divider) == 0 and (divider % 2) != 0 and (divider * divider) != i) {
				count++;
				data.push_back(divider);
				

				if (count > 6) break;
			}
			if ((i % (i / divider) == 0) and ((i / divider) % 2) != 0 and (divider * divider) != i) {
				count++;
				data.push_back(i / divider);


				if (count > 6) break;
			}
		}
		

		if (count == 6) {
			sort(data.begin(), data.end());
			for (int i = 0; i < 6; i++) {
				cout << data[i] << " ";
			} cout << endl;
		}
	}
}
