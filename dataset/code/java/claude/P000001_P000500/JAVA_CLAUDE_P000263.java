import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();Map<Character,Integer>f=new HashMap<>();for(char c:s.toCharArray())f.merge(c,1,Integer::sum);char res=0;for(char c:s.toCharArray())if(f.get(c)==1)res=c;System.out.println(res==0?-1:res);}}
