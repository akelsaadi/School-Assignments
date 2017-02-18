// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;


public class Doctor extends HospitalEmployee {
    private String specialty;
    
    public Doctor ()
    {
        super (" ", 0);
        specialty = " ";
    }
    public Doctor (String empName, int empNumber, String special)
    {
        super(empName, empNumber);
        specialty = special;
    }
    public void setSpecialty (String special)
    {
        specialty = special;
    }
    public String getSpecialty ()
    {
        return specialty;
    }
    
    public String toString()
    {
        return super.toString () + "Specialty: " + specialty;
    }
}
