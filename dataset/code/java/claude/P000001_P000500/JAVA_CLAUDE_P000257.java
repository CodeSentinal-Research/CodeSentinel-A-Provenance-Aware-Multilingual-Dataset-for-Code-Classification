import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);char[]s1=sc.next().toCharArray(),s2=sc.next().toCharArray();Arrays.sort(s1);Arrays.sort(s2);System.out.println(Arrays.equals(s1,s2)?"Yes":"No");}}
