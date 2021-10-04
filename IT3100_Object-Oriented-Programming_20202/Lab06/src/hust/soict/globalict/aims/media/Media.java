package hust.soict.globalict.aims.media;

public class Media {

	// attributes
		private String title;
		private String category;
		private float cost;
		private int id;

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
	
	public Media(String title, String category, float cost, int id)
	{
		this(title, category, cost);
		this.id = id;
	}
	
	// setter and getter
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

	public float getCost() {
		return cost;
	}

	public void setCost(float cost) {
		this.cost = cost;
	}
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
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

}
