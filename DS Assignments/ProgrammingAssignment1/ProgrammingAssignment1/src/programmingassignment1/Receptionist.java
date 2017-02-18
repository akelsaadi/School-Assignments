// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class Receptionist extends Adminstrator {
    private boolean answering;
    public Receptionist ()
    {
        super (" ", 0, " " );
        answering = false;
    }
    public Receptionist (String empName, int empNum, String dept, boolean ans)
    {
        super (empName, empNum, dept);
        answering = ans;
    }
    public void setIsAnswering( boolean isA)
    {
        answering = isA;
        
    }
    
    public boolean getIsAnswering()
    {
        return answering;
    }
    public String toString()
    {
        char Ans = 'N';
        if (answering)
            Ans = 'Y';
        return super.toString() + "Answering: "  + Ans;
    }
}

