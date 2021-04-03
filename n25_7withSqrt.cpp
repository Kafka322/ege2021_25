#include<iostream>
#include<vector>
#include<algorithm>

/*Напишите программу, которая ищет среди целых чисел, принадлежащих числовому отрезку [95632; 95700],
числа, имеющие ровно шесть различных чётных натуральных делителей.
Для каждого найденного числа запишите эти шесть делителей в шесть соседних столбцов на экране с новой строки.
Делители в строке должны следовать в порядке возрастания.*/

using namespace std;


int main() {
	int count = 0;
	vector<int> data(6);

	for (int i = 95632; i <= 95700; i++) {
		count = 0;
	
		data.clear();
		int val = sqrt(i);
		if (val * val == i and i % 2 == 0) {
			count++;
			data.push_back(sqrt(i));
			
		}
		if (i % 2 == 0) {
			data.push_back(i);
			count++;
		}
		for (int divider = 2; divider <= val; divider++) {
			
			if ((divider * divider != i) and (i % divider) == 0 and (divider % 2) == 0) {

				data.push_back(divider);
				count++;
					
				if (count > 6) break;
			}
			
			if ((divider * divider != i) and (i % (i / divider)) == 0 and (i / divider) % 2 == 0) {
				data.push_back( i / divider);
				count++;

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
