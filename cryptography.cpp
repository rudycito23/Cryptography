//
// Created by Rudy Lucas on 9/24/2021.
//
#include <cctype>
#include "cryptography.h"

void encrypt(string message, string passcode)
{
    string cipher = "";  // result
    int spaces{0};  // wanted to keep the passcode index corresponding to the plaintext index.

    cout << "Encrypting your message..." << endl;
    cout << endl;

    for (int i = 0; i < message.size(); ++i)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')  // if range between A-Z == true
        {
            int shiftVal = passcode[(i - spaces) % passcode.length()] - 65;  // I wanted 'A' = 0; subtract it by ASCII (65)
            int charVal = message[i] + shiftVal;  // variable == the new ASCII value after shifting
            if (charVal > 90)  // if the ASCII value is > 90 (Z) == true
            {
                charVal -= 26;  // then, subtract 26 to keep it in the range of A-Z
            }
            cipher += char(charVal); // adding the encrypted letter to the result
        }
        else
        {
            cipher += message[i];
            spaces++;
        }
    }
    cout << "Ciphertext message: " << cipher << endl;
    cout << endl;
}

void decrypt(string& cipher, string& passcode)
    {
        string message = "";
        int spaces{0};

            cout << "Decrypting your message..." << endl;
            cout << endl;

            for (int i = 0; i < cipher.size(); ++i)
            {
                if (cipher[i] >= 'A' && cipher[i] <= 'Z')
                {
                    int shiftVal = passcode[(i - spaces) % passcode.length()] - 65; // I wanted 'A' = 0; subtract it by ASCII (65)
                    int charVal = cipher[i] - shiftVal;  // subtracting the shift value
                    if (charVal < 65)  // if charVal < 65 == true
                    {
                        charVal += 26; // then add 26 to keep within the range of A-Z
                    }
                    message += char(charVal);
                }
                else
                {
                    message += cipher[i];
                    spaces++;
                }
            }
            cout << "Plaintext message: " << message << endl;
            cout << endl;
    }

void menu()
{
    string command;

    cout << "Welcome to the SMU Encryption Engine!" << endl;
    cout << endl;

    cout << "Please enter a command (encrypt / decrypt): ";
    getline (cin, command);

    while (command != "quit" || command != "QUIT")  // execute the while loop as long as "quit & QUIT" isn't entered
    {
        if (command == "ENCRYPT" || command == "encrypt")
        {
            string passcode;
            string message;

            cout << "Enter your passcode: ";
            getline (cin, passcode);
            for (int i = 0; i < passcode.size(); ++i)
            {
                passcode.at(i) = toupper(passcode.at(i));
            }

            cout << "Enter the message to be encrypted: ";
            getline (cin, message);
            for (int i = 0; i < message.size(); ++i)
            {
                message.at(i) = toupper(message.at(i));
            }

            encrypt(message, passcode);  // call the encrypt function
        }
        else if (command == "decrypt" || command == "DECRYPT")
        {
            string passcode;
            string cipher;

            cout << "Enter your passcode: ";
            getline (cin, passcode);
            for (int i = 0; i < passcode.size(); ++i)
            {
                passcode.at(i) = toupper(passcode.at(i));
            }

            cout << "Enter the message to be decrypted: ";
            getline (cin, cipher);
            for (int i = 0; i < cipher.size(); ++i)
            {
                cipher.at(i) = toupper(cipher.at(i));
            }

            decrypt(cipher, passcode);  // call the decrypt function
        }
        else if (command == "quit" || command == "QUIT")
        {
            cout << "Goodbye!";
            cout << endl;
            break;  // ends program
        }
        else
        {
            cout << command << " is not a valid command. Please enter one of ENCRYPT/DECRYPT/QUIT" << endl;
            cout << endl;
        }
        cout << "Please enter a command: ";
        getline (cin, command);
    }
}