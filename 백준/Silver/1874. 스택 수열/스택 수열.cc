#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int arr[n];
	for_each(arr, arr + n, [] (int& in) { cin >> in; });
	stack<int> stk;
    string result;
    
	int tmp = 1;
	
	for (const auto& i : arr) {
		if (i >= tmp) {
			for (auto x = tmp ; x < i ; x++) {
				stk.push(x);
				result += "+\n";
			}
			result += "+\n-\n";
			tmp = i + 1;
		} else if (!stk.empty() && stk.top() == i) {
			stk.pop();
			result += "-\n";
		} else {
            cout << "NO";
			return 0;
		}
	}
	
    cout << result;
}