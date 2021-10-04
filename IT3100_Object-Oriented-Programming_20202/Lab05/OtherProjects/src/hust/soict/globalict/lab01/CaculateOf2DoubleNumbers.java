package hust.soict.globalict.lab01;

import javax.swing.JOptionPane;

public class CaculateOf2DoubleNumbers {
	public static void main(String[] args) {
		String strNum1, strNum2;
		
		strNum1 = JOptionPane.showInputDialog("Please enter first number");
		double num1 = Double.parseDouble(strNum1);
		strNum2 = JOptionPane.showInputDialog("Please enter second number");
		double num2 = Double.parseDouble(strNum2);
		if (num2 != 0)
			JOptionPane.showMessageDialog(null, "sum =  " + (num1 + num2) +"\n"+ "differece = " + (num1 - num2) +"\n"+ "product = " + num1*num2 + "\n" + "quotient = " + num1/num2);
		else
			JOptionPane.showMessageDialog(null, "sum =  " + (num1 + num2) +"\n"+ "differece = " + (num1 - num2) +"\n"+ "product = " + num1*num2 + "\n" + "quotient does not exist");
	}
}
