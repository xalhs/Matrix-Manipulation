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
//cout<<"give number of rows"<<endl;
// cin>>n;
n=3;
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
/*cpp_rational jrerer;
jrerer=1;
jrerer*=4;
jrerer/=3;
A[1][1]=1;
A[1][2]=9;
A[1][3]=1;
A[2][1]=1;
A[2][2]=1;
A[2][3]=11;
A[3][1]=1;
A[3][2]=1;
A[3][3]=1; */

/*A[4][1]=1;
A[4][2]=1;
A[4][3]=1;
A[4][4]=1;
A[1][4]=1;
A[2][4]=1;
A[3][4]=13; */
/* A[1][1]=1;
A[1][2]=1;
A[1][3]=2;
A[1][4]=3;
A[2][1]=2;
A[2][2]=2;
A[2][3]=4;
A[2][4]=5;
A[3][1]=0;
A[3][2]=2;
A[3][3]=0;
A[3][4]=0;
A[4][1]=0;
A[4][2]=0;
A[4][3]=4;
A[4][4]=1; 
*/
for(i=1; i<=n;i++){
	for(j=1; j<=n;j++){
		cout<<"give the element A["<<i<<"]"<<"["<<j<<"] of the matrix"<<endl;
		cin>>A[i][j];
		if (A[i][j]!=0)
			indic=1;
	}
}
indic=1;
if(indic==0){
	cout<<"you gave me a null matrix, next time run the program and give a nonzero input";
	return 0; }
	
for (printi=1;printi<=n;printi++){
	for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
	}
	cout<<endl;
	cout<<endl;
}
cout<<"========================================================"<<endl;
cout<<endl;	
for(j=1; j<=n-1;j++){
	if (A[j][j]==0){
		trindic=0;
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
						cout<<"add row "<<row<<" to row "<<j<<endl;
					}
					else if (row==j){
						for (trk=1;trk<=n;trk++){
							A[trk][j]+=A[trk][col];
							I[trk][j]+=I[trk][col];		
						}
						cout<<"add column "<<col<<" to column "<<j<<endl;
					}
					else if(row!=j && col!=j)	{
						for (trk=1;trk<=n;trk++){
							A[j][trk]+=A[row][trk];
							I[j][trk]+=I[row][trk];
						}
						cout<<"add row "<<row<<" to row "<<j<<endl;			
						for (trk=1;trk<=n;trk++){
							A[trk][j]+=A[trk][col];
							I[trk][j]+=I[trk][col]; 
						}
						cout<<"add column "<<col<<" to column "<<j<<endl;
					}		
				}
				for (printi=1;printi<=n;printi++){
					for(printj=1;printj<=n;printj++){
						cout<<A[printi][printj]<<"\t";
					}
						cout<<endl;
						cout<<endl;
				}
				cout<<"========================================================"<<endl;
				if (trindic==1)
					break;
			}	
			if (trindic==1)
				break;
		}
	}
/*	for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
		cout<<A[printi][printj]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"========================================================"<<endl;
	*/
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
	//		cout<<"subtract "<<multconst/v2<<" times row "<<j<<" from row "<<i<<" multiplied by "<<multconst/v1<<endl;
			cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			for (printi=1;printi<=n;printi++){
				for(printj=1;printj<=n;printj++){
					cout<<A[printi][printj]<<"\t";
				}
				cout<<endl;
				cout<<endl;
			}
		cout<<"========================================================"<<endl;
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
cout<<"========================================================"<<endl;
rank=0;
rep=n;
while(rep>=1 && rank==0){
	if(A[rep][rep]!=0)
		rank=rep;		
	rep--;
}
if(rank<n){
	cout<<"The rank of the matrix is "<<rank<<" and thus it cannot be inversed"<<endl;
}
if (rank==n){

	for (i=n-1;i>=1;i--){
//			cout<<"kollhse"<<endl;
		for(j=n;j>=i+1;j--){
//			cout<<"kollhse2"<<endl;
			if(A[i][j]!=0){
				if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1) 
							multconst =lcm(finalsolution(A[j][j]),finalsolution(A[i][j]));
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
				cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
					for (printi=1;printi<=n;printi++){
				for(printj=1;printj<=n;printj++){
					cout<<A[printi][printj]<<"\t";
				}
				cout<<endl;
				cout<<endl;
			}
		cout<<"========================================================"<<endl;
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
//cout<<"kollhse3"<<endl;
for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			cout<<A[printi][printj]<<"\t";
}
	cout<<endl;
	cout<<endl;
}
cout<<"========================================================"<<endl;
if (rank==n){
	for(i=1;i<=n;i++){
//			cout<<"kollhse4"<<endl;
		multconst=A[i][i];
		A[i][i]/=(multconst);    // +0.0
		cout<<"divide row "<<i<<" by "<<multconst<<endl;
		for(k=1;k<=n;k++){
		//	cout<<"kollhse5"<<endl;
			if (egercheck(I[i][k])==1 && egercheck(multconst)==1) {
				gconst=gcd(finalsolution(I[i][k]),finalsolution(multconst));
				I[i][k]/=gconst;
				O[i][k]=multconst/gconst;
			//		cout<<"kollhse7"<<endl;
			}
			else
				I[i][k]/=(multconst);	//+0.0
		}
	}
}
// cout<<"kollhse5"<<endl;
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
// cout<<"kollhse6"<<endl;
if(rank==n){
	cout<<"the inverse matrix is"<<endl;
	for (printi=1;printi<=n;printi++){
		for(printj=1;printj<=n;printj++){
			if(I[printi][printj]==0 or O[printi][printj]==1){
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
system("pause");
return 0;

}
	int egercheck(int1024_t a){
	
		if (a==floorian(a))
		 return 1;
		 else 
		 return 0;}
	int1024_t gcd(int1024_t a,int1024_t b){
		if(a*b==0)
			return 1;
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

	
	
	
	
