#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void moveZeroes(vector<int>& nums)
        {
            int count_else = 0;
            int count_0 = 0;
            for (int i = 0 ; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                    count_0 += 1;
                else
                    nums[count_else++] = nums[i];
            }
            for (int j = 0; j < count_0; j++)
                nums[count_else + j] = 0;
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
    solution.moveZeroes(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}