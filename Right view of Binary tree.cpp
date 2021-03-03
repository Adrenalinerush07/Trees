#include <bits/stdc++.h>
using namespace std;
#define int long long

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
// void __print(long long x) {cerr << x;}
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const int N = 2e5 + 4;
const int mod = 1e9 + 7;

/*

https://www.interviewbit.com/problems/right-view-of-binary-tree/


*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Method 1 (recursion)
void tra(TreeNode *A, unordered_map<int, int> &hm, int k)
{
    if (!A)
    {
        return;
    }
    hm[k] = A->val;
    tra(A->left, hm, k + 1);
    tra(A->right, hm, k + 1);
}

vector<int> solve1(TreeNode *A)
{
    unordered_map<int, int> hm;
    tra(A, hm, 0);
    vector<int> ans;
    for (int i = 0; i < hm.size(); i++)
    {
        ans.push_back(hm[i]);
    }
    return ans;
}

// Method 2 (Queue)
vector<int> solve2(TreeNode *A)
{
    vector<int> right_view;
    queue<TreeNode *> q;
    if (A == NULL)
    {
        return right_view;
    }
    TreeNode *top;
    q.push(A);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            top = q.front();
            q.pop();
            if (top->left)
            {
                q.push(top->left);
            }
            if (top->right)
            {
                q.push(top->right);
            }
        }
        right_view.push_back(top->val);
    }
    return right_view;
}

void solve()
{
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}