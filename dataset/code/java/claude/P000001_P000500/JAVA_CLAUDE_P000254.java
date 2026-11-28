import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next().toLowerCase();String v="aeiou";int cnt=0;for(char c:s.toCharArray())if(Character.isLetter(c)&&v.indexOf(c)<0)cnt++;System.out.println(cnt);}}
