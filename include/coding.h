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
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

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

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode *n) : next(n), val(value) {}
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

// 26. 原地删除有序数组中的重复项
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int slow = 0, fast = 0; // 不可以int slow , fast = 0，必须对两个变量都赋值
    while (fast < nums.size())
    {
        if (nums[slow] != nums[fast])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}
// 27. 移除元素
int removeElement(vector<int> &nums, int val)
{
    int slow = 0;
    int fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
// 167. 两数之和 II - 输入有序数组
vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
        if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else
        {
            return vector<int>{left + 1, right + 1};
        }
    }
    return {-1, -1};
}

// 5.最长回文子串
// 从一个点向两端扩散，寻找回文串
string palindrome(string str, int left, int right)
{
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return str.substr(left + 1, right - left - 1);
}
string longestPalindrome(string s)
{
    string result = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i + 1);

        result = result.size() > s1.size() ? result : s1;
        result = result.size() > s2.size() ? result : s2;
    }
    return result;
}

// 86. 分隔链表
ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy1 = new ListNode(-1);
    ListNode *dummy2 = new ListNode(-1);
    ListNode *p1 = dummy1;
    ListNode *p2 = dummy2;
    ListNode *p = head;
    while (p)
    {
        if (p->val < x)
        {
            p1->next = p;
            p1 = p1->next;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
        // 断开原链表中的每个节点的 next 指针,必须断开
        ListNode *temp = p->next;
        p->next = nullptr;
        p = temp;
    }
    p1->next = dummy2->next;
    return dummy1->next;
}

//  19. 删除链表的倒数第 N 个结点
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;//可以防止列表只存在一个元素
    ListNode *fast = head;
    while (n > 0)
    {
        fast = fast->next;
        n--;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
}

#endif // CODING_H_