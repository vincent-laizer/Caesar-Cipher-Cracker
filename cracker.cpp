//Ceaser cipher C++ implementation
/*

CLASSICAL CIPHER ALGORITHM
 * The Caesar cipher
involves replacing each letter of the alphabet with the 
letter standing k places further down the alphabet, for k 
in the range 1 through 25.

*/
#include <iostream>

using namespace std;
//all characters we'll use
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
					'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', ',', ' '};

//function to encrypt the text
string encode(string plainText, int key=3){
	string cipherText;
	int value;
	for(int i=0; i< plainText.length(); i++){
		for(int j=0; j<sizeof(alphabet); j++){

			/*
			find the position of the letter in the alphabet array, compute its modulus value
			and finding the letter at the position of the modulus
			*/
			if( alphabet[j] == plainText[i]){
				value = (j+key)%sizeof(alphabet);
				cipherText = cipherText + alphabet[value];
			}
			
		}
	}
	return cipherText;
}

string decode(string cipherText, int key=3){
	string plainText;
	int value;
	for(int i=0; i< cipherText.length(); i++){
		for(int j=0; j<sizeof(alphabet); j++){
			
			if( alphabet[j] == cipherText[i] ){
				
				value = j-key;
				if(value < 0){
					value = value + sizeof(alphabet);
				}
				else{
					value = (j-key)%sizeof(alphabet);
				}
				
				plainText = plainText + alphabet[value];
			}
			
		}
	}
	return plainText;	
}

int main(){
	string cipherText, plainText, decodedText;
	unsigned long int key;
	
	cout<<"Enter Your message"<<endl;
	getline(cin, plainText);
	
	cout<<"Enter encryption key: ";
	cin>>key;
	
	key = key%sizeof(alphabet);
	
	cout<<endl;
	
	cipherText = encode(plainText, key);
	cout<<"Encrypted message: \n"<<cipherText<<endl<<endl;
	
	cout<<"Original message:"<<endl;
	decodedText = decode(cipherText, key);
	cout<<decodedText<<endl;
	
	return 0;
}
