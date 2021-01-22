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

https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/


*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Method -1
void allP(TreeNode *A, int B, vector<vector<int>> &res, vector<int> ans)
{
    if (!A)
        return;
    ans.push_back(A->val);
    if (A->val == B && !A->left && !A->right)
    {
        res.push_back(ans);
    }
    if (A->left)
    {
        allP(A->left, B - (A->val), res, ans);
    }
    if (A->right)
    {
        allP(A->right, B - (A->val), res, ans);
    }
}
vector<vector<int>> Solution::pathSum(TreeNode *A, int B)
{
    vector<vector<int>> res;
    vector<int> ans;
    if (!A)
        return res;
    allP(A, B, res, ans);
    return res;
}

// Method 2
void findpaths(vector<vector<int>> &v, vector<int> &row, TreeNode *root, int sum, int B)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        sum = sum + root->val;

        if (sum == B)
        {
            row.push_back(root->val);
            v.push_back(row);
            row.pop_back();
        }
        return;
    }
    sum = sum + root->val;
    row.push_back(root->val);
    findpaths(v, row, root->left, sum, B);
    findpaths(v, row, root->right, sum, B);
    row.pop_back();
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