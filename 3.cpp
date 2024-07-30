#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top()>prices[i]) st.pop();
            if(st.size()!=0) ans[i]=prices[i]-st.top();
            else ans[i]=prices[i];
            st.push(prices[i]);
        }
        return ans;
    }
};