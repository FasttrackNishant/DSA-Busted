package Java_21_Recursion.Standard.src;

public class Rec_01_Fibonacci {


    public static int solve(int n)
    {
        if(n<=1)
            return n;

        int ans = solve(n-1)+solve(n-2);


        return ans;
    }

    public static void main(String[] args) {
        int n = 4;
        int result = solve(n);
        System.out.println("result is "+result);
    }


}
