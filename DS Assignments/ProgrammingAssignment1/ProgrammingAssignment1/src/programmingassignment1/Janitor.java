// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;



public class Janitor extends Adminstrator{
    private boolean sweeping;
    public Janitor ()
    {
        super (" ", 0, " ");
        sweeping = false;
    }
    public Janitor (String empName, int empNum, String dept, boolean sw)
    {
        super(empName, empNum, dept);
        sweeping = sw;
    }
    public void setIsSweeping (boolean isS)
    {
        sweeping = isS;
        
    }
    public boolean getIsSweeping()
    {
        return sweeping;
    }
    public String toString()
    {
        char SW = 'N';
        if (sweeping)
            SW='T';
        return super.toString() + "Sweeping: " + SW;
    }
    
}
