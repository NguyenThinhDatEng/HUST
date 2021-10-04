package com.home.lab02;

public class AddTwoMatrices {
	public static void main(String[] args) {
		Array2D arr = new Array2D(3, 2);
		int[][] a = new int[arr.getRows()][arr.getColumns()];
		int[][] b = new int[arr.getRows()][arr.getColumns()];
		
		a = arr.initializeArr(a);
		arr.showArray2D(a);
		
		b = arr.initializeArr(b);
		arr.showArray2D(b);
		
		a = arr.add2Matrices(a, b);
		System.out.println();
		arr.showArray2D(a);
	}
}
