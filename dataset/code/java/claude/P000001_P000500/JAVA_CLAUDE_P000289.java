import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s=sc.next();int k=sc.nextInt(),win[]=new int[26],l=0,best=0,mxf=0;for(int r=0;r<s.length();r++){win[s.charAt(r)-'A']++;mxf=Math.max(mxf,win[s.charAt(r)-'A']);if(r-l+1-mxf>k)win[s.charAt(l++)-'A']--;best=Math.max(best,r-l+1);}System.out.println(best);}}
