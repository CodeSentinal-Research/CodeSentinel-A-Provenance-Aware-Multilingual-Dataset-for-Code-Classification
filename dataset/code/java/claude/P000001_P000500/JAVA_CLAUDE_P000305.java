import java.util.*;
public class Solution{public static void main(String[]a){
    String expr=new Scanner(System.in).nextLine();
    Deque<Integer>stk=new ArrayDeque<>();int num=0,sign=1,res=0;
    for(char c:expr.toCharArray()){
        if(Character.isDigit(c))num=num*10+(c-'0');
        else if(c=='+'||c=='-'){res+=sign*num;num=0;sign=(c=='+'?1:-1);}
        else if(c=='('){stk.push(res);stk.push(sign);res=0;sign=1;}
        else if(c==')'){res+=sign*num;num=0;sign=stk.pop();res=res*sign+stk.pop();sign=1;}
    }
    System.out.println(res+sign*num);}}
