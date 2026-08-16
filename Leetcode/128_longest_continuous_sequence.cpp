#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        int longestConsecutive(vector<int>& nums)
        {
            unordered_set<int> st;
            for (int x : nums)
                st.insert(x);
            int ans = 0;
            for (int x : st)
            {
                //x is not the starting point of a continuous sequence
                if (st.find(x - 1) != st.end())
                    continue;
                int current = x;
                int length = 1;
                while (st.find(current + 1) != st.end())
                {
                    current++;
                    length++;
                }
                ans = max(ans, length);
            }
            return ans;
        }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); 
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    int ans = solution.longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}