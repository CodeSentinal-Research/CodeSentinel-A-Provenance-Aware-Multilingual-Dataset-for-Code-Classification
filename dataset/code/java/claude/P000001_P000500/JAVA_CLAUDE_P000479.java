import java.util.*;
public class Solution {
    public boolean isValid(String s) {
        Deque<Character> st=new ArrayDeque<>();
        for(char c:s.toCharArray()){
            if(c=='('||c=='['||c=='{') st.push(c);
            else{if(st.isEmpty())return false;
                char t=st.pop();
                if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))return false;}
        }
        return st.isEmpty();
    }
    public static void main(String[] args) {
        System.out.println(new Solution().isValid(new Scanner(System.in).next())?"Yes":"No");
    }
}
