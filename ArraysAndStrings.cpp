#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Check if  a string contains only unique letters
//===================================================================================================

//Using a set
bool isUnique(string str)
{
	unordered_set<char> set;
	for (char letter : str)
	{
		if (!set.insert(letter).second)
		{
			return false;
		}
	}
	return true;
}
//Using sorting
bool isUnique2(string str)
{
	std::sort(str.begin(), str.end());
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1])
		{
			return false;
		}
	}
	return true;
}
//===================================================================================================

//Check if the second string is a permutation of anothers string
//===================================================================================================

//Using hash map
bool isPermutation(string str1, string str2)
{
	unordered_map<char, int> mp;
	for (char letter : str1)
	{
		mp[letter]++;
	}
	for (char letter : str2)
	{
		if (mp[letter] == 0)
		{
			return false;
		}
		else
		{
			mp[letter]--;
			if (mp[letter] == 0)
			{
				mp.erase(letter);
			}
		}
	}
	return mp.size() == 0;
}
//===================================================================================================

//Replace spaces in string with "%20"
//===================================================================================================
string URLify(string str, int strSize)
{
	int strIndex = strSize - 1;
	for (int i = str.length() - 1; i >= 0 && strIndex >= 0; i--)
	{
		if (str[strIndex] == ' ')
		{
			str[i] = '0';
			str[i - 1] = '2';
			str[i - 2] = '%';
			i -= 2;
		}
		else
		{
			str[i] = str[strIndex];
		}
		strIndex--;
	}
	return str;
}
//===================================================================================================

//Is the string a permutation of a palindrome
//===================================================================================================

//Using hash map
bool isPalindromePermutation(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	unordered_map<char, int> mp;
	for (char letr : str)
	{
		char letter = tolower(letr);
		if (mp.find(letter) != mp.end())
		{
			mp[letter]--;
			if (mp[letter] == 0)
			{
				mp.erase(letter);
			}
		}
		else
		{
			mp[letter]++;
		}
	}
	if (str.length() % 2 == 0)
	{
		return mp.size() == 0;
	}
	else
	{
		return mp.size() == 1;
	}
}

//Using Bit Manipulation
int toggleBitVector(int bitVector, int index)
{
	int mask = 1 << index;
	if ((mask & bitVector) == 0)
	{
		bitVector |= mask;
	}
	else
	{
		bitVector &= ~mask;
	}
	return bitVector;
}
int createBitVector(string str)
{
	int bitVector = 0;
	for (int i = 0; i < str.length(); i++)
	{
		bitVector = toggleBitVector(bitVector, i);
	}
	return bitVector;
}
bool exactlyOneBitSet(int bitVector)
{
	return (bitVector & (bitVector - 1)) == 0;
}
bool isPalindromePermutation2(string str)
{
	int bitVector = createBitVector(str);
	return bitVector == 0 || exactlyOneBitSet(bitVector);
}

int main()
{
	//Unique letters
	/*
	string str1 = "abcdef";
	string str2 = "abcddef";
	cout << str1 << " is unique (set): " << isUnique(str1) << endl;
	cout << str2 << " is unique (set): " << isUnique(str2) << endl;
	cout << str1 << " is unique (sorting): " << isUnique2(str1) << endl;
	cout << str2 << " is unique (sorting): " << isUnique2(str2) << endl;
	*/

	//Permutation of string
	/*
	string str1 = "abc";
	string str2 = "cba";
	string str3 = "def";
	cout << "Is " << str1 << " a permutation of " << str2 << "? " << isPermutation(str1, str2) << endl;
	cout << "Is " << str1 << " a permutation of " << str3 << "? " << isPermutation(str1, str3) << endl;
	*/

	//URLify string
	/*
	string str1 = "Mr John Smith    ";
	cout << "URLify: " << URLify(str1, 13) << endl;
	*/

	//Permutation of Palindrome
	string str1 = "Tact Coa";
	string str2 = "abcdef";
	cout << str1 << " is  a permutation of a palindrome (hash map): " << isPalindromePermutation(str1) << endl;
	cout << str2 << " is a permutation of a palindrome (hash map): " << isPalindromePermutation(str2) << endl;
	cout << str1 << " is  a permutation of a palindrome (bit manipulation): " << isPalindromePermutation2(str1) << endl;
	cout << str2 << " is a permutation of a palindrome (bit manipulation): " << isPalindromePermutation2(str2) << endl;

	return 0;
}