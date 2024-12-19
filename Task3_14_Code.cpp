#include <iostream>
#include <string>


using namespace std;

string cipherEncoding (string str);

int main(){

  string str = "IS TOIL LEAM MO BHEATHA";

  cout <<"The Encrypted text is : \""<< cipherEncoding(str)<<"\"" << endl;
  
  return 0;
}  


string cipherEncoding (string str){
  int a =7 , b=5 , n=18;
  char alphabet[18] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U'};
  string encoded="";

  for (int i = 0; i < str.length() ; i++){
    if (str[i]==' ')
    {
      encoded+=" ";
      continue;
    }

    char c = str[i];
    int index = -1;

    for (int j = 0; j < 18; j++){
      if(c == alphabet[j]){
        index = j;
        break;
      }
    }
    int encrebtedValue = (index*a+b)%n;
    encoded = encoded + alphabet[encrebtedValue];
    }

    return encoded;
};
