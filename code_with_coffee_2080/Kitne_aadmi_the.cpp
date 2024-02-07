/*
Problem Statement: Kitne aadmi the
Problem Level: EASY
Problem Description:

WRC is trying to organize VECTOR in college after a very long time. But due to the absense of Sobiyu(FSU), college is having hard time to select a good candidate for leading the event as coordinator.

The college decides to give fair chance to any student who's interested to lead the program. So, it decided to go for voting. The college conducts the voting and now it's time to count the votes. When the votes are counted, the one with the highest votes will be elected to be the event coordinator and lead the VECTOR.

Your task is to find, how many more votes did the winner get to the second highest voted candidate.

Input Format

First line contains total number n of votes casted in election
n space separated strings each representing candidate for which the vote was casted.
Constraints

0 < n < 10^5

Output Format

y = votes by which winner surpasses the second highest voted candiate

Sample Input 0

6
X X X Y Y X
Sample Output 0

2
Explanation 0

6 votes are casted on the election. 4 votes are on behalf of candiate 'X' and 2 votes are casted on behalf of candiate 'Y'
. So, the candidate 'X' wins the election by 2 votes (i.e 4-2) to the second highest voted canidate 'Y'.

Sample Input 1

3
X Y X
Sample Output 1

1
Explanation 1

Candidate 'X' wins by (2-1) = 1 votes to the candidate 'Y'.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int y = 0;
    int x = 0;

    for (int i = 0; i < n;i++){
        char ch;
        cin >> ch;
        if(ch == 'Y' || ch =='y'){
            y++;
        }
        if(ch == 'X' || ch =='x'){
            x++;
        }
    }
    cout << abs(y - x) << endl;
    return 0;
}