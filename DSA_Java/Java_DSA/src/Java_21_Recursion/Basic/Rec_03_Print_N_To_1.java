package Java_21_Recursion.Basic;
public class Rec_03_Print_N_To_1 {

    public static void Solve(int index, int target) {

        if(index <1 )
            return;
        
        System.out.println(index);
        Solve(index - 1, target);
    }

    public static void main(String[] args) {
        Solve(3, 3);
    }
}
// This is BackTracking