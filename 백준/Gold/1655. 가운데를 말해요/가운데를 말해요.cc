#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int n;

int main() {
    fastio;

    cin >> n;

    priority_queue<int> leftQ;
    priority_queue<int, vi, greater<>> rightQ;

    int num;

    while (n--) {
        cin >> num;

        if (leftQ.empty() or num <= leftQ.top())
            leftQ.em(num);
        else
            rightQ.em(num);

        switch ((leftQ.size() + rightQ.size()) & 1) {
        case 0:
            while (leftQ.size() != rightQ.size()) {
                if (leftQ.size() > rightQ.size()) {
                    rightQ.em(leftQ.top());
                    leftQ.pop();
                } else {
                    leftQ.em(rightQ.top());
                    rightQ.pop();
                }
            }
            break;

        case 1:
            while (leftQ.size() - rightQ.size() != 1) {
                if (leftQ.size() > rightQ.size()) {
                    rightQ.em(leftQ.top());
                    leftQ.pop();
                } else {
                    leftQ.em(rightQ.top());
                    rightQ.pop();
                }
            }
            break;
        }

        cout << leftQ.top() << endl;
    }
}