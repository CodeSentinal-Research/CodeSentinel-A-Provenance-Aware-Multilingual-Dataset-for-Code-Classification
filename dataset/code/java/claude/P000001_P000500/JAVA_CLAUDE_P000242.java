import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();int cnt=0;
for(int i=0;i<n*n;i++)if(sc.nextInt()==0)cnt++;
System.out.println(cnt);}}
