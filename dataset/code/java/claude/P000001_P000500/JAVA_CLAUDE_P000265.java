import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();Set<Character>seen=new LinkedHashSet<>();for(char c:s.toCharArray())seen.add(c);StringBuilder sb=new StringBuilder();for(char c:seen)sb.append(c);System.out.println(sb);}}
