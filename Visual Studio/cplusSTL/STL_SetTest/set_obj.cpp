#include <iostream>
#include <set>
#include <string>

using namespace std;

class Todo
{
public:

	int _priority;
	string _food;

	Todo(int p,string j) : _priority(p), _food(j) {}
	
	bool operator<(const Todo& t)
	{
		return _priority > t._priority;
	}
};

template <typename T>
void Print_set(set<T>& s) 
{
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr  )
	{
		cout << *itr;
	}
}

std::ostream& operator<<(ostream& out, const Todo& s)
{
	out << s._priority << "," << s._food << endl;
	return out;
}


int main()
{
	set<Todo> Todos;

	Todos.insert(Todo(1, "짜장면"));
	Todos.insert(Todo(2, "라면"));
	Todos.insert(Todo(3, "치킨"));
	Todos.insert(Todo(4, "탕수육"));

}