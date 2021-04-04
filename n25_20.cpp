#include<iostream>
#include<vector>
#include<algorithm>

/*Найдите все натуральные числа, принадлежащие отрезку [106 000 000; 107 000 000],
у которых ровно три различных чётных делителя. В ответе перечислите найденные числа в порядке возрастания.*/

using namespace std;

int main() {
	int count = 0;
	vector<int> data(3);
	for (int i = 106000000; i <= 107000000; i++) {
		data.clear();
		count = 1;
		if (i % 2 != 0) {
			continue;
		}

		int val = sqrt(i);
		if (val * val == i) {
			data.push_back(val);
			
			val -= 1;
			
			count++;
		}
		for (int divider = 2; divider <= val; divider++) {
			if (i % divider == 0) {
				if ( divider % 2 == 0) {
					count++;
					data.push_back(divider);

					if (count > 3) break;
				}
				if ((i / divider) % 2 == 0) {
					count++;
					data.push_back(i / divider);

					if (count > 3) break;
				}
			}
		}
	
		if (count == 3) 
		{
			sort(data.begin(), data.end());
			for (int i = 0; i < 2; i++) {
				cout << data[i] << " ";
			} cout << i << endl;
		}
	}
}
