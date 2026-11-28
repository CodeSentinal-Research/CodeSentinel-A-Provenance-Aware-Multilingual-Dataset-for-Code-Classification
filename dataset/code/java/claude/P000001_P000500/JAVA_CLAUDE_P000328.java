import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();int[]f=new int[256];for(char c:s.toCharArray())f[c]++;for(int i=0;i<s.length();i++)if(f[s.charAt(i)]==1){System.out.println(i);return;}System.out.println(-1);}}
