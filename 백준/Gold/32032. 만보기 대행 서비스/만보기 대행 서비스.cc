#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

using ll = long long;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);

    ll a = 0, b = 0, n, m;
    cin >> n >> m;

    while (n--) {
        ll x;
        cin >> x;

        a = min(a, x);
        b = max(b, x);
    }

    ll dist = abs(a - b);

    // 양 끝에서 m 대기
    ll ans = dist * 2 + m * 2;

    // 한 끝에서 m 대기
    ans = min(ans, m + dist * 2 + min(abs(a), abs(b)) * 2);

    // 왕복하고 조금 남은 시간 대기
    if (dist * 2 < m) ans = min(ans, dist * 2 + m);

    // 두번 왕복 사이에 완료 가능?
    if (dist * 2 >= m) ans = min(ans, dist * 4);

    cout << ans;

    return 0;
}