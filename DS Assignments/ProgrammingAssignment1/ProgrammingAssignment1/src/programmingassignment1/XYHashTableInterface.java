/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package programmingassignment1;

/**
 *
 * @author ali
 */
public interface XYHashTableInterface 
{
    public int hash(String key);
    public void add(String key, Object obj);
    public void remove (int hashIndex, int j);
    public Object get(String key);
    public Object get(int hash, int index);

}