#include<iostream>
#include<cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
//#include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
using namespace std;

cpp_dec_float_100 abs_doub(cpp_dec_float_100 a);
cpp_dec_float_100 floorian_doub(cpp_dec_float_100 a);
cpp_dec_float_100 gcd_doub(cpp_dec_float_100 a, cpp_dec_float_100 b);
cpp_dec_float_100 lcm_doub(cpp_dec_float_100 a, cpp_dec_float_100 b);
int egercheck(cpp_dec_float_100 a);

cpp_rational abs_rat(cpp_rational a);
cpp_rational floorian_rat(cpp_rational a);
cpp_rational gcd_rat(cpp_rational a,cpp_rational b);
cpp_rational lcm_rat(cpp_rational a, cpp_rational b);
int egercheck_rat(cpp_rational a);

int1024_t floorian(int1024_t a);

using boost::multiprecision::cpp_dec_float_100;  //? need to see its use

int main (){
std::cout << std::setprecision(std::numeric_limits<cpp_dec_float_100>::digits10);    //? increases float digits

int n,i,j,row,col,k,l,m,tri,trj,trindic,trk,printi,printj,rep,rank,indic;   // l unused, det to be used in the future
string n_str;

cout<<"give number of rows"<<endl;
cin>>n_str;
try
{
    if (std::stod(n_str) != floor(std::stod(n_str)) && std::stod(n_str) > 0)
    {
        cout<<"please give a positive integer value for the number of rows next time"<<endl;
        return 1;
    }
}
catch(...)
{
    cout<<"please give a positive integer value for the number of rows next time"<<endl;
    return 1;
}
n = std::stoi(n_str);


int double_indic = 0;
int rational_indic = 0;

indic = 0;

cout<<"you will be asked to give the elements of a matrix, accepted inputs are: integers (e.g. 5) Decimal numbers (e.g 2.1542332) or fractions (e.g 3/8)"<<endl
cout<<"avoid adding decimals along with fractions because if that happens fractions will be converted to decimals"<<endl<<endl;
string A_str[n+1][n+1];
for(i=1; i<=n;i++){
	for(j=1; j<=n;j++){
		cout<<"give the element A["<<i<<"]"<<"["<<j<<"] of the matrix"<<endl;
		cin>>A_str[i][j];
		try
        {   cpp_dec_float_100 flo(A_str[i][j]);
            if (egercheck(flo) == 1)
            {
               int1024_t floint(A_str[i][j]);
                cout<<"int is "<<flo<<endl;
                if (flo != 0)
                {
                    indic=1;
                }

            }
            else
            {
                cout<<"doub is "<<flo<<endl;
                if (flo != 0)
                {
                    indic=1;
                }
                double_indic = 1;
            }
        }
        catch(...)
        {
            try{

                cpp_rational tmp(A_str[i][j]);
                cout<<"rational is "<<tmp<<endl;
                if (tmp != 0)
                {
                    indic=1;
                }
                rational_indic = 1;
            }
            catch(...)
            {
                cout<<"you did not give a valid input, accepted inputs are: integers (e.g. 5) Decimal numbers (e.g 2.1542332) or fractions (e.g 3/8)"<<endl;
                return 1;
            }
        }

	}
}

if (indic == 0){
    cout<<"this is a NULL matrix, has rank and determinant 0 and cannot be inversed please do at least one non-zero input next time"<<endl;
    return 1;
}
if (double_indic == 1 && rational_indic == 1)
{
    cout<<"You've added both a fraction and a decimal, to do the computation, the fraction will be converted to the nearest decimal"<<endl;
} 
cout<<"hi"<<endl;
if (double_indic == 1){
    cpp_dec_float_100 det = 1;
    cpp_dec_float_100 epsilon_thetiko = 1E-99;

    cpp_dec_float_100 multconst,v1,v2,gconst;
    cpp_dec_float_100 A[n+1][n+1];
    cpp_dec_float_100 I[n+1][n+1];
    for(i=1; i<=n;i++){
    	for(j=1; j<=n;j++){
    	    if(i==j)
    	        I[i][j]=1;
    	    else
    	        I[i][j]=0;

		    try
            {
                cpp_dec_float_100 tmp(A_str[i][j]);
                A[i][j] = tmp;

            }
            catch(...)
            {
                try{

                    cpp_rational tmp(A_str[i][j]);
                    cpp_dec_float_100 df;
                    A[i][j]   = static_cast<cpp_dec_float_100>(tmp);
                }
                catch(...)
                {
                    cout<<"Something went wrong"<<endl;
                    return 1;
                }
            }
	    }
    }
    for (printi=1;printi<=n;printi++)
    {
	    for(printj=1;printj<=n;printj++)
	    {
			cout<<A[printi][printj]<<"\t";
	    }
	    cout<<endl;
	    cout<<endl;
    }
    cout<<"========================================================"<<endl;
    for(j=1; j<=n-1;j++)
    {
	    if (A[j][j]==0)
        {
            trindic=0;
            for (trj=j;trj<=n;trj++)
            {
                for (tri=j;tri<=n;tri++)
                {
                    if (A[tri][trj]!=0)
                    {
                        row=tri;
                        col=trj;
                        trindic=1;
				    	if (col==j)
                        {
	                        for (trk=1;trk<=n;trk++)
                            {
		                        A[j][trk]+=A[row][trk];
						      	if (abs_doub(A[j][trk]) < epsilon_thetiko)//=================================================================
						      	{
						      	    A[j][trk] = 0;

						      	}
							    I[j][trk]+=I[row][trk];
							    if (abs_doub(I[j][trk]) < epsilon_thetiko)
							    {
							        I[j][trk] = 0;
							    }
                            }
                            cout<<"add row "<<row<<" to row "<<j<<endl;
                        }
					    else if (row==j)
                        {
			                for (trk=1;trk<=n;trk++)
                            {
						        A[trk][j]+=A[trk][col];
						        if (abs_doub(A[trk][j]) < epsilon_thetiko)
    						    {
    						        A[trk][j] = 0;
    						    }
    							I[trk][j]+=I[trk][col];
    							if (abs_doub(I[trk][j]) < epsilon_thetiko)
    							{
    							    I[trk][j] = 0;
    							}
						    }
						    cout<<"add column "<<col<<" to column "<<j<<endl;
					    }
					    else if(row!=j && col!=j)
                        {
						    for (trk=1;trk<=n;trk++)
                            {
							    A[j][trk]+=A[row][trk];
							    if (abs_doub(A[j][trk]) < epsilon_thetiko)
                                {
			                        A[j][trk] = 0;

				                }
							    I[j][trk]+=I[row][trk];
							    if (abs_doub(I[j][trk]) < epsilon_thetiko)
					            {
				                    I[j][trk] = 0;
					            }
						    }
						    cout<<"add row "<<row<<" to row "<<j<<endl;
						    for (trk=1;trk<=n;trk++)
                            {
							    A[trk][j]+=A[trk][col];
							    if (abs_doub(A[trk][j]) < epsilon_thetiko)
						        {
					                A[trk][j] = 0;
						        }
							    I[trk][j]+=I[trk][col];
							    if (abs_doub(I[trk][j]) < epsilon_thetiko)
							    {
							        I[trk][j] = 0;
							    }

						    }
						    cout<<"add column "<<col<<" to column "<<j<<endl;
			            }
				    }

				    if (trindic==1)
					   break;
			     }
			     if (trindic==1)
				    break;
            }
           // cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
            for (printi=1;printi<=n;printi++)
            {
                for(printj=1;printj<=n;printj++)
                {
                    cout<<A[printi][printj]<<"\t";
                }
                cout<<endl;
            }
            cout<<"========================================================"<<endl;
            cout<<endl;
	    }

        for(i=n; i>=j+1;i--)
        {
            if (A[i][j]!=0)
            {  // cout<<abs_doub(A[j][j])<<endl;
                if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1)
				    multconst = lcm_doub(abs_doub(A[j][j]),abs_doub(A[i][j]));
			    else
			    	multconst =(A[j][j])*A[i][j];
			    v1=A[i][j];
			    v2=A[j][j];
			    for (k=1; k<=n; k++)
                {
				    A[i][k]*=multconst/v1;
			    	I[i][k]*=multconst/v1;
				    A[i][k]-=A[j][k]*multconst/v2;
			    	I[i][k]-=I[j][k]*multconst/v2;
			    	if (abs_doub(A[i][k]) < epsilon_thetiko)
			    	{
			    	    //cout<<"smol number "<<A[i][k]<<endl;
			    	    //cout<<epsilon_thetiko<<endl;
			    	    A[i][k] = 0;
			    	}

			    }
			    if (multconst/v2 > 0)
			    {
			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			    }
			    else
			    {
			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs_doub(multconst/v2)<<" times row "<<j<<endl<<endl;
			    }
			    det *= v1/multconst;
		    }

	   }

    }

    for (printi=1;printi<=n;printi++)
    {
	   for(printj=1;printj<=n;printj++)
       {
            cout<<A[printi][printj]<<"/ \t";
	   }
        cout<<endl;
        cout<<endl;
    }
    cout<<"========================================================"<<endl;

    rank=0;
    rep=n;
    while(rep>=1 && rank==0)
    {
        if(A[rep][rep]!=0)
		rank=rep;
        rep--;
    }
    if (rank < n)
    {
        cout<<"The rank of the matrix is "<<rank<<" which is less than its number of rows and thus cannot be inversed"<<endl;
    }
    if (rank==n)
    {
        for (i=n-1;i>=1;i--)
        {
            for(j=n;j>=i+1;j--)
            {
                if(A[i][j]!=0)
                {
                    if(egercheck(A[j][j])==1 && egercheck(A[i][j])==1)
                        multconst =lcm_doub(abs_doub(A[j][j]),abs_doub(A[i][j]));
				    else
                        multconst =(A[j][j])*A[i][j];
					v1=A[i][j];
					v2=A[j][j];
					for (k=1; k<=n; k++)
                    {
						A[i][k]*=multconst/v1;
						I[i][k]*=multconst/v1;
						A[i][k]-=A[j][k]*multconst/v2;
						I[i][k]-=I[j][k]*multconst/v2;
						if (abs_doub(A[i][k]) < epsilon_thetiko)
			    	    {
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	        A[i][k] = 0;
			    	    }
			    	    if (abs_doub(I[i][k]) < epsilon_thetiko)
			    	    {
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	        I[i][k] = 0;
			    	    }
					}
				    if (multconst/v2 > 0)
		            {

		                cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
		            }
		            else
		            {
		                cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs_doub(multconst/v2)<<" times row "<<j<<endl<<endl;
		            }
		            det *= v1/multconst;
                    for (printi=1;printi<=n;printi++)
                    {
                        for(printj=1;printj<=n;printj++)
                        {
                            cout<<A[printi][printj]<<"\t";
                        }
                        cout<<endl;
                        cout<<endl;
                    }
                    cout<<"========================================================"<<endl;
                }
            }
        }
    }

    if (rank==n)
    {

        for(i=1;i<=n;i++)
        {

            multconst=A[i][i];
            A[i][i]/=(multconst);
            cout<<"divide row "<<i<<" by "<<multconst<<endl;
            det *= multconst;
            for(k=1;k<=n;k++)
            {
                if (egercheck(I[i][k])==1 && egercheck(multconst)==1)
                {
                    gconst=gcd_doub(abs_doub(I[i][k]),abs_doub(multconst));
				    I[i][k]/=gconst;
			//	    O[i][k]=multconst/gconst;
                }
                else
                    I[i][k]/=(multconst);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(A[i][j]==0)
                A[i][j]=0;
            if (I[i][j]==0)
                I[i][j]=0;

        }
    }
    cout<<"ROW ECHELON FORM"<<endl;
    for (printi=1;printi<=n;printi++)
    {
        for(printj=1;printj<=n;printj++)
        {
            cout<<A[printi][printj]<<"\t";
        }
        cout<<endl;
        cout<<endl;

    }
    cout<<"========================================================"<<endl;

    if(rank==n)
    {
        cout<<"the determinant is "<<det<<" and"<<endl;
        cout<<"the inverse matrix is"<<endl;
        for (printi=1;printi<=n;printi++)
        {
            for(printj=1;printj<=n;printj++)
            {
                    cout<<I[printi][printj]<<"  \t ";

            }
            cout<<endl;
            cout<<endl;
        }
    }
    system("pause");
    return 0;


}
else if(rational_indic == 1)
{
    cpp_rational det = 1;
    cpp_rational epsilon_thetiko = 1;
    for (m=1; m<=11; m++)
    {
        epsilon_thetiko/= 1000000000;
    }
    cpp_rational multconst,v1,v2,gconst;
    cpp_rational A[n+1][n+1];
    cpp_rational I[n+1][n+1];
    for(i=1; i<=n;i++)
    {
    	for(j=1; j<=n;j++)
    	{
    	    if(i==j)
    	        I[i][j]=1;
    	    else
    	        I[i][j]=0;

		    try
            {
                cpp_rational tmp(A_str[i][j]);
                A[i][j]   = tmp;
            }
            catch(...)
            {
                cout<<"Something went wrong"<<endl;
            }

        }
	}
	for (printi=1;printi<=n;printi++){
	    for(printj=1;printj<=n;printj++){
            cout<<A[printi][printj]<<"\t";
        }
	    cout<<endl;
    }
    cout<<"========================================================"<<endl;
    cout<<endl;

    for(j=1; j<=n-1;j++)
    {
	    if (A[j][j]==0)
	    {
		    trindic=0;
		    for (trj=j;trj<=n;trj++)
            {
			    for (tri=j;tri<=n;tri++)
                {
				    if (A[tri][trj]!=0)
				    {
				    	row=tri;
				    	col=trj;
				    	trindic=1;
					    if (col==j)
                        {
	                        for (trk=1;trk<=n;trk++)
                            {
		                        A[j][trk]+=A[row][trk];
						      	if (abs_rat(A[j][trk]) < epsilon_thetiko)//=================================================================
						      	{
						      	    A[j][trk] = 0;

						      	}
							    I[j][trk]+=I[row][trk];
							    if (abs_rat(I[j][trk]) < epsilon_thetiko)
							    {
							        I[j][trk] = 0;
							    }
                            }
                            cout<<"add row "<<row<<" to row "<<j<<endl;
                        }
					    else if (row==j)
                        {
			                for (trk=1;trk<=n;trk++)
                            {
    						    A[trk][j]+=A[trk][col];
    						    if (abs_rat(A[trk][j]) < epsilon_thetiko)
    						    {
    						        A[trk][j] = 0;
    						    }
    							I[trk][j]+=I[trk][col];
    							if (abs_rat(I[trk][j]) < epsilon_thetiko)
    							{
    							    I[trk][j] = 0;
    							}
						    }
						    cout<<"add column "<<col<<" to column "<<j<<endl;
					    }
					    else if(row!=j && col!=j)
                        {
						    for (trk=1;trk<=n;trk++)
                            {
							    A[j][trk]+=A[row][trk];
							    if (abs_rat(A[j][trk]) < epsilon_thetiko)
                                {
			                        A[j][trk] = 0;

				                }
							    I[j][trk]+=I[row][trk];
							    if (abs_rat(I[j][trk]) < epsilon_thetiko)
					            {
				                    I[j][trk] = 0;
					            }
						    }
						    cout<<"add row "<<row<<" to row "<<j<<endl;
						    for (trk=1;trk<=n;trk++)
                            {
							    A[trk][j]+=A[trk][col];
							    if (abs_rat(A[trk][j]) < epsilon_thetiko)
						        {
					                A[trk][j] = 0;
						        }
							    I[trk][j]+=I[trk][col];
							    if (abs_rat(I[trk][j]) < epsilon_thetiko)
							    {
							        I[trk][j] = 0;
							    }

						    }
						    cout<<"add column "<<col<<" to column "<<j<<endl;
			            }
				    }
				    if (trindic==1)
					    break;
			    }
			    if (trindic==1)
				    break;
		    }
		    for (printi=1;printi<=n;printi++){
		        for(printj=1;printj<=n;printj++){
	                cout<<A[printi][printj]<<"\t";
		        }
		        cout<<endl;
	        }
	        cout<<"========================================================"<<endl;
	        cout<<endl;
	    }



	    for(i=n; i>=j+1;i--){
		    if (A[i][j]!=0){
		    	if(egercheck_rat(A[j][j])==1 && egercheck_rat(A[i][j])==1) {
			    	multconst = lcm_rat(abs_rat(A[j][j]),abs_rat(A[i][j]));
		    	}
		    	else
			    	multconst =(A[j][j])*A[i][j];
		    	v1=A[i][j];
			    v2=A[j][j];
			    for (k=1; k<=n; k++){
			    	A[i][k]*=multconst/v1;
			    	I[i][k]*=multconst/v1;
			    	A[i][k]-=A[j][k]*multconst/v2;
			    	I[i][k]-=I[j][k]*multconst/v2;
			    	if (abs_rat(A[i][k]) < epsilon_thetiko)
			    	{
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	    A[i][k] = 0;
			    	}
			    	if (abs_rat(I[i][k]) < epsilon_thetiko)
			    	{
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	    I[i][k] = 0;
			    	}
			    }
			    if (multconst/v2 > 0)
			    {
			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			    }
			    else
			    {
			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs_rat(multconst/v2)<<" times row "<<j<<endl<<endl;
			    }
			    det *= v1/multconst;
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

    }


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
	    	for(j=n;j>=i+1;j--){
	    		if(A[i][j]!=0)
	    		{
	    			if(egercheck_rat(A[j][j])==1 && egercheck_rat(A[i][j])==1)
							multconst =lcm_rat(abs_rat(A[j][j]),abs_rat(A[i][j]));
			    	else
				 	    multconst =(A[j][j])*A[i][j];

					v1=A[i][j];
					v2=A[j][j];
					for (k=1; k<=n; k++)
					{
						A[i][k]*=multconst/v1;
						I[i][k]*=multconst/v1;
						A[i][k]-=A[j][k]*multconst/v2;
						I[i][k]-=I[j][k]*multconst/v2;
						if (abs_rat(A[i][k]) < epsilon_thetiko)
			    	    {
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	        A[i][k] = 0;
			    	    }
			        	if (abs_rat(I[i][k]) < epsilon_thetiko)
			    	    {
			    	      //  cout<<"smol number "<<A[i][k]<<endl;
			    	     //   cout<<epsilon_thetiko<<endl;
			    	        I[i][k] = 0;
			    	    }
					}
					if (multconst/v2 > 0)
			        {
			            cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			        }
			        else
		        	{
			            cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs_rat(multconst/v2)<<" times row "<<j<<endl<<endl;
			        }
			        det *= v1/multconst;
					for (printi=1;printi<=n;printi++)
					{
		                for(printj=1;printj<=n;printj++)
		                {
			            cout<<A[printi][printj]<<"\t";
                        }
	                    cout<<endl;
	                    cout<<endl;
                    }
                    cout<<"========================================================"<<endl;
			    }
		    }

	    }


    }
    cout<<"ROW ECHELON FORM"<<endl;
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
	    	multconst=A[i][i];
	    	A[i][i]/=(multconst);
	    	cout<<"divide row "<<i<<" by "<<multconst<<endl;
	    	det *= multconst;
	    	for(k=1;k<=n;k++){
          I[i][k]/=(multconst);
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
    cout<<"========================================================"<<endl;

    if(rank==n){
        cout<<"the determinant is "<<det<<" and"<<endl;
    	cout<<"the inverse matrix is"<<endl;
	    for (printi=1;printi<=n;printi++){
	    	for(printj=1;printj<=n;printj++){
		    	cout<<I[printi][printj]<<"  \t ";
		    }
	    cout<<endl;
	    cout<<endl;
	    }
	    cout<<"========================================================"<<endl;
    }
    system("pause");
    return 0;

}
else
{
    cpp_rational det = 1;
    int1024_t multconst,v1,v2,gconst;
    int1024_t A[n+1][n+1];
    int1024_t I[n+1][n+1];
    int1024_t O[n+1][n+1];
    std::fill(O[1], O[1] + (n+1) * (n+1), 0);
    for(i=1; i<=n;i++){
    	for(j=1; j<=n;j++){
    	    if(i==j)
    	        I[i][j]=1;
    	    else
    	        I[i][j]=0;

    		try
            {
                int1024_t tmp(A_str[i][j]);
                A[i][j] = tmp;

            }
            catch(...)
            {
                cout<<"Something went wrong"<<endl;
                return 1;
            }

	    }
    }
    for (printi=1;printi<=n;printi++)
    {
	    for(printj=1;printj<=n;printj++)
	    {
			cout<<A[printi][printj]<<"\t";
	    }
	    cout<<endl;
	    cout<<endl;
    }
    trindic =0;

    for(i=1;i<=n;i++){

	    for(j=1;j<=n;j++){
		    if(i==j)
			    I[i][j]=1;
		    else
			    I[i][j]=0;
	    }
    }


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
    	for(i=n; i>=j+1;i--){
    		if (A[i][j]!=0){
    			multconst = lcm(abs(A[j][j]),abs(A[i][j]));
    			v1=A[i][j];
    			v2=A[j][j];
    			for (k=1; k<=n; k++){
    				A[i][k]*=multconst/v1;
    				I[i][k]*=multconst/v1;
    				A[i][k]-=A[j][k]*multconst/v2;
    				I[i][k]-=I[j][k]*multconst/v2;
    			}
    	//		cout<<"subtract "<<multconst/v2<<" times row "<<j<<" from row "<<i<<" multiplied by "<<multconst/v1<<endl;
    			if (multconst/v2 > 0)
		        {

			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			    }
			    else
			    {
			        cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs(multconst/v2)<<" times row "<<j<<endl<<endl;
			    }
			    det *= v1;
			    det /=multconst;
			    cout<<"det is "<<det<<endl;
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


    }
    cout<<"ROW ECHELON FORM"<<endl;
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
    		for(j=n;j>=i+1;j--){
    			if(A[i][j]!=0){
    				multconst =lcm(abs(A[j][j]),abs(A[i][j]));
    				v1=A[i][j];
    				v2=A[j][j];
    				for (k=1; k<=n; k++){
    					A[i][k]*=multconst/v1;
    					I[i][k]*=multconst/v1;
    					A[i][k]-=A[j][k]*multconst/v2;
    					I[i][k]-=I[j][k]*multconst/v2;
    				}
    				if (multconst/v2 > 0)
			        {

			             cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and subtract "<<multconst/v2<<" times row "<<j<<endl<<endl;
			        }
			        else
			        {
			            cout<<"multiply row "<<i<<" by "<<multconst/v1<<" and add "<<abs(multconst/v2)<<" times row "<<j<<endl<<endl;
			        }
			        det *= v1;
			        det /=multconst;
			        cout<<"det is "<<det<<endl;
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
	    }
    }

    if (rank==n){
    	for(i=1;i<=n;i++){
    		multconst=A[i][i];
    		A[i][i]/=(multconst);    // +0.0
    		cout<<"divide row "<<i<<" by "<<multconst<<endl;
    		det *= multconst;
    		for(k=1;k<=n;k++){
    			gconst=gcd(abs(I[i][k]),abs(multconst));
    			I[i][k]/=gconst;
    			O[i][k]=multconst/gconst;
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
        cout<<"the determinant is "<<det<<" and"<<endl;
    	cout<<"the inverse matrix is"<<endl;
    	for (printi=1;printi<=n;printi++){
    		for(printj=1;printj<=n;printj++){
    			if(I[printi][printj]==0 or O[printi][printj]==1){
    				cout<<I[printi][printj]<<"  \t ";
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
    system("pause");
    return 0;


}
}

cpp_dec_float_100 abs_doub(cpp_dec_float_100 a)
{
	if (a<0)
		return -a;
	else
		return a;
}

cpp_dec_float_100 floorian_doub(cpp_dec_float_100 a)
{
    cpp_dec_float_100 i,b;
	if (a==0)
		return 0;
	else if (a>0)
	{
		i=1;
		b=0;
		while(b+i<a)
		{
 			i*=2;
 			if(b+i>a)
 			{
				 b+=i/2;
				 i=1;
			 }

		 }
 			return i+b;
	}
	else
	{
		i=-1;
 		b=0;
 		while(b+i>a-1)
 		{
 			i*=2;
 			if(b+i<a-1)
 			{
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

cpp_dec_float_100 gcd_doub(cpp_dec_float_100 a, cpp_dec_float_100 b)
{
	while (a!=b)
    {
		if (a<b)
		{
			b-=a*floorian_doub((b)/a);
			if (b==0)
				return a;
		}
		else if (a>b)
		{
			a-=b*floorian_doub(a/b);
			if (a==0)
				return b;
		}
	}
	return a;
}

cpp_dec_float_100 lcm_doub(cpp_dec_float_100 a, cpp_dec_float_100 b)
{
	cpp_dec_float_100 least;
	least = a*b/gcd_doub(a,b);
	return least;
}

int egercheck(cpp_dec_float_100 a)
{
	if (a==floorian_doub(a))
        return 1;
	else
        return 0;
}

cpp_rational abs_rat(cpp_rational a)
{
	if (a<0)
		return -a;
	else
		return a;
}

cpp_rational floorian_rat(cpp_rational a)
{
	cpp_rational i,b;
	if (a==0)
		return 0;
	else if (a>0)
	{
		i=1;
		b=0;
		while(b+i<a)
		{
 			i*=2;
 			if(b+i>a)
 			{
				b+=i/2;
				i=1;
			 }

		 }
 		return i+b-1;
	}
	else
	{
        i=-1;
 		b=0;
 		while(b+i>a-1)
 		{
 			i*=2;
 			if(b+i<a-1)
 			{
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

cpp_rational gcd_rat(cpp_rational a, cpp_rational b)
{
	while (a!=b)
	{
		if (a<b)
		{
		    b-=a*floorian_rat((b)/a);
			if (b==0)
				return a;
		}
		else if (a>b)
		{
			a-=b*floorian_rat(a/b);
			if (a==0)
				return b;
		}
	}
    return a;
}

cpp_rational lcm_rat(cpp_rational a, cpp_rational b)
{
	cpp_rational least;
	least = a*b/gcd_rat(a,b);
	return least;
}

int egercheck_rat(cpp_rational a)
{

	if (a==floorian_rat(a))
	return 1;
	else
	return 0;
}

int1024_t floorian(int1024_t a)
{
	int1024_t i,b;
	if (a==0)
		return 0;
	else if (a>0)
	{
		i=1;
		b=0;
		while(b+i<a)
		{
 		    i*=2;
 			if(b+i>a)
 			{
				b+=i/2;
				i=1;
			 }

		 }
 		return i+b;
	}
	else
	{
    	i=-1;
    	b=0;
     	while(b+i>a-1)
     	{
     		i*=2;
     		if(b+i<a-1)
     		{
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
