#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Function to generate a short url from integer ID
string idToShortURL(long int n)
{
    // Map to store 62 possible characters
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string shorturl;

    // Convert given integer id to a base 62 number
    while (n)
    {
        // use above map to store actual character
        // in short url
        shorturl.push_back(map[n % 62]);
        n = n / 62;
    }

    // Reverse shortURL to complete base conversion
    reverse(shorturl.begin(), shorturl.end());

    return shorturl;
}

// Function to get integer ID back from a short url
long int shortURLtoID(string shortURL)
{
    long int id = 0; // initialize result

    // A simple base conversion logic
    for (int i = 0; i < shortURL.length(); i++)
    {
        if ('a' <= shortURL[i] && shortURL[i] <= 'z')
            id = id * 62 + shortURL[i] - 'a';
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
            id = id * 62 + shortURL[i] - 'A' + 26;
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
            id = id * 62 + shortURL[i] - '0' + 52;
    }
    return id;
}

// Function to validate if a string is a valid short URL
bool isValidShortURL(string shortURL)
{
    for (char c : shortURL)
    {
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')))
            return false;
    }
    return true;
}

int main()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Generate Short URL\n";
        cout << "2. Retrieve ID from Short URL\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            long int n;
            cout << "Enter ID to convert to Short URL: ";
            cin >> n;
            string shorturl = idToShortURL(n);
            cout << "Generated short URL is " << shorturl << endl;
            break;
        }
        case 2:
        {
            string shorturl;
            cout << "Enter Short URL to convert to ID: ";
            cin >> shorturl;
            if (isValidShortURL(shorturl))
            {
                long int id = shortURLtoID(shorturl);
                cout << "ID from URL is " << id << endl;
            }
            else
            {
                cout << "Invalid Short URL format.\n";
            }
            break;
        }
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
