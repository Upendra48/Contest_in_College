/*
Problem Name: Coin Odyssey: The Quantum Matrix Adventure
Problem Level: Hard

Welcome to the digital wonderland where 0s and 1s come to life, and you are the fearless coder on a mission! Imagine a 
universe of binary magic, where every move takes you closer to treasure – the sparkling 1s that are coins, and the 
mysterious 0s that are voids.

With two legendary moves up your sleeve, your quest begins: ie: Right and Down.

Your challenge is to write a code that unlocks the secret path, guiding you to amass the maximum number of golden 
coins scattered across this binary odyssey. Get ready to code your way to glory!

image

Input Format

First line contains size of row m and column n separated by space.
Next m line contains n numbers separated by space.
Constraints

0<= m,n <= 1000
Grid[i][j] is either 0 or 1
Output Format

result is the max number of coins that can be achieved

Sample Input 0

3 3
1 1 1
0 1 0
1 1 1
Sample Output 0

5
*/

#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    // Create a 2D array to store the maximum number of coins that can be collected at each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first cell
    dp[0][0] = grid[0][0];

    // Initialize the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Initialize the first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill in the rest of the dp array
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Return the maximum number of coins collected at the bottom-right cell
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = maxCoins(grid);
    cout << result << endl;

    return 0;
}
