using System;
using System.Collections;
using System.Linq;

namespace BasicMathLib.Mathematics.Tools
{
    public class Complex
    {
        private double _real;
        private double _imaginary;
        public double Real
        {
            get { return _real; }
            set { _real = value; }
        }
        public double Imaginary
        {
            get { return _imaginary; }
            set { _imaginary = value; }
        }

        public Complex() : this(0, 0) { }
        public Complex(double real, double imaginary)
        {
            _real = real;
            _imaginary = imaginary;
        }

        public static Complex operator +(Complex left, Complex right)
        {
            Complex res = new Complex
            {
                _real = left._real + right._real,
                _imaginary = left._imaginary + right._imaginary
            };
            return res;
        }
        public static Complex operator -(Complex left, Complex right)
        {
            Complex res = new Complex
            {
                _real = left._real - right._real,
                _imaginary = left._imaginary - right._imaginary
            };
            return res;
        }
        public static Complex operator *(Complex left, Complex right)
        {
            Complex res = new Complex
            {
                _real = left._real * right._real - left._imaginary * right._imaginary,
                _imaginary = left._real * right._imaginary + left._imaginary * right._real
            };
            return res;
        }
        public static Complex operator /(Complex left, Complex right)
        {
            double temp = right._real * right._real + right._imaginary * right._imaginary;
            Complex res = new Complex
            {
                _real = (left._real * right._real + left._imaginary * right._imaginary) / temp,
                _imaginary = (left._imaginary * right._real - left._real * right._imaginary) / temp
            };
            return res;
        }
        public static Complex operator ^(Complex left, int right)
        {
            Complex res = left;
            while (--right > 0)
            {
                res *= left;
            }
            return res;
        }

        public Complex GetConjugate()
        {
            return new Complex(_real, -_imaginary);
        }
        public double GetMagnitude()
        {
            return Math.Sqrt(_real * _real + _imaginary * _imaginary);
        }
        public double GetArgument()
        {
            return Math.Atan(_imaginary / _real);
        }

        public override string ToString()
        {
            if (_imaginary == 0)
            {
                return _real.ToString();
            }
            else if (_real == 0)
            {
                return _imaginary.ToString() + 'i';
            }
            else
            {
                string RealPart = _real.ToString();
                string ImaginaryPart = (_imaginary > 0 ? '+' : null) + _imaginary.ToString() + 'i';
                return RealPart + ImaginaryPart;
            }
        }
    }

    namespace Old.Vector
    {
        public class Vector
        {
            private readonly int _dimension;
            private readonly bool _isColumnVector;
            private readonly double[] _list;

            public int Dimension
            {
                get { return _dimension; }
            }
            public double this[int index]
            {
                get { return _list[index]; }
                set { _list[index] = value; }
            }

            public Vector() : this(2, 0, true) { }
            public Vector(Vector vector)
            {
                _dimension = vector._dimension;
                _isColumnVector = vector._isColumnVector;
                _list = new double[vector._list.Length];
                Array.Copy(vector._list, _list, vector._list.Length);
            }
            public Vector(int dimension) : this(dimension, 0, true) { }
            public Vector(int dimension, double element, bool isColumnVector = true)
            {
                _dimension = dimension;
                _isColumnVector = isColumnVector;
                _list = new double[dimension];
                for (int i = 0; i < dimension; i++) _list[i] = element;
            }
            public Vector(double[] list, bool isColumnVector = true)
            {
                _dimension = list.Length;
                _isColumnVector = isColumnVector;
                _list = new double[list.Length];
                Array.Copy(list, _list, list.Length);
            }
            public Vector(bool isColumnVector, params double[] list) : this(list, isColumnVector) { }
            public Vector(IEnumerable list, bool isColumnVector = true)
            {
                int length = 0;
                foreach (double element in list) length++;
                _dimension = length;
                _isColumnVector = isColumnVector;
                int index = 0;
                _list = new double[length];
                foreach (double element in list) _list[index++] = element;
            }

            public static Vector operator +(Vector left, Vector right)
            {
                if (left._dimension != right._dimension)
                {
                    // throw
                    return new Vector();
                }
                if (!(left._dimension == 1 && right._dimension == 1) && (left._isColumnVector != right._isColumnVector))
                {
                    // throw
                    return new Vector();
                }

                Vector ans = new Vector(left);
                for (int i = 0; i < ans._dimension; i++) ans[i] += right[i];
                return ans;
            }
            public static Vector operator -(Vector left, Vector right)
            {
                if (left._dimension != right._dimension)
                {
                    // throw
                    return new Vector();
                }
                if (!(left._dimension == 1 && right._dimension == 1) && (left._isColumnVector != right._isColumnVector))
                {
                    // throw
                    return new Vector();
                }

                Vector ans = new Vector(left);
                for (int i = 0; i < ans._dimension; i++) ans[i] -= right[i];
                return ans;
            }
            public static Vector operator *(double left, Vector right)
            {
                Vector ans = new Vector(right);
                for (int i = 0; i < ans.Dimension; i++) ans[i] *= left;
                return ans;
            }
            public static Vector operator *(Vector left, double right)
            {
                Vector ans = new Vector(left);
                for (int i = 0; i < ans.Dimension; i++) ans[i] *= right;
                return ans;
            }
            public static double operator *(Vector left, Vector right)
            {
                if (left._dimension != right._dimension)
                {
                    //throw
                    return 0;
                }

                double sum = 0;
                for (int i = 0; i < left._dimension; i++)
                {
                    sum += left[i] * right[i];
                }
                return sum;
            }
            public static Vector operator /(double left, Vector right)
            {
                Vector ans = new Vector(right);
                for (int i = 0; i < ans.Dimension; i++) ans[i] /= left;
                return ans;
            }
            public static Vector operator /(Vector left, double right)
            {
                Vector ans = new Vector(left);
                for (int i = 0; i < ans.Dimension; i++) ans[i] /= right;
                return ans;
            }

            public Vector Reverse()
            {
                return new Vector(_list.Reverse(), _isColumnVector);
            }
            public Vector GetTransposition()
            {
                double[] list = new double[_dimension];
                for (int i = 0; i < _dimension; i++) list[i] = this[i];
                return new Vector(list, !_isColumnVector);
            }
            public double GetPNorm()
            {
                double[] temp = new double[_dimension];
                for (int i = 0; i < _dimension; i++) temp[i] = _list[i];
                Array.Sort(temp, (a, b) => b.CompareTo(a));
                return temp[0];
            }
            public double GetPNorm(int p)
            {
                double sum = 0;
                for (int i = 0; i < _dimension; i++)
                {
                    sum += Math.Pow(Math.Abs(_list[i]), p);
                }
                return Math.Pow(sum, 1.0 / p);
            }
            public double GetEuclideanDistance()
            {
                double sum = 0;
                for (int i = 0; i < _dimension; i++)
                {
                    sum += Math.Pow(_list[i], 2);
                }
                return Math.Sqrt(sum);
            }

            public static double Similarity(Vector a, Vector b)
            {
                return a / a.GetEuclideanDistance() * b / b.GetEuclideanDistance();
            }
            public static Vector CrossProduct(params Vector[] vectors)
            {
                bool isColumnVector = vectors[0]._isColumnVector;
                for (int i = 0; i < vectors.Length; i++)
                {
                    if (vectors[i]._dimension != vectors.Length + 1)
                    {
                        //throw
                        return new Vector();
                    }
                    if (vectors[i]._isColumnVector != isColumnVector)
                    {
                        //throw
                        return new Vector();
                    }
                }
                double[][] list = new double[vectors.Length + 1][];
                list[0] = new double[vectors.Length + 1];
                for (int i = 1; i < vectors.Length + 1; i++)
                {
                    list[i] = vectors[i - 1]._list;
                }
                Determinant resDet = new Determinant(list);
                double[] res = new double[vectors.Length + 1];
                for (int i = 0; i < vectors.Length + 1; i++)
                {
                    res[i] = resDet.GetAlgebraicCofactor(1, i + 1).Value;
                }
                return new Vector(res);
            }

            public override string ToString()
            {
                string str = "[";
                for (int i = 0; i < _dimension; i++)
                    str += _list[i].ToString() + ',';
                return str[0..^1] + ']' + (_isColumnVector ? "^T" : "");
            }
        }
        public class Matrix
        {
            private readonly int _row;
            private readonly int _column;
            private readonly double[,] _list;

            public int Row
            {
                get { return _row; }
            }
            public int Column
            {
                get { return _column; }
            }
            public double this[int row, int column]
            {
                get { return _list[row - 1, column - 1]; }
                set { _list[row - 1, column - 1] = value; }
            }

            public Matrix() : this(3, 3) { }
            public Matrix(Matrix matrix)
            {
                _row = matrix._row;
                _column = matrix._column;
                _list = new double[_row, _column];
                Array.Copy(matrix._list, _list, matrix._list.Length);
            }
            public Matrix(int row, int column, double element = 0)
            {
                _row = row;
                _column = column;
                _list = new double[row, column];
                for (int i = 0; i < _row; i++)
                {
                    for (int j = 0; j < _column; j++) _list[i, j] = element;
                }
            }
            public Matrix(double[,] list)
            {
                _row = list.GetLength(0);
                _column = list.GetLength(1);
                _list = new double[_row, _column];
                Array.Copy(list, _list, list.Length);
            }

            public static Matrix operator +(Matrix left, Matrix right)
            {
                if (!(left._row == right._row && left._column == right._column))
                {
                    //throw
                    return new Matrix();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] + right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix operator -(Matrix left, Matrix right)
            {
                if (!(left._row == right._row && left._column == right._column))
                {
                    //throw
                    return new Matrix();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] - right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix operator *(int left, Matrix right)
            {
                Matrix ans = new Matrix(right);
                for (int i = 0; i < right._row; i++)
                {
                    for (int j = 0; j < right._column; j++)
                    {
                        ans._list[i, j] *= left;
                    }
                }
                return ans;
            }
            public static Matrix operator *(Matrix left, int right)
            {
                Matrix ans = new Matrix(left);
                for (int i = 0; i < left._row; i++)
                {
                    for (int j = 0; j < left._column; j++)
                    {
                        ans._list[i, j] *= right;
                    }
                }
                return ans;
            }
            public static Matrix operator *(Matrix left, Matrix right)
            {
                if (left._column != right._row)
                {
                    // throw
                    return new Matrix();
                }

                int vectorLen = left._column;
                int row = left._row;
                int column = right._column;
                Matrix ans = new Matrix(row, column);

                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        double temp = 0;
                        for (int flag = 0; flag < vectorLen; flag++)
                        {
                            temp += left._list[i, flag] * right._list[flag, j];
                        }
                        ans._list[i, j] = temp;
                    }
                }
                return ans;
            }
            public static Matrix operator /(Matrix left, int right)
            {
                Matrix ans = new Matrix(left);
                for (int i = 0; i < left._row; i++)
                {
                    for (int j = 0; j < left._column; j++)
                    {
                        ans._list[i, j] /= right;
                    }
                }
                return ans;
            }
            public static Matrix HadamardProduct(Matrix left, Matrix right)
            {
                if (!(left._row == right._row && left._column == right._column))
                {
                    // throw
                    return new Matrix();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] * right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix KroneckerProduct(Matrix left, Matrix right)
            {
                int row = left._row * right._row;
                int column = left._column * right._column;
                int leftRowIndex = 0, leftColumnIndex = 0;
                int rightRowIndex = 0, rightColumnIndex = 0;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    if (rightRowIndex >= right._row)
                    {
                        leftRowIndex++;
                        rightRowIndex = 0;
                    }
                    for (int j = 0; j < column; j++)
                    {
                        if (rightColumnIndex >= right._column)
                        {
                            leftColumnIndex++;
                            rightColumnIndex = 0;
                        }
                        ans._list[i, j] = left._list[leftRowIndex, leftColumnIndex] * right._list[rightRowIndex, rightColumnIndex++];
                    }
                    rightRowIndex++;
                    leftColumnIndex = 0;
                    rightColumnIndex = 0;
                }
                return ans;
            }
            public static Matrix GetIdentity(int n)
            {
                Matrix matrix = new Matrix(n, n);
                for (int i = 0; i < n; i++)
                {
                    matrix._list[i, i] = 1;
                }
                return matrix;
            }

            public double GetTrace()
            {
                if (_row != _column)
                {
                    // throw
                    return 0;
                }

                double ans = 0;
                for (int i = 0; i < _row; i++)
                {
                    ans += _list[i, i];
                }
                return ans;
            }
            public Matrix GetTransposition()
            {
                double[,] list = new double[_column, _row];
                for (int i = 0; i < _column; i++)
                {
                    for (int j = 0; j < _row; j++)
                    {
                        list[i, j] = _list[j, i];
                    }
                }
                return new Matrix(list);
            }
            public Determinant GetDeterminant()
            {
                if (_row != _column)
                {
                    // throw
                    return new Determinant();
                }
                return new Determinant(_list);
            }

            public override string ToString()
            {
                string str = "";
                for (int i = 0; i < _row; i++)
                {
                    for (int j = 0; j < _column; j++)
                    {
                        str += _list[i, j].ToString() + ' ';
                    }
                    str = str[0..^1] + '\n';
                }
                return str[0..^1];
            }
        }
        public class Determinant
        {
            private readonly int _dimension;
            private readonly double[,] _det;

            public int Dimension
            {
                get { return _dimension; }
            }
            public double Value
            {
                get
                {
                    if (_dimension == 1) return _det[0, 0];
                    if (_dimension == 2) return _det[0, 0] * _det[1, 1] - _det[0, 1] * _det[1, 0];

                    double res = 0;
                    for (int i = 0; i < _dimension; i++)
                    {
                        res += (_det[0, i] * GetAlgebraicCofactor(1, i + 1).Value);
                    }
                    return res;
                }
            }
            public double this[int row, int column]
            {
                get { return _det[row - 1, column - 1]; }
                set { _det[row - 1, column - 1] = value; }
            }

            public Determinant() : this(3) { }
            public Determinant(int dimension) : this(dimension, 0) { }
            public Determinant(int dimension, double element)
            {
                _dimension = dimension;
                _det = new double[dimension, dimension];
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        _det[i, j] = element;
                    }
                }
            }
            public Determinant(double[][] list)
            {
                for (int i = 0; i < list.Length; i++)
                {
                    if (list[i].Length != list.Length)
                    {
                        // throw
                        break;
                    }
                }

                _dimension = list.Length;
                _det = new double[list.Length, list.Length];
                for (int i = 0; i < list.Length; i++)
                {
                    for (int j = 0; j < list.Length; j++)
                    {
                        _det[i, j] = list[i][j];
                    }
                }
            }
            public Determinant(double[,] list)
            {
                _dimension = (int)Math.Sqrt(list.Length);
                _det = new double[_dimension, _dimension];
                Array.Copy(list, _det, list.Length);
            }

            public Determinant GetCofactor(int i, int j)
            {
                double[,] list = new double[_dimension - 1, _dimension - 1];
                int newRow = 0;
                int newColumn = 0;
                for (int row = 0; row < _dimension; row++)
                {
                    if (row == i - 1) continue;
                    for (int column = 0; column < _dimension; column++)
                    {
                        if (column == j - 1) continue;
                        list[newRow, newColumn++] = _det[row, column];
                    }
                    newRow++;
                    newColumn = 0;
                }
                return new Determinant(list);
            }
            public Determinant GetAlgebraicCofactor(int i, int j)
            {
                double[,] list = new double[_dimension - 1, _dimension - 1];
                int newRow = 0;
                int newColumn = 0;
                for (int row = 0; row < _dimension; row++)
                {
                    if (row == i - 1) continue;
                    for (int column = 0; column < _dimension; column++)
                    {
                        if (column == j - 1) continue;
                        if (newRow == 0) list[newRow, newColumn++] = Math.Pow(-1, i + j) * _det[row, column];
                        else list[newRow, newColumn++] = _det[row, column];
                    }
                    newRow++;
                    newColumn = 0;
                }
                return new Determinant(list);
            }
            public Determinant GetTransposition()
            {
                double[,] list = new double[_dimension, _dimension];
                for (int i = 0; i < _dimension; i++)
                {
                    for (int j = 0; j < _dimension; j++)
                    {
                        list[i, j] = _det[j, i];
                    }
                }
                return new Determinant(list);
            }

            public override string ToString()
            {
                string str = "";
                for (int i = 0; i < _dimension; i++)
                {
                    for (int j = 0; j < _dimension; j++)
                    {
                        str += _det[i, j].ToString() + ' ';
                    }
                    str = str[0..^1] + '\n';
                }
                return str[0..^1];
            }
        }
    }
    namespace Vector
    {
        internal interface IVector
        {
            void Reverse();
            double GetLPNorm(int p);
            double GetLInftyNorm();
            double GetEuclideanDistance();
            string ToString();
        }
        public class Vector : IVector
        {
            protected readonly int _dimension;
            protected readonly double[] _list;

            public double this[int index]
            {
                get { return _list[index + 1]; }
                set { _list[index + 1] = value; }
            }

            protected Vector() : this(3) { }
            protected Vector(Vector vector)
            {
                _dimension = vector._dimension;
                _list = new double[vector._dimension];
                Array.Copy(vector._list, _list, vector._list.Length);
            }
            protected Vector(int dimension, double element = 0)
            {
                _dimension = dimension;
                _list = new double[dimension];
                for (int i = 0; i < dimension; i++)
                {
                    _list[i] = element;
                }
            }
            protected Vector(params double[] list)
            {
                _dimension = list.Length;
                _list = new double[list.Length];
                Array.Copy(list, _list, list.Length);
            }

            public static Vector operator +(Vector left, Vector right)
            {
                if (left._dimension != right._dimension) { return new Vector(); }
                if (left.GetType() != right.GetType()) { return new Vector(); }

                int dimension = left._dimension;
                Vector ans = left.GetType() == typeof(ColumnVector) ? new ColumnVector(dimension) : new RowVector(dimension);
                for (int i = 0; i < dimension; i++)
                {
                    ans._list[i] = (double)((decimal)left._list[i] + (decimal)right._list[i]);
                }
                return ans;
            }
            public static Vector operator -(Vector left, Vector right)
            {
                if (left._dimension != right._dimension) { return new Vector(); }
                if (left.GetType() != right.GetType()) { return new Vector(); }

                int dimension = left._dimension;
                Vector ans = left.GetType() == typeof(ColumnVector) ? new ColumnVector(dimension) : new RowVector(dimension);
                for (int i = 0; i < dimension; i++)
                {
                    ans._list[i] = (double)((decimal)left._list[i] - (decimal)right._list[i]);
                }
                return ans;
            }
            public static Vector operator *(double left, Vector right)
            {
                Vector ans = right.GetType() == typeof(ColumnVector) ? new ColumnVector(right._dimension) : new RowVector(right._dimension);
                for (int i = 0; i < ans._dimension; i++)
                {
                    ans._list[i] *= (double)(decimal)left;
                }

                return ans;
            }
            public static Vector operator *(Vector left, double right)
            {
                Vector ans = left.GetType() == typeof(ColumnVector) ? new ColumnVector(left._dimension) : new RowVector(left._dimension);
                for (int i = 0; i < ans._dimension; i++)
                {
                    ans._list[i] *= (double)(decimal)right;
                }
                return ans;
            }
            public static double operator *(Vector left, Vector right)
            {
                if (left._dimension != right._dimension) { return 0; }

                int dimension = left._dimension;
                decimal ans = 0;
                for (int i = 0; i < dimension; i++)
                {
                    ans += (decimal)(left._list[i] * right._list[i]);
                }
                return (double)ans;
            }
            public static Vector operator /(Vector left, double right)
            {
                Vector ans = left.GetType() == typeof(ColumnVector) ? new ColumnVector(left._dimension) : new RowVector(left._dimension);
                for (int i = 0; i < ans._dimension; i++)
                {
                    ans._list[i] /= (double)(decimal)right;
                }
                return ans;
            }

            public void Reverse()
            {
                IEnumerable list = _list.Reverse();
                int i = 0;
                foreach (double element in list) _list[i++] = element;
            }
            public double GetLPNorm(int p)
            {
                double ans = 0;
                for (int i = 0; i < _dimension; i++)
                {
                    ans += Math.Pow(Math.Abs(_list[i]), p);
                }
                return Math.Pow(ans, 1.0 / p);
            }
            public double GetLInftyNorm()
            {
                double[] list = new double[_dimension];
                Array.Copy(_list, list, _dimension);
                Array.Sort(list, (a, b) => b.CompareTo(a));
                return list[0];
            }
            public double GetEuclideanDistance()
            {
                double ans = 0;
                for (int i = 0; i < _dimension; i++)
                {
                    ans += Math.Pow(_list[i], 2);
                }
                return Math.Sqrt(ans);
            }

            public static double Similarity(Vector a, Vector b)
            {
                return a / a.GetEuclideanDistance() * b / b.GetEuclideanDistance();
            }
        }
        public class ColumnVector : Vector
        {
            public ColumnVector() : base() { }
            public ColumnVector(int dimension, double element = 0) : base(dimension, element) { }
            public ColumnVector(params double[] list) : base(list) { }

            public RowVector GetTransposition()
            {
                return new RowVector(_list);
            }

            public override string ToString()
            {
                string str = "[";
                for (int i = 0; i < _dimension; i++)
                    str += _list[i].ToString() + ',';
                return str[0..^1] + ']' + "^T";
            }
        }
        public class RowVector : Vector
        {
            public RowVector() : base() { }
            public RowVector(int dimension, double element = 0) : base(dimension, element) { }
            public RowVector(params double[] list) : base(list) { }

            public ColumnVector GetTransposition()
            {
                return new ColumnVector(_list);
            }

            public override string ToString()
            {
                string str = "[";
                for (int i = 0; i < _dimension; i++)
                    str += _list[i].ToString() + ',';
                return str[0..^1] + ']';
            }
        }
    }
    namespace Matrix
    {
        public class Matrix
        {
            public int _row;
            public int _column;
            public double[,] _list;

            public int Row
            {
                get { return _row; }
            }
            public int Column
            {
                get { return _column; }
            }
            public double this[int row, int column]
            {
                get { return _list[row - 1, column - 1]; }
                set { _list[row - 1, column - 1] = value; }
            }

            public Matrix() : this(2, 3) { }
            public Matrix(Matrix matrix)
            {
                _row = matrix._row;
                _column = matrix._column;
                _list = new double[matrix._row, matrix._column];
                Array.Copy(matrix._list, _list, matrix._list.Length);
            }
            public Matrix(int row, int column, double element = 0)
            {
                _row = row;
                _column = column;
                _list = new double[row, column];
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        _list[i, j] = element;
                    }
                }
            }
            public Matrix(double[,] list)
            {
                _row = list.GetLength(0);
                _column = list.GetLength(1);
                _list = new double[_row, _column];
                Array.Copy(list, _list, list.Length);
            }

            public static Matrix operator +(Matrix left, Matrix right)
            {
                if (!IsSameType(left, right))
                {
                    throw new MatrixException.RowColumnMismatchException();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] + right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix operator -(Matrix left, Matrix right)
            {
                if (!IsSameType(left, right))
                {
                    throw new MatrixException.RowColumnMismatchException();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] - right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix operator *(int left, Matrix right)
            {
                Matrix ans = new Matrix(right);
                for (int i = 0; i < right._row; i++)
                {
                    for (int j = 0; j < right._column; j++)
                    {
                        ans._list[i, j] *= left;
                    }
                }
                return ans;
            }
            public static Matrix operator *(Matrix left, int right)
            {
                Matrix ans = new Matrix(left);
                for (int i = 0; i < left._row; i++)
                {
                    for (int j = 0; j < left._column; j++)
                    {
                        ans._list[i, j] *= right;
                    }
                }
                return ans;
            }
            public static Matrix operator *(Matrix left, Matrix right)
            {
                if (left._column != right._row)
                {
                    throw new MatrixException.RowColumnMismatchException();
                }

                int vectorLen = left._column;
                int row = left._row;
                int column = right._column;
                Matrix ans = new Matrix(row, column);

                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        double temp = 0;
                        for (int flag = 0; flag < vectorLen; flag++)
                        {
                            temp += left._list[i, flag] * right._list[flag, j];
                        }
                        ans._list[i, j] = temp;
                    }
                }
                return ans;
            }
            public static Matrix operator /(Matrix left, int right)
            {
                Matrix ans = new Matrix(left);
                for (int i = 0; i < left._row; i++)
                {
                    for (int j = 0; j < left._column; j++)
                    {
                        ans._list[i, j] /= right;
                    }
                }
                return ans;
            }

            public static bool IsSameType(Matrix matrix1, Matrix matrix2)
            {
                return matrix1._row == matrix2._row && matrix1._column == matrix2._column;
            }
            public static Matrix HadamardProduct(Matrix left, Matrix right)
            {
                if (!IsSameType(left, right))
                {
                    throw new MatrixException.RowColumnMismatchException();
                }

                int row = left._row;
                int column = left._column;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        ans._list[i, j] = left._list[i, j] * right._list[i, j];
                    }
                }
                return ans;
            }
            public static Matrix KroneckerProduct(Matrix left, Matrix right)
            {
                int row = left._row * right._row;
                int column = left._column * right._column;
                int leftRowIndex = 0, leftColumnIndex = 0;
                int rightRowIndex = 0, rightColumnIndex = 0;
                Matrix ans = new Matrix(row, column);
                for (int i = 0; i < row; i++)
                {
                    if (rightRowIndex >= right._row)
                    {
                        leftRowIndex++;
                        rightRowIndex = 0;
                    }
                    for (int j = 0; j < column; j++)
                    {
                        if (rightColumnIndex >= right._column)
                        {
                            leftColumnIndex++;
                            rightColumnIndex = 0;
                        }
                        ans._list[i, j] = left._list[leftRowIndex, leftColumnIndex] * right._list[rightRowIndex, rightColumnIndex++];
                    }
                    rightRowIndex++;
                    leftColumnIndex = 0;
                    rightColumnIndex = 0;
                }
                return ans;
            }

            public bool IsSameType(Matrix matrix)
            {
                return _row == matrix._row && _column == matrix._column;
            }
            public virtual Matrix GetTransposition()
            {
                double[,] list = new double[_column, _row];
                for (int i = 0; i < _column; i++)
                {
                    for (int j = 0; j < _row; j++)
                    {
                        list[i, j] = _list[j, i];
                    }
                }
                return new Matrix(list);
            }

            public override string ToString()
            {
                string str = "";
                for (int i = 0; i < _row; i++)
                {
                    for (int j = 0; j < _column; j++)
                    {
                        str += _list[i, j].ToString() + ' ';
                    }
                    str = str[0..^1] + '\n';
                }
                return str[0..^1];
            }
        }
        public class SquareMatrix : Matrix
        {
            private readonly int _n;
            public int N
            {
                get { return _n; }
            }

            public SquareMatrix() : base(3, 3) { _n = 3; }
            public SquareMatrix(SquareMatrix matrix) : base(matrix) { _n = matrix._n; }
            public SquareMatrix(int n, double element = 0) : base(n, n, element) { _n = n; }
            public SquareMatrix(double[,] list) : base(list)
            {
                if (list.GetLength(0) != list.GetLength(1))
                {
                    throw new MatrixException.RowColumnMismatchException();
                }

                _n = list.GetLength(0);
            }

            public static SquareMatrix operator ^(SquareMatrix left, int right)
            {
                Matrix ans = new Matrix(left);
                while (--right > 0)
                {
                    ans = new Matrix(ans * left);
                }
                return new SquareMatrix(ans._list);
            }

            public static SquareMatrix GetIdentity(int n)
            {
                SquareMatrix matrix = new SquareMatrix(n);
                for (int i = 0; i < n; i++)
                {
                    matrix._list[i, i] = 1;
                }
                return matrix;
            }
            public override SquareMatrix GetTransposition()
            {
                double[,] list = new double[_column, _row];
                for (int i = 0; i < _n; i++)
                {
                    for (int j = 0; j < _n; j++)
                    {
                        list[i, j] = _list[j, i];
                    }
                }
                return new SquareMatrix(list);
            }

            public double GetTrace()
            {
                if (_row != _column) { return 0; }

                double ans = 0;
                for (int i = 0; i < _row; i++)
                {
                    ans += _list[i, i];
                }
                return ans;
            }
            public SquareMatrix GetAdjugate()
            {
                SquareMatrix ans = new SquareMatrix(_n);
                for (int i = 0; i < _n; i++)
                {
                    for (int j = 0; j < _n; j++)
                    {
                        ans._list[i, j] = GetDeterminant().GetAlgebraicCofactor(j + 1, i + 1).Value;
                    }
                }
                return ans;
            }
            public SquareMatrix GetInverse()
            {
                SquareMatrix ans = GetAdjugate();
                decimal a = (decimal)GetDeterminant().Value;
                if (a == 0) return null;

                for (int i = 0; i < _n; i++)
                {
                    for (int j = 0; j < _n; j++)
                    {
                        ans._list[i, j] /= (double)a;
                    }
                }
                return ans;
            }
            public Determinant.Determinant GetDeterminant()
            {
                return new Determinant.Determinant(_list);
            }
        }
        namespace MatrixException
        {
            public class RowColumnMismatchException : ApplicationException
            {
                public RowColumnMismatchException() : base("Row and Column mismatch!") { }
                public RowColumnMismatchException(string message) : base(message) { }
                public RowColumnMismatchException(string message, Exception inner) : base(message, inner) { }
            }
        }
    }
    namespace Determinant
    {
        public class Determinant
        {
            private readonly int _dimension;
            private readonly double[,] _list;

            public double Value
            {
                get
                {
                    if (_dimension == 1) return _list[0, 0];
                    if (_dimension == 2) return _list[0, 0] * _list[1, 1] - _list[0, 1] * _list[1, 0];

                    double res = 0;
                    for (int i = 0; i < _dimension; i++)
                    {
                        res += (_list[0, i] * GetAlgebraicCofactor(1, i + 1).Value);
                    }
                    return res;
                }
            }
            public int Dimension
            {
                get { return _dimension; }
            }
            public double this[int row, int column]
            {
                get { return _list[row - 1, column - 1]; }
                set { _list[row - 1, column - 1] = value; }
            }

            public Determinant() : this(3) { }
            public Determinant(Determinant determinant)
            {
                _dimension = determinant._dimension;
                _list = new double[determinant._dimension, determinant._dimension];
                Array.Copy(determinant._list, _list, determinant._list.Length);
            }
            public Determinant(int dimension, double element = 0)
            {
                _dimension = dimension;
                _list = new double[dimension, dimension];
                for (int i = 0; i < dimension; i++)
                {
                    for (int j = 0; j < dimension; j++)
                    {
                        _list[i, j] = element;
                    }
                }
            }
            public Determinant(double[,] list)
            {
                if (list.GetLength(0) != list.GetLength(1)) { return; }

                _dimension = list.GetLength(0);
                _list = new double[_dimension, _dimension];
                Array.Copy(list, _list, list.Length);
            }

            public Determinant GetCofactor(int i, int j)
            {
                double[,] list = new double[_dimension - 1, _dimension - 1];
                int newRow = 0;
                int newColumn = 0;
                for (int row = 0; row < _dimension; row++)
                {
                    if (row == i - 1) continue;
                    for (int column = 0; column < _dimension; column++)
                    {
                        if (column == j - 1) continue;
                        list[newRow, newColumn++] = _list[row, column];
                    }
                    newRow++;
                    newColumn = 0;
                }
                return new Determinant(list);
            }
            public Determinant GetAlgebraicCofactor(int i, int j)
            {
                double[,] list = new double[_dimension - 1, _dimension - 1];
                int newRow = 0;
                int newColumn = 0;
                for (int row = 0; row < _dimension; row++)
                {
                    if (row == i - 1) continue;
                    for (int column = 0; column < _dimension; column++)
                    {
                        if (column == j - 1) continue;
                        if (newRow == 0) list[newRow, newColumn++] = Math.Pow(-1, i + j) * _list[row, column];
                        else list[newRow, newColumn++] = _list[row, column];
                    }
                    newRow++;
                    newColumn = 0;
                }
                return new Determinant(list);
            }
            public Determinant GetTransposition()
            {
                double[,] list = new double[_dimension, _dimension];
                for (int i = 0; i < _dimension; i++)
                {
                    for (int j = 0; j < _dimension; j++)
                    {
                        list[i, j] = _list[j, i];
                    }
                }
                return new Determinant(list);
            }
            public Matrix.SquareMatrix GetMatrix()
            {
                return new Matrix.SquareMatrix(_list);
            }

            public override string ToString()
            {
                string str = "";
                for (int i = 0; i < _dimension; i++)
                {
                    for (int j = 0; j < _dimension; j++)
                    {
                        str += _list[i, j].ToString() + ' ';
                    }
                    str = str[0..^1] + '\n';
                }
                return str[0..^1];
            }
        }
    }
}