package hust.soict.globalict.aims.media;

public abstract class Media {

	// attributes
		private String title;
		private String category;
		private float cost;

	// Constructor
	public Media() {
		// TODO Auto-generated constructor stub
	}
	
	public Media(String title) {
		this.title = title;
	}

	public Media(String title, String category) {
		this(title);
		this.category = category;
	}

	public Media(String title, String category, float cost) {
		this(title, category);
		this.cost = cost;
	}
	
	// setter and getter
	public String getTitle() {
		return title;
	}

	public String getCategory() {
		return category;
	}

	public float getCost() {
		return cost;
	}

	// try to find title which users are entered in system 
	public boolean search(String title)
	{
		title = title.toUpperCase();
		String[] words = getTitle().split("\\s");
		for (String word : words) {
			word = word.toUpperCase();
			if (title.indexOf(word) < 0)
			{
				return false;
			}
		}
		return true;
	}
	// show information
	public abstract void information(); 
}
