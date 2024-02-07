/*
? Problem Statement

The NSA was sending a super confidential information to the Government of Nepal 
regarding the Corruption. Being the hub of corrupted politicians, they sold it 
to the Mafias.The document in wrong hand can lead to the death of honest Journalist 
who risked their life to gather the evidence.But the Corrupted Politician forgot 
to get the key while selling. When asked an honest non-corrupted citizen hid it 
inside a safe. They got a hint that the key is the count of Zing Zing numbers. 
A Zing Zing number is formed when it reads the same from both ends and is constructed 
from the product of numbers that also exhibit the same symmetric pattern. 
You are bribed to crack the code to the confidential document. Given a range, 
calculate the Zing Zing count.


Input Format

left right

Constraints

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left is less than or equal to right.
Output Format

result

Sample Input 0

4 1000
Sample Output 0

4
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// Function to count Zing Zing numbers in the given range
int countZingZingNumbers(int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
        // Check if the square root is an integer
        int sqrt_num = sqrt(i);
        if (sqrt_num * sqrt_num == i) {
            // Check if both the square root and the original number are palindromes
            if (isPalindrome(sqrt_num) && isPalindrome(i)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int left, right;
    cin >> left >> right;

    int result = countZingZingNumbers(left, right);
    cout << result << endl;

    return 0;
}
