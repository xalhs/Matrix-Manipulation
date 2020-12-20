#include<iostream>
#include<cmath>
using namespace std;
int egercheck(double a);
double gcd(double a,double b);
double lcm(double a, double b);
int main (){
	
int n,i,j,row,col,k,l,m,tri,trj,trindic,trk,printi,printj,rep,det,rank,gconst;
double multconst,v1,v2;
int normalpatam=1;
cout<<"give number of rows"<<endl;
 cin>>n;
double A[n][n];
double I[n][n];
int O[n][n];
// std::fill(O[1], O[1] + n * n, 0);
trindic =0;
int indic=0 ;
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(i==j)
			I[i][j]=1;
		else
			I[i][j]=0;
	}
}
/*A[1][1]=6;
A[1][2]=7;
A[1][3]=3;
A[1][4]=45;
A[2][1]=9;
A[2][2]=10;
A[2][3]=13;
A[2][4]=4;
A[3][1]=0;
A[3][2]=88;
A[3][3]=4;
A[3][4]=15;
A[4][1]=9;
A[4][2]=91;
A[4][3]=43;
A[4][4]=3;
*/
for(i=1; i<=n;i++){
	for(j=1; j<=n;j++){
		cout<<"give the element A["<<i<<"]"<<"["<<j<<"] of the matrix"<<endl;
		cin>>A[i][j];
		if (A[i][j]!=0)
			indic=1;
	}
}
if(indic==0){
	cout<<"you think this is a motherfucking game you just gave me a NULL matrix try again next time: OUTPLAYED  OUTSMARTED  OUTSKILLED";
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
		for (trj=j;trj<=n;trj++){
			for (tri=j;tri<=n;tri++){
				if (A[tri][trj]!=0){
					row=tri;
					col=trj;
					trindic=1;		
					if (col==j){
						for (trk=1;trk<=n;trk++){
							A[j][trk]+=A[row][trk];
							I[j][trk]+=I[row][trk];
						}
					}
					else if (row==j){
						for (trk=1;trk<=n;trk++){
							A[trk][j]+=A[trk][col];
							I[trk][j]+=I[trk][col];		
						}
					}
					else if(row!=j && col!=j)	{
						for (trk=1;trk<=n;trk++){
							A[j][trk]+=A[row][trk];
							I[j][trk]+=I[row][trk];
						}			
						for (trk=1;trk<=n;trk++){
							A[trk][j]+=A[trk][col];
							I[trk][j]+=I[trk][col]; 
						}
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
/*
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<I[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
} */
	for(i=n; i>=j+1;i--){
		if (A[i][j]!=0){
			if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1) 
				multconst = lcm(abs(A[j][j]),abs(A[i][j]));
			else
			 	multconst =(A[j][j]+0.0)*A[i][j];
			v1=A[i][j];
			v2=A[j][j];
			for (k=1; k<=n; k++){
				A[i][k]*=multconst/v1;
				I[i][k]*=multconst/v1;
				A[i][k]-=A[j][k]*multconst/v2;
				I[i][k]-=I[j][k]*multconst/v2;
			}
		}
		/*		for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
cout<<endl;
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<I[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
} */
	}


}
for (printi=1;printi<=n;printi++){
	for(printj=1;printj<=n;printj++){
		cout<<A[printi][printj]<<"\t";
	}
	cout<<endl;
	cout<<endl;
}

rank=0;
rep=n;
while(rep>=1 && rank==0){
	if(A[rep][rep]!=0)
		rank=rep;		
	rep--;
}

if (rank==n){
	for (i=n-1;i>=1;i--){
			cout<<"kollhse"<<endl;
		for(j=n;j>=i+1;j--){
			if(A[i][j]!=0){
					cout<<"kollhse2.1"<<endl;
				if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1) 
							multconst =lcm(abs(A[j][j]),abs(A[i][j]));
				else
				 	multconst =(A[j][j]+0.0)*A[i][j];
				
					v1=A[i][j];
					v2=A[j][j];
					for (k=1; k<=n; k++){
						A[i][k]*=multconst/v1;
						I[i][k]*=multconst/v1;
						A[i][k]-=A[j][k]*multconst/v2;
						I[i][k]-=I[j][k]*multconst/v2;
						
				
					}
			}
		}
		
	/*	
		for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
}
cout<<endl;
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<I[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
}
		*/
	}
	
	
}
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
}

if (rank==n){
	
	for(i=1;i<=n;i++){
	
		multconst=A[i][i];
		A[i][i]/=(0.0+multconst);
		for(k=1;k<=n;k++){
			if (egercheck(I[i][k])==1 && egercheck(multconst)==1) {
				gconst=gcd(abs(I[i][k]),abs(multconst));
				I[i][k]/=gconst;
				O[i][k]=multconst/gconst;
			}
			else
				I[i][k]/=(0.0+multconst);	
		}
	}
}
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(A[i][j]==0)
		A[i][j]=0;
		if (I[i][j]==0)
		I[i][j]=0;
	
	}
}
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
}

if(rank==n){
	cout<<"the inverse matrix is"<<endl;
	for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			if(O[printi][printj]==0 or O[printi][printj]==1){
				cout<<I[printi][printj]<<"\t ";
			}
			else{
				if((I[printi][printj]*O[printi][printj])>0){
					cout<<abs(I[printi][printj])<<"/"<<abs(O[printi][printj])<<"\t ";
				}
				else
					cout<<"-"<<abs(I[printi][printj])<<"/"<<abs(O[printi][printj])<<"\t ";
				}
		}
	cout<<endl;
	cout<<endl;
	}
}
return 0;

}
	int egercheck(double a){
	
		if (a-floor(a)==0)
		 return 1;
		 else 
		 return 0;}
	double gcd(double a,double b){
		while (a!=b){
			if (a<b)
				b-=a;
			else if (a>b)
				a-=b;	
}
			return a;}
	double lcm(double a, double b){
		double least;
		least = a*b/gcd(a,b);
		return least;
	}

	
	
	
