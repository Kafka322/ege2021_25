#include<iostream>
#include<vector>
#include<algorithm>

/*Назовём нетривиальным делителем натурального числа его делитель, не равный единице и самому числу.
Например, у числа 6 есть два нетривиальных делителя: 2 и 3. 
Найдите все натуральные числа, принадлежащие отрезку [289123456; 389123456] и имеющие ровно три нетривиальных делителя. 
Для каждого найденного числа запишите в ответе его наибольший нетривиальный делитель. Ответы расположите в порядке возрастания.

Например, в диапазоне [5; 16] ровно три различных натуральных делителя имеет число 16, 
поэтому для этого диапазона вывод на экране должна содержать следующие значения:

16 8*/
using namespace std;

int main() {
	int count = 0;
	vector<int> data(3);

	for (int i = 289123456; i <= 389123456; i++) {
		data.clear();
		int val = sqrt(i);
		count = 0;
		if (val * val == i) {
			count++;
			data.push_back(val);
		}
		for (int divider = 2; divider <= val; divider++) {
			if (i % divider == 0 and divider * divider != i) {
				count += 2;
				data.push_back(divider);
				data.push_back(i / divider);
			}
			if (count > 3) break;
		}

		if (count == 3) {
			sort(data.begin(), data.end());
			cout << data[2] << " " << i;
		}
	}
}
