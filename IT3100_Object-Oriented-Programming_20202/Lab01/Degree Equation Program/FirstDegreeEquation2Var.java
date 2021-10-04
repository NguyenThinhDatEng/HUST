package com.home.lab01;

import java.text.DecimalFormat;

public class FirstDegreeEquation2Var {
	private double a, b, c;
	
	private DecimalFormat decimalFormat = new DecimalFormat("#.###");

	public FirstDegreeEquation2Var(double a, double b, double c) {
		super();
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public FirstDegreeEquation2Var() {
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
	
	public void ShowEquation(double a, double b, double c) {
		System.out.println(decimalFormat.format(a) + "x + " + decimalFormat.format(b) + "y" + " = " + decimalFormat.format(c));
	}
	
	public String solution(double a, double b, double c) {
/*		(ab' + a'b).x = cb' + c'b;
		(ab' + a'b).y = ac' + a'c;
		D = ab' + a'b;
		Dx = cb' + b'c;
		Dy = ac' + a'c;
		D.x = Dx
		D.y = Dy 
*/
		double D = this.a * b - a * this.b;
		double Dx = this.c * b - c * this.b;
		double Dy = this.a * c - a * this.c;
		
		if (D == 0)
			if (Dx != 0 || Dy != 0)
				return "the equations have no solution";
			else
				return "the equations have countless solutions";
		else
			return "the equations have a solution: (x, y) = " + "(" + decimalFormat.format(Dx / D) + ", " + decimalFormat.format(Dy / D) + ")";
	}
}
