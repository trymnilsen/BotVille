using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class testClass
    {
        public int value;
        public testClass(int val)
        {
            value = val;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<testClass> testList = new List<testClass>();
            Random ran = new Random();
            for (int i = 0; i < 10; i++)
            {
                testList.Add(new testClass(ran.Next(100)));
            }
            foreach (testClass tc in testList)
            {
                Console.WriteLine(tc.value);
            }
            List<testClass> sortedList = testList.OrderBy(x => x.value).ToList();
            Console.WriteLine("SORTED:");
            foreach (testClass tc in sortedList)
            {
                Console.WriteLine(tc.value);

            }
            Console.ReadLine();
        }
    }
}
