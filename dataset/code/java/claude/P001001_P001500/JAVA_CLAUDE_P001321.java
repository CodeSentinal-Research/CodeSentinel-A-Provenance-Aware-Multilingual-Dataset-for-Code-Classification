import java.util.*;
public class Solution {
    private String[] phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    private void bt(String digits,int idx,StringBuilder curr,List<String> res){
        if(idx==digits.length()){res.add(curr.toString());return;}
        for(char c:phone[digits.charAt(idx)-'0'].toCharArray()){curr.append(c);bt(digits,idx+1,curr,res);curr.deleteCharAt(curr.length()-1);}
    }
    public List<String> letterCombinations(String digits){
        List<String> res=new ArrayList<>();
        if(!digits.isEmpty()) bt(digits,0,new StringBuilder(),res); return res;
    }
    public static void main(String[] args){
        for(String s:new Solution().letterCombinations(new Scanner(System.in).next())) System.out.println(s);
    }
}
