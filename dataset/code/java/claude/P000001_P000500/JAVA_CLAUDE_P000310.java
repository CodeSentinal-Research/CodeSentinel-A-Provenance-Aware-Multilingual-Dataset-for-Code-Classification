import java.util.*;
public class Solution{public static void main(String[]a){
    String[]p=new Scanner(System.in).nextLine().split(" ");
    String s1=p[0],s2=p[1];int la=s1.length()-1,lb=s2.length()-1,carry=0;StringBuilder sb=new StringBuilder();
    while(la>=0||lb>=0||carry>0){int s=carry;if(la>=0)s+=s1.charAt(la--)-'0';if(lb>=0)s+=s2.charAt(lb--)-'0';sb.append(s%2);carry=s/2;}
    System.out.println(sb.reverse().toString());}}
