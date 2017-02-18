// COSC 2320 Summer 2015
// Ali Elsaadi
// Progamming Assignment 1
// This is my own work; I will not post

package programmingassignment1;


public class AEAList implements EAListInterface {
    private int size = 10;
    private int length = 0;
    Object data [] = new Object[10];
    
    public AEAList(){}
    
    AEAList(int size)
    {
        length = 0;
        this.size = size;
        data = new Object[size];
    }
    
    public void AEadd(int index, Object data)
    {
        if(size == length)
            System.out.println("Full");
        else
        {
            for(int i = length-1; i >= index; i--)
                this.data[i] = this.data[i-1];
        this.data[index] = data;
        length++;
        }
    }
    
    public void AEremove(int index)
    {
        // say we have the size as 3 : indexes 0,1,2
        // say index we are removing is 1
        for (int i=index; i<size-1; i++)
        {
            this.data[i] = this.data[i+1];
        }
        size--;
    }
    
    public Object AEget(int index){
        if(index >= length){
            System.out.println("\tERROR - That entry does not exist.");
            return null;
        }
        else
            return data[index];
    }
    
    public int AEgetLength(){
        return length;
    }

    
    public int AEgetSize()
    {
        return size;
    }
    
}
