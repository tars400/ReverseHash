#include <bits/stdc++.h>
using namespace std;

class Hashing
{
	private:
		string letters = "acdegilmnoprstuw";
	
	public:
		long Hashit(string);
		string Reverse_Hash(long);
};

long Hashing::Hashit(string s)
{
	long h = 7;
    
    for (int i=0; i<s.length(); i++)
      	h = h * 37 + letters.find(s[i]); // Encoding the string from base 37 to base 10
    
    return h;
}

string Hashing::Reverse_Hash(long h) // converting from base 10 to base 37
{
	string res="";
	long rem;
	
	while (h>7)
	{
		rem=h%37; 			// the last letter can be found by hash%37, where character is at letters[hash%37]
      	res = letters[rem] + res; 		// adding it to the resulting string.
      	h = (h-rem)/37;		// subtracting out the addition of that last letter, we divide by 37 to find the next character.
    }
    
    if(h==7)
    	return res;
	else
	{
			cout<<"Incorrect Hashing"<<endl; 
			exit(1);
	}
}

int main() {

	Hashing H;
	
	cout<<H.Hashit("leepadg")<<endl;;  //Change the string get the required hash of it.
	cout<<H.Reverse_Hash(680131659347L)<<endl; // Change the Hash to get the string formed by letters ="acdegilmnoprstuw"

	return 0;
}