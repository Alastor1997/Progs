
using namespace std;

class Vector
{
private:
    int size;
    double *V;
public:
    Vector(int size);
    Vector MultMatrixInVector(Matrix A); //умножение матрицы на векто
    ~Vector();
    double &operator[](int j) //перегрузка []     
    {
        return V[j];
    }
    void ShowData();
};


Vector::Vector(int size) : size(size)
{
	size = size;
    V = new double [size];
    for(int i = 0; i < size; i++)
    {
        V[i] = 0;
    }
}
Vector::~Vector()
{
    delete[] V;
};

Vector Vector::MultMatrixInVector(Matrix A)
{
    Vector result(size); //создали vector result
    for(int i=0;i<size;i++) //перемещаемся по столбцам матрицы result
        for(int j=0;j<size;j++) //индекс который меняется при умножении
            result.V[i]= result.V[i] + A.ReturnElementMatrix(i,j) * V[j];
    return result;
}

void Vector::ShowData()
{
	for(int i=0;i<size;++i)
		cout<<V[i]<<"\n";
}
