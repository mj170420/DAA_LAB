import java.util.Scanner;

public class heapsort {
	
	static int heap[]= new int[30];

	public static int insertInHeap(int pos, int data)
	{
		 int i;
		    i=pos;
		    heap[i]=data;
		    while(i>1 && heap[i/2]<data)
		    {
		        heap[i]=heap[i/2];
		        i=i/2;
		    }
		    heap[i]=data;
		    return pos;
	}
	
	public static int delete(int n)
	{
	    int num=heap[1];
	    heap[1]=heap[n];
	    adjust(n-1,1);
	    return num;
	}

	public static void adjust(int n, int i)
	{
	    int j,item,temp=0;
	    j=2*i;
	    item = heap[i];
	    while(j!=temp && j<=n)
	    {
	        temp=j;
	        if(heap[j]>heap[j+1]&&heap[j]>item)
	        {
	            heap[i]=heap[j];
	            i=j;
	        }
	        else if(item<heap[j+1])
	        {
	            heap[i]=heap[j+1];
	            i=j+1;
	        }
	        j=2*i;
	    }
	    heap[i]=item;
	}

	public static void display(int c)
	{
	    int i;
	    if(c==0)
	        System.out.println("no element present");
	    else{
	    for(i=1;i<=c;i++){
	        System.out.print(heap[i]+" ");
	    }
	}
	}
	
	public static void main(String at[])
{
	
		Scanner s = new Scanner(System.in);
		int n=0,i,x,j,temp,del=0,n1,a[];
		a= new int[30];
		char ch;
		        System.out.println("Enter the no elements of the array\n");
		        n=s.nextInt();
		        n1=n;
		        System.out.println("Enter the element to be inserted in the array\n");
		        for(i=0;i<n;i++)
		        {
		        x=s.nextInt();
		        insertInHeap(i+1,x);
		        }
		        System.out.println("The array after insertion is\n");
		        display(n);
		        if(n==0)
		        System.out.println("No element present\n");
		        for(i=0;i<n;i++)
		        {
		            a[i]=delete(n1);
		            n1=n1-1;
		        }
		System.out.println("The heap sort output is\n");
		for (i=0;i<n;i++)
		{
		    System.out.println(a[i]+" ");
		}
}
}
