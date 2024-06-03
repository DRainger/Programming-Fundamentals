using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_2
{
    internal class Program
    {
        public static void Init(int[,] arr)
        {
            int i, j;
            Random rnd = new Random();
            for (i = 0; i < arr.GetLength(0); i++)
                for (j = 0; j < arr.GetLength(1); j++)
                    arr[i, j] = rnd.Next(-999, 1000);
        }
        public static void PRN(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                    Console.Write("\t" + arr[i, j]);
                Console.WriteLine();
            }
        }
        
        public static int SUMEven(int[,] arr)
        {
            int i, j, sum = 0;
            for (i = 0; i < arr.GetLength(0); i++)
                for (j = 0; j < arr.GetLength(1); j++)
                    if (arr[i, j] % 2 == 0)
                        sum += arr[i, j];
            return sum;
        }
        public static double AVGEven(int[,] arr)
        {
            int i, j, sum = 0, c = 0;
            for (i = 0; i < arr.GetLength(0); i++)
                for (j = 0; j < arr.GetLength(1); j++)
                    if (arr[i, j] % 2 == 0)
                    {
                        c++;
                        sum += arr[i, j];
                    }
            return sum / c * 1.0;
        }
        public static int SumMaxRow(int[,] arr)
        {
            int i, j, sum , max = 0;
            for (i = 0; i < arr.GetLength(0); i++)
            {
                sum = 0;
                for (j = 0; j < arr.GetLength(1); j++)
                    sum += arr[i, j];
                if (sum > max) 
                    max = sum;
            }
            return max;
        }
        public static void SwapRows(int[,] arr)
        {
            int i, j;
            int[] a = new int[arr.GetLength(1)];
            for (i = 0; i < arr.GetLength(1); i++)
                a[i] = arr[0,i];
            for (i = 0; i < arr.GetLength(1); i++)
            {
                arr[0, i] = arr[arr.GetLength(0) - 1, i];
                arr[arr.GetLength(0) - 1, i] = a[i];
            }
        }
        public static void ShowMaxCol(int[,] arr)
        {
            int i, j, max;
            for (i = 0; i < arr.GetLength(1); i++)
            {
                max = arr[0,i];
                for (j = 1; j < arr.GetLength(0); j++)
                    if (arr[j, i] > max)
                        max = arr[j, i];
                Console.WriteLine("col{0} --> MAX:{1}",i,max);
            }
        }
        static void Main(string[] args)
        {
            int[,] arr = new int[3, 5];
            Init(arr);
            PRN(arr);
            Console.WriteLine();
            Console.WriteLine("sum of even numbers: " + SUMEven(arr));
            Console.WriteLine();
            Console.WriteLine("avg of even numbers: " + AVGEven(arr));
            Console.WriteLine();
            Console.WriteLine("max sam of rows: " + SumMaxRow(arr)); 
            Console.WriteLine();
            SwapRows(arr);
            PRN(arr);
            Console.WriteLine();
            ShowMaxCol(arr);
        }
    }
}
