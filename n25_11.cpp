#include<iostream>
#include<vector>
#include<algorithm>

/*Напишите программу, которая ищет среди целых чисел, принадлежащих числовому отрезку [201455; 201470],
числа, имеющие ровно 4 различных натуральных делителя.
Выведите эти четыре делителя для каждого найденного числа в порядке возрастания.
*/

using namespace std;

int main() {
	int count = 0;
	vector<int> data(4);
	for (int i = 201455; i <= 201470; i++) {
		count = 0;
		data.clear();
		int val = sqrt(i);
		if (val * val == i) {
			data.push_back(val);
		}
		for (int divider = 1; divider <= val; divider++) {
			if (i % divider == 0 and divider * divider != i) {
				data.push_back(divider);
				data.push_back(i / divider);
				count += 2;
			}
			if (count > 4) {
				break;
			}
		}

		if (count == 4) {
			sort(data.begin(), data.end());
			for (int i = 0; i < 4; i++) {
				cout << data[i] << " ";
			}cout << endl;
		}
	}
}
