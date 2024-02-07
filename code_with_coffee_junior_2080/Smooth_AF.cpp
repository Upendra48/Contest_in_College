/*
Problem Name: Smooth AF
Problem Level: Medium
Problem Description:

CWC has got a wild craze in the market. 100s of groups registered for the competition but only 10 of them made it out 
of the selection round. Team names are as follow:

Annapurna Bit Dhaulagiri Segfault Binary Quantum Glitch Titans ByteMe Lambda

The competition has started and the guys are on fire🔥. Each group has started submitting solutions to solve the various 
questions. Ofcourse, who won't want to title the competition after their name.

We as the organizers have collected the record of order in which each groups has submitted their solutions. After the 
competition is completed, we want to find out the team which has submitted the maximum solutions in a row, and 
largest number of solutions they submitted without interruption.

How about you help us with this? Afterall, you're also a nerd🧑‍💻.

Input Format

First line contains number of teams n
Second line contains n team names separated by space.
Constraints

0<=n<=2000

Output Format

First line should output the team name
Second line should output the maximum number of consecutive submissions
Sample Input 0

6
Sagarmatha Annapurna Sagarmatha Sagarmatha Sagarmatha Annapurna
Sample Output 0

Sagarmatha
3
Explanation 0

Only 6 submissions were recorded in the game, which were submitted by only two teams, Sagarmatha and Annapurna. 
Sagarmatha has managed to submit 3 solutions in a row, but Annapurna has managed to solve only one questions in a row. 
So, higest scoring team in a row is team "Sagarmatha" and the count is 3.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> teams[i];
    }

    int maxConsecutive = 0;
    string maxConsecutiveTeam;
    int consecutiveCount = 0;
    string currentTeam = teams[0];

    for (int i = 0; i < n; ++i) {
        if (teams[i] == currentTeam) {
            consecutiveCount++;
        } else {
            if (consecutiveCount > maxConsecutive) {
                maxConsecutive = consecutiveCount;
                maxConsecutiveTeam = currentTeam;
            }
            consecutiveCount = 1;
            currentTeam = teams[i];
        }
    }

    // Check if the last team had the maximum consecutive submissions
    if (consecutiveCount > maxConsecutive) {
        maxConsecutive = consecutiveCount;
        maxConsecutiveTeam = currentTeam;
    }

    cout << maxConsecutiveTeam << endl;
    cout << maxConsecutive << endl;

    return 0;
}
