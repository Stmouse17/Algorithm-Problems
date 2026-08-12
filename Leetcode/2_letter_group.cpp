#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            int count[26] = {0};
            for (char c : s)
                count[c - 'a']++;
            string key;
            for (int i = 0; i < 26; i++)
            {
                key += '#';
                key += to_string(count[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &pair : mp)
            ans.push_back(pair.second);
        return ans;       
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    Solution solution;
    vector<vector<string>> ans = solution.groupAnagrams(strs);
    for (auto &group : ans)
    {
        for (string s : group)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}