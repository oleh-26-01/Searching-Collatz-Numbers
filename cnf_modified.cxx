#include <iostream>
#include <chrono>
#include <list>
#include <cmath>

using namespace std;
using namespace chrono;

int get_time()
{
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main()
{
	int long k, i = 0, n, j, l = 0, d = 1;
	int ll = pow(10, 9);
	unsigned *m = new unsigned[ll];
	cin >> k;
	float start = get_time();
	
	while (true)
	{
		i++;
		j = 0;
		n = i;
		
		while (n != 1)
		{
			if (n < l*d and n % d == 0)
			{
				j += m[n/d];
				break;
			}
			if (n % 2 == 0) { n /= 2; }
			else { n = n * 3 + 1; }
			j++;
		}
		
		if (j == k) { break; }
		if (i % d == 0) { m[l+1] = j; l++; }
		if (i % 1000000 == 0) { cout << i/1000000 << "kk " << (get_time() - start) / 1000 << endl; }
	}
	
	cout << i << " " << (get_time() - start) / 1000;
}