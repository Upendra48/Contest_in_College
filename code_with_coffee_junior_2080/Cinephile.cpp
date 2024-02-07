/*
Problem : Cinephile
Problem Level: EASY
Problem Statement:

Preeti is fond of watching movies and series, but she is kinda old-class. So, she loves collecting her favourite ones in CDs.

She is trying to organize the disks today. Till now, she has already boxed all the movies which has single CD. Now, the movies having two CDS, each storing one part are left. She is having tough time managing them. So, she first put them in a single straight line and tries to find the pair of each CD.

Your task is to help Preeti find where the second CD of the movie lies in line, given the first CD.

Note: The CDs storing same movie has same name on it. Incase, there's no pair of provided CD return -1;

Input Format

First line contains number of CDs n
Second line contains name of n CDs separated by space
Third line contains the index of the first part of CD whose second part is to be found
Constraints

0 < n < 10^6

Output Format

y = index of second part of CD

Sample Input 0

6
A B C A C B
1
Sample Output 0

5
Explanation 0

The CD 'B' is present at the index 1 of the remaining disks.

So, we start looking forward in the list for it's second part ie. another 'B' again.

As we traverse through the list, we see that 'B' is present at index 5. So, we return 5 as the result.

Sample Input 1

4
A B B A
0
Sample Output 1

3
Explanation 1

Here CD 'A is present at index 0.

As we traverse forward in the list, we find another 'A' at index 3.

So, we return 3 as the position of second CD containing same movie Preeti was looking for.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findSecondCD(const vector<string>& CDs, const string& firstCD, int startIndex) {
    for (int i = startIndex + 1; i < CDs.size(); ++i) {
        if (CDs[i] == firstCD) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<string> CDs(n);
    for (int i = 0; i < n; ++i) {
        cin >> CDs[i];
    }

    int firstCDIndex;
    cin >> firstCDIndex;

    string firstCD = CDs[firstCDIndex];
    int secondCDIndex = findSecondCD(CDs, firstCD, firstCDIndex);

    cout << secondCDIndex << endl;

    return 0;
}
