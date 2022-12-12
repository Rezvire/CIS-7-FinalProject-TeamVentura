#include <iostream>
#include <vector>
#include <string>

using namespace std;

	//Geberates key based on user input in main
	string genKey(string str, string key)
	{
		int z = str.size();

		for (int i = 0; ; i++)
		{
			if (z == i)
				i = 0;
			if (key.size() == str.size())
				break;
			key.push_back(key[i]);
		}
		return key;
	}

	//Encrypts text inputted by user
	string encryptedText(string str, string key)
	{		
		string encrypted_text;

		//For loops goes through all letters of message to switch them depening on key provided, letter by letter.
		for (int i = 0; i < str.size(); i++)
		{
			char z = (str[i] + key[i]) % 26;

			z += 'A';

			encrypted_text.push_back(z);
		}
		return encrypted_text;
	}

	//Decrypts text inputted by user
	string decryptText(string encrypted_text, string key)
	{
		string orig_text;

		//Same as encrypting but instead goes backwards to get original message.
		for (int i = 0; i < encrypted_text.size(); i++)
		{
			char z = (encrypted_text[i] - key[i] + 26) % 26;

			z += 'A';
			orig_text.push_back(z);
		}
		return orig_text;
	}

	int main()
	{
		//While loop keeps program running until user quits		
		while (1)
		{

			int choice;
		
			//User is asked to encrypt, decrypt, or end the program.
			cout << "Choose an Option Below." << endl;
			cout << "1) Encrypt" << endl;
			cout << "2) Decrypt" << endl;
			cout << "3) End Program" << endl << endl;
			cout << "Input: ";

			//User inputs choice
			cin >> choice;
			cout << endl;

			//Choice '1' encrypts message
			if (choice == 1)
			{	
				
				string str;
				string keyword = "";

				//User is asked to enter a message and a key in order to encrypt
				cout << "Enter A Message to Encrypt: ";
				cin >> str;
				cout << "Enter a key: ";
				cin >> keyword;

				//The two 'for' loops turn the user inputs into all capital letters, so encryption is the same across capital and lower case letters
				for (int i = 0; i < str.length(); i++)
				{
					str[i] = toupper(str[i]);
				}

				for (int i = 0; i < keyword.length(); i++)
				{
					keyword[i] = toupper(keyword[i]);
				}

				cout << endl;

				//Function is called to get the key
				keyword = genKey(str, keyword);
				//Function is called to encrypt the message using the key provided
				string encrypted_text = encryptedText(str, keyword);
				//Encrypted message is displayed
				cout << "Ciphertext : " << encrypted_text << endl << endl;

				cout << "----------------------------------------------------------------" << endl;
			}

			//Choice 2 decrypts messages
			else if (choice == 2)
			{
				string str;
				string keyword = "";

				//User is asked to enter a message and a key in order to decrypt
				cout << "Enter A Message to Decrypt: ";
				cin >> str;
				cout << "Enter a key: ";
				cin >> keyword;

				//The two 'for' loops turn the user inputs into all capital letters, so encryption is the same across capital and lower case letters
				for (int i = 0; i < str.length(); i++)
				{
					str[i] = toupper(str[i]);
				}

				for (int i = 0; i < keyword.length(); i++)
				{
					keyword[i] = toupper(keyword[i]);
				}

				cout << endl;

				keyword = genKey(str, keyword);

				string decrypted_text = encryptedText(str, keyword);
				cout << "Original/Decrypted Text : " << decryptText(str, keyword) << endl << endl;
				cout << "----------------------------------------------------------------" << endl;
			}

			//Choice 3 breaks the loop and terminates the program
			else if (choice == 3)
			{
				cout << endl;
				cout << "Thanks for using the program! Exiting..." << endl << endl;
				break;
			}

			//if any other input is provided, user is prompted to choose a valid option 
			else
			{
				cout << "Choice is: " << choice << endl;
				cout << "Invalid Input. Choose From the Choices Provided." << endl;
				cout << "----------------------------------------------------------------" << endl;
			}
		}
		
		system("pause");
		return 0;
	}

