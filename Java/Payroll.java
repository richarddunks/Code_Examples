package payroll;

/*
 * This program calculates state and federal tax withholding based on user input
 * based on an exercise in Java Programs to Accompany Programming Logic 
 * and Design, 2nd Edition by Jo Ann Smith. All code is self-generated to meet
 * parameters outlined in the exercise.
 */


import javax.swing.JOptionPane;

public class Payroll {

    public static void main(String[] args) {
        String grossSalaryString, numberDependentString;
        double grossSalary, federalTax, stateTax, dependentDeduction, totalWithholding, netSalary;
        int numberDependent;
        
        //Input Gross Salary
        grossSalaryString = JOptionPane.showInputDialog("Enter Gross Salary:");
        //Input number of Dependents
        numberDependentString = JOptionPane.showInputDialog("Enter the number of dependents:");
        //Convert salary string to double
        grossSalary = Double.parseDouble(grossSalaryString);
        //Convert dependent string to double
        numberDependent = Integer.parseInt(numberDependentString);
        //Calculate federal tax
        federalTax = grossSalary * 0.32;
        //Calculate state tax
        stateTax = grossSalary * 0.07;
        //Calculate dependent deduction
        dependentDeduction = (numberDependent * 0.04) * grossSalary;
        //Calculate total withholding
        totalWithholding = federalTax + stateTax - dependentDeduction;
        //Calculate net salary
        netSalary = grossSalary - totalWithholding;
        //Print out result
        System.out.println("State Tax: $" + stateTax);
        System.out.println("Federal Tax: $" + federalTax);
        System.out.println("Dependents: $" + dependentDeduction);
        System.out.println("Salary: $" + grossSalary);
        System.out.println("Take-Home Pay: $" + netSalary);
        System.exit(0);
        
    }
}
