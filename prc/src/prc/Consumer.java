package prc;

import java.util.List;

public class Consumer implements Runnable {
	List<Goods> list;
	Consumer(List<Goods> list)
	{
		this.list = list;
	}
	public void run()
	{
		
		while(true)
		{	
				if(Thread.currentThread().isInterrupted())
					break;
			Goods g = null;
			Main.lock.lock();
			
	        if(list.size() >= 0) {
	        	Main.full.signalAll();//full�ź���-1
	        	try {
					Main.empty.await();//empty�ź���+1
				} catch (InterruptedException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
	        }
	        //g = list.remove(0);
	        g = list.get(0);
	        list.remove(0);
			Main.lock.unlock();
			System.out.println("�����ߣ�" + Thread.currentThread().getId() + "������" + g.getData());
			
		}

	}
}
