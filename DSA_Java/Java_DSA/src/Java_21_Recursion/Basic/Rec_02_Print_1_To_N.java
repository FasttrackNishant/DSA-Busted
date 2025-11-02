package Java_21_Recursion.Basic;

public class Rec_02_Print_1_To_N {

    public static void Solve(int index , int target)
    {
      if(index > target)
          return;
        
      System.out.println(index);
      Solve(index + 1, target);
    }

    public static void main(String[] args) {
        int n=3;
        Solve(1,n);
    }
}
