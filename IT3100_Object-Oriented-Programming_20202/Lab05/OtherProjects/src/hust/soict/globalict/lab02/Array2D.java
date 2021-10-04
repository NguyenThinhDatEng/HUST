package hust.soict.globalict.lab02;
import java.util.*;

class Array2D	{
	private int rows;
	private int columns;
	Scanner sc = new Scanner(System.in);
	
	public Array2D(int rows, int columns) {
		super();
		this.rows = rows;
		this.columns = columns;
	}
	
	public int getRows() {
		return rows;
	}

	public int getColumns() {
		return columns;
	}

	public int[][] initializeArr(int[][] array) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
			{
				array[i][j] = sc.nextInt();
			}
		return array;
	}
	
	public int[][] add2Matrices(int[][] a, int[][] b){
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
			{
				a[i][j] += b[i][j]; 
			}
		return a;
	}
	
	public void showArray2D(int [][] a)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println("");
		}
	}
}