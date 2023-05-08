#include <iostream>
using namespace std;
int main()
{
    // taking input
    string msg, crc, encoded = "";
    cout << "Enter the message: ";
    getline(cin, msg);
    cout << "Enter the crc generator polynomial: ";
    getline(cin, crc);
    int m = msg.length();
    int n = crc.length();
    encoded += msg; // storing message in encoded

    //**Sender Side**

    for (int i = 1; i <= n - 1; i++)
    {
        encoded += '0'; // adding n-1 0s in the last of the original message
    }
    for (int i = 0; i <= encoded.length() - n;)
    {
        for (int j = 0; j < n; j++)
        {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }

        for (; i < encoded.length() && encoded[i] != '1'; i++)
            ;
    }
    cout << "Remainder: " << encoded.substr(encoded.length() - n + 1) << endl;
    cout << "Final Message: " << msg + encoded.substr(encoded.length() - n + 1) << endl;

    //**Receiver side**
    string crc1, encoded1;
    cout << "Enter the recieved message: ";
    getline(cin, encoded1);
    cout << "Enter the crc generator polynomial: ";
    getline(cin, crc1);

    for (int i = 0; i <= encoded1.length() - crc1.length();)
    {
        for (int j = 0; j < crc1.length(); j++)
        {
            encoded1[i + j] = encoded1[i + j] == crc1[j] ? '0' : '1';
        }

        for (; i < encoded1.length() && encoded1[i] != '1'; i++)
            ;
    }
    for (char i : encoded1.substr(encoded1.length() - crc1.length()))
    {
        if (i != '0')
        {
            cout << "Error in communication....";
            return 0;
        }
    }
    cout << "No error!";

    return 0;
}
