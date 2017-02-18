// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class Adminstrator extends HospitalEmployee {
    
    private String department;
    
    public Adminstrator ()
    {
        super ("", 0);
        department = " ";
    }
    public Adminstrator (String empName, int empNumber, String dept)
    {
        super(empName, empNumber);
        department = dept;
    }
    public void setDepartment (String dept)
    {
        department = dept;
    }
    public String getDepartment ()
    {
        return department;
    }
    public String toString()
    {
        return super.toString() + "Department: " + department + " ";
    }
    
    
}
