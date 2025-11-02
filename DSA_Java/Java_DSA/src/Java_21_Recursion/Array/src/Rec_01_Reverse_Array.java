package Java_21_Recursion.Array.src;

// 1 2 3 4 -> 4 3 2 1
public class Rec_01_Reverse_Array {


    public static void solve(int index, int[] arr, int size) {
        if (index >= size / 2)
            return;

        int temp = arr[index];
        arr[index] = arr[size - index - 1];
        arr[size - index - 1] = temp;
        solve(index+1, arr, size);

    }


    public static void main(String[] args) {

        int index = 0;
        int size = 5;
        int[] arr = new int[size];
        arr[0] = 21;
        arr[1] = 23;
        arr[2] = 32;
        arr[3] = 45;
        arr[4] = 53;

        //before swap
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();


        solve(index, arr, size);


        //aftet swap

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();


    }


}
 