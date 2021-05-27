//cracking the caesar cipher
#include <iostream>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//the table used for encryption
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', ',', ' '};

string frequencyCracker(string);
string bruteForceCracker(string, int);
map<char, float, greater<float>> computeFrequency(string);
int posMostOccurring(map<char, float, greater<float>>);

int main(){
	string line(10, '-');
	string encryptedText, decodedText;
	char choice;

	cout<<line<<"CaEsaR CrAcKeR"<<line<<endl;

	cout<<"Enter the encrypted text, lots of them"<<endl;
	getline(cin, encryptedText);

	cout<<"Brute Force (b) Frequency Analysis (f): ";
	cin>>choice;

	if(choice == 'b' || choice == 'B'){
		cout<<"Brute force cracking"<<endl;
		for(int i=0; i<sizeof(alphabet); i++){
			decodedText = bruteForceCracker(encryptedText, i);

			cout<<"Decoding with key "<<i<<endl;
			cout<<decodedText<<endl;
		}
	}
	else if(choice == 'f' || choice == 'F'){
		cout<<"Frequency Analysis Cracking"<<endl;
		decodedText = frequencyCracker(encryptedText);
		cout<<"Decoded Text:"<<endl;
		cout<<decodedText<<endl;
	}
	else{
		cout<<"Wrong option, performing frequency analysis..."<<endl;
		cout<<"Frequency Analysis Cracking"<<endl;
		decodedText = frequencyCracker(encryptedText);
		cout<<"Decoded Text:"<<endl;
		cout<<decodedText<<endl;
	}

	cin.get();
	return 0;
}

//using frequency analysis to crack the cipher text
string frequencyCracker(string cipherText){
	string plainText;
	/*
	<letter, frequency>
	fileLetterFrequency = the known relative frequency of letters of the english language
	cipherLetterFrequency = realtive frequency of letters computed from the  cipher text
	*/
	map<char, float, greater<float>> fileLetterFrequency, cipherLetterFrequency;

	//obtain values of frequency of letters in the cipher text from computing function
	cipherLetterFrequency = computeFrequency(cipherText);

	//displaying all the unique letters togather with their computed frequencies from cipher text
	for(auto elm: cipherLetterFrequency){
		cout<<elm.first<<" -> "<<elm.second<<endl;
	}

	//position of most occuring excluding blank spaces
	int pos_most_occurring = posMostOccurring(cipherLetterFrequency);
	//position of most occuring - position of e in alphabet
	int encryptionKey = pos_most_occurring - 4;

	//displaying the encryption key to user
	cout<<"Encryption key: "<<encryptionKey<<endl;

	//calling bruteForceCracker with a specific encryption key
	plainText = bruteForceCracker(cipherText, encryptionKey);

	return plainText;
}

//function to compare vector elements basing on value
bool cmp(pair<char, float>& a, pair<char, float>& b){
    return a.second > b.second;
}

//position of the second most occuring element in the cipherLetterFrequency
int posMostOccurring(map<char, float, greater<float>> letters){
	int position; //position of the second most occuring letter in the cipherText in the alphabet
	char theLetter; //the second most occuring letter
	vector<pair<char, float>> sortedLetters;

	//add all elements of map to vector
	for(auto elm: letters){
		sortedLetters.push_back(elm);
	}

	//use built in sort function std::sort()
	//STUDY MORE ON THIS
	sort(sortedLetters.begin(), sortedLetters.end(), cmp);

	//the second elemnt in the sorted vector of letter frequencies
	//for the enter the index for appropriate cracking
	int index;
	cout<<"Enter index: ";
	cin>>index;

	theLetter = sortedLetters.at(index).first;
	//cout<<endl<<"The letter is: "<<theLetter<<endl;

	for(int i=0; i<sizeof(alphabet); i++){
		if(theLetter == alphabet[i]){
			position = i;
		}
	}

	return position;
}

//compute frequency of letters in the cipher text
map<char, float, greater<float>> computeFrequency(string cipherText){
	//relative frequency of occurance
	map<char, float, greater<float>> computedFrequency;
	//frequency of unique letters
	vector<pair<char, int>> uniqueComputedFrequency;

	for(char ltr:cipherText){
		int i=0;
		for(i; i < uniqueComputedFrequency.size(); i++){
			auto elm = uniqueComputedFrequency.at(i);

			if(elm.first == ltr){
				uniqueComputedFrequency.at(i).second++;
				break;
			}
		}

		if(i == uniqueComputedFrequency.size()){
			uniqueComputedFrequency.push_back(make_pair(ltr, 1));
		}
	}

	//number of letter present in the cipher text
	int total_letters = cipherText.length();
	//relative occurance of each letter expressed in percentage
	float relative_frequency;

	for(auto elm: uniqueComputedFrequency){
		relative_frequency = ((float)elm.second/(float)total_letters)*100;
		computedFrequency.insert(make_pair(elm.first, relative_frequency));
		//cout<<elm.first<<" -> "<<elm.second<<" r.f "<<relative_frequency<<endl;
	}

	//for(auto elm:computedFrequency){ cout<<elm.first<<" -> "<<elm.second<<endl; }

	return computedFrequency;
}

//brute forcing possible key combinations to crack the cipher text
//the very same technique used in decryption but now we dont know the key used in encryption
string bruteForceCracker(string cipherText, int key){
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
