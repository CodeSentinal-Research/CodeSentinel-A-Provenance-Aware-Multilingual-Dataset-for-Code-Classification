import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Set<String> res = new TreeSet<>();
        int left = 0, right = 0;
        for(char c : s.toCharArray()) {
            if(c == '(') left++;
            else if(c == ')') {
                if(left > 0) left--;
                else right++;
            }
        }
        removeInvalid(s, 0, new StringBuilder(), left, right, 0, res);
        for(String str : res) System.out.println(str);
    }
    
    static void removeInvalid(String s, int idx, StringBuilder curr, int lRem, int rRem, int open, Set<String> res) {
        if(idx == s.length()) {
            if(lRem == 0 && rRem == 0) res.add(curr.toString());
            return;
        }
        char c = s.charAt(idx);
        if(c != '(' && c != ')') {
            curr.append(c);
            removeInvalid(s, idx+1, curr, lRem, rRem, open, res);
            curr.deleteCharAt(curr.length()-1);
        } else {
            if(c == '(') {
                if(lRem > 0) removeInvalid(s, idx+1, curr, lRem-1, rRem, open, res);
                curr.append(c);
                removeInvalid(s, idx+1, curr, lRem, rRem, open+1, res);
                curr.deleteCharAt(curr.length()-1);
            } else {
                if(rRem > 0) removeInvalid(s, idx+1, curr, lRem, rRem-1, open, res);
                if(open > 0) {
                    curr.append(c);
                    removeInvalid(s, idx+1, curr, lRem, rRem, open-1, res);
                    curr.deleteCharAt(curr.length()-1);
                }
            }
        }
    }
}
