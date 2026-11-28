package src.backtracking.subsequence;

public class binaryStrings_without_Consecutive_ones {
    static void main() {

    int n = 3;
    generate(n,0, "");
}
static void generate(int n,int index,String ans){

    if(index==n){
        System.out.print(ans+" ");
        return;
    }

    // add the zeros
    generate(n,index+1,ans+"0");

    // if previous character is '1' then simply return
    if(ans.length()==0 || ans.charAt(ans.length()-1)!='1'){
        generate(n,index+1,ans+"1");
    }


}
}
