using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeWork_7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Student[] students = new Student[]
            {
                new Student("123456789","Tony Stark",24),
                new Student("987654321","Steve Rogers",32)
            };
            Course[] courses = new Course[]
            {
                new Course(222,"Robotics"),
                new Course(555,"Strategy")
            };
            Grades[] grages = new Grades[]
            {
                new Grades("123456789",222,100),
                new Grades("987654321",555,89),
                new Grades("123456789",555,92),
                new Grades("987654321",222,68)
            };

            int i, c = 0, max = grages[0].getCgrade();
            string id = grages[0].get_id();
            for (i = 1; i < grages.Length; i++)
            {
                if (max < grages[i].getCgrade())
                {
                    max = grages[i].getCgrade();
                    id = grages[i].get_id();
                    c = i;
                }
            }
            Console.WriteLine("student with the best grade:");
            Console.WriteLine(students[c].toString());
        }
    }
}
