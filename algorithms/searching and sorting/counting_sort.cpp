// COUNTING SORT ALGORITHM 
//Contribued by :  Pooja Singh

#include <bits/stdc++.h>
using namespace std;
 typedef long long int  ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define t_ime auto end = chrono::steady_clock::now(); auto diff = end - start;
#define t_time cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#define  clk auto start = chrono::steady_clock::now();
#define MOD     1000000007
#define mp      make_pair
#define pb        push_back
#define f           first
#define s          second
#define ln "\n"
#define min_heap    priority_queue<ll,vector<ll>,greater<ll>> //min top
#define max_heap     priority_queue<ll> //max top
#define vpair  vector<pair<ll,ll>> 
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1,  0, -1};

int main() 
{
    FAST;
    
	ll t;
	t=1;
	clk;
	ll count[1001]={0};
	
    ll n;
    cin>>n; //number of elements
    ll a[n];
    ll b[n];
    cout<<"Enter array elements between 1 to 1000"<<ln;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i]; //copy of array
        count[a[i]]++; //store frequency of elements
    }
    sort(b,b+n);  //sort copied array to get maximum elemnet of array 
    
    ll max=b[n-1]; //maximum among all the given elements
    
    ll output[n] ; //create temp array to store output
    
   // Store the cummulative count of each array
  for (ll i = 1; i <= max; i++) 
  {
    count[i] += count[i - 1];
  }

 
  for (ll i =n- 1;i >= 0;i--)
  {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
 
 cout<<"ARRYA AFTER SORTING"<<ln;
 
 for(ll i=0;i<n;i++)
 {
     cout<<output[i]<<" ";
 }
 
	//t_ime;t_time;
	
	return 0;
}
