package hust.soict.globalict.aims.media;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class Book extends Media{
	// Instance member
	private ArrayList<String> authors = new ArrayList<String>();
	private List<String> contentTokens = new ArrayList<String>();
	private Map<String,Integer> wordFrequency = new TreeMap<String, Integer>();
	private String content;
	
	// Constructor
	public Book() {
		// TODO Auto-generated constructor stub
	}
	
	public Book (String title, String category, float cost, int id) {
		super(title, category, cost, id);
	}
	
	public Book (String title, String category, ArrayList<String> authors, int id) {
		super(title, category, id);
		this.authors = checkListAuthors(authors);
	}
	
	public Book (String title, String category, float cost) {
		super(title, category, cost);
	}
	
	// setter and getter
	public void setAuthors(ArrayList<String> authors) {
		this.authors = checkListAuthors(authors);
	}
	
	public List<String> getContentTokens() {
		return contentTokens;
	}
	
	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
		String[] tmp = content.split("[\\s\\+\\.\\(\\)\\@\\?\\{\\}\\^\\|\\$\\[\\]<>:,/*\"\\\\-]+");								// \\'\\?\\,\\_\\@]+");
		for (int i = 0; i < tmp.length; i++) {
			tmp[i] = tmp[i].toLowerCase();
			contentTokens.add(tmp[i]);
		}
		Collections.sort(contentTokens);
	}
	
	public void getWordFrequency() {
		int frequency = 0;
		int i = 0, j = 0;
		do {
			if (contentTokens.get(i).equals(contentTokens.get(j)))
			{
				frequency++;
				j++;
			}
			else
			{
				wordFrequency.put(contentTokens.get(i), frequency);
				i = j;
				frequency = 0;
			}
		} while (j < contentTokens.size());
		wordFrequency.put(contentTokens.get(j - 1), frequency);
	}
	
	@Override
	public String toString() {
		System.out.println("Content: ");
		System.out.println("\"" + getContent() + "\"");
		System.out.println("-----------------------------");
		System.out.println("Content Tokens: ");
		for (String word : contentTokens)
		{
			System.out.println(word);
		}
		System.out.println("-----------------------------");
		System.out.println("The content length: " + processContent());
		System.out.println("-----------------------------");
		System.out.println("the token list and the word frequency of the content: ");
		show();
		 return "";
	}
	
	// show the the token list and the word frequency of the content.
	public void show() {
        Set<String> keySet = wordFrequency.keySet();
        for (String key : keySet) {
            System.out.println(key + " - " + wordFrequency.get(key));
        }
    }
	
	// calculating the following information of the book content
	public int processContent() {
		return contentTokens.size();
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
