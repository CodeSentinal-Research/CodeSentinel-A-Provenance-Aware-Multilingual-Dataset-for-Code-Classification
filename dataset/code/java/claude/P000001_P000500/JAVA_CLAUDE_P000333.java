import java.util.*;
public class Solution{static boolean isSub(String w,String s){int i=0;for(char c:s.toCharArray())if(i<w.length()&&c==w.charAt(i))i++;return i==w.length();}public static void main(String[]a){Scanner sc=new Scanner(System.in);String s=sc.next();int n=sc.nextInt();int cnt=0;while(n-->0)if(isSub(sc.next(),s))cnt++;System.out.println(cnt);}}
