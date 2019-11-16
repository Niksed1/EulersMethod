#include <iomanip>
#include <iostream>

double Function(double x, double y) 
{
	//any dy/dx equation
	return (x + y + x*y);
}
void Euler(double y0, double h, double a, double b) //h is a stepsize, a and b are endpoints such : (a,b]
{
	double yn = y0;
	int n = (b - a) / h;	//to find number of calculations

	double* vals;

	vals = new double[n+1]; //array to store values of x(1), x(2) etc.
	vals[0] = y0;
	int counter = 1;

	for (int t = a; t <= b; t += h)
	{
		std::cout << std::fixed << std::setprecision(3) << t << " " << yn << "\n\n";
		yn += h * Function(t, yn);	// Eulers method formula;	using Function(x,y) to calculate the values

		vals[counter] = yn; //storing resulting value in an array
		counter++;
	}
	
	std::cout << "Calculations made: "<<n<<"\n"; //on less calculation than output because 0th function is not calculated
	std::cout << "done\n\n";

	delete [] vals;
}

void main()
{
	Euler(0, 1, 0, 2);

	system("PAUSE");
}