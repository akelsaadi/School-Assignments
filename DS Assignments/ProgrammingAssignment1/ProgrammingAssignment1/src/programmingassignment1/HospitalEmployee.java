// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class HospitalEmployee {
    
    private String name;
    private int number;
    
    public HospitalEmployee ()
    {
        name = "";
        number = 0;
    }
    public HospitalEmployee (String empName, int empNumber)
    {
        name = empName;
        number = empNumber;
    }
    public void setName (String empName)
    {
        name = empName;
    }
    public void setNumber (int empNumber)
    {
        number = empNumber;
    }
    public String getName()
    {
        return name;
    }
    public int getNumber()
    {
        return number;
    }
    
    public String toString()
    {
        return "Name: " + name + " " +"Employee Number: " + number + " ";
    }
             
}
