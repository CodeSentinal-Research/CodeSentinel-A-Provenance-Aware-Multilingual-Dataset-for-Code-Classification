import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();long s=0;StringJoiner sj=new StringJoiner(" ");
    for(int i=0;i<n;i++){s+=sc.nextInt();sj.add(String.valueOf(s));}System.out.println(sj);}}
