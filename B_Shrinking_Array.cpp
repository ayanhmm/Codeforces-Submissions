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
        lol temp; cin>>temp; ans.push_back(temp);
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

    if(n <= 1){
        cout << -1 << endl;
        return;
    }

    if(n==2){
        if(nums[0] == nums[1] || nums[0] == nums[1]+1 || nums[0]+1 == nums[1]){
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    for(int i = 0; i < n-1; i++) {
        if(nums[i] == nums[i+1] || nums[i] == nums[i+1]+1 || nums[i]+1 == nums[i+1]) {
            cout << 0 << endl;
            return;
        }
    }

    bool inc = 0;
    bool dec = 0;

    for(int i = 0; i<n-1; i++){
        if(nums[i] > nums[i+1]) inc = 1;
        if(nums[i] < nums[i+1]) dec = 1;
    }

    if(inc && dec){
        cout << 1 << endl;
        return;
    }
    cout<<-1<<endl;


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