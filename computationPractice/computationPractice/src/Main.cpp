#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<double>temps;
	
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0; 
	for (double x : temps)sum += x;
	cout << "Average temp is: " << sum / temps.size() << endl;

	std::sort(temps);
	cout << "Median temperature: " << temps[temps.size() / 2] << endl;
}