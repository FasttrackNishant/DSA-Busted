package Java_21_Recursion.Strings.src;

public class Rec_01_String_Palindrome {

    public  static  boolean solve(int index , String str){
        if(index >= str.length()/2)
            return true;
        return str.charAt(index) == str.charAt(str.length() - index - 1) && solve(index + 1, str);


    }

    public static void main(String[] args) {

        String str = "MADAMty";
         boolean result =  solve(0 , str);
        System.out.println("Result is "+result);

    }


}
