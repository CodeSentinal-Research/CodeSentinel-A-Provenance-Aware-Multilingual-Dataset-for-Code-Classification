import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).next();Deque<Integer>stk=new ArrayDeque<>();stk.push(0);
    for(char c:s.toCharArray()){
        if(c=='(')stk.push(0);
        else{int v=stk.pop();stk.push(stk.pop()+(v>0?2*v:1));}
    }System.out.println(stk.peek());}}
