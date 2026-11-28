import java.util.*;
public class Solution{public static void main(String[]a){
    String[]p=new Scanner(System.in).nextLine().split(" ");
    String[]pa=p[0].split("\\."),pb=p[1].split("\\.");
    int n=Math.max(pa.length,pb.length);
    for(int i=0;i<n;i++){int va=i<pa.length?Integer.parseInt(pa[i]):0,vb=i<pb.length?Integer.parseInt(pb[i]):0;
        if(va<vb){System.out.println(-1);return;}if(va>vb){System.out.println(1);return;}}System.out.println(0);}}
