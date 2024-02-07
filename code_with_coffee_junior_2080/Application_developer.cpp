/*
Problem Name; Application Developer
Problem Level: Medium
Problem Description:

You've recently joined a company as an application developer. After launching the new application, you started tracking
 the time users spend using it. Users can open and close the app multiple times, and each time they open it, 
 the duration is recorded.

You're given two arrays: one containing user IDs and the other representing the time each user spent when opening the app.
 User IDs can repeat in the arrays. Your task is to find and identify the user who spent the maximum total time using 
 the application across all instances of opening.

Input Format

First line contains the size of array n
Second line contains n user ids separated by space
Third line contains n time entries separated by space.
Constraints

1 < n < 100
user_id[i] is not negative
time_spent[i] is not negative
Output Format

First line should output the user_id
Second line should ouput the usage time of that user
Sample Input 0

5
7 2 7 5 5 
5 6 8 3 7
Sample Output 0

7
13
Explanation 0

The array [7,2,7,5,5] represents the user_id and [5,6,8,3,7] represents time spent by them when the user opened the
 application.

The user with id '7' opened app two times one for 5 minutes and next for 8 minutes. => total = 13
The user with id '2' used the the application for 6 minutes.=> total = 6
The user with id '5' also opened twice and used for 3 minutes and 7 minutes. => total = 10
So the highest using user_id is '7' with the corresponding total time of '13'.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> user_ids(n);
    vector<int> time_spent(n);

    for (int i = 0; i < n; ++i) {
        cin >> user_ids[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> time_spent[i];
    }

    unordered_map<int, int> total_time;

    for (int i = 0; i < n; ++i) {
        total_time[user_ids[i]] += time_spent[i];
    }

    int max_user_id = -1;
    int max_time = -1;

    for (const auto& entry : total_time) {
        if (entry.second > max_time) {
            max_user_id = entry.first;
            max_time = entry.second;
        }
    }

    cout << max_user_id << endl;
    cout << max_time << endl;

    return 0;
}
