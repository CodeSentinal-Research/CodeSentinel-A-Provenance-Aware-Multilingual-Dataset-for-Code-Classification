import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).nextLine().trim();
    Deque<Long>stk=new ArrayDeque<>();long num=0;char sign='+';
    for(int i=0;i<s.length();i++){char c=s.charAt(i);
        if(Character.isDigit(c))num=num*10+(c-'0');
        if((!Character.isDigit(c)&&c!=' ')||i==s.length()-1){
            if(sign=='+')stk.push(num);else if(sign=='-')stk.push(-num);
            else if(sign=='*'){long t=stk.pop();stk.push(t*num);}
            else{long t=stk.pop();stk.push((long)(t/num));}
            sign=c;num=0;
        }
    }long res=0;for(long v:stk)res+=v;System.out.println(res);}}
