#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countOnes(ll num) {
    if (num == 0) return 0;
    if (num < 0) num = -num;
    
    string s = to_string(num);
    int count = 0;
    for (char c : s) {
        if (c == '1') count++;
    }
    return count;
}

/**
 * @brief Solves the problem of finding the minimum number of "1's" needed to 
 *        represent a given number n using numbers composed entirely of the digit '1'.
 * 
 * The function generates all numbers composed entirely of the digit '1' (both positive 
 * and negative) up to the given number n. It then uses dynamic programming to determine 
 * the minimum number of such "1's" required to sum up to n.
 * 
 * @param n The target number for which the minimum number of "1's" is to be calculated.
 *          It is assumed to be a non-negative integer.
 * 
 * @return The minimum number of "1's" required to represent the number n.
 * 
 * @note The function assumes the existence of a helper function `countOnes(ll one)` 
 *       that counts the number of '1's in a given number.
 * 
 * @details
 * - A vector `ones` is used to store all numbers composed entirely of the digit '1'.
 * - Both positive and negative numbers are considered to allow subtraction.
 * - A dynamic programming approach is used with a `dp` array where `dp[i]` represents 
 *   the minimum number of "1's" needed to sum up to `i`.
 * - The function iterates through all possible states and transitions using the numbers 
 *   in the `ones` vector to compute the result.
 * 
 * @complexity
 * - Time Complexity: O(n * m), where n is the target number and m is the number of 
 *   "1's" numbers generated.
 * - Space Complexity: O(n), for the `dp` array.
 */
int solve(ll n) {
    // Generate all numbers with only 1's up to certain length
    vector<ll> ones;
    ll num = 1;
    while (num <= n) {
        ones.push_back(num);
        num = num * 10 + 1;
    }
    
    // Also consider negative numbers with all 1's
    int size = ones.size();
    for (int i = 0; i < size; i++) {
        ones.push_back(-ones[i]);
    }
    
    // Dynamic programming to find minimum ones needed
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 0; i <= n; i++) {
        if (dp[i] == INT_MAX) continue;
        
        for (ll one : ones) {
            ll next = i + one;
            if (next >= 0 && next <= n) {
                dp[next] = min(dp[next], dp[i] + countOnes(one));
            }
        }
    }
    
    return dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    
    return 0;
}