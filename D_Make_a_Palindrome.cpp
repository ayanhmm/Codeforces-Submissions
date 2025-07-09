#pragma region HelperFunctions
#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define RESETCOL   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#define debug(x) cerr<<RED << #x << " = " << x << endl << RESETCOL
#define showtc(x) cerr<<endl <<YELLOW <<  #x << " " << x << ": "<< RESETCOL
#else
#define debug(x)
#define showtc(x)
#endif

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

#define pb push_back
#define allof(x) (x).begin(), (x).end()
#define loop(a,b) for(int i = a; i<b; i++)
#define haan cout << "YES" << endl
#define nahn cout << "NO" << endl
#define ppc  __builtin_popcountll
#define msb  63-__builtin_clzll

typedef long long lol;
typedef vector<lol> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;
typedef priority_queue<lol, v1d, greater<lol>> minh; 
typedef priority_queue<lol> maxh;

void print(v1d nums){
    for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
    cout<<"\n";
    return;
}
void print(v2d nums){
    for(int i=0; i<nums.size(); i++) print(nums[i]);
    return;
}

v1d getvec(int size){
    vector<lol> ans;
    while(size--){
        lol temp; cin>>temp; ans.push_back(temp);
    }
    return ans;
}
v2d getvec(int rows, int columns){
    v2d ans;
    for(int i = 0; i<rows; i++) ans.push_back(getvec(columns));
    return ans;
}

v1d sieve(lol n){
    vector<bool> arr(n+1, 1); 
    v1d primes; 
    for(lol i=2;i<=n;i++) if(arr[i]) {
                                        primes.emplace_back(i); 
                                        for(lol j=2*i;j<=n;j+=i) arr[j]=0;
                                    } 
    return primes;}


v1d lcs(v1d a,v1d b) {
    int m = a.size(), n = b.size();
    v2d dp(m + 1,v1d(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    v1d lcs;
    lol i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}
#pragma endregion

// ---------------------------------------------------------------------------------------------
void runtestcases(){
    int n,k; cin>>n>>k;
    v1d nums= getvec(n);

    map<int,int> mop;

    for(auto i : nums) mop[i]++;

    int tot = 0;
    unordered_set<int> sat;

    int largest = 0;

    for(auto i : mop){
        if(tot >= k) break;
        tot += i.second;
        sat.insert(i.first); 
        largest = i.first;
    }

    v1d simp;

    for(auto i : nums){
        if(sat.count(i)) simp.push_back(i);
    }

    // print(simp);

    int rem = simp.size() - k + 1;
    // cout<<rem<<endl;
    int l = 0;
    int r = simp.size() - 1;

    while( l <= r){
        if(simp[l] == simp[r]){l++; r--; continue;}
        rem--;
        if(rem < 0) {nahn;return;}
        if(simp[l] > simp[r]){if(simp[l] != largest) {nahn;return;}     l++;}
        else {if(simp[r] != largest) {nahn;return;}     r--;}
    }
    haan;
    

    







    return;
}
// ----------------------------------------------------------------------------------------------

#pragma region mainfunction
int main() {
    fastio();
    int testcases = 1; 
    cin>>testcases;
    int tc = 1;

    while(testcases--){
        showtc(tc); tc++; 
        runtestcases();
    }

    return 0;
}
#pragma endregion