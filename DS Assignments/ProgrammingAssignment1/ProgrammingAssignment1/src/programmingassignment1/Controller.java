// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;

import java.io.FileNotFoundException;


public class Controller {
    Employee emp = new Employee();
    
    public void UCLoadData()
    {
        emp.loadData();
        System.out.println("Data loaded");
        
    }
    public void UCDisplay()
    {
        emp.displayHT();
    }
    public void UCADD()
    {
        emp.addEmployee();
    }
    public void UCRemove()
    {
        emp.removeEmployees();
    }
    public void UCSave() throws FileNotFoundException
    {
        emp.save();
    }
}
