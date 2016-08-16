using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmsAndDataStructuresCsharp
{
    public class ArraysAndStrings
    {
        public void DictionaryExample()
        {
            Console.WriteLine("-- Dictionary Example --");
            Dictionary<char, int> dict = new Dictionary<char, int>();
            dict.Add('c', 3);
            dict.Add('b', 2);
            // dict.Add('b', 3); throws exception
            dict.Add('a', 1);
            foreach (var d in dict)
            {
                Console.WriteLine(d.Key + " -- " + d.Value);
            }

            Console.WriteLine("Key 'a' value: " + dict['a']);
            Console.WriteLine("===");
        }

        public void SortedDictionaryExample()
        {
            Console.WriteLine("-- Sorted Dictionary Example --");
            SortedDictionary<char, int> dict = new SortedDictionary<char, int>();
            dict.Add('c', 3);
            dict.Add('b', 2);
            // dict.Add('b', 3); throws exception
            dict.Add('a', 1);
            foreach (var d in dict)
            {
                Console.WriteLine(d.Key + " -- " + d.Value);
            }

            Console.WriteLine("Key 'a' value: " + dict['a']);
            Console.WriteLine("===");
        }

        public void HashtableExample()
        {
            Console.WriteLine("-- Hashtable Example --");
            Hashtable dict = new Hashtable();
            dict.Add('c', 3);
            dict.Add('b', 2);
            // dict.Add('b', 3); throws exception
            dict.Add('a', 1);
            foreach (DictionaryEntry d in dict)
            {
                Console.WriteLine(d.Key + " -- " + d.Value);
            }

            Console.WriteLine("Key 'a' value: " + dict['a']);
            Console.WriteLine("===");
        }

        public void SortedHashtableExample()
        {
            Console.WriteLine("-- Sorted Hashtable Example --");
            Console.WriteLine("Does not exist ;)");
            Console.WriteLine("===");
        }

        public void ArrayListExample()
        {
            //ArrayList is pretty depreciated
            Console.WriteLine("-- ArrayList Example --");
            ArrayList array = new ArrayList() { 1, 2, "dsa", 4 };
            Console.WriteLine(array[2]);
            Console.WriteLine(array[3]);

            Console.WriteLine("--");
            List<int> betterArray = new List<int>() { 1, 2, 3, 4 };
            Console.WriteLine(betterArray[2]);
            Console.WriteLine(betterArray[3]);
        }

        public void StringBufferExample()
        {
            Console.WriteLine("-- StringBuilder Example --");
            StringBuilder builder = new StringBuilder();
            builder.Append("hehe");
            builder.Append("hehe");
            builder.Append("hehe");
            Console.WriteLine(builder.ToString());
        }

        public void TaskOne()
        {
            //string str = "123456";
            string str = "1234564";
            HashSet<char> set = new HashSet<char>();
            for (int i = 0; i < str.Length; ++i)
            {
                if (!set.Add(str[i]))
                {
                    Console.WriteLine("False");
                    return;
                }
            }
            Console.WriteLine("True");
        }
    }
}
