/*
Problem Statement:Temperature lower than my results.
Problem Level: Medium
Problem Description:

Imagine you're on a quest to find the quirkiest(unpredictable) temperature in the universe. 
Your spaceship's sensors are collecting mind-boggling temperature data from the most exotic planets. 
To aid you in this cosmic adventure, I've crafted a method that will help you navigate through these otherworldly
 climates and pinpoint the temperature closest to zero. Will you be able to find the temperature closest to zero
  in a set of temperatures readings given by your spaceship's sensor?

Input Format

First line contains the number of temperature readings n
Second line contains the temperature readingsT separated by space.
Constraints

0 ≤ N < 10000
-273 ≤ T[i] < 5526

Output Format

Display 0 (zero) if no temperatures are provided. Otherwise, display the temperature closest to 0. 
[if the difference of two temperatures are equally near from zero, prioritize the positive one]

Sample Input 0

5
1 -2 -8 4 5
Sample Output 0

1

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int closestToZero(const vector<int>& temperatures) {
    if (temperatures.empty())
        return 0; // If no temperatures provided, return 0

    int closestTemp = temperatures[0];
    for (int i = 1; i < temperatures.size(); ++i) {
        int currentTemp = temperatures[i];

        if (abs(currentTemp) < abs(closestTemp) || (abs(currentTemp) == abs(closestTemp) && currentTemp > 0)) {
            closestTemp = currentTemp;
        }
    }
    return closestTemp;
}

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);
    for (int i = 0; i < n; ++i) {
        cin >> temperatures[i];
    }

    int result = closestToZero(temperatures);
    cout << result << endl;

    return 0;
}
