/*
Problem Name: World Peace
Problem Level: Medium
Problem Description:

In a secret meeting organized by the World Union, representatives from all around the world are gathered to discuss 
important matters about world peace and prosperity. To make sure things are fair, they decided that each country 
should have an equal number of representatives making decisions.

For example, if Country 'A' has 5 representatives, Country 'B' has 3, and Country 'C' has 1, each country 
can only have 1 representative in the decision room. So, 4 representatives from Country 'A' and 2 from Country 'B' 
need to leave the room.

The representatives are sitting in a row of chairs, and the entrance to the decision room is on the right. 
If a country has too many representatives, the ones sitting near the door will leave.

Your job is to figure out how the representatives will be arranged after making sure each country has the same 
number of representatives as the others.

Input Format

input_string ; shows the representatives arrangement in the room.

Constraints

input_string is lowercase

Output Format

output_string

Sample Input 0

abcddeebc
Sample Output 0

abcde
Explanation 0

The number of representatives from Country 'a' is 1, whereas it is 2 for other countries such as 'b', 'c', 'd,' and 'e'.
 Therefore, only 1 representative is permitted in the decision room. Consequently, starting from the right side, 
 the surplus representatives exit the room, resulting in the final seat arrangement as 'abcde'.
Sample Input 1

adeabdeb
Sample Output 1

adeabdeb
Explanation 1

Every country has 2 representatives in the decision making room.


*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    unordered_map<char, int> counts;
    string output = "";

    // Count the number of representatives from each country
    for (char c : input) {
        counts[c]++;
    }

    // Find the minimum count among the representatives from different countries
    int minCount = INT_MAX;
    for (const auto& kv : counts) {
        minCount = min(minCount, kv.second);
    }

    // Construct the output string by including only one representative from each country
    for (int i = input.size() - 1; i >= 0; --i) {
        char c = input[i];
        if (counts[c] <= minCount) {
            output = c + output;
        }
        counts[c]--;
    }

    cout << output << endl;

    return 0;
}
