package hust.soict.globalict.test.media;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

import hust.soict.globalict.aims.media.CompactDisc;
import hust.soict.globalict.aims.media.DigitalVideoDisc;
import hust.soict.globalict.aims.media.Media;

public class TestMediaCompareTo {
	public static void main(String[] args) {
		// instance member
		ArrayList<Media> media = new ArrayList<Media>();
		
		//add the DVD objects to the arrayList
		media.add(new DigitalVideoDisc("naruto", 5000));
		media.add(new DigitalVideoDisc("ok", 3));
		media.add(new CompactDisc("the Lion King cd", 120));
		media.add(new DigitalVideoDisc("star Wars", 101));
		media.add(new CompactDisc("amd cd", 123));
		media.add(new DigitalVideoDisc("dr.stone", 12));
		media.add(new DigitalVideoDisc("baby girls", 17));
		
		// iterate through the arrayList and output their titles
		Iterator<Media> iterator = media.iterator();
		
		System.out.println("____________________________________");
		System.out.println("The DVDs currently in the order are:");
		
		while (iterator.hasNext())
		{
			Object object = iterator.next();
			System.out.println(((Media) object).getTitle());
		}
		
		// sort
		Collections.sort(media);
		iterator = media.iterator();
		System.out.println("____________________________________");
		System.out.println("The DVDs in sorted order are:");
		while (iterator.hasNext())
		{
			Object object = iterator.next();
			System.out.println(((Media) object).getTitle());
		}
	}
}
