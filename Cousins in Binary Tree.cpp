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

https://www.interviewbit.com/problems/cousins-in-binary-tree/

*/

struct tree
{
    int val;
    tree *left;
    tree *right;
    tree(int x) : val(x), left(NULL), right(NULL) {}
};

int getLevel(tree *node, int val, int level)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->val == val)
    {
        return level;
    }
    int result = getLevel(node->left, val, level + 1);
    if (result)
    {
        return result;
    }
    return getLevel(node->right, val, level + 1);
}

void getcousins(tree *node, vector<int> &v, int val, int level)
{
    if (level <= 1)
    {
        return;
    }
    if (node == NULL)
    {
        return;
    }
    if (level == 2)
    {
        if (node->left and node->right)
        {
            if (node->left->val != val and node->right->val != val)
            {
                v.push_back(node->left->val);
                v.push_back(node->right->val);
            }
        }
        else
        {
            if (node->left)
            {
                if (node->left->val != val)
                {
                    v.push_back(node->left->val);
                }
            }
            if (node->right)
            {
                if (node->right->val != val)
                {
                    v.push_back(node->right->val);
                }
            }
        }
    }
    else
    {
        getcousins(node->left, v, val, level - 1);
        getcousins(node->right, v, val, level - 1);
    }
}

void solve()
{
    tree root(10);
    tree a(11);
    tree b(12);
    tree c(13);
    tree d(14);
    tree e(15);

    root.left = &a;
    a.left = &b;
    a.right = &c;
    root.right = &d;
    d.right = &e;

    // cout<< root.val << " " << root.left->val << " " << root.left->left->val << " " << root.left->left->left->val << endl;

    cout << "Level test #1: " << getLevel(&root, 15, 1) << endl;
    // cout<<"Level test #2: "<< getLevel(&root, 13, 1)<<endl;

    int level = getLevel(&root, 15, 1);

    vector<int> cousins;
    getcousins(&root, cousins, 15, level);

    cout << "Cousin folks: ";
    debug(cousins);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    // cin>>tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}