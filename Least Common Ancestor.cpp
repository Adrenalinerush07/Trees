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

https://www.interviewbit.com/problems/least-common-ancestor/

*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool preOrder(TreeNode *A, vector<int> &path, int target)
{
    if (!A)
    {
        return 0;
    }
    path.push_back(A->val);
    if (A->val == target)
    {
        return 1;
    }
    if (preOrder(A->left, path, target) || preOrder(A->right, path, target))
    {
        return 1;
    }
    path.pop_back();
    return 0;
}

int Solution::lca(TreeNode *A, int B, int C)
{
    vector<int> vecB, vecC;

    preOrder(A, vecB, B);
    preOrder(A, vecC, C);

    if (vecB.empty() || vecC.empty())
        return -1;

    for (int i = vecB.size() - 1; i >= 0; i--)
    {
        for (int j = vecC.size() - 1; j >= 0; j--)
        {
            if (vecC[j] == vecB[i])
                return vecC[j];
        }
    }
    return -1;
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