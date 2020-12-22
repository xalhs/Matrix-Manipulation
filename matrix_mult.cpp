#include<stdio.h>
#include<iostream>

int main () {
	int i,m,n,k,j,z;
	FILE*fp;
	printf("This program will multiply two matrices of sizes m×k and k×n respectively")
	printf("give m \n");
	scanf("%d",&m);
	printf("give k \n");
	scanf("%d",&k);
	printf("give n \n");
	scanf("%d",&n);
	double a[m][k];
	double b[k][n];
	double c[m][n];
	double sum;
	fp=fopen("GIGALUL.dat","w");
	for (i=1;i<=m;i++){
		for(j=1;j<=k;j++){
			printf("give a[%d][%d] \n", i,j);
			scanf("%lf", &a[i][j]);
		}
	}
	for (i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			printf("give b[%d][%d] \n", i,j);
			scanf("%lf", &b[i][j]);
		}
	}
	
	for (i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			sum=0;
			for(z=1;z<=k;z++){
			sum+= a[i][z]*b[z][j];
				
			}
			c[i][j]=sum;
		}		
	}
	for (i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			fprintf(fp,"c[%d][%d] = %lf \t", i,j,c[i][j]);
			printf("%lf \t",c[i][j]);
		}
		fprintf(fp,"\n");
		printf("\n");
	}
	system("pause");
}

