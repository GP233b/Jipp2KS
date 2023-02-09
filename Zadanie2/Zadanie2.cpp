#include <iostream>
#include<vector>
#include<string>
using namespace std;


class Computation
{
private:
	double* result;
	int n;
public:
	Computation()
	{
		result = nullptr;
		n = 0;
	}
	Computation(double* result, int n){

		this->n = n;
		this->result = new double[n];
		for (int i = 0; i < n; i++) {
			this->result[i] = result[i];
		}

	}
	Computation(const Computation& obj) {
		this->n = obj.n;
		this->result = new double[obj.n];
		for (int i = 0; i < obj.n; i++) {
			this->result[i] = obj.result[i];
		}
	}
	~Computation(){
		if (result) {
			delete[] result;
		}
	}

	void displayResult(){
		for (int i = 0; i < n; i++){
			cout << this->result[i] << endl;
		}
	}
	
	Computation &operator=(Computation &obj) {
		if (this != &obj) {
			delete[] result;
			this->n = obj.n;
			this->result = new double[obj.n];
			for (int i = 0; i < obj.n; i++) {
				this->result[i] = obj.result[i];
			}


		}
		return *this;
	}

	double operator=(Computation* obj) {
		double pom = 0;
		for (int i = 0; i < obj->n; i++) {
			pom += obj->result[i];
		}
		return pom;
	}

	operator double() const{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += result[i];
		}
		return sum;
	}


};


int main()
{
	//nie zmieniaj funkcji main !!!
	const int n = 3;
	double result[n] = { 1.23, 4.76, 5.23 };
	Computation* comp = new Computation(result, n);
	comp->displayResult();

	Computation secondComp = Computation(result, n);
	Computation clone = secondComp;
	clone.displayResult();

	Computation thirdComp = Computation(result, n);
	Computation lastComp;
	lastComp = thirdComp;

	//dokonaj konwersji obiektu na doubla. Po konwersji niech nowa wartoœæ bêdzie sumie elementów z results
    double conversion = *comp; 
	cout << conversion << endl;
}