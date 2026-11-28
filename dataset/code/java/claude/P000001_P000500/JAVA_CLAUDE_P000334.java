import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String src=sc.next(),tgt=sc.next();int sl=src.length(),tl=tgt.length(),j=0,cnt=0;while(j<tl){int prev=j;for(int i=0;i<sl&&j<tl;i++)if(src.charAt(i)==tgt.charAt(j))j++;if(j==prev){System.out.println(-1);return;}cnt++;}System.out.println(cnt);}}
