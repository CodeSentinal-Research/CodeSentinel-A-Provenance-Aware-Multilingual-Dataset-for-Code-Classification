import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).nextLine().trim();
    StringBuilder res=new StringBuilder();Deque<Integer>stk=new ArrayDeque<>();
    for(char c:s.toCharArray()){
        if(c=='(')stk.push(res.length());
        else if(c==')'){int st=stk.pop();res.replace(st,res.length(),new StringBuilder(res.substring(st)).reverse().toString());}
        else res.append(c);
    }System.out.println(res);}}
