#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string encrypt(const string &text, const string &key, const char alphabet[], bool useASCII = false) {
    string result = text;

    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        char k = key[i % key.length()];  // Pasikartojantis raktas
        if (useASCII) {
            int ci = (c + k) % 256; // ASCII kodavimas
            result[i] = ci;
        } else {
            int ci = (c + k - alphabet[0]) % strlen (alphabet) + alphabet[0]; // Raidžių kodavimas
            result[i] = ci;
        }
    }
    return result;
}

string decrypt(const string &text, const string &key, const char alphabet[], bool useASCII = false) {
    string result = text;

    for (int i = 0; i < text.length(); ++i) {
        char ci = text[i];
        char k = key[i % key.length()];  // Pasikartojantis raktas
        if (useASCII) {
            int mi = (ci - k + 256) % 256; // ASCII dekodavimas
            result[i] = mi;
        } else {
            int mi = (ci - k - alphabet[0] + strlen(alphabet)) % strlen(alphabet) + alphabet[0]; // Dešifruojame raidžių kodavimą
            result[i] = mi;
        }
    }
    return result;
}

int main() {
    string text, key;
    int choice;

    cout << "Pasirinkite veiksma:\n";
    cout << "1. Sifruoti\n";
    cout << "2. Desifruoti\n";
    cin >> choice;

    char englishAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Anglų abėcėlė

    if (choice == 1 || choice == 2) {
        cout << "Iveskite teksta: ";
        cin >> text;
        cout << "Iveskite rakta: ";
        cin >> key;

        if (choice == 1) {
            bool useASCII;
            cout << "Ar naudoti ASCII sifravima (iveskite 1 jei taip, 0 jei ne)? ";
            cin >> useASCII;
            string encrypted = encrypt(text, key, englishAlphabet, useASCII);
            cout << "Uzsifruotas tekstas: " << encrypted << endl;
        } else if (choice == 2) {
            bool useASCII;
            cout << "Ar naudoti ASCII sifravima (iveskite 1 jei taip, 0 jei ne)? ";
            cin >> useASCII;
            string decrypted = decrypt(text, key, englishAlphabet, useASCII);
            cout << "Desifruotas tekstas: " << decrypted << endl;
        }
    } else {
        cout << "Neteisinga pasirinkimo reiksme.";
    }

    return 0;
}
