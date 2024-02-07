/*
? Problem Statement

In IOE entrance examinations, you serve as an invigilator and your work is to 
arrange those people in order. The students seem to know but for each session 
we found atmost one such student who sat on other's seat. 
The seats are arranged according to their roll numbers. 
You need to find the place for the lost student who couldn't 
find his exact seat and created the problem.

Input Format

n ; number of students

student[n] ; where student[i] is the roll number

Constraints

students is a positive integer array

Output Format

a; problem student

Sample Input 0

6
1 3 5 6 7 8
Sample Output 0

0
Sample Input 1

6
1 3 4 5 8 7
Sample Output 1

5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findProblemStudent(const vector<int>& students) {
    // Make a copy of the original array
    vector<int> originalStudents = students;

    // Sort the copy
    sort(originalStudents.begin(), originalStudents.end());

    // Compare the sorted array with the original array
    for (int i = 0; i < students.size(); ++i) {
        if (students[i] != originalStudents[i]) {
            return i+1; // Return the index of the problem student
        }
    }

    return 0; // Array is already sorted, no problem student found
}

int main() {
    int n;
    cin >> n;

    vector<int> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }

    int problemStudent = findProblemStudent(students);
    cout << problemStudent << endl;

    return 0;
}


/*

*/