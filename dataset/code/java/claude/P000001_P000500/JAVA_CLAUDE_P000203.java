import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Map<Integer,Integer> freq=new HashMap<>();
        int bestVal=0,bestCnt=0;
        for(int i=0;i<n;i++){int x=sc.nextInt();freq.merge(x,1,Integer::sum);if(freq.get(x)>bestCnt){bestCnt=freq.get(x);bestVal=x;}}
        System.out.println(bestVal);
    }
}
