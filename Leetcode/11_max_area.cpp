#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int left_board = 0, right_board = height.size() - 1;
            int max = 0;
            while (left_board < right_board)
            {
                int left_heigth = height[left_board];
                int right_height = height[right_board];
                int area;
                if (left_heigth > right_height)
                {
                    area = (right_board - left_board) * right_height;
                    right_board--;
                }
                else
                {
                    area = (right_board - left_board) * left_heigth;
                    left_board++;
                }
                max = (area > max) ? area : max;
            }
            return max;
        }
};

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    Solution solution;
    int max_area = solution.maxArea(height);
    cout << max_area << endl;
    return 0;
}