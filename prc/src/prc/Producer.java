package prc;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Producer implements Runnable {
	static List<Goods> list = new ArrayList<Goods> ();
	int buffer_size = 5;
	static int mutex1 = 1,empty = 5,full = 0,in = 0,count = 0;
	Producer()
	{
		
	}
	public void run()
	{	
		while(true)
		{
			if(count != 0)
			{
				empty = Consumer.empty;
				full = Consumer.full;
			}
            
			Random r = new Random();
		
			int temp = r.nextInt(10);
			if(empty <= 0)
			{
				System.out.println("资源不足");
			}
			else
				empty--;
			if(mutex1 > 0)
			{
				mutex1--;
				list.add(new Goods(temp));
				count++;
				System.out.println("该缓冲池现在已经有"+list.size()+"缓冲区被填满");
				System.out.println("第"+count+"号生产者生产了" + list.get(in).getData());
				in += 1;
				mutex1++;
				full++;
				sleep(1000);
			}
		}
	}
	
	private void sleep(int i) {
		// TODO 自动生成的方法存根
		
	}
	public static List getList()
	{
		return list;
	}
	
	
}
