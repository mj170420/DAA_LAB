package javaapplication1;
import java.util.Scanner;
import java.util.Stack;
public class postfix {
   int Postfix(String expression)
    {
        Stack<Integer> s=new Stack<>();
        try
     { 
        for(int i=0;i<expression.length();i++)
        {
            char c=expression.charAt(i);
             
            if(Character.isDigit(c))
            s.push(c - '0');
             
            else
            {
                int op1 = s.pop();
                int op2 = s.pop();
               
                if(c=='+')
                {   
                    s.push(op2+op1);
                }
                else
                    if(c=='-')
                    {
                        s.push(op2-op1);
                    }
                else
                    if(c=='*')
                    {
                        s.push(op2*op1);
                    }
                else
                    if(c=='/')
                    {
                        s.push(op2/op1);
                    }
                else
                    {
                        System.out.println("error !!!");
                    }
            }
        }
    }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
        return s.pop();    
    }

    public static void main(String a[])
    {
        Scanner s = new Scanner(System.in);
        String expr = s.nextLine();
        postfix pf = new postfix();
        int result = pf.Postfix(expr);
        System.out.println("The Result of the given Expression is:"+result);
    }
}
