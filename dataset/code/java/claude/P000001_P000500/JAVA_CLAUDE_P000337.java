import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();int n=s.length(),ones=(int)s.chars().filter(c->c=='1').count(),zeros=0,best=0;for(int i=0;i<n-1;i++){if(s.charAt(i)=='0')zeros++;else ones--;best=Math.max(best,zeros+ones);}System.out.println(best);}}
