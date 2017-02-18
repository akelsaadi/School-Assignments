// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class Nurse extends HospitalEmployee{
    private int numPatients;
    
    public Nurse ()
    {
        super (" ", 0);
        numPatients = 0;
    }
    
    public Nurse (String empName, int empNumber, int numPat)
    {
        super (empName, empNumber);
        numPatients = numPat;
    }
    
    public void setNumPatients (int pat)
    {
        numPatients = pat;
        
    }
    
    public int getNumPatients()
    {
        return numPatients;
    }
    
    public String toString()
    {
        return super.toString() + "Number of patients: " + numPatients;
    }
}
