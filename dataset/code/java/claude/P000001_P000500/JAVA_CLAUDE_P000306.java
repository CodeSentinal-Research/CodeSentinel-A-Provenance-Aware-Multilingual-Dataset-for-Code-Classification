import java.util.*;
public class Solution{public static void main(String[]a){
    String expr=new Scanner(System.in).nextLine().replaceAll(" ","");
    Deque<Long>stk=new ArrayDeque<>();long num=0;char op='+';
    for(int i=0;i<expr.length();i++){
        char c=expr.charAt(i);
        if(Character.isDigit(c))num=num*10+(c-'0');
        if(!Character.isDigit(c)||i==expr.length()-1){
            if(op=='+')stk.push(num);
            else if(op=='-')stk.push(-num);
            else if(op=='*'){long t=stk.pop();stk.push(t*num);}
            else{long t=stk.pop();stk.push(t<0?-((-t)/num):(t/num));}
            op=c;num=0;
        }
    }
    long res=0;for(long v:stk)res+=v;System.out.println(res);}}
