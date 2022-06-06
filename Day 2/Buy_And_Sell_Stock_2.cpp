#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int buyAndSell(int currentIndex, int canBuy, int transCount, vector<int> &prices, unordered_map<string, int> &memo)
{
    if (currentIndex >= prices.size())
        return 0;

    string currentKey = to_string(currentIndex) + "-" + to_string(canBuy);

    if (memo.find(currentKey) != memo.end())
        return memo[currentKey];

    int currentPrice = prices[currentIndex];
    int ans = 0;

    if (canBuy == 1)
    {
        int idle = buyAndSell(currentIndex + 1, canBuy, transCount, prices, memo);
        int buy = buyAndSell(currentIndex + 1, 0, transCount, prices, memo) - currentPrice;

        ans = max(idle, buy);
    }

    else
    {
        int idle = buyAndSell(currentIndex + 1, canBuy, transCount, prices, memo);
        int sell = buyAndSell(currentIndex + 1, 1, transCount - 1, prices, memo) + currentPrice;

        ans = max(idle, sell);
    }

    memo[currentKey] = ans;

    return ans;
}

int maxProfit(vector<int> &prices)
{

    unordered_map<string, int> memo;

    int ans = buyAndSell(0, 1, 1, prices, memo);
    return ans;
}