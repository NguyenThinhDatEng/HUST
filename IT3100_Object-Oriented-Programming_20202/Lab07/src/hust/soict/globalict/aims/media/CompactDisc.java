package hust.soict.globalict.aims.media;

import java.util.ArrayList;

public class CompactDisc extends Disc implements Playable{

	// instance members
	private String artist;
	private ArrayList<Track> tracks = new ArrayList<Track>();
	
	// constructor
	public CompactDisc() {
		
	}
	
	public CompactDisc(String title, String category, String director, int length, float cost, String artist)
	{
		super(title, category, director, length, cost);
		this.artist = artist;
	}
	// getter
	public String getArtist() {
		return artist;
	}
	
	// add a track to the disc
	public void addTrack(Track track) {
		if (tracks.contains(track)) {
			System.out.println("This track already exists on the disc");
			return;
		}
		tracks.add(track);
		System.out.println(track.getTitle() + " has been added");
	}
	
	// remove a track from the disc
	public void removeTrack(Track track) {
		if (tracks.contains(track)) {
			tracks.remove(track);
			System.out.println(track.getTitle() + " has been removed");
		}
		else
			System.out.println(track.getTitle() + " is not already exists");
	}
	
	// get length of CD
	public int getLength() {
		int length = 0;
		for (Track track : tracks) {
			length += track.getLength();
		}
		return length;
	}

	@Override
	public void play() {
		// TODO Auto-generated method stub
		for (Track track : tracks) {
			track.play();
		}
	}
	
	@Override
	public void information() {
		System.out.println("CD - " +
				getTitle() +  " - " + 
				getCategory() + " - " +
				getCost() + "$" +
				getDirector() + " - " +
				getLength() + " - " +
				getArtist());
		play();
	}
}
