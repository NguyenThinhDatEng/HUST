package hust.soict.globalict.aims.media;

import java.util.ArrayList;

public class Book extends Media{
	// Instance member
	private ArrayList<String> authors = new ArrayList<String>();
	
	// Constructor
	public Book() {
		// TODO Auto-generated constructor stub
	}
	
	public Book(String title) {
		super(title);
	}
	
	public Book (String title, String category) {
		super(title, category);
	}
	
	public Book (String title, String category, ArrayList<String> authors) {
		super(title, category);
		this.authors = checkListAuthors(authors);
	}
	
	public Book (String title, String category, float cost) {
		super(title, category, cost);
	}
	
	// setter and getter
	public void setAuthors(ArrayList<String> authors) {
		this.authors = checkListAuthors(authors);
	}
	
	// add an author for the book
	public void addAuthor(String authorName)
	{
		if (authors.contains(authorName))
		{
			System.out.println("The author is already exists");
		}
		else
			{
				authors.add(authorName);
				System.out.println("The author has been added");
			}
	}
	
	// remove an author for the book
	public void removeAuthor(String authorName)
	{
		if (authors.contains(authorName))
		{
			authors.remove(authorName);
			System.out.println("The author has been removed");
		}
		else
		{
			System.out.println("The author is not already exists");
		}
	}
	
	// return an ArrayList of no 2 authors with the same name
	public ArrayList<String> checkListAuthors(ArrayList<String> authors)
	{
		for (int i = 0; i < authors.size() - 1; i++)
		{
			for (int j = i + 1; j < authors.size(); j++)
			{
				if (authors.get(j).equals(authors.get(i)))
					authors.remove(j);
			}
		}
		return authors;
	}
	
	@Override
	public void information() {
		System.out.print( 	"Book - " +
							getTitle() +  " - " + 
							getCategory() + " - " +
							getCost() + "$");
		System.out.print("   By: ");
		int nbAuthors = authors.size();
		for (String author : authors)
		{
			System.out.print(author);
			if (!author.equals(authors.get(nbAuthors - 1)))
			{
				System.out.print(", ");
			}
		}
		System.out.println("");
	}
}
