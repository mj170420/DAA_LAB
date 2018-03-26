
import java.util.Scanner;

/**
 *
 * @author Mayank-Gupta
 */
public class toh
{
    
    static void towerOfHanoi(int n, char first, char last, char aux)
    {
        if (n == 1)
        {
            System.out.println("Move disk 1 from rod " +  first + " to rod " + last);
            return;
        }
        towerOfHanoi(n-1, first, aux, last);
        System.out.println("Move disk " + n + " from rod " +  first + " to rod " + last);
        towerOfHanoi(n-1, aux, last, first);
    }
    
    
    public static void main(String args[])
    {
        Scanner s= new Scanner(System.in);
        System.out.println("Enter the number of disks.");   
        int n = s.nextInt();
        towerOfHanoi(n, 'A', 'C', 'B'); 
    }
}