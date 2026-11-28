/*
LeetCode 1406: Stone Game III

Difficulty: Hard  
Topics: Array, Math, Dynamic Programming, Game Theory, Minimax

Problem Description:
Alice and Bob continue their games with piles of stones. There are several 
stones arranged in a row, and each stone has an associated value given in 
the integer array stoneValue.

- Alice and Bob take turns, with Alice starting first.
- On each player's turn, that player can take 1, 2, or 3 stones from the 
  first remaining stones in the row.
- The score of each player is the sum of the values of the stones taken.
- The objective of the game is to end with the highest score. 
- The game continues until all the stones have been taken.

Assuming both Alice and Bob play optimally, the program must return:
- "Alice" if Alice will win.
- "Bob" if Bob will win.
- "Tie" if they will end the game with the same score.

Approach: Minimax with Dynamic Programming
Because both players play optimally, we cannot use a simple greedy approach. 
We must evaluate every possible move (taking 1, 2, or 3 stones) and choose 
the one that leaves the opponent in the worst possible position.

Instead of tracking absolute scores for both players, we track the relative 
score difference (Current Player Score - Opponent's Score).

We work backwards from the end of the array to the beginning. At any given 
stone i, the current player evaluates the next 3 possible moves:
1. Take 1 stone: stoneValue[i] - (best difference opponent gets from i+1)
2. Take 2 stones: stoneValue[i] + stoneValue[i+1] - (best difference from i+2)
3. Take 3 stones: stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - (from i+3)

The player chooses the move that yields the maximum possible difference.

Space Optimization: O(1) Space
Since we only ever need to look ahead a maximum of 3 steps, we do not need 
to store the results of the entire game in an O(N) array. Instead, we use 
three variables (n1, n2, n3) as a sliding window to keep track of the results 
for the next 3 moves, reducing our space complexity to O(1).

Complexity:
- Time Complexity: O(N) where N is the length of stoneValue. 
- Space Complexity: O(1) because we only use three integer variables.
*/
#include<limits.h>
#define MAX(a,b) ((a)>(b)? (a):(b))
char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n1=0,n2=0,n3=0;
    for(int i=stoneValueSize-1; i>=0; i--)
    {
        int best=INT_MIN, take=0;
        take+=stoneValue[i];
        best = MAX(best, take - n1);

        if((i+1)<stoneValueSize)
        {
            take+=stoneValue[i+1];
            best = MAX(best, take - n2);
        }

        if((i+2)<stoneValueSize)
        {
            take+=stoneValue[i+2];
            best = MAX(best, take - n3);
        }

        n3=n2;
        n2=n1;
        n1=best;
        
    }
    if (n1 > 0) return "Alice";
    if (n1 < 0) return "Bob";
    return "Tie";
}
