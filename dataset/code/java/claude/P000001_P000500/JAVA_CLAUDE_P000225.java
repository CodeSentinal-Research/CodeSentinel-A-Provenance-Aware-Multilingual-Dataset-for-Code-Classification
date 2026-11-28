import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
Integer[]idx=new Integer[n];int[]a=new int[n];
for(int i=0;i<n;i++){a[i]=sc.nextInt();idx[i]=i;}
Arrays.sort(idx,(i,j)->a[i]-a[j]);
boolean[]vis=new boolean[n];int sw=0;
for(int i=0;i<n;i++){if(vis[i]||idx[i]==i)continue;int j=i,c=0;while(!vis[j]){vis[j]=true;j=idx[j];c++;}sw+=c-1;}
System.out.println(sw);}}
