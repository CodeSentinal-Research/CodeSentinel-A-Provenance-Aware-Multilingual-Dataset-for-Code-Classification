import java.util.*;
public class Solution{public static void main(String[]a){String path=new Scanner(System.in).nextLine().trim();Deque<String>stk=new ArrayDeque<>();for(String p:path.split("/")){if(p.equals("..")){if(!stk.isEmpty())stk.pollLast();}else if(!p.isEmpty()&&!p.equals("."))stk.addLast(p);}System.out.println("/"+String.join("/",stk));}}
