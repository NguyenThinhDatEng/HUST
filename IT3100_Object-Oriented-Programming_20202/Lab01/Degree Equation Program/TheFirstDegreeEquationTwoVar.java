package com.home.lab01;

import java.util.Scanner;

public class TheFirstDegreeEquationTwoVar {
	public static void main(String[] args) {
		double a, b, c;
		FirstDegreeEquation2Var coefficient = new FirstDegreeEquation2Var();
		
		Scanner sc = new Scanner(System.in);
        
        System.out.println("a1, b1, c1 = ");
        a = sc.nextDouble();
        coefficient.setA(a);
        b = sc.nextDouble();
        coefficient.setB(b);
        c = sc.nextDouble();
        coefficient.setC(c);
        
        System.out.println("a2, b2, c2 = ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        
        System.out.println("The equations:");
        coefficient.ShowEquation(coefficient.getA(), coefficient.getB(), coefficient.getC());
        coefficient.ShowEquation(a, b, c);
        
        System.out.println(coefficient.solution(a, b, c));
	}
}
