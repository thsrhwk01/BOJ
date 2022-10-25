#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	string s;

	vector<pair<string, int>> v;

	while(n--) {
		cin >> s;
		v.push_back({s, s.length()});
	}

	sort(v.begin(), v.end(), comp);

	v.erase(unique(v.begin(), v.end()), v.end());

	for (pair<string, int> s : v)
		cout << s.first << '\n';
}