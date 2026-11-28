import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();StringBuilder sb=new StringBuilder();for(char c:s.toCharArray())if("aeiouAEIOU".indexOf(c)>=0||!Character.isLetter(c))sb.append(c);System.out.println(sb);}}
