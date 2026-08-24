#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};

int main() 
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    vector<vector<int>> ans = solution.threeSum(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) 
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    return 0;
}