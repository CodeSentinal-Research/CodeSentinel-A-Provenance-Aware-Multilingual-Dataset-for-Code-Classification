import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next().toLowerCase();String v="aeiou";int n=s.length(),ca=0,cb=0;for(int i=0;i<n/2;i++)if(v.indexOf(s.charAt(i))>=0)ca++;for(int i=n/2;i<n;i++)if(v.indexOf(s.charAt(i))>=0)cb++;System.out.println(ca==cb?"Yes":"No");}}
