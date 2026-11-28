import java.util.*;
public class Solution{public static void main(String[]a){long n=new Scanner(System.in).nextLong();long r=(long)Math.sqrt(n);while(r*r>n)r--;while((r+1)*(r+1)<=n)r++;System.out.println(r*r==n?"Yes":"No");}}
