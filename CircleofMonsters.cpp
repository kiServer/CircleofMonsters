#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int qpr;
int qpg;
/*Num Monster*/
 
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll r[n][2];
		/*total*/
		for(int i=0;i<n;i++){
			cin>>r[i][0] >> r[i][1];
		}		
		if(n==1){
			cout<<r[0][0]<<endl;
		}
		/*cmv*/
		ll ans,q=0,p=0;
		for(int i=0;i<n;i++){
			if(r[i][0]>p){
				q=q+(r[i][0]-p);
			}	
			p=r[i][1];
		}
		ans=q;
		p=q; 
		for(int i=1;i<n;i++){
			q=p-r[i-1][0];
			if(r[i][0] > r[i-1][1]){
				q=q+r[i-1][1];
			}	
			else{
				q+=r[i][0];
			}		
			if(r[(i+n-1)%n][0] > r[(i+n-2)%n][1]){
				//qpr=q+r[(i+n-1)%n][0];
				//qpg=r[(i+n-2)%n][1];
				//q=qpr-qpg 
				/*min fire*/ 
				q+=r[(i+n-1)%n][0] - r[(i+n-2)%n][1];
			}
			/*unify*/		
			ans=min(ans,q);
			p=q;
		}
		cout<<ans<<endl;
	}
		return 0;
}
