#include <iostream>
#include <string>

using namespace std;

//26 letters + space = 27 characters
const int English = 27;

const string CAP_characters = " ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
const string small_characters = " abcdefghijklmnopqrstuvwxyz";

int find_inverse(int a, int language) {
    /*
    Trys to find the inverse of the key

    Paramters:
    integer a: The(a) key
    integer language: The number of letters in the language

    Returns:
    integer: The inverse of the key
    */
    for(int i = 0; i < language; i++) {
        if((a * i) % language == 1) {
            return i; 
        }
    }
    return -1;
}

int floor(double x) {
    /*
    This function calculates the floor of a number

    Parameters:
    double x: The number to calculate the floor of

    Returns:
    integer: The floor of the number
    */
    if(x >= 0) {
        return ((int)x);
    } else {
        int y = (int)x;
        return ((float)y == x) ? y : y - 1;
    }
}

int mod(int x, int y){
    /*
    This function calculates the modulus of two numbers

    Parameters:
    integer x: The first number
    integer y: The second number

    Returns:
    integer: The modulus of the two numbers
    */
    return x - (floor(((double)x/y)) * y);
}

char decode(char c, int a_inv,int b){
    /*
    This function checks weither the character is small or cap then decodes the character using the given keys a_inv and b 

    Parameters:
    char c: The character to be decoded
    integer a_inv: The inverse of the first key
    integer b: The second key

    Returns:
    char: The decoded character
     */
    int idx;
    if(c >= 'A' && c <= 'Z' || c == ' '){
            for(int i=0; i < CAP_characters.length(); i++){
                if(c == CAP_characters[i]){
                    idx = i;
                    break;
                }
            }
            return CAP_characters[mod((a_inv * (idx - b)), CAP_characters.length())];
        } 
        //if lower case
        else{
            for(int i=0; i < small_characters.length(); i++){
                if(c == small_characters[i]){
                    idx = i;
                    break;
                }
            }
            return small_characters[mod((a_inv * (idx - b)), small_characters.length())];
        }
    }


int main(){
    
    string message;
        int a;
        int b;
        string output;

        cout<<"Type the message to be deciphered:\n";
        cout<<"message: ";
        getline(cin, message);
        cout<<"\nType the keys\n";
        cout<<"a: ";
        cin >> a;
        cout<<"b: ";
        cin >> b;

        int a_inv = find_inverse(a, English);

        for (int i = 0; i < message.size(); i++){

            output += decode(message[i], a_inv, b);

        }

        cout << output;
    return 0;
}