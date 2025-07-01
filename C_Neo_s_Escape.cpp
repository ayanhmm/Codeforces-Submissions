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

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define pb push_back
#define allof(x) (x).begin(), (x).end()
#define loop(a,b) for(int i = a; i<b; i++)
#define haan cout << "YES" << endl
#define nahn cout << "NO" << endl


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
        lol temp; cin>>temp; 
        if(ans.size() > 0 && temp == ans[ans.size() -1]) continue;
        ans.push_back(temp);
    }
    return ans;
}
v2d getvec(int rows, int columns){
    v2d ans;
    for(int i = 0; i<rows; i++) ans.push_back(getvec(columns));
    return ans;
}

#pragma endregion

// ---------------------------------------------------------------------------------------------
void runtestcases(){
    int n;
    cin>>n;
    v1d nums = getvec(n);
    n = nums.size();

    if(n == 1 || n == 2){
        cout<<1<<endl; return;
    }

    lol ans =0;

    loop(0, n){
        if(i == 0){
            if(nums[i] > nums[i+1]){
                ans++; continue;
            }
        }
        else if(i == n-1){
            if(nums[i] > nums[i-1]){
                ans++; continue;
            }
        }
        else{
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) ans++;
        }
    }

    cout<<ans<<endl;


    return;
}
// ----------------------------------------------------------------------------------------------

#pragma region mainfunction
int main() {
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