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

class bst
{
public:
    treeNode *root;

    bst()
    {
        root = NULL;
    }
    bool isempty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void insert(int item)
    {
        treeNode *p = new treeNode;
        treeNode *parent;
        p->val = item;
        p->left = NULL;
        p->right = NULL;
        parent = NULL;
        if (isempty())
        {
            root = p;
        }
        else
        {
            treeNode *ptr;
            ptr = root;
            while (ptr != NULL)
            {
                parent = ptr;
                if (item > ptr->val)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            if (item < parent->val)
            {
                parent->left = p;
            }
            else
            {
                parent->right = p;
            }
        }
    }

    void levelwiseprint()
    {
        queue<treeNode *> q;
        treeNode *itr = root;
        q.push(root);
        while (q.size() > 0)
        {
            itr = q.front();
            cout << q.front()->val << " ";
            q.pop();
            if (itr->left != NULL)
            {
                q.push(itr->left);
            }
            if (itr->right != NULL)
            {
                q.push(itr->right);
            }
        }
    }

    vector<vector<int>> queue_separate_level_print()
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<treeNode *> q;
        q.push(root);
        vector<int> temp;
        while (q.size() > 0)
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                }
                temp.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void solve()
{
    treeNode *head = NULL;
    bst a1;
    a1.root = head;
    a1.insert(2);
    a1.insert(4);
    a1.insert(5);
    a1.insert(3);
    a1.insert(24);
    a1.insert(12);
    a1.insert(6);
    // a1.levelwiseprint();
    // cout<<endl;

    vector<vector<int>> ans = a1.queue_separate_level_print();
    debug(ans);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}