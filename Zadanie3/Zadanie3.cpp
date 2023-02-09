#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

namespace Zadanie3Egzamin {

	class Person
	{
	private:
		string name;
		int age;
	public:
		Person(string name, int age)
		{
			this->name = name;
			this->age = age;
		}
		string getName() {
			return name;
		}
		int getAge() {
			return age;
		}
		friend ostream& operator<<(ostream& lhs, const Person& obj) {
			return	lhs << obj.name << " " << obj.age;
		}
	};

}
using namespace Zadanie3Egzamin;

int main()
{
	vector<Person> personList = { Person("Jan",23),Person("Tomek",12) ,Person("Krzy�",50) };

	//Dodaj na koniec listy Patrycje, wiek 25
	personList.push_back(Person("Patrycja", 25));

	//Uzupe�nij klas� Person tak by poprawny by� fragment kodu
	cout << personList[0] << endl;

	//Zarezerwuj w vectorze wi�cej pami�ci, tak by pomiescic 50 osob, czujesz, 
	//�e czeka Ci� du�o oblicze�
	personList.reserve(50);

	//Wstaw poni�sze osoby do vectora personList by by�y po Janie
	vector<Person> newPerson = { Person("Adam", 33), Person("Zosia",66) };
	//personList.insert(personList.begin() + 1, newPerson.begin() , newPerson.end());

	personList.insert(personList.begin() +1, newPerson[0]);
	personList.insert(personList.begin() + 2, newPerson[1]);

	//Wy�wietl elementy korzystaj�c z iteratora

	vector<Person>::iterator IT;
	for (IT = personList.begin(); IT != personList.end(); IT++) {
		cout << *IT<<endl;
	}
	//usun z listy Krzysia
	for (IT = personList.begin(); IT != personList.end(); IT++) {
		if (IT->getName() == "Krzy�") {
			IT = personList.erase(IT);
		}
	}
	
	//posortuj elementy w vectorze po wieku, tak by najpierw byli najmlodsi, potem najstarsi
	sort(personList.begin(), personList.end(), [](Person& A, Person& B) {return A.getAge() < B.getAge(); });

	//Jeste� dobrym programist� dbaj�cym o pami��, zmniejsz odpowiednio pojemno�� twojego vectora
	personList.shrink_to_fit();


	//Co wi�cej jako dobry programista dbasz o porz�dek w kodzie i 
	//ca�y kod odpowiedzialny za klas� Person umiescisz w przestrzeni nazw Zadanie3Egzamin

	//Na koniec pracy wyczy�� ca�y vector personList by by� pusty
	personList.clear();


}