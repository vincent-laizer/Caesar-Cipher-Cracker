## Caesar Cipher Cracker

The program prompts user to enter cipher text, ciphered using Caesar cipher algorithim, asked to choose between brute force or frequency analysis, the rest is upon the program. It will display the plain text and the key used during encryption.

The brute force option is not recommended since it will print the output of all keys that have been tried and its upon the user to look for the text that makes sense.

## Sample Run
![Uploading cracker_running.png…]()


### Functions Implemented
##### Brute force function
A loop is to be used to go through all possible keys for the given table
```
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

```

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/vincent0x1/Caesar-Cipher-Cracker/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Check out our quick video on youtube explaining this program [here](https://www.youtube.com/watch?v=rEpzBJMSOmc&t=1s).
