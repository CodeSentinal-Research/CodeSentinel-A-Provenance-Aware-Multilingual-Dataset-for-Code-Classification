/*
    DP-2 :
    1. Dungeon Game
    2. Wine Problem
    3. Knight Dialer
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------

// 1. Dungeon Game

// class Solution {
// public:

// int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j){

//     // base case
//     if(i == m - 1 && j == n - 1){
//         // find the minimum HP before you enter (m-1, n-1)th room
//         return dungeon[i][j] >= 0 ? 1 : abs(dungeon[i][j]) + 1;
//     }

//     if(i == m || j == n){
//         // knight has gone outside the dungeon
//         return INT_MAX;
//     }

//     // recursive case

//     // fetch the min amount of health that you'll need if you take a right move (x) and a down move (y)

//     // find the minimum HP before you enter (i, j)th room // decide the next step
//     // option 1 : move right
//     int x = helper(dungeon, m, n, i, j + 1);
//     // option 2 : move down
//     int y = helper(dungeon, m, n, i + 1, j);

//     // now it all depends on what kind of value does the cell that you're standing at contains

//     if(dungeon[i][j] == 0){
//         return min(x, y); // or min(x,y) - dungeon[i][j]
//     }else if(dungeon[i][j] < 0){
//         return min(x, y) - dungeon[i][j]; // or min(x, y) + abs(dungeon[i][j])
//     }else { // dungeon[i][j] > 0
//         return dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];
//     }

//     // return dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];

// }

//     int helperBottomUp(vector<vector<int>>& dungeon, int m, int n){

//         // dp[i][j] is exactly f(i,j) and is the min health that I need to go from that i,jth cell to the last target cell

//         // (m+1)(n+1) would be the size of the dp grid as that many unique sub problems exists

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

//         for(int i = 0; i <= m; i ++){
//             dp[i][n] = INT_MAX;
//         }

//         for(int j = 0; j <= n; j++){
//             dp[m][j] = INT_MAX;
//         }

//         for(int i = m - 1; i >= 0; i--){
//             for(int j = n - 1; j >= 0; j--){

//                 if(i == m - 1 && j == n - 1){
//                     // last cell. depends on if it has a positive val or a neg one
//                     dp[i][j] = dungeon[i][j] >= 0 ? 1 : abs(dungeon[i][j]) + 1;
//                 }else{

//                     // for any other box. the formula is enough to handle cases of going outside the maze as we have one extra row and col in the dp filled with INT_MAX

//                     int x = dp[i][j + 1]; // right move min health
//                     int y = dp[i + 1][j]; // down move min health

//                     dp[i][j] = dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];

//                 }

//             }
//         }

//         return dp[0][0]; // f(0,0)

//     }

//     int calculateMinimumHP(vector<vector<int>>& dungeon) {

//         int m = dungeon.size();
//         int n = dungeon[0].size();

//         // return helper(dungeon, m, n, 0, 0);

//         // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

//         // return helperTopDown(dungeon, m, n, 0, 0, dp);

//         return helperBottomUp(dungeon, m, n);

//     }
// };

// int main() {

//     Solution s;

//     vector<vector<int>> dungeon = {{ -2, -3, 3}, { -5, -10, 1}, {10, 30, -5}};

//     cout << s.calculateMinimumHP(dungeon) << endl;

// }

//-----------------------------------------------------------------------------------------------------------------------------------

// 2. Wine Problem

// exponential time complexity

// int maxProfit(vector<int> prices, int i, int j, int year){

//     // base case
//     if(i == j){
//         return prices[i] * year; // last bottle remaining to sell
//     }

//     // recursive case

//     // make a decision for the yth year

//     // option 1 : sell the ith bottle and fetch the max profit from i+1 to j
//     int X = maxProfit(prices, i + 1, j, year + 1);

//     // option 2 : sell the jth bottle and fetch the max profit from i to j-1
//     int Z = maxProfit(prices, i, j - 1, year + 1);

//     // now with the bottle (ith or jth) you chose, return the max overall profit that can be generated
//     return max((prices[i] * year + X), (prices[j] * year + Z));

// }

// // time : O(n^2)
// // space : n^2 due to dp[][] + n due to function call stack ~ O(n^2)
// int maxProfitTopDown(vector<int> prices, int i, int j, int year, vector<vector<int>>& dp){

//     // lookup
//     if(dp[i][j] != -1){
//         // already calculated
//         return dp[i][j];
//     }

//     // base case
//     if(i == j){
//         return dp[i][j] = prices[i] * year; // last bottle remaining to sell
//     }

//     // recursive case

//     // option 1 : sell the ith bottle and fetch the max profit from i+1 to j
//     int X = maxProfit(prices, i + 1, j, year + 1);

//     // option 2 : sell the jth bottle and fetch the max profit from i to j-1
//     int Z = maxProfit(prices, i, j - 1, year + 1);

//     return dp[i][j] =  max((prices[i] * year + X), (prices[j] * year + Z));

// }

// int maxProfitBottomUp(vector<int> prices, int n){

//     vector<vector<int>> dp(n, vector<int>(n));

//     // filling up the base case diagonal manually first where i == j
//     for(int i = 0; i < n; i++){
//         // obviously it'll be the last bottle and for the last bottle, value of year is n
//         dp[i][i] = prices[i] * n;
//     }

//     for(int i = n - 2; i >= 0; i--){
//         for(int j = i + 1; j < n; j++){

//             // dp[i][j] is exactly the same as f(i,j)

//             int year = n - j + i;

//             // sell the ith bottle
//             int X = dp[i + 1][j];

//             // sell the jth bottle
//             int Z = dp[i][j - 1];

//             dp[i][j] = max((prices[i] * year + X), (prices[j] * year + Z));

//         }
//     }

//     return dp[0][n - 1]; // max profit after selling all bottles from 0th to n-1th idx. initial problem

// }

// int main(){

//     vector<int> prices = {2, 3, 5, 1, 4};
// 	int n = prices.size();
// 	cout << maxProfit(prices, 0, n - 1, 1) << endl;

//     vector<vector<int>> dp(n, vector<int>(n, -1));

// 	cout << maxProfitTopDown(prices, 0, n - 1, 1, dp) << endl;

// 	cout << maxProfitBottomUp(prices, n) << endl;

// 	return 0;

// }

//-----------------------------------------------------------------------------------------------------------------------------------

// 3. Knight Dialer

// class Solution {
// public:

//     vector<int> dx = {-2, -2, 2, 2, -1, 1, -1, 1};
//     vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

//     int MOD = 1e9 + 10;

//     int helper(int i, int j, int m){

//         // base case
//         if((i == 3 && j == 0) || (i == 3 && j == 2)){
//             // you're at the abandoned cells
//             return 0;
//         }

//         if(i < 0 || i > 3 || j < 0 || j > 2){
//             // you're out of bounds of the numpad
//             return 0;
//         }

//         if(m == 0){
//             // a unique n digit no has been dialed
//             return 1;
//         }

//         // recursive case

//         int count = 0;

//         // count the #phoneNumbers the knight can dial by making 'm' moves starting from the (i, j)th cell
//         // from this i,j cell technically I have 8 different moves. if some of them are not valid, we'll handle them in the base case
//         for(int k = 0; k < 8; k++){
//             count += helper(i + dx[k], j + dy[k], m - 1) % MOD;
//         }

//         return count % MOD;

//     }

//     int helperTopDown(int i, int j, int m, vector< vector<vector<int>> >& dp){

//         // base case
//         if((i == 3 && j == 0) || (i == 3 && j == 2)){
//              // you're at the abandoned cells
//             return 0;
//         }

//         if(i < 0 || i > 3 || j < 0 || j > 2){
//             // you're out of bounds of the numpad
//             return 0;
//         }

//         if(m == 0){
//              // a unique n digit no has been dialed
//             return 1;
//         }

//         // lookup
//         if(dp[i][j][m] != -1){
//             return dp[i][j][m];
//         }

//         // recursive case

//         // count the #phoneNumbers the knight can dial by making 'm' moves starting from the (i, j)th cell

//         int count = 0;

//         for(int k = 0; k < 8; k++){
//             count += helperTopDown(i + dx[k], j + dy[k], m - 1, dp) % MOD;
//         }

//         return dp[i][j][m] = count % MOD;

//     }

//     int knightDialer(int n) {

//         vector< vector<vector<int>> > dp (4, vector<vector<int>>(3, vector<int>(n, -1)));

//         int total = 0;
//         for(int i = 0; i < 4; i++){
//             for(int j = 0; j < 3; j++){

//                 if((i == 3 && j == 0) || (i == 3 && j == 2)) continue;

//                 // total += helper(i, j, n - 1);
//                 total += helperTopDown(i, j, n - 1, dp);

//             }
//         }

//         return total;
//     }
// };

// int main() {

//     Solution s;

//     cout << s.knightDialer(2) << endl;
//     cout << s.knightDialer(3) << endl;

//     return 0;
// }

//-----------------------------------------------------------------------------------------------------------------------------------
