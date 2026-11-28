import java.util.*;
public class Solution{public static void main(String[]a){
    String[]tokens=new Scanner(System.in).nextLine().trim().split(" ");
    Deque<Long>stk=new ArrayDeque<>();
    for(String t:tokens){
        if("+-*/".contains(t)&&t.length()==1){long b=stk.pop(),aa=stk.pop();
        switch(t){case"+":stk.push(aa+b);break;case"-":stk.push(aa-b);break;case"*":stk.push(aa*b);break;default:stk.push((long)(aa/b));}}
        else stk.push(Long.parseLong(t));
    }System.out.println(stk.peek());}}
