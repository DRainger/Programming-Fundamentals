using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_1
{
    internal class Program
    {
        /*--------------- (1) ---------------*/
        public static int diffUnderThree(int number)
        {
            if (number / 10 - number % 10 > 3) 
                return 0;
            return 1;
        }
        /*--------------- (1) ---------------*/
        /*--------------- (2) ---------------*/
        public static bool goodString(string str)
        {
            int i = 0;
            if (str.Contains("."))
            { 
                if (str.IndexOf(".") == 0 || str[str.Length-1] == '.')
                    return false;
                while (i < str.Length -1)
                {
                    for (; str[i] != '.' && i < str.Length - 1 ; i++) ;
                    if (i == str.Length - 1) 
                        break;
                    if (str[i] == '.' && str[i + 1] == '.')
                            return false;
                    if (i < str.Length)
                        i++;
                }
            }
            return true;
        }
        /*--------------- (2) ---------------*/
        /*--------------- (3) ---------------*/
        public static int NumConsecutiveOdd(int[] arr)
        {
            int c = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if ((arr[i] + arr[i + 1]) % 2 != 0)
                    c++;
            }

            return c;
        }
        /*--------------- (3) ---------------*/
        static void Main(string[] args)
        {
            /*--------------- (1) ---------------*/
            int[] numbers = new int[90];
            int i, c = 0;
            for (i = 0; i < numbers.Length; i++)
                numbers[i] = diffUnderThree(i+10);
            for (i = 0; i < numbers.Length; i++)
                if (numbers[i] != 0)
                {
                    Console.Write(i + 10 + " ");
                    c++;
                }
            Console.WriteLine("\namount of numbers that fit condion: " + c);
            /*--------------- (1) ---------------*/
            /*--------------- (2) ---------------*/
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(goodString("www.sport5.co.il"));
            Console.WriteLine(goodString("www.sport5..co.il"));
            Console.WriteLine(goodString(".www.sport5.co.il"));
            Console.WriteLine(goodString("www.sport5.co.il."));
            /*--------------- (2) ---------------*/
            /*--------------- (3) ---------------*/
            int[] a = new int[20];
            Random random = new Random();
            for (i=0; i<a.Length; i++)
                a[i] = random.Next(8) + 1;
            for (i=0; i<a.Length; i++)
                Console.Write(a[i] + " ");
            Console.WriteLine();
            Console.WriteLine(NumConsecutiveOdd(a));
            /*--------------- (3) ---------------*/

        }
    }
}
