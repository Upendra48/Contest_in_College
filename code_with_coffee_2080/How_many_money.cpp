/*
Problem Name: How many money
Problem description:

Sudarshan and Seamoon are playing a game with two coin stacks of equal height. However, there's a twist: they can only
 see the top coin of each stack. In each turn, they alternate picking up the top coin from one of the stacks. 
 If they choose the stack with the larger coin, that coin is added to Sudarshan's total. At the end of the game, 
 Sudarshan's total will be the sum of all the coins he has collected. Your task is to determine the final amount 
 Sudarshan will have given the initial configurations of the coin stacks.

Input Format

Number representing the number of coins in each stack. n
n space-separated numbers representing the values of the coins in the first stack.
n space-separated integers representing the values of the coins in the second stack.
Constraints

1 <= n <= 10^5
0 <= Stack[i] <= 10^5
Output Format

An integer representing Sudarshan's final total.

Sample Input 0

3
71 60 70
4 100 3
Sample Output 0

241
Explanation 0

In this example, Sudarshan picks up the coin with value 71 from the first stack, adding 71 to his total. 
Seamoon then picks up the coin with value 60 from the second stack. Sudarshan continues to pick the larger
 coins from each stack until all coins have been taken. Thus, Sudarshan's total is ( 71 + 70 + 100 ), 
 and the final answer is 241.
*/

