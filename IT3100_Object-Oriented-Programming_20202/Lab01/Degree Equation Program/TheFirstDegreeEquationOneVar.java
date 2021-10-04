package com.home.lab01;

import java.util.Scanner;
 
public class TheFirstDegreeEquationOneVar {
 
    public static void main(String[] args) {
        double a, b, c;
        FirstDegreeEquation1Var coefficient = new FirstDegreeEquation1Var();
        Scanner sc = new Scanner(System.in);
         
        System.out.println("a, b, c = ");
        a = sc.nextDouble();
        coefficient.setA(a);
        
        b = sc.nextDouble();
        coefficient.setB(b);
        
        c = sc.nextDouble();
        coefficient.setC(c);
        
        coefficient.ShowEquation();
        
        System.out.println(coefficient.solution());
    }	
}
