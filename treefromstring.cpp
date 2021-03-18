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

struct Node
{
    int data;
    Node *left, *right;
};

void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int findIndex(string s, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    stack<char> st;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            st.pop();
            if (st.size() == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

Node *treeFromString(string s, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    Node *root = new (Node);
    root->data = s[l] - '0';
    root->left = NULL;
    root->right = NULL;

    int index = -1;
    if (l <= r - 1 and s[l + 1] == '(')
    {
        index = findIndex(s, l + 1, r);
    }
    if (index != -1)
    {
        root->left = treeFromString(s, l + 2, index - 1);
        root->right = treeFromString(s, index + 2, r - 1);
    }
    return root;
}

void solve()
{
    string s = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(s, 0, s.size());
    preOrder(root);
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