import java.util.*;
public class Solution{static String s;static int idx;
static long calc(){Deque<Long>stk=new ArrayDeque<>();long num=0;char sign='+';
    while(idx<s.length()){char c=s.charAt(idx++);
        if(Character.isDigit(c))num=num*10+(c-'0');
        else if(c=='(')num=calc();
        if((!Character.isDigit(c)&&c!=' ')||idx==s.length()){
            if(sign=='+')stk.push(num);else if(sign=='-')stk.push(-num);
            else if(sign=='*'){long t=stk.pop();stk.push(t*num);}
            else{long t=stk.pop();stk.push((long)(t/num));}
            if(c==')')break;sign=c;num=0;
        }
    }long r=0;for(long v:stk)r+=v;return r;
}
public static void main(String[]a){s=new Scanner(System.in).nextLine().trim();idx=0;System.out.println(calc());}}
