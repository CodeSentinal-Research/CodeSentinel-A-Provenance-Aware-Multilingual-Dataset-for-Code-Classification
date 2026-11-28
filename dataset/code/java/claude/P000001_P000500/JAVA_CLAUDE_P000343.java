import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String w1=sc.next(),w2=sc.next();int[]f=new int[26];for(char c:w1.toCharArray())f[c-'a']++;for(char c:w2.toCharArray())f[c-'a']--;for(int v:f)if(Math.abs(v)>3){System.out.println("No");return;}System.out.println("Yes");}}
