package prc;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
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
			System.out.println("�û���������Ѿ���"+list.size()+"������������");
			new Thread(new Producer(mutex1,empty,full)).start();
			new Thread(new Consumer(mutex2,empty,full)).start();
		}
	}

}
