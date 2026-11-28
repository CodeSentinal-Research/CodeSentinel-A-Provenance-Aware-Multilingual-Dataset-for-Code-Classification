import java.util.*;
public class Solution{static boolean pal(char[]s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}public static void main(String[]a){char[]s=new Scanner(System.in).next().toCharArray();int l=0,r=s.length-1;while(l<r&&s[l]==s[r]){l++;r--;}System.out.println(l>=r||pal(s,l+1,r)||pal(s,l,r-1)?"Yes":"No");}}
