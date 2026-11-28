import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();System.out.println(s.chars().filter(c->c=='A').count()<=1&&!s.contains("LLL")?"Yes":"No");}}
