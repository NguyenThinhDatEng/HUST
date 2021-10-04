package hust.soict.globalict.test.media;

import hust.soict.globalict.aims.media.Book;

public class BookTest {
	public static void main(String[] args) {
		Book book = new Book();
		book.setContent("In a GUI program, a component must be kept in a container.");
		System.out.println(book.toString());
	}
}
