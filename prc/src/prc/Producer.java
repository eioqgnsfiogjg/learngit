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
				System.out.println("��Դ����");
			}
			else
				empty--;
			if(mutex1 > 0)
			{
				mutex1--;
				list.add(new Goods(temp));
				count++;
				System.out.println("�û���������Ѿ���"+list.size()+"������������");
				System.out.println("��"+count+"��������������" + list.get(in).getData());
				in += 1;
				mutex1++;
				full++;
				sleep(1000);
			}
		}
	}
	
	private void sleep(int i) {
		// TODO �Զ����ɵķ������
		
	}
	public static List getList()
	{
		return list;
	}
	
	
}
