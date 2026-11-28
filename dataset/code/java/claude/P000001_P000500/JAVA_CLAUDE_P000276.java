import java.util.*;
public class Solution{public static void main(String[]a){int n=new Scanner(System.in).nextInt();String s="1";for(int i=1;i<n;i++){StringBuilder sb=new StringBuilder();int j=0;while(j<s.length()){int cnt=1;while(j+cnt<s.length()&&s.charAt(j+cnt)==s.charAt(j))cnt++;sb.append(cnt).append(s.charAt(j));j+=cnt;}s=sb.toString();}System.out.println(s);}}
