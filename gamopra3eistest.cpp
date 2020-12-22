#include<iostream>
#include<cmath>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
int egercheck(int1024_t a);
cpp_int floorian(int1024_t a);
int1024_t gcd(int1024_t a,int1024_t b);
int1024_t lcm(int1024_t a, int1024_t b);
int1024_t finalsolution(int1024_t a);
int main (){
	
int n,i,j,row,col,k,l,m,tri,trj,trindic,trk,printi,printj,rep,det,rank;
int1024_t multconst,v1,v2,gconst;
cout<<"give number of rows"<<endl;
//cin>>n;
n=4;
int1024_t A[n+1][n+1];
int1024_t I[n+1][n+1];
int1024_t O[n+1][n+1];
 for (i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		O[i][j]=0;
	}
} 
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
cout<<"oorismostoukollhse5"<<endl;
A[1][1]=6;
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

/*for(i=1; i<=n;i++){
	for(j=1; j<=n;j++){
		cout<<"give the element A["<<i<<"]"<<"["<<j<<"] of the matrix"<<endl;
		cin>>A[i][j];
		if (A[i][j]!=0)
			indic=1;
	}
}
if(indic==0){
	cout<<"you gave me a null matrix, next time run the program and give a nonzero input";
	return 0; }
	*/
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
				multconst = lcm(finalsolution(A[j][j]),finalsolution(A[i][j]));
			else
			 	multconst =(A[j][j])*A[i][j]; //0.0
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
		for(j=n;j>=i+1;j--){
			if(A[i][j]!=0){
				if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1) {
							multconst =lcm(finalsolution(A[j][j]),finalsolution(A[i][j]));
						}
				else
				 	multconst =(A[j][j])*A[i][j];  //+0.0
				
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
		A[i][i]/=(multconst);    // +0.0
		for(k=1;k<=n;k++){
			if (egercheck(I[i][k])==1 && egercheck(multconst)==1) {
				gconst=gcd(finalsolution(I[i][k]),finalsolution(multconst));
				I[i][k]/=gconst;
				O[i][k]=multconst/gconst;
		}
			else{
				I[i][k]/=(multconst);
				}	//+0.0
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
				cout<<I[printi][printj]<<"  \t ";
			}
			else{
				if((I[printi][printj]*O[printi][printj])>0){
					cout<<finalsolution(I[printi][printj])<<"/"<<finalsolution(O[printi][printj])<<"\t ";
				}
				else
					cout<<"-"<<finalsolution(I[printi][printj])<<"/"<<finalsolution(O[printi][printj])<<"\t ";
				}
		}
	cout<<endl;
	cout<<endl;
	}
}
return 0;

}
	int egercheck(int1024_t a){
	
		if (a==floorian(a))
		 return 1;
		 else 
		 return 0;}
	int1024_t gcd(int1024_t a,int1024_t b){
		while (a!=b){
			if (a<b){
				b-=a*floorian(b/a);
				if (b==0)
					return a;
			}
				
			else if (a>b){
				a-=b*floorian(a/b);	
				if (a==0)
					return b;
			}
			//	cout<<a<<endl;
		}
		return a;}
	int1024_t lcm(int1024_t a, int1024_t b){
		int1024_t least;
		least = a*b/gcd(a,b);
		return least;
	}
	int1024_t finalsolution(int1024_t a){
		if (a<0)
			return -a;
		else
			return a;
	}
	cpp_int floorian(int1024_t a){
		cpp_int i,b;
		if (a==0)
			return 0;
		else if (a>0){
			 i=1;
			 b=0;
			 while(b+i<a){
 				i*=2;
 				if(b+i>a){
					 b+=i/2;
					 i=1;
			 	}
	 
		 	}
 			return i+b;
		}
		else {
		 	i=-1;
 			b=0;
 			while(b+i>a-1){
 				i*=2;
 				if(b+i<a-1){
					 b+=i/2;
					 i=-1;
		 		}
	 
			 }
			if(a-(i+b)==1)
 				return i+b+1;
 			else
 				return i+b;
 			
		}
	}

	
	
	
	
