#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// function to return minimum number of squares whose sum is equal to n
int minSquares(int n)
{
    // base cases
    if (n <= 3)
        return n;

    // minSquares table for storing results of subproblems
    int minSquares[n + 1];

    // get the least perfect square number which is smaller than or equal to n
    int max_square = sqrt(n);

    // initialize the table
    for (int i = 0; i <= n; i++)
        minSquares[i] = i; // set the value as the same as the index (minimum is 1)

    // go through all perfect squares and store the minimum number of squares
    for (int i = 1; i <= max_square; i++)
        for (int j = 1; j <= n; j++)
            if (i * i <= j) // if the perfect square is smaller than or equal to j
                minSquares[j] = min(minSquares[j], 1 + minSquares[j - i * i]); // update the minimum number of squares

    // return the final result
    return minSquares[n];
}

int main()
{
    int n;

    // read n from standard input
    cin >> n;

    // print the result
    cout << minSquares(n) << endl;

    return 0;
}
