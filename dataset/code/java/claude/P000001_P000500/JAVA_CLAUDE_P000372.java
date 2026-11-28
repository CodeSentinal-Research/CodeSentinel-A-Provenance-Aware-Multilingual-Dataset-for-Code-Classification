import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    List<String> recs=new ArrayList<>();
    for(int i=0;i<n;i++) recs.add(sc.nextLine().trim());
    String roll=sc.nextLine().trim();
    for(String r:recs){
        if(r.split(" ")[0].equals(roll)){System.out.println(r);return;}
    }
    System.out.println("Record Not Found");
}}
