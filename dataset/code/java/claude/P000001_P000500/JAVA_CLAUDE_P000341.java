import java.util.*;
public class Solution{static long val(String s){long v=0;for(char c:s.toCharArray())v=v*10+(c-'a');return v;}public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next(),t=sc.next();System.out.println(val(s1)+val(s2)==val(t)?"Yes":"No");}}
