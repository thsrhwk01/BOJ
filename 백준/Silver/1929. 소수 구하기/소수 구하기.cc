//
// Created by ㅇㅇ on 2022-07-26.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int min,max;
    bool *prime;
    cin >> min;
    cin >> max;
    prime = new bool[max+1];
    fill_n(prime, max+1, 1);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
        if(prime[i])
            for(int j = i*2; j <= max; j += i)
                prime[j] = false;

    for (int i = min; i <= max; i++)
        if(prime[i])
            cout << i << "\n";
}