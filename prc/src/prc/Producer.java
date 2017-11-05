package prc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Producer extends Thread {
	static List<Object> list = new ArrayList<Object> ();
	int buffer_size = 5;
	static int mutex1,empty,full;
	Producer(int mutex1,int empty,int full)
	{
		this.mutex1 = mutex1;
		this.empty = empty;
		this.full = full;
	}
	public void run()
	{
		if(empty <= 0)
		{
			System.out.println("×ÊÔ´²»×ã");
		}
		else
			empty--;
		if(mutex1 > 0)
		{
			mutex1--;
			list.add(new Object());
			mutex1++;
			full++;
		}
	}
	
	public static List getList()
	{
		return list;
	}
	
	
}
