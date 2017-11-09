package prc;

import java.util.List;
import java.util.Random;

public class Producer implements Runnable {
	static List<Goods> list;
	private int len;

	Producer(List<Goods> list,int len)
	{
		this.list = list;
		this.len = len;
	}
	public void run()
	{	
		while(true)
		{
			if(Thread.currentThread().isInterrupted())
				break;
			
			Random r = new Random();
            //�����ߵ���ҵ����
			Goods g = new Goods();
            //
			g.setData(r.nextInt(100));
            Main.lock.lock();
            
            if(list.size() >= len)
            {
                Main.empty.signalAll();//empty�ź���-1
                try {
					Main.full.await();//full�ź���+1
				} catch (InterruptedException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
            }
            try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
            list.add(g);
            
            //�໺�����Ļ����
             /*
            int overbuffer = list.size() - Main.bufferSize;
            if(list.size() >= Main.bufferSize)
            {
            	for(int j = 0;j < overbuffer;j++)
            		list.remove(0);
            	continue;
            }*/
            
            Main.lock.unlock();
            System.out.println("������ID:"+Thread.currentThread().getId()+" ������:"+g.getData());
            
		}
	}
	
	
	

	
}
