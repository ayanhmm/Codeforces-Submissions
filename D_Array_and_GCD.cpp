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
v1d getPrimes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    std::vector<lol> primes;
 
    if (n < 2) return primes; // No primes less than 2
 
    is_prime[0] = is_prime[1] = false;
 
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
 
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
 
    return primes;
}
v1d yo = getPrimes(8e6);
// ---------------------------------------------------------------------------------------------
void runtestcases(){
    int n;
    cin>>n;

    v1d nums = getvec(n);

    lol sum = 0;
    for(int i : nums) sum += i;

    
    

    sort(allof(nums));

    int ans = 0;
    while(true){
        if(sum >= yo[n - 1 - ans] || ans == n){
            cout<<ans<<endl;
            return;
        }
        debug(sum);
        debug(yo[n - 1 - ans]);

        sum -= nums[ans];
        ans++;
    }

    


    return;
}
// ----------------------------------------------------------------------------------------------

#pragma region mainfunction
int main() {
    int testcases = 1; 
    cin>>testcases;
    int tc = 1;
    loop(1,yo.size()) yo[i] += yo[i-1];

    while(testcases--){
        showtc(tc); tc++; 
        runtestcases();
    }

    return 0;
}
#pragma endregion