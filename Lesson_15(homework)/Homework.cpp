#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

template <typename T>
void Delete_Element(list<T>& obj)
{
	int index;
	cout << "Enter index which you want to delete:\n";
	cin >> index;
	if (obj.empty() || index<0 || index>obj.size())
	{
		throw runtime_error("Error!");
	}
	auto it = obj.begin();
	advance(it, index);
	obj.erase(it);
}

template <typename T>
void Show_Reverse(list<T>& obj)
{
	if (obj.empty())
	{
		throw runtime_error("Error!");
	}

	auto it = obj.end();
	do
	{
		it--;
		cout << *it << ' ';
	} while (it!=obj.begin());
	cout << endl;
}

int main()
{
	list<int> obj;
	try
	{
		Show_Reverse(obj);
		Delete_Element(obj);
		Show_Reverse(obj);
	}
	catch (const runtime_error& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}