import java.util.*;
public class Solution {
    public int minOperations(String[] logs){
        int depth=0;
        for(String op:logs){if(op.equals("../"))depth=Math.max(0,depth-1);else if(!op.equals("./"))depth++;}
        return depth;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); String[] logs=new String[n];
        for(int i=0;i<n;i++) logs[i]=sc.next();
        System.out.println(new Solution().minOperations(logs));
    }
}
