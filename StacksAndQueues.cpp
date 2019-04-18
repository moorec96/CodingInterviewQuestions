#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

class StackOfPlates
{
      public:
	vector<stack<int>> stacks;
	int currentStack;
	const int CAPACITY = 50;
	int size = 0;

	StackOfPlates()
	{
		currentStack = 0;
		size = 0;
	}

	void push(int val)
	{
		if (stacks[currentStack].size() == CAPACITY)
		{
			currentStack++;
		}
		if (stacks.size() == currentStack)
		{
			stack<int> st;
			stacks.push_back(st);
		}
		stacks[currentStack].push(val);
		size++;
	}

	void pop()
	{
		if (stacks[currentStack].empty())
		{
			return;
		}
		stacks[currentStack].pop();
		if (stacks[currentStack].empty() && currentStack > 0)
		{
			currentStack--;
		}
		size--;
	}

	int top()
	{
		if (size == 0)
		{
			return INT_MIN;
		}
		else
		{
			return stacks[currentStack].top();
		}
	}
}

main()
{

	return 0;
}