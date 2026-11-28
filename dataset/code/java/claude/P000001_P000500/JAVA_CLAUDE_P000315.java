import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();int res=0;for(char c:s.toCharArray())res=res*26+(c-'A'+1);System.out.println(res);}}
