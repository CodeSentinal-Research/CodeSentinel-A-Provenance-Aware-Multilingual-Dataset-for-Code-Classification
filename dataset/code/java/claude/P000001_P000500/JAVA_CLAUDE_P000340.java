import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String text=sc.nextLine(),broken=sc.nextLine().trim();Set<Character>bs=new HashSet<>();for(char c:broken.toCharArray())bs.add(c);int cnt=0;for(String w:text.split(" ")){boolean ok=true;for(char c:w.toCharArray())if(bs.contains(c)){ok=false;break;}if(ok)cnt++;}System.out.println(cnt);}}
