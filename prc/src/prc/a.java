package prc;

import java.util.Random;

public class a {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		int i;
		String[] names= {"liu","wang","zhang"};
		for(String s:names)
			System.out.print(s+", ");
		Random rand =new Random(25);//�����ڵ����������ɵ�������޹ء�
	
		i=rand.nextInt(100);//�����ڵ����ֱ�ʾ���ɵ���������ޡ�
		System.out.println(i);
	}
	
}
