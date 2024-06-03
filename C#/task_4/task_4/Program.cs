using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // task_(1)
            int i, sign = 1;
            double sum = 0;
            for (i = 3; i <= 13; i = i + 2) 
            {
                sum += 1.0 / i * sign;
                sign *= -1;

            }
            Console.WriteLine($"sum is: {sum}");

            //task_(2)
            int j, students, sum_students = 0, count = 0;
            
            for (j = 1; j <= 7; j++)
            {
                Console.WriteLine("Enter number of students:");
                students = int.Parse(Console.ReadLine());
                sum_students += students;
                if (students > 35 )
                    count++;
            }
            Console.WriteLine($"there are {sum_students} in the 11'nth grade\nwith {count} classes with more then 35 students.");

            //task_(3)
            int k, max, borrow, total_fine = 0;
            Console.WriteLine("days borroed:");
            borrow = int.Parse(Console.ReadLine());
            max = borrow;
            for (k = 1; k <= 19; k++)
            {
                if (borrow > max)
                    max = borrow;
                if (borrow > 30 && borrow < 45)
                    total_fine += 5;
                if (borrow >= 45)
                    total_fine += 10;
                Console.WriteLine("days borroed:");
                borrow = int.Parse(Console.ReadLine());
            }
            Console.WriteLine($"longest time a book was borrowed : {max} days\ntotal of fines payed for late returns: {total_fine}NIS");
        }
    }
}
