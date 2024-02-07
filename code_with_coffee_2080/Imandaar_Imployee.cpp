/*
Problem name: Imandaar Imployee
Problem Description:

You work at the Pokhara Metropolitan City Office, and today your job is to use a stamp on documents. To use the stamp correctly, you need to dip it in ink or a stamp pad. After dipping, the stamp can be used for a certain amount of time.

Your task is to determine how many times the stamp was dipped in the ink, based on the times the documents were stamped and the duration the ink remains on the stamp after each dip.

Input Format

size of array 'n'
n space separated value of document where document[i] represents time when document was stamped.
ink duration
Constraints

document is always sorted
ink duration is a positive integer.
Output Format

dip_count; which represents the times the stamp was dipped in the ink.

Sample Input 0

5
2 4 5 6 14
4
Sample Output 0

2
Explanation 0

Given the stamp times [2, 4, 5, 6, 14] and ink duration 4.

The first stamp time is 2, so the initial dip time is 2 + 4 = 6.
The second stamp time is 4, which is within the ink duration (6), so no need to dip again.
The third stamp time is 5, within the ink duration (6), so no additional dip.
The fourth stamp time is 6, which matches the current dip time (6), so no need to dip again.
The fifth stamp time is 14, which is greater than the current dip time (6 + 4). Dip again, and the new dip time is 14 + 4 = 18.
The stamp is dipped in the ink at 2 different times: first at 2 and then at 14.

Sample Input 1

4
7 8 10 13
1
Sample Output 1

3
*/

#include <iostream>
#include <vector>

using namespace std;

int countDips(const vector<int>& documents, int inkDuration) {
    int dipCount = 0;
    int currentDipTime = 0;

    for (int stampTime : documents) {
        if (stampTime > currentDipTime) {
            dipCount++;
            currentDipTime = stampTime + inkDuration;
        }
    }

    return dipCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> documents(n);
    for (int i = 0; i < n; ++i) {
        cin >> documents[i];
    }

    int inkDuration;
    cin >> inkDuration;

    int dipCount = countDips(documents, inkDuration);
    cout << dipCount << endl;

    return 0;
}
