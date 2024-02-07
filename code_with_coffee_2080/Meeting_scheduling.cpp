/*
Problem Name: Meeting scheduling
Problem statement:

Sudarshan, the organized member at ICES, plans his day by recording all his meetings in his Google calendar as time 
intervals. Each entry marks the start and end time.

Suddenly, Paras calls for an urgent meeting! Sudarshan scrambles to fit this crucial event into his already packed
 schedule. Sudarshan must insert the urgent meeting (new_interval) into his existing calendar (intervals) without 
 any overlaps. He can reschedule or shorten other meetings, or even merge them if they're close together.

Just like Sudarshan's calendar, the intervals represent his busy times. Your task is to help him become a scheduling
 wizard by strategically adding the urgent meeting while maintaining an organized and efficient schedule. Can you help
  Sudarshan make it work?

Function Description: Complete the function reschedule in the editor below. It should return an array of meeting 
schedule after the urgent meeting is inserted. Parameter: schedule : an array of meeting where 
schedule[i] = [start_i, end_i] urgent_meeting : the urgent meeting to be inserted into the schedule urgent_meeting
 = [start, end] Return: an array of meeting after the urgent meeting is inserted schedule[i] = [start_i, end_i]

Input Format

The first line contains an integer n denoting the number of meetings in the schedule.
The next n lines contains the start and end time of each meeting separated by space.
The next line will have the start and end time of the urgent meeting separated by space.
Constraints

0 <= n <= 10^5
0 < start < end <= 10^5
Output Format

Print the resulting schedule with each meeting in a new line.
Each line must have the start and end time of the meeting separated by space.
Sample Input 0

2
3 7
9 11
2 5
Sample Output 0

2 7
9 11
Explanation 0

Initial meeting schedule: [[3, 7], [9, 11]]

Emergency meeting: [2, 5]

Resulting schedule: [[2, 7], [9, 11]]

Sample Input 1

5
1 2
3 5
6 7
8 10
12 16
4 8
Sample Output 1

1 2
3 10
12 16
Explanation 1

Initial meeting schedule: [[1,2], [3,5], [6,7], [8,10], [12,16]]
Emergency meeting: [4, 8]
Resulting schedule: [[1,2], [3,10], [12,16]]
Explanation: The meeting at [4, 8] overlaps with the existing [3,5], [6,7], and [8,10] meeting resulting in [3, 10]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> reschedule(vector<vector<int>>& schedule, vector<int>& urgent_meeting) {
    // Combine the existing meetings and the urgent meeting
    schedule.push_back(urgent_meeting);
    
    // Sort the meetings based on start time
    sort(schedule.begin(), schedule.end());
    
    // Initialize an empty vector to store the resulting schedule
    vector<vector<int>> result;
    
    // Iterate through the sorted meetings
    for (const auto& interval : schedule) {
        // If the result is empty or if the current meeting does not overlap with the last meeting in result
        if (result.empty() || interval[0] > result.back()[1]) {
            result.push_back(interval);
        } else {
            // Merge the overlapping meetings
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> schedule(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> schedule[i][0] >> schedule[i][1];
    }
    
    vector<int> urgent_meeting(2);
    cin >> urgent_meeting[0] >> urgent_meeting[1];
    
    // Get the resulting schedule
    vector<vector<int>> resulting_schedule = reschedule(schedule, urgent_meeting);
    
    // Print the resulting schedule
    for (const auto& interval : resulting_schedule) {
        cout << interval[0] << " " << interval[1] << endl;
    }
    
    return 0;
}
