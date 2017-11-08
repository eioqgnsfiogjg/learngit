package prc;

import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		
		int empty = 5,full = 0;
		int buffer_size = 5;
		int[] buffer = new int[buffer_size];
		List<Goods> list = Producer.getList();
		System.out.println("是否要清空缓存 池（Y/N）");
		Scanner a1 = new Scanner(System.in);
		String reader = a1.next();
		if(reader.equals("Y"))
			for(Goods l:list)
			{
				list.remove(l);
				Producer.count = 0;
			}
			
		Producer p = new Producer();
		Consumer c = new Consumer();
		new Thread(c).start();
		new Thread(p).start();
		
			
		
	}

}
