// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class Surgeon extends Doctor {
    
    private boolean operating;
    public Surgeon ()
    {
        super (" ", 0, " ");
        operating = false;
    }
    
    public Surgeon (String empName, int empNumber, String special, boolean isOp)
    {
        super (empName, empNumber, special);
        operating = isOp;
    }
    
    public boolean getIsOperating()
    {
        return operating;
    }
    public void setIsOperating(boolean isO)
    {
        operating = isO;
    }
    
    public String tostring()
    {
        char OP = 'N';
        if (operating)
             OP = 'Y';
        return super.toString() + "Operating: " + OP;
    }
}
