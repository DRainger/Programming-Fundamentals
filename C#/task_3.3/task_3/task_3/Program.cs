using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_3
{
    internal class Program
    {
        public static void PrintMatrix(int[,] m)
        {
            int i, j;
            for (i = 0; i < m.GetLength(0); i++)
            {
                for (j = 0; j < m.GetLength(1); j++)
                    Console.Write("\t" + m[i, j]);
                Console.WriteLine();
            }
        }
        public static void SwapNegetiv(int[,] m)
        {
            int jt, jb, ii, jj;
            for (jt = 0; jt < m.GetLength(1); jt++)
                if (m[0, jt] > 0)
                {
                    for (ii = 1; ii < m.GetLength(0) - 1; ii++)
                    {
                        for (jj = 0; jj < m.GetLength(1); jj++)
                            if (m[ii, jj] > 0)
                                break;
                        if (m[ii, jj] < 0)
                        {
                            Swap(m, ii, jj, 0, jt);
                            break;
                        }
                    }
                }

            for (jb = 0; jb < m.GetLength(1); jb++)
                if (m[m.GetLength(0) - 1, jb] > 0)
                {
                    for (ii = 1; ii < m.GetLength(0) - 1; ii++)
                    {
                        for (jj = 0; jj < m.GetLength(1) ; jj++)
                            if (m[ii, jj] > 0)
                                break;
                        if (m[ii, jj] < 0)
                        {
                            Swap(m, ii, jj, m.GetLength(0) - 1, jb);
                            break;
                        }
                    }
                }
        }
        public static void Swap(int[,] m, int ii, int jj, int i, int j)
        {
            int help;
            help = m[ii,jj];
            m[ii,jj] = m[i, j];
            m[i, j] = help;
        }
        static void Main(string[] args)
        {
            int[,] m = { { 5, -9, 2, 1 }, { 6, -7, -3, 4 }, { -99, 7, -45, -7 }, { -22, 35, -77, 14 } };
            PrintMatrix(m);
            SwapNegetiv(m);
            Console.WriteLine();
            PrintMatrix(m);

        }
    }
}
