import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();int n=s.length(),i=0;StringBuilder sb=new StringBuilder();while(i<n){int cnt=1;while(i+cnt<n&&s.charAt(i+cnt)==s.charAt(i))cnt++;sb.append(s.charAt(i));if(cnt>1)sb.append(cnt);i+=cnt;}System.out.println(sb);}}
