import java.util.*;
public class Solution{public static void main(String[]a){long n=new Scanner(System.in).nextLong();long lo=0,hi=n;while(lo<hi){long m=(lo+hi+1)/2;if(m*m<=n)lo=m;else hi=m-1;}System.out.println(lo);}}
