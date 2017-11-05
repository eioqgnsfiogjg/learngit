package prc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Consumer extends Thread {
	int buffer_size = 5;
	static int mutex2,empty,full;
	static List<Object> list = new ArrayList<Object> ();
	Consumer(int mutex2,int empty,int full)
	{
		this.mutex2 = mutex2;
		this.empty = empty;
		this.full = full;
	}
	public void run(int mutex2,int empty,int full,int[] buffer,int out)
	{
		if(full <= 0)
		{
			System.out.println("×ÊÔ´²»×ã");
		}
		else
			full--;
		if(mutex2 > 0)
		{
			mutex2--;
			Scanner a1 = new Scanner(System.in);
			list.remove(new Object());
			mutex2++;
			empty++;
		}
	}
			
		

	

	
		
	
}
