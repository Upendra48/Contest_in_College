/*
? Problem Statement

You are dealing with Osama Bin Laden's right hand man for some dangerous weapon dealing.
 Your goal is to do as much as heavy destruction you can in the city of Kathmandu. 
 The greater the price the greater the destruction created by that weapon and 
 the after effects. While you were buying he proposed a strange thing 
 followed in his teams and that was he didn't allow you to choose two 
 consecutive weapons for some reason. So your goal is maximum destruction by 
 buying the maximum destructive weapons.

Input Format

weapon[n] where weapon[i] is the destruction level of weapon

Constraints

arr[i] is positive integer.

Output Format

integer for the greatest possible destruction

Sample Input 0

7
1 2 3 4 5 6 7
Sample Output 0

16
*/

#include <iostream>
#include <vector>
#include <algorithm>

int maxDestruction(const std::vector<int>& weapons) {
    int prev1 = 0, prev2 = 0;
    for (int i = 0; i < weapons.size(); ++i) {
        int current = std::max(prev2 + weapons[i], prev1);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> weapons(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weapons[i];
    }

    int result = maxDestruction(weapons);
    std::cout << result << std::endl;

    return 0;
}
