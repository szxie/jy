#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int _Min(int a,int b,int c) 
{ 
int min=a; 
if (b <min) 
  min=b; 
 if(c <min) 
 min=c; 
 return min; 
 } 
 
 int ComputeDistance(char s[],char t[]) 
 { 
	 int n = strlen(s); 
	 
	 int m = strlen(t); 
	 
	 //int d[][] = new int[n + 1, m + 1]; // matrix 
	 int **d = (int **)malloc((n+1) * sizeof(int *)); 
	 for(int i=0; i<=n; ++i) 
	 { 
	 d[i] = (int *)malloc((m+1) * sizeof(int)); 
	 } 
	 // Step 1 
	 if (n == 0) 
	 { 
	 return m; 
	 } 
	 
	 if (m == 0) 
	 { 
	 return n; 
	 } 
	 
	 // Step 2 
	 for (int i = 0; i <= n; i++) 
	 { 
	 d[i][0] =i; 
	 } 
	 
	 for (int j = 0; j <= m; d[0][j] = j++) 
	 { 
	 d[0][j] =j; 
	 } 
	 
	 // Step 3 
	 for (int i = 1; i <= n; i++) 
	 { 
	//Step 4 
	 for (int j = 1; j <= m; j++) 
	 { 
	 // Step 5 
	 int cost = (t[j-1] == s[i-1]) ? 0 : 1; 
	 
	 // Step 6 
	 d[i][j] = _Min(d[i-1][j]+1, d[i][j-1]+1,d[i-1][j-1]+cost); 
	 } 
	 } 
	 // Step 7 
	 return d[n][m]; 
 } 
 
 int main(int argc, char *argv[]) 
 { 
	 char a[9999]; 
	 char b[9999]; 
	 printf("请输入字符串1\n"); 
	 scanf("%s",&a); 
	 printf("请输入字符串2\n"); 
	 scanf("%s",&b); 
	 int result= ComputeDistance(a,b); 
	 printf("%d\n",result); 
	 return 0; 
 }