package programmingassignment1;

public class XYHashTable implements XYHashTableInterface
{
    private AEAList[] table; // as we are going to do "chaining" on each of the key index
    private int[] counts;
    
    
    public XYHashTable()
    {
        counts = new int[7];
        //for (int i=0; i<7; i++) counts[i]=0;
        table  = new AEAList[7]; //  setting up the array 
        
        for (int i=0; i<7; i++) // initialize 7 indexes on the "table" array
        {
            table[i] = new AEAList(5);
        }
    }
    
    
    public int hash(String key) {
        
        int hashVal = 0;

        for (int i = 0; i < key.length(); i++) {
            hashVal = 37 * hashVal + key.charAt(i);
        }

        hashVal %= 7;
        if (hashVal < 0) {
            hashVal += 7;
        }

        return hashVal;
    }
    
    public void add(String key, Object obj)
    {
        // get hash index
        int hashIndex = hash(key);        
        
        // add to the hash table

            table[hashIndex].AEadd( counts[hashIndex], obj);

        counts[hashIndex]++;
    }
    
    public void remove (int hashIndex, int j)
    {
     
                table[hashIndex].AEremove(j);
                counts[hashIndex]--;

        
    }
    
    public Object get(String key)
    {
        int hashIndex = hash(key);
        
        for (int i=0; i<counts[hashIndex]; i++)
        {
            String currentName = ((HospitalEmployee)table[hashIndex].AEget(i)).getName();
            
            if (currentName.equals(key))
            {
                 
                return table[hashIndex].AEget(i);
            }
        }
        // at the end of the loop, if no found match
        return null;
    }
    
    public int getCounts(int hash)
    {
        return counts[hash];
    }
    
    public Object get(int hash, int index)
    {
        return table[hash].AEget(index);
    }
}