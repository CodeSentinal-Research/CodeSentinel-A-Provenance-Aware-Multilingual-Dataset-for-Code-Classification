import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    Map<String,String> mp=new LinkedHashMap<>();
    for(int i=0;i<n;i++){
        String line=sc.nextLine().trim();
        String key=line.split(" ")[0];
        mp.put(key,line);
    }
    String q=sc.nextLine().trim();
    System.out.println(mp.getOrDefault(q,"Record Not Found"));
}}
