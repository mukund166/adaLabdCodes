#include <stdio.h>
int max(int a,int b)
{
  if(a>b)
     return a;
   else return b;
}
int main()
{
  int n,M,i,j,w[10],p[10],v[10][10],x[10]={0};
  printf("\n Read the number of objects :");
    scanf("%d",&n);
  printf("\n enter the weights of objects\n");
  for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
  printf("\n enter the profits of objects\n");
  for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
  printf("\n enter the knapsack capacity :");
    scanf("%d",&M);
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=M;j++)
      {
	if(i==0 || j==0)
	     v[i][j]=0;
	else if(j < w[i])
	     v[i][j]=v[i-1][j];
	else
	     v[i][j]=max(v[i-1][j],v[i-1][j-w[i]] + p[i]);
	     printf("%d\t",v[i][j]);
       }
       printf("\n");
    }
  i=n;
  j=M;
  while(i!=0 && j!=0)
  {
     if(v[i][j]!= v[i-1][j])
      {
	x[i]=1;
	j=j-w[i];
      }
     i=i-1;
  }
  printf("\n The max profit obtained is %d",v[n][M]);
  printf("\n The objects considered are");
  printf("\nobjno\tweight\tprofit\n");
  for(i=1;i<=n;i++)
    if(x[i]==1)
      printf("%d\t%d\t%d\n",i,w[i],p[i]);
  return 0;
}
