import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int l=sc.nextInt()-1,r=sc.nextInt()-1;
    while(l<r){int t=arr[l];arr[l]=arr[r];arr[r]=t;l++;r--;}
    StringJoiner sj=new StringJoiner(" ");for(int v:arr)sj.add(String.valueOf(v));System.out.println(sj);}}
