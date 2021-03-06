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



*/

struct treeNode
{
    treeNode *left;
    treeNode *right;
    int val;
};

class tree
{
public:
    treeNode *root;

    bool isempty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
            return false;
    }

    treeNode *newNode(int data)
    {
        treeNode *temp = new treeNode();
        temp->left = NULL;
        temp->right = NULL;
        temp->val = data;
        return temp;
    }

    int diameter(treeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);

        int left_diameter = diameter(root->left);
        int right_diameter = diameter(root->right);

        return max({left_height + right_height + 1, left_diameter, right_diameter});
    }

    int height(treeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return (max({height(root->left), height(root->right)}) + 1);
    }
};

class Solution
{
public:
};

void solve()
{
    tree a1;
    a1.root = a1.newNode(1);
    a1.root->left = a1.newNode(3);
    a1.root->left->left = a1.newNode(5);
    a1.root->right = a1.newNode(7);
    a1.root->right->left = a1.newNode(8);

    cout << a1.diameter(a1.root);
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