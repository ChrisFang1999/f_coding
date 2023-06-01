#ifndef CODING_H_
#define CODING_H_
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode *l) : val(value), left(l), right(nullptr) {}
    TreeNode(int value, TreeNode *l, TreeNode *r) : val(value), left(l), right(r) {}
};

// 滑动窗口求最值双端队列 239
class MyDeQueue
{
public:
    deque<int> que;
    void pop(int val)
    {
        if (!que.empty() && val == que.front())
        {
            que.pop_front();
        }
    }
    void push(int val)
    {
        while (!que.empty() && val > que.back())
        {
            que.pop_back();
        }
        que.push_back(val);
    }
    int front()
    {
        return que.front();
    }
};

// 滑动窗口求最大值
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    MyDeQueue que;
    vector<int> result;
    for (int i = 0; i < k; i++)
    { // 先将前k的元素放进队列
        que.push(nums[i]);
    }
    result.push_back(que.front()); // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i++)
    {
        que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
        que.push(nums[i]);             // 滑动窗口前加入最后面的元素
        result.push_back(que.front()); // 记录对应的最大值
    }
    return result;
}

// 242. 有效的字母异位词
bool isAnagram(string s, string t)
{
    vector<int> record(26, 0);
    for (size_t i = 0; i < s.size(); i++)
    {
        record[s[i] - 'a']++;
    }
    for (size_t i = 0; i < t.size(); i++)
    {
        record[t[i] - 'a']--;
    }
    for (size_t i = 0; i < record.size(); i++)
    {
        if (record[i] != 0)
        {
            return false;
        }
    }
    return true;
}
// 383. 赎金信
bool canConstruct(string ransomNote, string magazine)
{
    vector<int> record(26, 0);
    for (size_t i = 0; i < magazine.size(); i++)
    {
        record[magazine[i] - 'a']++;
    }
    for (size_t i = 0; i < ransomNote.size(); i++)
    {
        record[ransomNote[i] - 'a']--;
    }
    for (size_t i = 0; i < record.size(); i++)
    {
        if (record[i] < 0)
        {
            return false;
        }
    }
    return true;
}
// 49. 字母异位词分组
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans.emplace_back(it->second);
    }
    return ans;
}
#endif // CODING_H_