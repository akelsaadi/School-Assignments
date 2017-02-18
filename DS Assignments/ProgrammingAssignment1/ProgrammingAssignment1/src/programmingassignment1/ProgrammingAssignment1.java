// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post
package programmingassignment1;



import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author ali
 */
public class ProgrammingAssignment1 {

   
    public static void main(String[] args) throws FileNotFoundException {
        View v = new View();
        Controller c = new Controller();
        int choice;
        do{
            v.showOptions();
            Scanner input = new Scanner(System.in);
            choice = input.nextInt();

            switch(choice){
                case 1:
                   c.UCLoadData();
                   break;
                case 2:
                    c.UCDisplay();
                    break;
                case 3:
                    c.UCADD();
                    break;
                case 4:
                    c.UCRemove();
                    break;
                case 5:
                    c.UCSave();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Please enter a valid input");
                    break;
            }
        }while(choice !=6);
       
    }
    
}
