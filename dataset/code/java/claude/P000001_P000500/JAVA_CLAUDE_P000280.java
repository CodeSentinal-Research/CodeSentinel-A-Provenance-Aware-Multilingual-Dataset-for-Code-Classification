import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();int[]f=new int[256];for(char c:s1.toCharArray())f[c]++;for(char c:s2.toCharArray())f[c]--;int d=0;for(int v:f)if(v<0)d+=-v;System.out.println(d<=1?"Yes":"No");}}
