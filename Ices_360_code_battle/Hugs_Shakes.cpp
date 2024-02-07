/*
? Problem Statement

In the heart of our lively WRC, seven groups—BCT, BEI, BEL, BCE, BGE, BME, and 
BAME—each added their own touch of color to the annual interaction program. 
As the day turned to dusk, students gathered for an evening filled with surprises.

A unique game was on the agenda, starting from the end of the line. 
Think of it like a story where, instead of pages, the students were chapters. 
The rule was straightforward: if two students had the same faculty, they hugged; 
if different, they shook hands.

As the game wrapped up, a question lingered: which group had the longest chain of hugs? 
Who became the hero of this tale, creating a story of unity echoing through the campus? 
The answers were hidden in the students' intertwined journey, waiting to be discovered.

Input Format

size
actual array
Constraints

0<=array.length<=2000

Output Format

faculty no of hugs

Sample Input 0

6
BCT BEI BEL BEL BCT BCE
Sample Output 0

BEL
1
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<string, int> findLongestHugChain(const vector<string>& array) {
    unordered_map<string, int> hugCount;
    string maxHugGroup;
    int maxHugs = 0;
    string prevGroup = ""; // To track the previous group

    for (const auto& group : array) {
        if (group == prevGroup) {
            hugCount[group]++;
        } else {
            if (hugCount[prevGroup] > maxHugs) {
                maxHugs = hugCount[prevGroup];
                maxHugGroup = prevGroup;
            }
            prevGroup = group;
            hugCount[group] = 0; 
        }
    }

    
    if (hugCount[prevGroup] > maxHugs) {
        maxHugGroup = prevGroup;
        maxHugs = hugCount[prevGroup];
    }

    return make_pair(maxHugGroup, maxHugs);
}

int main() {
    int size;
    cin >> size;

    vector<string> array(size);
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    pair<string, int> result = findLongestHugChain(array);
    cout << result.first <<endl;
    cout<< result.second << endl;

    return 0;
}

/*

*/