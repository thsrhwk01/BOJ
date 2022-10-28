#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;

  string inp;
  cin >> t;
  for (t; t>0; t--){
    cin >> inp;
    int res = 0;
    int streak = 0;
    for (int i = 0; i < inp.length(); i++){
      if (inp[i] == 'O') streak++; else streak = 0;
      res+=streak;
    }
    cout << res << '\n';
  }
} 