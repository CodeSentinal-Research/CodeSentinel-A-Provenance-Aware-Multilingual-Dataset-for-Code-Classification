import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();Deque<Character>stk=new ArrayDeque<>();for(char c:s.toCharArray()){if(!stk.isEmpty()&&stk.peek()==c)stk.pop();else stk.push(c);}StringBuilder sb=new StringBuilder();for(char c:stk)sb.append(c);System.out.println(sb.reverse());}}
