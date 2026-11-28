import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();Map<Character,Integer>f=new LinkedHashMap<>();for(char c:s.toCharArray())f.merge(c,1,Integer::sum);for(char c:s.toCharArray())if(f.get(c)==1){System.out.println(c);return;}System.out.println(-1);}}
