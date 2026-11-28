import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();Set<Character>a1=new HashSet<>(),a2=new HashSet<>();for(char c:s1.toCharArray())a1.add(c);for(char c:s2.toCharArray())a2.add(c);System.out.println(a1.equals(a2)?"Yes":"No");}}
