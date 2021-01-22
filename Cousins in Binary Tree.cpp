#include<bits/stdc++.h>
using namespace std;
#define int long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif 

const int N=2e5+4;
const int mod=1e9+7;

/*



*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int getlevel(TreeNode* A, int B, int level)
 {
     if(A==NULL) return 0;
     if(A->val==B) return level;
     int val=getlevel(A->left,B,level+1);
     if(val>0) return val;
     
     return getlevel(A->right,B,level+1);
     //if(val>0) return val;
 }
 
void getcousin(TreeNode* A, vector<int> &v, int level,int B)
{
    if(A==NULL || level<2) return;
    if(level==2)
    {
        if(A->left && A->right)
        {
         if(A->left->val==B || A->right->val==B) return;
        }
        if(A->left )
        {
            if(A->left->val!=B) v.push_back(A->left->val);
        }    
        if(A->right) 
        {
            if(A->right->val!=B) v.push_back(A->right->val);
        }    
    }
    else if(level>2)
    {
        getcousin(A->left,v,level-1,B);
        getcousin(A->right,v,level-1,B);
    }
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    int level=getlevel(A,B, 1);
    
    getcousin(A,ans,level,B);
    //cout<<level;
    
    return ans;
}

void solve(){
    
}

int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt; 
    tt=1;
    cin>>tt;
    for(int t=1;t<=tt;t++){
        solve();
    }
} 