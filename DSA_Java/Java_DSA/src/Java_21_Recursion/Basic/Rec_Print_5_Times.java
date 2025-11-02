package Java_21_Recursion.Basic;

public class Rec_Print_5_Times {

    public static void Solve(int index , int n) {

        if(index >= n)
        {
            return; 
        }
        System.out.println("Raj" + index);
        Solve(index+1, n);
    }

    public static void main(String[] args) {

        System.out.println("Hello world");
        Solve(0,10);

    }
}
