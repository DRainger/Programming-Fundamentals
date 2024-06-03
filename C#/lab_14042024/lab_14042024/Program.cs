using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace lab_14042024
{
    internal class Program
    {
        public static void Init(int[,] a)
        {
            Random rand = new Random();
            for (int i = 0; i < a.GetLength(0); i++)
                for (int j = 0; j < a.GetLength(1); j++)
                    a[i, j] = rand.Next(10);
        }

        public static void PRN(int[,] a)
        {
            for (int i = 0; i < a.GetLength(0); i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                    Console.Write("\t" + a[i, j]);
                Console.WriteLine();
            }
        }
        public static bool IsPolindrom(int[,] a)
        {
            int i, j;
            for (i = 0; i < a.GetLength(0); i++)
                for (j = 0; j < a.GetLength(1) / 2; j++)
                    if (a[i, j] != a[i, a.GetLength(1) - j - 1])
                        return false;
            return true;
        }

        public static int IsMax(int[,] a ,int x , int y)
        {
            int i, j;
            for (i = 0; i < a.GetLength(0); i++)
                if (a[x, y] < a[i, y] && i != x)
                    return 0;

            for (j = 0; j<a.GetLength(1); j++)
                if (a[x,y] < a[x, j] && j != y)
                    return 0;   

            return 1;
        }

        public static void PRNOdd(int[,] a)
        {
            int i, j;
            bool flag;
            for (j = 0; j < a.GetLength(1); j++)
            {
                flag = true;
                for (i = 0; i < a.GetLength(0); i++)
                    if (a[i, j] % 2 == 0)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                    Console.WriteLine("colomn = {0}",j + 1);
                else
                    Console.WriteLine("no odd numbers in {0}", j + 1);
            }
        }
        static void Main(string[] args)
        {
            int[,] a = new int[5, 5];//{ { 1,2,5,2,1},{ 1,2,5,2,1},{ 1,2,5,2,1},{ 1,2,5,2,1},{ 1,2,5,2,1} };
            int[,] b = new int[6, 5];
            //Init(a);
            //PRN(a);
            Init(b);
            PRN(b);
            Console.WriteLine();
            PRNOdd(b);

            //Console.WriteLine(IsPolindrom(a));

            //Console.WriteLine(IsMax(a, int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine())));




        }
    }
}
