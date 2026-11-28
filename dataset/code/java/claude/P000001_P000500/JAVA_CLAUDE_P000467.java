import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int m=sc.nextInt(),n=sc.nextInt();int[]c=new int[m+n];for(int i=0;i<m+n;i++)c[i]=sc.nextInt();Arrays.sort(c);int t=m+n;if(t%2==1)System.out.println(c[t/2]);else{double med=(c[t/2-1]+c[t/2])/2.0;System.out.println(med%1==0?(long)med:med);} }}
