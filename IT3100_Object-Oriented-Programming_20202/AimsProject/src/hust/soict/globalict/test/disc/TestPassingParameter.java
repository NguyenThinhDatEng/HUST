package hust.soict.globalict.test.disc;

import hust.soict.globalict.aims.media.DigitalVideoDisc;

public class TestPassingParameter {
	public static void main(String[] args) {
		DigitalVideoDisc jungleDVD = new DigitalVideoDisc("Jungle", 10);
		DigitalVideoDisc cinderyllaDVD = new DigitalVideoDisc("Cinderella", 12);
		
		swap(jungleDVD, cinderyllaDVD);
		System.out.println("Jungle dvd title: " + jungleDVD.getTitle());
		System.out.println("Cinderella dvd title: " + cinderyllaDVD.getTitle());
		
		changeTitle(jungleDVD, cinderyllaDVD.getTitle());
		System.out.println("jungle dvd title: " + jungleDVD.getTitle());
	}
	
	public static void swap(DigitalVideoDisc dvd1, DigitalVideoDisc dvd2) {
		String tmp = dvd1.getTitle();
		//dvd1.setTitle(dvd2.getTitle());
		//dvd2.setTitle(tmp);
	}
	
	public static void swap(Object o1, Object o2) {
		Object tmp = o1;
		o1 = o2;
		o2 = tmp;
	}
	
	public static void changeTitle(DigitalVideoDisc dvd, String title) {
		String oldTitle = dvd.getTitle();
		//dvd.setTitle(oldTitle);
		dvd = new DigitalVideoDisc(oldTitle, 20);
	}
}

// Java is always a pass by value programming language
