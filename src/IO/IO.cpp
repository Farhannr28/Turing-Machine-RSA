#include <iostream>

#include "../header/IO.hpp"
#include "../header/printColor.hpp"
#include "../header/RSA.hpp"

using namespace std;

IO::IO(){
    IO::showTitle();
}

void IO::showTitle(){
    system("clear");
    startTextYellow();
    cout << " ████████ ██    ██ ██████  ██ ███    ██  ██████      ███    ███  █████   ██████ ██   ██ ██ ███    ██ ███████     ██████  ███████  █████ " << "\n";
    cout << "    ██    ██    ██ ██   ██ ██ ████   ██ ██           ████  ████ ██   ██ ██      ██   ██ ██ ████   ██ ██          ██   ██ ██      ██   ██" << "\n"; 
    cout << "    ██    ██    ██ ██████  ██ ██ ██  ██ ██   ███     ██ ████ ██ ███████ ██      ███████ ██ ██ ██  ██ █████       ██████  ███████ ███████" << "\n"; 
    cout << "    ██    ██    ██ ██   ██ ██ ██  ██ ██ ██    ██     ██  ██  ██ ██   ██ ██      ██   ██ ██ ██  ██ ██ ██          ██   ██      ██ ██   ██" << "\n"; 
    cout << "    ██     ██████  ██   ██ ██ ██   ████  ██████      ██      ██ ██   ██  ██████ ██   ██ ██ ██   ████ ███████     ██   ██ ███████ ██   ██" << "\n"; 
    cout << "\n";
    startTextCyan();
    cout << "oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo oo1oo" << "\n";
    cout << "\n";                                                                                             
}

bool IO::checkBooleanInput(string input){
    return input == "Yes" || input == "yes" || input == "YES" || input == "Y" || input == "y";
}

void IO::askInputs(){
    int selection;
    string input;
    bool isEncrypt;
    bool isTuring;
    string text;
    bool isPrint;

    resetTextColor();  
    cout << ">>> Would you like to Encrypt or Decrypt?" << "\n";
    cout << ">>>     1. Encrypt" << "\n";
    cout << ">>>     2. Decrypt" << "\n";
    cout << "\n";  
    cout << "??? ";
    cin >> selection;
    cout << "\n";  
    isEncrypt = selection == 1;
    startTextGreen();
    if (isEncrypt){
        cout << ">>> You selected Encrypt" << "\n";
    } else {
        cout << ">>> You selected Decrypt" << "\n";
    }

    resetTextColor();
    cout << "\n";  
    cout << ">>> Which RSA implementation you want?" << "\n";
    cout << ">>>     1. Turing Machine" << "\n";
    cout << ">>>     2. Naive" << "\n";
    cout << "\n";  
    cout << "??? ";
    cin >> selection;
    cout << "\n";  
    isTuring = selection == 1;
    startTextGreen();
    if (isTuring){
        cout << ">>> You selected Turing Machine" << "\n";
    } else {
        cout << ">>> You selected Naive" << "\n";
    }

    resetTextColor();
    cout << "\n";  
    if (isEncrypt){
        cout << ">>> Enter your Plaintext" << "\n";
    } else {
        cout << ">>> Enter your Ciphertext" << "\n";
    }
    cout << "\n";  
    cout << "??? ";
    cin >> input;
    cout << "\n";  
    text = input;
    startTextGreen();
    cout << ">>> ";
    cout << input;
    if (isEncrypt){
        cout << " is a valid Plaintext" << "\n";
    } else {
        cout << " is a valid Ciphertext" << "\n";
    }

    if (isTuring){
        resetTextColor();
        cout << "\n";  
        cout << ">>> Would you like to print every Turing Machine step? (yes/no)" << "\n";
        cout << "\n";  
        cout << "??? ";
        cin >> input;
        cout << "\n";  
        isPrint = checkBooleanInput(input);
        startTextGreen();
        if (isPrint){
            cout << ">>> Every step will be printed, this might take a while" << "\n";
        } else {
            cout << ">>> You will skip to the solution" << "\n";
        }
    }

    doAlgorithm(isEncrypt, isTuring, text, isPrint);
}

void IO::doAlgorithm(bool isEncrypt, bool isTuring, string text, bool isPrint){
    string solution;
    if (isTuring){
        if (isEncrypt){
            solution = RSA::getInstance().turingEncrypt(text, isPrint);
        } else {
            solution = RSA::getInstance().turingDecrypt(text, isPrint);
        }
    } else {
        if (isEncrypt){
            solution = RSA::getInstance().naiveEncrypt(text);
        } else {
            solution = RSA::getInstance().naiveDecrypt(text);
        }
    }

    resetTextColor();
    cout << "\n";
    if (isEncrypt){
        cout << ">>> Your Encrypted Ciphertext is: ";
    } else {
        cout << ">>> Your Decrypted Plaintext is: ";
    }
    startTextMagenta();
    cout << solution << "\n";
}

bool IO::askToRepeat(){
    string input;
    resetTextColor();
    cout << "\n";
    cout << ">>> Would you like to try another Cryptography?\n";
    cout << "\n";
    cout << "??? ";
    cin >> input;
    cout << "\n";
    return checkBooleanInput(input);
}