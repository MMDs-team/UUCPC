Problem name: wrestling
Order:
    - Time complexity: O(2 ^ N)
    - Space complexity: O(2 ^ N) -> Our solution: O(1)
Constraints: 1 <= N <= 18, 1 <= K <= N
* Note: If powers are same for two player, then the one with lower idx will win!

Input format:
N K
a_1 a_2 ... a_(2 ^ N)

Output format:
M
b_1 b_2 ... b_(2 ^ M)

Sample input:
4 1
1 2 4 3

Sample output:
2
2 3
