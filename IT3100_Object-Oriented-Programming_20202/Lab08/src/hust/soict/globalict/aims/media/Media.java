package hust.soict.globalict.aims.media;

public abstract class Media<T> implements Comparable<T>{

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
	
	public Media(String title, float cost) {
		this(title);
		this.cost = cost;
	}

	public Media(String title, String category, float cost) {
		this(title, category);
		this.cost = cost;
	}
	
	public Media(String title, String category, float cost, int id) {
		this(title, category, cost);
		this.id = id;
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
	
	public int getId() {
		return id;
	}
	
	// show information
	public abstract void information(); 

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
	
	public boolean equals(Media<T> media) {
		if (this.id == media.getId())
			return true;
		return false;
	}

	@Override
	public int compareTo(T media) {
		if (media instanceof DigitalVideoDisc && this instanceof DigitalVideoDisc)
		{
			float cost1 = this.getCost();
			return cost1 > ((DigitalVideoDisc)media).getCost() ? 1 : -1;
		}
		else
			if(media instanceof DigitalVideoDisc)
				return -1;
			else
				if (media instanceof CompactDisc && this instanceof CompactDisc)
				{
					int numberOfTrack1 = ((CompactDisc)this).getNumberOfTracks();
					int nubmerOfTrack2 = ((CompactDisc)media).getNumberOfTracks();
					if (numberOfTrack1 > nubmerOfTrack2)
						return -1;
					if (numberOfTrack1 == nubmerOfTrack2)
					{
						int length1 = ((CompactDisc)this).getLength();
						int length2 = ((CompactDisc)media).getLength();
						if (length1 > length2)
							return -1;
					}
				}
		return 0;
	}
}
