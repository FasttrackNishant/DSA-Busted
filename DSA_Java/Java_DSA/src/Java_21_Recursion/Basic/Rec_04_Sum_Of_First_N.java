package Java_21_Recursion.Basic;
public class Rec_04_Sum_Of_First_N {

    //Parameter
    private static void Solve(int number , int sum)
    {
        if(number < 1)
        {
            System.out.println(sum);
            return;
        }
        Solve(number - 1, sum + number);
    }

    public static void main(String[] args) {
        
        int sum = 0;
        int number= 3;
        Solve(number , sum);
        int Result = SolveReturn(3);
        System.out.println(Result);
        int factResult = SolveFactorial(5);
        System.out.println("fact Result "+factResult);
    }

    //Functional
    private static int SolveReturn(int num)
    {
        if(num == 0 )
            return  0;
        int ans =num+ SolveReturn(num-1);
        return ans;
    }

    private static int SolveFactorial(int n)
    {
        if(n==1 || n==0)
            return 1;

        int ans = n * SolveFactorial(n-1);
        return ans;
    }

    /*
     * 3 -> nahi 3
     * (3-1) ->nahi 2
     * (2->1)-> nahi 1
     * (1-1)-> 0 -> Yes return 0
     * 
     * 
     * 
     */




}
