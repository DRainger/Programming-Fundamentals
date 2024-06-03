using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lask_4._4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            flower[] f = new flower[6];
            planting_month[] pm = new planting_month[6];
            int i, id, s, counter = 0, month;
            string n, col;
            float h;
            for (i = 0; i < f.Length; i++)
            {
                Console.WriteLine("enter flower ditails:(barcode),(name),(hight),(collor),(inventory).");
                id = int.Parse(Console.ReadLine());
                n = Console.ReadLine();
                h = float.Parse(Console.ReadLine());
                col = Console.ReadLine();
                s = int.Parse(Console.ReadLine());
                f[i] = new flower(id, n, h, col,s);
                if (h > 30 && col == "pink")
                    counter++;
            }
            for (i = 0; i < pm.Length; i++)
            {
                Console.WriteLine($"when do we plant {f[i].getfid()}-{f[i].getn()}?");
                month = int.Parse(Console.ReadLine());
                pm[i] = new planting_month(f[i].getfid(),month);
            }
            /*----------------------------------------------- B ------------------------------------------------*/
            Console.WriteLine($"we have {counter} pink flower over 30 centimeters");
            /*----------------------------------------------- E ------------------------------------------------*/
            for (i = 0;i < pm.Length; i++)
            {
                Console.WriteLine($"at month-{pm[i].getmid()} we have {f[i].getstock()} to plant.");
            }
            /*----------------------------------------------- E ------------------------------------------------*/

            /*----------------------------------------------- C ------------------------------------------------*/
            for (i = 0; i < f.Length; ++i)
            {
                Console.WriteLine($"{i + 1}.{f[i].getn()}.");
            }
            Console.WriteLine("Enter number 0-5:");
            int index = int.Parse(Console.ReadLine());
            counter = -1;
            for(i = 0; i < f.Length;i++)
            {
                if (f[i].getco() == f[index].getco())
                    counter++;
            }
            Console.WriteLine($"we have {counter} of the same collor.");
            /*----------------------------------------------- D ------------------------------------------------*/
            Console.WriteLine("we have:\n");
            for(i=0; i < f.Length; ++i)
            {
                Console.WriteLine($"{i + 1}.{f[i].getn()}.");
            }
            Console.WriteLine("which flower would you like?");
            index = int.Parse(Console.ReadLine());
            Console.WriteLine($"{f[index].getstock()} in inventory");
            Console.WriteLine("how many?");
            s = int.Parse(Console.ReadLine());
            if (f[index].getstock() - s >= 0)
            {
                Console.WriteLine("Yes!");
                f[index].setstock(s);
            }
            else { Console.WriteLine("No!"); }
            Console.WriteLine($"{f[index].getstock()} in inventory");
        }

        class flower
        {
            int fid;
            string n;
            float h;
            string co;
            int stock;

            public flower(int fid, string n, float h, string co, int stock)
            {
                this.fid = fid;
                this.n = n;
                this.h = h;
                this.co = co;
                this.stock = stock;
            }
            public int getfid() { return fid; }
            public string getn() { return n; }
            public float geth() { return h; }
            public string getco() { return co; }
            public int getstock() { return stock; }
            public void setfid(int fid) { this.fid = fid; }
            public void setn(string n) { this.n = n; }
            public void seth(float h) { this.h = h; }
            public void setco(string co) { this.co = co; }
            public void setstock(int s) { this.stock -= s; }
        }
        class planting_month
        {
            int fid;
            int mid;

            public planting_month(int fid, int mid)
            {
                this.fid = fid;
                this.mid = mid;
            }
            public int getfid() { return fid; }
            public int getmid() { return mid; }
            public void setfid(int fid) { this.fid = fid; }
            public void setmid(int mid) { this.mid = mid; }
        }
    }
}
