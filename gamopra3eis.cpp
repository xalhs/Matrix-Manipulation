#include<iostream>
#include<cmath>
using namespace std;
int egercheck(double a);
int gcd(int a,int b);
int lcm(int a, int b);
int main (){
	
	int n,i,j,row,col,k,l,m,tri,trj,trindic,trk,printi,printj;
	float multconst,v1,v2;
	
	cout<<"give number of rows"<<endl;
	cin>>n;
	
	float A[n][n];
	trindic =0;
	int indic=0 ;
	for(i=1; i<=n;i++){
		for(j=1; j<=n;j++){
			cout<<"give the element A["<<i<<"]"<<"["<<j<<"] of the matrix"<<endl;
			cin>>A[i][j];
			if (A[i][j]!=0)
			indic=1;
			}
		}
		if(indic==0){
		cout<<"you think this is a motherfucking game nigga you just gave me a NULL matrix try again next time: OUTPLAYED   OUTSMARTED   OUTSKILLED";
		return 0; }
		for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
cout<<endl;
		
	
	for(j=1; j<=n-1;j++){
		if (A[j][j]==0){
			cout<<"my nigga"<<endl;
		    for (trj=j;trj<=n;trj++){
				for (tri=j;tri<=n;tri++){
						if (A[tri][trj]!=0){
							row=tri;
							col=trj;
							trindic=1;
								cout<<"my nigga"<<endl;
							if (col==j){
							for (trk=1;trk<=n;trk++){
								A[j][trk]+=A[row][trk];
								}
							}
							else if (row==j){
								for (trk=1;trk<=n;trk++){
								A[trk][j]+=A[trk][col];
								}
							}
							else if(row!=j && col!=j)	{
								for (trk=1;trk<=n;trk++){
								A[j][trk]+=A[row][trk];}
								
								for (trk=1;trk<=n;trk++){
								A[trk][j]+=A[trk][col]; }
								
							}
							
							
						}
						if (trindic==1)
						break;
					}	
						if (trindic==1)
						break;
			}
		}
		for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
cout<<endl;
		for(i=n; i>=j+1;i--){
			if (A[i][j]!=0){
				if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1) 
					multconst = lcm(A[j][j],A[i][j]);
				else
				 	multconst =(A[j][j]+0.0)*A[i][j];
				v1=A[i][j];
				v2=A[j][j];
				for (k=1; k<=n; k++){
					A[i][k]*=multconst/v1;
					A[j][k]*=multconst/v2;
					A[i][k]-=A[j][k];
					
				}
				
			}
				for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
cout<<endl;
}

}

for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
return 0;
}
	int egercheck(double a){
	
		if (a-floor(a)==0 && a>=0)
		 return 1;
		 else 
		 return 0;}
	int gcd(int a,int b){
		while (a!=b){
			if (a<b)
				b-=a;
			else if (a>b)
				a-=b;	
}
			return a;}
	int lcm(int a, int b){
		int least;
		least = a*b/gcd(a,b);
		return least;
	}

	
	
	
	
	
	
