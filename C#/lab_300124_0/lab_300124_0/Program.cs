using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_300124_0
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int i, j;
            for (i = 1; i <= 4; i++)
            {
                for (j = 1; j <= 4-i; j++)
                    Console.Write(" ");
                for (j = 1; j <= i; j++)
                    Console.Write(j);
                Console.WriteLine();
            }
        }
    }
}
