import java.util.*;
public class Solution{static List<String>res=new ArrayList<>();static void gen(int n,int o,int c,String s){if(o==n&&c==n){res.add(s);return;}if(o<n)gen(n,o+1,c,s+"(");if(c<o)gen(n,o,c+1,s+")");}public static void main(String[]a){int n=new Scanner(System.in).nextInt();gen(n,0,0,"");System.out.println(String.join(" ",res));}}
