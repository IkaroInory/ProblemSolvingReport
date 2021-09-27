//
//
// Author   IkaroInory
// Date     2021/9/27
//
// All the code of this course and submitted on Online Judge is open source on Github.
// Welcome to reference and verification.
//
// Online Judge
// http://10.11.219.17/JudgeOnline/
// Github Repository
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

using System;

namespace Cs
{
    public class Point
    {
        private double x;
        private double y;

        public double X
        {
            get { return x; }
            set { x = value; }
        }
        public double Y
        {
            get { return y; }
            set { y = value; }
        }

        public Point()
        {
            x = 0;
            y = 0;
        }
        public Point(double _x, double _y)
        {
            x = _x;
            y = _y;
        }
    }
    public class Circle
    {
        private Point center;
        private double radius;

        public Point Center
        {
            get { return center; }
            set { center = value; }
        }
        public double Radius
        {
            get { return radius; }
            set { radius = value; }
        }

        public Circle()
        {
            center = new Point();
            radius = 0;
        }
        public Circle(Point _o, double _r)
        {
            center = _o;
            radius = _r;
        }
        public Circle(double _x, double _y, double _r)
        {
            center = new Point(_x, _y);
            radius = _r;
        }

        public void SetCenter(Point _o)
        {
            center = _o;
        }
        public void SetCenter(double _x, double _y)
        {
            center = new Point(_x, _y);
        }
        public void SetRadius(double _r)
        {
            radius = _r;
        }
        public double GetArea()
        {
            return 3.14 * radius * radius;
        }
        public double GetLength()
        {
            return 2 * 3.14 * radius;
        }
        public bool IsContain(Point p)
        {
            return (p.X - center.X) * (p.X - center.X) + (p.Y - center.Y) * (p.Y - center.Y) <= radius;
        }
        public string IsContain_print(Point p)
        {
            return IsContain(p) ? "yes" : "no";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int ox, oy, r;
            int x, y;
            string inputData1 = Console.ReadLine();
            string inputData2 = Console.ReadLine();
            string[] iData1 = inputData1.Split(' ');
            string[] iData2 = inputData2.Split(' ');
            ox = int.Parse(iData1[0]);
            oy = int.Parse(iData1[1]);
            r = int.Parse(iData1[2]);
            x = int.Parse(iData2[0]);
            y = int.Parse(iData2[1]);

            Circle c = new Circle(ox, oy, r);
            Console.WriteLine("{0} {1}", c.GetArea(), c.GetLength());
            Console.WriteLine(c.IsContain_print(new Point(x, y)));
        }
    }
}