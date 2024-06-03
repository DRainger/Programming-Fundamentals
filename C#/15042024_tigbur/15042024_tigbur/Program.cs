using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _15042024_tigbur
{
    internal class Program
    {
        public static bool foo(int[,] a)
        {
            int sum = 0,sum1=0, i, j;
            if (a.GetLength(1) %2 == 0)
                return false;

                for (i = 0; i < a.GetLength(1); i++)
                {
                    sum = sum1 = 0;
                    for (j = 0; j < a.GetLength(0) / 2; j++)
                        sum += a[j, i];
                    for(; j < a.GetLength(0); j++)
                        sum1 += a[j, i];
                    if (sum != sum1)
                        return false;
                }
            return true;
        }
        static void Main(string[] args)
        {
            //int[] plays = new int[15];
            //int play, tickits, sum = 0;
            
            //play = int.Parse(Console.ReadLine());
            //tickits = int.Parse(Console.ReadLine());
            //while (play != 0 || tickits != 0)
            //{
            //    plays[play - 1] += tickits;
            //    sum += tickits;
            //    play = int.Parse(Console.ReadLine());
            //    tickits = int.Parse(Console.ReadLine());
            //}
            //Console.WriteLine("total tikets:"+sum);
            //for (int i = 0; i < plays.Length; i++)
            //    if (plays[i] != 0) 
            //        Console.WriteLine("play :{0} -> tikets: {1} - {2:f2}%", i + 1, plays[i], (plays[i] * 100.0)/sum);


        }
    }
}
