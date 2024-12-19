#include <iostream>
#include <string>

using namespace std;

string cipherEncoding(string str, int a, int b);

int main()
{

  string str = "IS TOIL LEAM MO BHEATHA"; // Text to be Ciphered
  int a = 7, b = 5;                       // Affine Cipher keys

  cout << "The Encrypted text is : \"" << cipherEncoding(str, a, b) << "\"" << endl; // Calling cipherEncoding function to see the output

  return 0;
}

string cipherEncoding(string str, int a, int b)
{
  int n = 19;           // number of letters
  char alphabet[19] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U'}; // The Scottish Gaelic Alphabet
  string encoded = "";  // string to store the encrypted text

  for (int i = 0; i < str.length(); i++)
  {
    char c = str[i]; // extracting text letter by letter
    int index = -1;

    for (int j = 0; j < 18; j++)
    {
      if (c == alphabet[j])
      {
        index = j; // finding the index of each letter
        break;
      }
    }

    int encrebtedValue = (index * a + b) % n;     // calculateing the encrypted char
    encoded = encoded + alphabet[encrebtedValue]; // storing the encrypted text letter by letter
  }

  return encoded;
};
