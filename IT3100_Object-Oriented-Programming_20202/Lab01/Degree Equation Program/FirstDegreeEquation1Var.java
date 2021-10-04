package com.home.lab01;

import java.text.DecimalFormat;

public class FirstDegreeEquation1Var {
	private double a, b, c;
	
	private DecimalFormat decimalFormat = new DecimalFormat("#.###");

	public FirstDegreeEquation1Var(double a, double b, double c) {
		super();
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public FirstDegreeEquation1Var() {
		// TODO Auto-generated constructor stub
	}

	public double getA() {
		return a;
	}

	public void setA(double a) {
		this.a = a;
	}

	public double getB() {
		return b;
	}

	public void setB(double b) {
		this.b = b;
	}

	public double getC() {
		return c;
	}

	public void setC(double c) {
		this.c = c;
	}
	
	public void ShowEquation() {
		System.out.println("The First Degree Equation: " + decimalFormat.format(a) + "x + " + decimalFormat.format(b) + " = " + decimalFormat.format(c));
	}

	public String solution() {
		if (a == 0)
        	if (b == c)
        		return "the equation has countless solutions";
        	else
        		return "the equation has no solution";
        else
        	return "the equation has a solution: " + decimalFormat.format((c - b) / a);
	}
}
