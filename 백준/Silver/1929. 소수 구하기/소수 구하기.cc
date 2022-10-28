//
// Created by ㅇㅇ on 2022-07-24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int begin, end; cin >> begin >> end;

    bool result[1000001];
    result[2] = true;
    if (begin < 2) begin = 2;

    for (int i = (begin % 2 ? begin : begin + 1) ; i <= end ; i+=2) {
        bool is_prime = true;
        for (int j = 3 ; j * j <= i ; j+=2)
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        if (is_prime)
            result[i] = true;
    }
    
    for (int i = begin ; i <= end ; i++)
        if (result[i])
            cout << i << '\n';
}