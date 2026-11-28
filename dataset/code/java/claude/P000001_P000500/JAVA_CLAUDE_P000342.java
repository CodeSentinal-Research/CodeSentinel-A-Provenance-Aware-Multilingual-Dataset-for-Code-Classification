import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();StringBuilder sb=new StringBuilder();for(int i=0;i<s.length();i++){if(i%2==0)sb.append(s.charAt(i));else sb.append((char)(s.charAt(i-1)+s.charAt(i)-'0'));}System.out.println(sb);}}
