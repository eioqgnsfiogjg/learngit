package prc;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int mutex1 = 1;
		int mutex2 = 1;
		int empty = 5;
		int full = 0;
		int in = 0,out = 0;
		int buffer_size = 5;
		int[] buffer = new int[buffer_size];
		while(true)
		{
			List<Object> list = Producer.getList();
			System.out.println("该缓冲池现在已经有"+list.size()+"缓冲区被填满");
			new Thread(new Producer(mutex1,empty,full)).start();
			new Thread(new Consumer(mutex2,empty,full)).start();
		}
	}

}
