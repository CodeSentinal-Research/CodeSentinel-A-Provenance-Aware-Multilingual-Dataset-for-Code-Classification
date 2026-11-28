import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String note=sc.next(),mag=sc.nextLine().trim();int[]fn=new int[256],fm=new int[256];for(char c:note.toCharArray())fn[c]++;for(char c:mag.toCharArray())fm[c]++;for(int i=0;i<256;i++)if(fn[i]>fm[i]){System.out.println("No");return;}System.out.println("Yes");}}
