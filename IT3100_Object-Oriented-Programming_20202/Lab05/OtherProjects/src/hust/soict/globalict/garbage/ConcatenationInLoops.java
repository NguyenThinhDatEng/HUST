package hust.soict.globalict.garbage;

import java.util.Random;

public class ConcatenationInLoops {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random r = new Random(123);
		long start = System.currentTimeMillis();
		String s = "";
		for (int i = 0; i < 6; i++)
			s += r.nextInt(2);
		System.out.println(System.currentTimeMillis() - start);		//this prints roughly 4500.
			
		r = new Random(123);
		start = System.currentTimeMillis();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < Math.pow(10, 7); i++)
			sb.append(r.nextInt());
		s = sb.toString();
		System.out.println(System.currentTimeMillis() - start);	
		
		r = new Random(123);
		start = System.currentTimeMillis();
		StringBuffer sbf = new StringBuffer();
		for (long i = 0; i < Math.pow(10, 7); i++)
			sbf.append(r.nextInt());
		s = sbf.toString();
		System.out.println(System.currentTimeMillis() - start);
		
	}

}
