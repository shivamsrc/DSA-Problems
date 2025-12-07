#include<bits/stdc++.h>
using namespace std;

// stock buy and sell

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int mini = prices[0];                          // the minimum price out of all the prices before selling the stock day ('i' represents the day of selling)
    int maxProfit = 0;


    // starting from index i=1 as with i=0 we'll have no other day means buying and selling at same price means no profit
    for(int i=1; i<n; i++){
        int currentProfit = prices[i] - mini;                   // check current profit by checking the difference between the today's price(selling) and the minimum price on the previous days(buying).
        maxProfit = max(maxProfit, currentProfit);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    cout<<maxProfit(arr);

    return 0;
}