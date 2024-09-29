#include <iostream>
#include <string>
using namespace std;

int main() {
    string email;
    bool isValid = true;
    int atPos = -1, dotPos = -1;
    int length = 0;

    
    cout << "Enter an email address: ";
    cin >> email;

    
    while (email[length] != '\0') {
        length++;
    }

    
    for (int i = 0; i < length; i++) {
        char c = email[i];

        
        if (c == '@') {
            if (atPos == -1) {
                atPos = i;  // Mark the position of '@'
            } else {
                isValid = false;  // More than one '@' symbol
                break;
            }
        }

        
        if (c == '.' && atPos != -1) {
            dotPos = i;  // Mark the position of the last '.'
        }

        
        if (atPos == -1) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '_' || c == '-' || c == '+')) {
                isValid = false;
                break;
            }
        }

        
        if (atPos != -1 && dotPos == -1) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-')) {
                isValid = false;
                break;
            }
        }

        
        if (dotPos != -1 && i > dotPos) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                isValid = false;
                break;
            }
        }
    }

    
    if (atPos == -1 || dotPos == -1 || atPos == 0 || dotPos == length - 1 || dotPos <= atPos + 1) {
        isValid = false;
    }

    
    if (isValid) {
        cout << "The email address is valid." << endl;
    } else {
        cout << "The email address is invalid." << endl;
    }

    return 0;
}
