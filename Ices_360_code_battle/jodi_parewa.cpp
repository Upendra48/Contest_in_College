/*
? Problem Statement

On a saturday afternoon, the Yugal Jodi will gather at the TCC park and Badnaam Gully. 
The Jodi will be indentified by 
their locket which should be the mirror of each other like they are the mirror of each
 other. If a better half has a locket as "parana" , the other half will have "anarap".

In this whole story, the Eklo person is you and the one seeing other Jodi in jealousy. 
You are Jodi Maker and assigned to give the Jealous person his soulmate. Who will get 
the Sworga ki Apsara?

Input Format

n is the number of people people[n]; where people[i] is the Jodi locket

Constraints

0 < N < 1000

Output Format

Jealous Eklo

Sample Input 0

3
parana anarap Eklo
Sample Output 0

Eklo
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    return str == std::string(str.rbegin(), str.rend());
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> list(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> list[i];
    }

    // Iterate through the list and find pairs of palindromes to delete
    std::vector<bool> deleted(n, false); // To keep track of deleted strings
    for (int i = 0; i < n; ++i) {
        if (!deleted[i]) { // Skip if already deleted
            for (int j = i + 1; j < n; ++j) {
                if (!deleted[j] && list[i] == std::string(list[j].rbegin(), list[j].rend())) {
                    deleted[i] = deleted[j] = true; // Mark both strings as deleted
                    break;
                }
            }
        }
    }

    // Print remaining strings
    bool foundRemaining = false;
    for (int i = 0; i < n; ++i) {
        if (!deleted[i]) {
            std::cout << list[i] << std::endl;
            foundRemaining = true;
        }
    }

    return 0;
}

//* Test cases wrong
/*
7
otto hannah anna bob aana hannah otto
output: bob

5
ram sita mar geeta ateeg atis
output: 0
*/
//? 