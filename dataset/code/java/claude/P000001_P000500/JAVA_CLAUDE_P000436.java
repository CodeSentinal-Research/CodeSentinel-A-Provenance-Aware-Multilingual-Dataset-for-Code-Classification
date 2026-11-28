import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(),x=sc.nextInt();
    int[]arr=new int[n];
    for(int i=0;i<n;i++) arr[i]=sc.nextInt();
    int lo=0,hi=n;
    while(lo<hi){int m=(lo+hi)/2;if(arr[m]<x)lo=m+1;else hi=m;}
    System.out.println(lo);
}}
