#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int buyAndSell(int currentIndex, int canBuy, int transCount, vector<int> &prices, unordered_map<string, int> &memo, vector<vector<vector<int>>> &dp)
{
    if (currentIndex >= prices.size())
        return 0;

    if (transCount == 0)
        return 0;

    // string currentKey = to_string(currentIndex) + "-" + to_string(canBuy) + to_string(transCount) ;

    // if(memo.find(currentKey) != memo.end() )
    // return memo[currentKey] ;

    if (dp[currentIndex][canBuy][transCount] != -1)
        return dp[currentIndex][canBuy][transCount];

    int currentPrice = prices[currentIndex];
    int ans = 0;

    if (canBuy == 1)
    {
        int idle = buyAndSell(currentIndex + 1, canBuy, transCount, prices, memo, dp);
        int buy = buyAndSell(currentIndex + 1, 0, transCount, prices, memo, dp) - currentPrice;

        ans = max(idle, buy);
    }

    else
    {
        int idle = buyAndSell(currentIndex + 1, canBuy, transCount, prices, memo, dp);
        int sell = buyAndSell(currentIndex + 1, 1, transCount - 1, prices, memo, dp) + currentPrice;

        ans = max(idle, sell);
    }

    // memo[currentKey] = ans ;

    dp[currentIndex][canBuy][transCount] = ans;

    return ans;
}

int maxProfit(vector<int> &prices)
{

    unordered_map<string, int> memo;
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(2, -1)));

    int ans = buyAndSell(0, 1, 1, prices, memo, dp);

    return ans;
}