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
#define haan cout << "Yes" << endl
#define nahn cout << "No" << endl
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

#pragma endregion

// ---------------------------------------------------------------------------------------------
void runtestcases(){
    lol lr,hr; cin>>lr>>hr;
    lol ls,hs; cin>>ls>>hs;

    lol x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;

    // if(x1>x2){swap(x1,x2) ; swap(y1,y2);}

    int x11 = x1 + ls;
    int y11 = y1 + hs;
    // cout<<x11<<" "<<y11<<" ";


    if(x11 > x2){
        if((y2 - y11)  % hs == 0) haan;
        else nahn;
        return;
    }


    if(y1>y2){swap(x1,x2) ; swap(y1,y2);}
    x11 = x1 + ls;
    y11 = y1 + hs;

    if(y2 < y11){
        if((x2 - x11 )% ls == 0) haan;
        else nahn;
        return;
    }
    if(abs(y2 - y11)  % hs == 0 || abs(x2 - x11 )% ls == 0) haan;

    else nahn;

    





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