import java.util.*;
public class Solution{static String s;static String exp(int l,int r){while(l>=0&&r<s.length()&&s.charAt(l)==s.charAt(r)){l--;r++;}return s.substring(l+1,r);}public static void main(String[]a){s=new Scanner(System.in).next();String best="";for(int i=0;i<s.length();i++){for(String p:new String[]{exp(i,i),exp(i,i+1)})if(p.length()>best.length())best=p;}System.out.println(best);}}
