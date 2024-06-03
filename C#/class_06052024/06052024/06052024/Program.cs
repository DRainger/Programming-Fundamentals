using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _06052024
{
    internal class Program
    {
        public static void print(int[,] a, string n)
        {
            int i, j;
            string[] name = n.Split('@');
            for (i=0;i<a.GetLength(0);i++)
            {
                if (i < name.Length)
                    Console.Write(name[i]);
                for (j = 0; j < a.GetLength(1); j++)
                    Console.Write("\t" + a[i, j]);
                Console.WriteLine();
            }
        }
        public static int[,] Grades(string names)
        {
            int  i , j;
            string[] n = names.Split('@');
            
            int[,] arr = new int[n.Length, 10];

            for (i=0;i<arr.GetLength(0);i++)
            {
                for(j=0;j<arr.GetLength(1);j++)
                {
                    if (i < n.Length && j < n[i].Length)
                        arr[i, j] = (int)n[i][j];
                }
            }    

            return arr;
        }


        static void Main(string[] args)
        {
            string names = "John@Dany@Yakov";

            print(Grades(names),names);
        }
    }
}
