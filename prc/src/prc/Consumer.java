package prc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Consumer implements Runnable {
	int buffer_size = 5;
	static int mutex2 = 1,empty,full,out = 0,ccount = 0;
	static List<Goods> list = new ArrayList<Goods> ();
	Consumer()
	{
	
	}
	public void run()
	{
		
		while(true)
		{
			empty = Producer.empty;
			full = Producer.full;
			if(full <= 0)
			{
				System.out.println("资源不足");
			}
			else
				full--;
			if(mutex2 > 0)
			{
				mutex2--;
				System.out.println("第"+ccount+"号消费者者消费了" + list.get(out).getData());
				out += 1;
				mutex2++;
				empty++;
			}
		}
	}
			
		

	

	
		
	
}
