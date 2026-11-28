import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();StringBuilder sb=new StringBuilder();for(char c:s.toCharArray())sb.append(Character.isUpperCase(c)?Character.toLowerCase(c):Character.isLowerCase(c)?Character.toUpperCase(c):c);System.out.println(sb);}}
