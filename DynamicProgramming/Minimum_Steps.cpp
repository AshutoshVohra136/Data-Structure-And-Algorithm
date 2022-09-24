/*
Minimum number of squares whose sum equals to given number n

Examples : 

Input:  n = 100
Output: 1
Explanation:
100 can be written as 102. Note that 100 can also be written as 52 + 52 + 52 + 52, but this representation requires 4 squares.

Input:  n = 6
Output: 3




*/


/*
BRUTE FORCE [SIMPLE APPROACH]

// A naive recursive C++
// program to find minimum
// number of squares whose sum
// is equal to a given number
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of minimum
// squares that sum to n
int getMinSquares(unsigned int n)
{
    // base cases
    // if n is perfect square then
    // Minimum squares required is 1
    // (144 = 12^2)
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;
 
    // getMinSquares rest of the
    // table using recursive
    // formula
    // Maximum squares required
    // is n (1*1 + 1*1 + ..)
    int res = n;
 
    // Go through all smaller numbers
    // to recursively find minimum
    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + getMinSquares
                                  (n - temp));
    }
    return res;
}
The time complexity of the above solution is exponential.
 If we draw the recursion tree, we can observe that many subproblems are solved again and again.
  For example, when we start from n = 6, we can reach 4 by subtracting
   one 2 times and by subtracting 2 one times. So the subproblem for 4 is called twice.

Since the same subproblems are called again, this problem has the Overlapping 
Subproblems property. So min square sum problem has both properties (see this and this)
 of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems,
  recomputations of the same subproblems can be avoided by constructing a 
  temporary array table[][] in a bottom-up manner.
*/
/*
Dynamic programming-based solution.

// A dynamic programming based
// C++ program to find minimum
// number of squares whose sum
// is equal to a given number
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of minimum
// squares that sum to n
int getMinSquares(int n)
{
    // We need to check base case
    // for n i.e. 0,1,2
    // the below array creation
    // will go OutOfBounds.
    if(n<=3)
      return n;
     
    // Create a dynamic
    // programming table
    // to store sq
    int* dp = new int[n + 1];
 
    // getMinSquares table
    // for base case entries
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    // getMinSquares rest of the
    // table using recursive
    // formula
    for (int i = 4; i <= n; i++)
    {
         
        // max value is i as i can
        // always be represented
        // as 1*1 + 1*1 + ...
        dp[i] = i;
 
        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 +
                                  dp[i - temp]);
        }
    }
 
    // Store result and free dp[]
    int res = dp[n];
    delete[] dp;
 
    return res;
}
Time Complexity: O(n*sqrtn)
Auxiliary Space: O(n)

Thanks to Gaurav Ahirwar for suggesting this solution
*/


/*


Another Approach: (USING MEMOIZATION)

int minCount(int n)
 
{
 
    int* minSquaresRequired = new int[n + 1];
 
    minSquaresRequired[0] = 0;
 
    minSquaresRequired[1] = 1;
 
    for (int i = 2; i <= n; ++i)
 
    {
 
        minSquaresRequired[i] = INT_MAX;
 
        for (int j = 1; i - (j * j) >= 0; ++j)
 
        {
 
            minSquaresRequired[i]
                = min(minSquaresRequired[i],
                      minSquaresRequired[i - (j * j)]);
        }
 
        minSquaresRequired[i] += 1;
    }
 
    int result = minSquaresRequired[n];
 
    delete[] minSquaresRequired;
 
    return result;
}
 
*/
