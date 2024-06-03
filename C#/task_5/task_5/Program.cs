using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //(1)
            int grade_m, grade_e, count_pass = 0, count_flunked = 0, sum_pass = 0, sum_flunked = 0;
            Console.WriteLine("Enter your grades here:");
            grade_m = int.Parse(Console.ReadLine());
            grade_e = int.Parse(Console.ReadLine());
            while (grade_e != -1 && grade_m != -1)
            {
                if (grade_m >= 60 && grade_e >= 60)
                {
                    count_pass++;
                    sum_pass += grade_m;
                }
                else
                {
                    count_flunked++;
                    sum_flunked += grade_m;
                }
                Console.WriteLine("to end input enter: -1 -1");
                Console.WriteLine("Enter your grades here:");
                grade_m = int.Parse(Console.ReadLine());
                grade_e = int.Parse(Console.ReadLine());
            }
            Console.WriteLine($"students passed: {count_pass}\navrege grade of math tests {sum_pass/count_pass}\nstudents flunked: {count_flunked}\navrege grade of math tests {sum_flunked / count_flunked}");

            //---------------------------------------------------------------------------------------------------

            //(2)
            int i, number , sum;
            for (i = 0; i < 6; i++)
            {
                Console.WriteLine("Enter number:");
                number = int.Parse(Console.ReadLine());
                sum = 0;
                while (number != 0)
                {
                    if (number % 2 == 0)
                        sum += number % 10;
                    number /= 10;
                }
                Console.WriteLine("sum of even digits: " + sum);
            }

            //----------------------------------------------------------------------------------------------------

            //(3)
            int j, num, min_sum, max_sum, accumulativ;
            Console.WriteLine("Enter number:");
            num = int.Parse(Console.ReadLine());
            accumulativ = min_sum = max_sum = num;
            for (j = 1; j < 10; j++)
            {
                Console.WriteLine("Enter number:");
                num = int.Parse(Console.ReadLine());
                accumulativ += num;
                if (accumulativ > max_sum)
                    max_sum = accumulativ;
                else if (accumulativ < min_sum)
                    min_sum = accumulativ;
            }
            Console.WriteLine($"maximum accumulativ sum is: {max_sum}\nminimum accumulativ sum is: {min_sum}\naverege is {accumulativ/(float)j:f1}");
        }
    }
}
