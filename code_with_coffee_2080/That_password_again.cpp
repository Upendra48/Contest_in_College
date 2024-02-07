/*
Problem Name: That password again
Problem statement:

Indra is not good at remembering his password. So he thought of writing it down in a sheet of paper. But he can't write it in plain text. So he had an idea to write his password without anyone else understanding it.

He wrote a list of strings. Each string when splitted into halves had a common character in it. When the common character from every entry in the list was joined he got his actual password.

Indra wanted an easy way to decipher his password. Can you help Indra in writing the program to decipher his password?

Function Description: Complete the function decipher in the editor below. It should return the original password as string. Parameter: strings : an array of strings Return: a string representing the original password

Input Format

The first line contains an integer n , the number of strings. Each of the next n lines contains a string.

Constraints

0 <= n <= 10^5 0 < strings[i].length <= 10^5

Output Format

Print the original password as string.

Sample Input 0

9
feciOhOran
k3yf7gfl
tf9f
aimdfexcit
c0nfm28jezcd
uie0vero
r1nm1k
22
d3dm3n
Sample Output 0

Office123
Explanation 0

strings: ["feciOhOran", "k3yf7gfl", "tf9f", "aimdfexcit", "c0nfm28jezc", "uie0vero", "r1nm1k", "22", "d3dm3n"]
password: Office123

"feciOhOran" -> feciO, hOran -> O
"k3yf7gfl" -> k3yf, 7gfl -> f
"tf9f" -> tf, 9f -> f
"aimdfexcit" -> aimdf, excit -> i
"c0nfm28jezcd" -> c0nfm2, 8jezcd -> c
"uie0vero" -> uie0, vero -> e
"r1nm1k" -> r1n, m1k -> 1
"22" -> 2, 2 -> 2
"d3dm3n" -> d3d, m3n -> 3
*/

