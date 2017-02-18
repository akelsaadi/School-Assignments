// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post

package programmingassignment1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Employee extends AEAList {
    
   private int totalEmployees = 0;
   
   private XYHashTable ht;
   
   public Employee()
   {
    ht = new XYHashTable();
   }
   
   
   public void loadData()
    {
        try
        {
        File file = new File("Programming Assignment 1 Data.txt");
        Scanner scanner = new Scanner (file);
        String currentPhrase;
        while (scanner.hasNext())
        {
            HospitalEmployee hospemp = new HospitalEmployee();
            Doctor doc = new Doctor();
            Surgeon surg = new Surgeon();
            Adminstrator admin = new Adminstrator();
            Janitor jan = new Janitor();
            Receptionist rec = new Receptionist();
            Nurse nurse = new Nurse();
            
            currentPhrase=(scanner.next());
            String key = scanner.next();
            if ("h".equals(currentPhrase))
            {
                hospemp.setName(key);
                int number = Integer.parseInt(scanner.next());
                hospemp.setNumber(number);
                
                ht.add(key, hospemp);
                
               // hospitalEmployees.AEadd(hospitalEmployeesCount,hospemp);
               // hospitalEmployeesCount++;
            }
            else if ("d".equals(currentPhrase))
            {                
                doc.setName(key);
                int number = Integer.parseInt(scanner.next());
                doc.setNumber(number);
                doc.setSpecialty(scanner.next());
                
                ht.add(key, doc);
                /*doctors.AEadd(doctorsCount,doc);
                doctorsCount++;*/
            }
            else if ("s".equals(currentPhrase))
            {
                surg.setName(key);
                int number = Integer.parseInt(scanner.next());
                surg.setNumber(number);
                surg.setSpecialty(scanner.next());
                String operating = scanner.next();
                if ("Y".equals(operating))
                    surg.setIsOperating(true);
                else
                    jan.setIsSweeping(false);
                ht.add(key, surg);
                
            }
            else if ("a".equals(currentPhrase))
            {
                admin.setName(key);
                int number = Integer.parseInt(scanner.next());
                admin.setNumber(number);
                admin.setDepartment(scanner.next());
                ht.add(key, admin);
                
            }
            else if ("j".equals(currentPhrase))
            {
                
                jan.setName(key);
                int number = Integer.parseInt(scanner.next());
                jan.setNumber(number);
                jan.setDepartment(scanner.next());
                
                String sweep = scanner.next();
                if ("Y".equals(sweep))
                    jan.setIsSweeping(true);
                else
                    jan.setIsSweeping(false);
                ht.add(key, jan);
                // add on the array list
            }
            else if ("r".equals(currentPhrase))
            {
                
                rec.setName(key);
                int number = Integer.parseInt(scanner.next());
                rec.setNumber(number);
                rec.setDepartment(scanner.next());
                
                String ans = scanner.next();
                if ("Y".equals(ans))
                    rec.setIsAnswering(true);
                else
                    rec.setIsAnswering(false);
                ht.add(key, rec);
                // add on the array list
            }
            else if ("n".equals(currentPhrase))
            {
                nurse.setName(key);
                int number = Integer.parseInt(scanner.next());
                nurse.setNumber(number);
                int patients = Integer.parseInt(scanner.next());
                nurse.setNumPatients(patients);
                ht.add(key, nurse);
            }
            
        }
        }
        catch (IOException e) 
        {
                e.printStackTrace();
        }
    }
   public void addEmployee()
   {
        String empType = "";
        String name = "";
        int number = 0;
        Scanner keyboard = new Scanner(System.in);
        empType = keyboard.next();
        while(!"HospitalEmployee".equals(empType) && !"Doctor".equals(empType) && !"Surgeon".equals(empType) && !"Nurse".equals(empType) && !"Adminstrator".equals(empType) && !"Receptionist".equals(empType) && !"Janitor".equals(empType)){
            System.out.print("\tERROR - Invalid entry, please enter a valid employee type: ");
            empType = keyboard.next();
        }
        System.out.print("Name: ");
        name = keyboard.next();
        
        System.out.print("Employee Number: ");
        number = keyboard.nextInt();
        
        if("HospitalEmployee".equals(empType))
        {
            HospitalEmployee newEmp = new HospitalEmployee(name, number);
            ht.add(name, newEmp);
           // hospitalEmployees.AEadd(hospitalEmployees.AEgetLength(), newEmp);
           // hospitalEmployeesCount++;
        }
            
             if("Doctor".equals(empType) || "Surgeon".equals(empType))
        {
            
            String spec = "";
            System.out.print("Specialty: ");
            spec = keyboard.next();
            
            if ("Doctor".equals(empType))
            {
                Doctor doc = new Doctor (name, number, spec);
                ht.add(name, doc);
               // doctors.AEadd(doctors.AEgetLength(), doc);
               // doctorsCount++;
            }
            
            if("Surgeon".equals(empType))
            {
                boolean OP = false;
                char OPin = ' ';
                System.out.print("Operating? (y/n): ");
                OPin = keyboard.next().charAt(0);
                while(OPin != 'y' && OPin != 'n'){
                    System.out.print("Invalid, Enter y/n");
                    OPin = keyboard.next().charAt(0);
                }
                if(OPin == 'y')
                    OP = true;
                
                Surgeon surg = new Surgeon(name, number, spec, OP);
                ht.add(name, surg);
                //surgeons.AEadd(surgeons.AEgetLength(),surg );
                //surgeonCount++;
            }
        }
        if("Nurse".equals(empType))
        {
            int patients;
            System.out.print("Patients: ");
            patients = keyboard.nextInt();
            
            Nurse nurse = new Nurse(name, number, patients);
            ht.add(name, nurse);
            /*nurses.AEadd(nurses.AEgetLength(), nurse);
            nurseCount++;*/
        }
        if("Adminstrator".equals(empType) || "Receptionist".equals(empType) || "Janitor".equals(empType))
        {
            String dept = "";
            System.out.print("Department: ");
            dept = keyboard.next();
            
            if("Adminstrator".equals(empType)){
                Adminstrator ad = new Adminstrator(name, number, dept);
                ht.add(name, ad);
            }
            
            if("Receptionist".equals(empType)){
                boolean isAns = false;
                char isAnsInput = ' ';
                System.out.print("Answering? (y/n): ");
                isAnsInput = keyboard.next().charAt(0);
                while(isAnsInput != 'y' && isAnsInput != 'n'){
                    System.out.print("Invalid Enter y or n");
                    isAnsInput = keyboard.next().charAt(0);
                }
                if(isAnsInput == 'y')
                    isAns = true;
                
                Receptionist rec = new Receptionist(name, number, dept, isAns);
                ht.add(name, rec);
            }
            
            if("Janitor".equals(empType)){
                boolean isSweep = false;
                char isSweepInput = ' ';
                System.out.print("Sweeping? (y/n): ");
                isSweepInput = keyboard.next().charAt(0);
                while(isSweepInput != 'y' && isSweepInput != 'n'){
                    System.out.print("Invalid entry, please enter \"y\" or \"n\": ");
                    isSweepInput = keyboard.next().charAt(0);
                }
                if(isSweepInput == 'y')
                    isSweep = true;
                Janitor jan = new Janitor(name, number, dept, isSweep);
                ht.add(name, jan);
            }
        }             
    }
   
   
   public void displayEmployees() 
   {
       
       System.out.println("What employee do you want to see the detials for ?? ");
       Scanner scan = new Scanner(System.in);
       String name = scan.next();
       
       
       
       
       int hashIndex = ht.hash(name); // get the hashIndex
       int count = ht.getCounts(hashIndex); // the "count" of values stored at this hashed-index
       for (int j=0; j<count; j++)
       {
           Object obj = ht.get(hashIndex, j);
           
           if (obj instanceof HospitalEmployee)
           {
               HospitalEmployee hospEmp = (HospitalEmployee) obj;
               if ( (hospEmp.getName()).equals(name) )
               {
                   // match found, display these details
                   
                   System.out.println(hospEmp.toString());
                   break;
               }
           }
           else if (obj instanceof Doctor)
           {
               Doctor doc = (Doctor) obj;
               if ( (doc.getName()).equals(name))
               {
                   
               }
           }
       }
   }
   
   public void displayHT() // full display on hashtable
   {
       System.out.println("The hospital has  the following employees : \n");
       
       
       for (int i=0; i<7; i++)
       {
           int count = ht.getCounts(i);
           System.out.println ( "Hashtable index " + i);  // the hashtable index
           for (int j=0; j<count; j++)
           {
               // inside this loop we are displaying the set of key-values (key being the name and values is the rest of the set of info
               Object obj = ht.get(i, j);
               
               if (obj instanceof HospitalEmployee)
               {
                   HospitalEmployee hospEmp = (HospitalEmployee) obj;
                   System.out.println(hospEmp.getName() + " " + hospEmp.getNumber());
               }
               else if (obj instanceof Doctor)
               {
                   Doctor doc = (Doctor) obj;
                   System.out.println(doc.getName() + " " + doc.getNumber() + " " + doc.getSpecialty() );
               }
               // other ELSE stateme4nts
           }
       }
       
       /*System.out.println("Hospital Employees: " + hospitalEmployeesCount);       
       for (int i=0; i<hospitalEmployeesCount; i++)
       {
           System.out.println( hospitalEmployees.AEget(i) );
       }
       System.out.println("Doctors: " + doctorsCount);       
       for (int i=0; i<doctorsCount; i++)
       {
           System.out.println( doctors.AEget(i) );
       }
       System.out.println("Surgeons: " + surgeonCount);       
       for (int i=0; i<surgeonCount; i++)
       {
           System.out.println( surgeons.AEget(i) );
       }
       System.out.println("Nurses: " + nurseCount);       
       for (int i=0; i<nurseCount; i++)
       {
           System.out.println( nurses.AEget(i) );
       }
        System.out.println("Adminstrators: " + adminCount);       
       for (int i=0; i<adminCount; i++)
       {
           System.out.println( administrators.AEget(i) );
       }
        System.out.println("Receptionists: " + receptionistCount);       
       for (int i=0; i<receptionistCount; i++)
       {
           System.out.println( receptionists.AEget(i) );
       }
       System.out.println("Janitors: " + janitorsCount);       
       for (int i=0; i<janitorsCount; i++)
       {
           System.out.println( janitors.AEget(i) );
       }*/
   }
   
   public void removeEmployees()
   {
       // so get the user input on name
       System.out.println("What employee do you want to remove ");
       Scanner scan = new Scanner(System.in);
       String name = scan.next();
       
       
       
       int hashIndex = ht.hash(name); // get the hashIndex
       int count = ht.getCounts(hashIndex); // the "count" of values stored at this hashed-index
       for (int j=0; j<count; j++)
       {
           Object obj = ht.get(hashIndex, j);
           
           if (obj instanceof HospitalEmployee)
           {
               HospitalEmployee hospEmp = (HospitalEmployee) obj;
               if ( (hospEmp.getName()).equals(name) )
               {               
                   
                   ht.remove(hashIndex, j);
                   break;
               }
           }
           else if (obj instanceof Doctor)
           {
               Doctor doc = (Doctor) obj;
               if ( (doc.getName()).equals(name))
               {
                   
               }
           }
       }       
       
       
        /*String empType = "";
        String name = "";
        Scanner keyboard = new Scanner(System.in);
        empType = keyboard.next();
        while(!"HospitalEmployee".equals(empType) && !"Doctor".equals(empType) && !"Surgeon".equals(empType) && !"Nurse".equals(empType) && !"Adminstrator".equals(empType) && !"Receptionist".equals(empType) && !"Janitor".equals(empType)){
            System.out.print("Invalid, Please enter a valid employee type: ");
            empType = keyboard.next();
        }
        System.out.print("Name: ");
        name = keyboard.next();       
        
        if ("HospitalEmployee".equals(empType))
        {
            for (int i=0; i<hospitalEmployeesCount; i++)
            {
                String hospEmpName = ((HospitalEmployee)hospitalEmployees.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (hospEmpName.equals(name)) // compare with the user input
                {
                    hospitalEmployees.AEremove(i);
                    hospitalEmployeesCount--;
                    break; 
                }
            }
        }
        else if ("Doctor".equals(empType))
        {
            for (int i=0; i<hospitalEmployeesCount; i++)
            {
                String doctorName = ((Doctor)doctors.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (doctorName.equals(name)) // compare with the user input
                {
                    doctors.AEremove(i);
                    doctorsCount--;
                    break; 
                }
            }
        }
        else if ("Janitor".equals(empType))
        {
            for (int i=0; i<janitorsCount; i++)
            {
                String doctorName = ((Janitor)janitors.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (doctorName.equals(name)) // compare with the user input
                {
                    janitors.AEremove(i);
                    janitorsCount--;
                    break; 
                }
            }
        }
        else if ("Nurse".equals(empType))
        {
            for (int i=0; i<nurseCount; i++)
            {
                String nursesName = ((Nurse)nurses.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (nursesName.equals(name)) // compare with the user input
                {
                    nurses.AEremove(i);
                    nurseCount--;
                    break; 
                }
            }
        }
        else if ("Adminstrator".equals(empType))
        {
            for (int i=0; i<nurseCount; i++)
            {
                String adminName = ((Nurse)administrators.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (adminName.equals(name)) // compare with the user input
                {
                    administrators.AEremove(i);
                    adminCount--;
                    break; 
                }
            }
        }
        else if ("Surgeon".equals(empType))
        {
            for (int i=0; i<nurseCount; i++)
            {
                String surgName = ((Surgeon)surgeons.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (surgName.equals(name)) // compare with the user input
                {
                    surgeons.AEremove(i);
                    surgeonCount--;
                    break; 
                }
           }
        }
        else if ("Receptionist".equals(empType))
        {
            for (int i=0; i<receptionistCount; i++)
            {
                String recepName = ((Nurse)receptionists.AEget(i)).getName(); // fetch the name from the i-th object
                
                if (recepName.equals(name)) // compare with the user input
                {
                    receptionists.AEremove(i);
                    receptionistCount--;
                    break; 
                }
            }
        }*/
        
   }
   
   /*public void save() throws FileNotFoundException
   {
       PrintWriter writer= new PrintWriter("Programming Assignment 1 Data.txt");
       
       for (int i=0; i<hospitalEmployeesCount; i++)
       {
           HospitalEmployee hp = (HospitalEmployee)hospitalEmployees.AEget(i);
           writer.println("h" + " " + hp.getName() + " " + hp.getNumber());
       }
       for (int i=0; i<adminCount; i++)
       {
           Adminstrator ad = (Adminstrator)administrators.AEget(i);
           writer.println("a" + " " + ad.getName() + " " + ad.getNumber() + " " + ad.getDepartment());
       }
       for (int i=0; i<doctorsCount; i++)
       {
           Doctor doc = (Doctor)doctors.AEget(i);
           writer.println("d" + " " + doc.getName() + " " + doc.getNumber() + " " + doc.getSpecialty());
       }
       for (int i=0; i<nurseCount; i++)
       {
           Nurse ns = (Nurse)nurses.AEget(i);
           writer.println("n" + " " + ns.getName() + " " + ns.getNumber() + " " + ns.getNumPatients());
       }
       for (int i=0; i<surgeonCount; i++)
       {
           Surgeon sg = (Surgeon)surgeons.AEget(i);
           writer.println("s" + " " + sg.getName() + " " + sg.getNumber() + " " + sg.getSpecialty() + " " + sg.getIsOperating());
       }
       for (int i=0; i<receptionistCount; i++)
       {
           Receptionist rp = (Receptionist)receptionists.AEget(i);
           char temp;
           if (rp.getIsAnswering()==true)
               temp = 'Y';
           else
               temp = 'N';
           writer.println("r" + " " + rp.getName() + " " + rp.getNumber()+ " " + rp.getDepartment() + " " + temp);
       }    
       for (int i=0; i<janitorsCount; i++)
       {
           Janitor jan = (Janitor)janitors.AEget(i);
           char temp;
           if (jan.getIsSweeping()==true)
               temp = 'Y';
           else
               temp = 'N';
           writer.println("j" + " " + jan.getName() + " " + jan.getNumber() + " " +jan.getDepartment() + " " + temp);
       }
       
       writer.close();
   }*/

}
   
