import java.util.*;
public class Solution{
static long mc(int[]a,int[]t,int l,int r){
if(r-l<=1)return 0;
int m=(l+r)/2;long inv=mc(a,t,l,m)+mc(a,t,m,r);
int i=l,j=m,k=l;
while(i<m&&j<r){if(a[i]<=a[j])t[k++]=a[i++];else{t[k++]=a[j++];inv+=m-i;}}
while(i<m)t[k++]=a[i++];while(j<r)t[k++]=a[j++];
for(int x=l;x<r;x++)a[x]=t[x];return inv;}
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[]a=new int[n];for(int i=0;i<n;i++)a[i]=sc.nextInt();
System.out.println(mc(a,new int[n],0,n));}}
