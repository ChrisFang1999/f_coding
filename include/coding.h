#ifndef CODING_H_
#define CODING_H_
#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

//滑动窗口求最值双端队列
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

//滑动窗口求最大值
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
#endif // CODING_H_