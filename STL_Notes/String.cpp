/*
01 : Declaration & Initialization
02 : Checking is a string empty or not
03 : String concatenation
04 : Comparing two strings
05 : String Reverse
06 : String Sorting
07 : Finding Unique
08 : Finding Maximum , Minimum
09 : getline()
10 : Vector String
11 : pop_back(), back()
12 : Integer to String
13 : Substring (find(), substr())
14 : Erasing a character from a string
15 :Take multiple lines of string as input
16 : (Func) To lower case
17 : (Func) is_Vowel()
18 : (Func) is palindrome
19 : Lexographically next permutation
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*--------------------------------------
        01 : Declaration & Initialization
    ------------------------------------*/
    /// Declare string
    string s;

    /// Assign string
    s = "abcdf";

    /// Printing size of string
    cout << s.size() << endl; /// 5

    /// Printing string
    cout << s << endl; /// abcdf

    /// Pushing char back to a string
    s += 'b';
    s += 'c';
    cout << s << endl; /// abcdfbc

    /// Taking input string
    cin >> s;
    cout << s << endl;

    s = "asdfgg";
    /*---------------------------------------------------------
        ///02 : Checking is a string empty or not
    ---------------------------------------------------*/
    string s1;
    cout << s.empty() << endl;  /// 0
    cout << s1.empty() << endl; /// 1

    /// Assigning an string in another string variable
    s1 = s;
    s.clear();

    cout << s.empty() << endl;  /// 1
    cout << s1.empty() << endl; /// 0

    /// assigning 'k' in 0-th index
    s = "asdfg";
    s[0] = 'k';
    cout << s << endl; /// kasdfg;

    s = "abc";
    s1 = "def";
    /*-----------------------------------------------
           ///03 : String concatenation
    -----------------------------------------*/
    string tmp = s + s1;
    cout << tmp << endl; /// abcdef

    /// String iterator
    string::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it; /// abc
    cout << endl;

    /// For each loop
    for (auto c : s)
        cout << c; /// abc
    cout << endl;

    s = "asd";
    tmp = s;

    /*------------------------------------------------------
        ///04 : Comparing two strings
    ---------------------------------------------------*/
    if (tmp == s)
        cout << "Yes Match\n"; // O/P
    else
        "No Match\n";
    // can also use (tmp < s) or (tmp > s ) to check their lexographical

    /*--------------------------------------------------------
                05 : String Reverse
  --------------------------------------------------*/
    /// String reverse and checking is a string is palindrome or not
    s = "asddsa";
    tmp = s;
    reverse(tmp.begin(), tmp.end()); // Time CX : O(n)

    if (tmp == s)
        cout << "Yes Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    /*----------------------------------------------------------
                     06 : String Sorting
    ---------------------------------------------*/

    /// String sorting in non-decreasing order
    s = "gfds";
    sort(s.begin(), s.end()); // Time CX : O(nlogn)
    cout << s << endl;        /// dfgs

    /// String sorting in non-increasing order
    sort(s.rbegin(), s.rend());
    cout << s << endl; /// sgfd

    /*-------------------------------------------------------------------
               07 : Finding Unique
--------------------------------------------------------*/

    /// Getting all unique elements of a string. Be care full, string should be sorted.
    s = "aaadddsss";
    int n = unique(s.begin(), s.end()) - s.begin();
    for (int i = 0; i < n; i++)
        cout << s[i]; /// ads
    cout << endl;

    /*-------------------------------------------------------------------
               08 : Finding Maximum , Minimum
--------------------------------------------------------*/

    /// Getting maximum element of string
    cout << *max_element(s.begin(), s.end()) << endl; /// s
    /// Getting minimum element of string
    cout << *min_element(s.begin(), s.end()) << endl; /// a

    /*-------------------------------------------------------------------
               09 : getline()
--------------------------------------------------------*/

    /// When we want to take input with space
    /// input : Muhammad Shahriar Alam

    char c;
    cin >> c;
    getline(cin, s);
    s = c + s;

    cout << s << endl; /// Muhammad Shahriar Alam

    /*-------------------------------------------------------------------
               10 :  Vector String
--------------------------------------------------------*/

    /// If we need to sort some string on lexicographical order :

    vector<string> v;
    v.push_back("Muhammad");
    v.push_back("Nova");
    v.push_back("Maslenia Mubarrat");
    v.push_back("CPS Academy");
    v.push_back("Rashedul Alam Anik");
    v.push_back("Farhan sadik Sakib");
    v.push_back("Gazi Mohaimin Iqbal");

    sort(v.begin(), v.end());
    for (auto u : v)
        cout << u << endl;

    /**

    Out put :

    CPS Academy
    Farhan sadik Sakib
    Gazi Mohaimin Iqbal
    Maslenia Mubarrat
    Muhammad
    Nova
    Rashedul Alam Anik

    */

    /*-------------------------------------------------------------------
               11 : pop_back(), back()
--------------------------------------------------------*/
    s = "asdf";

    s.pop_back();             /// removes last char of string
    cout << s.back() << endl; /// print last char of string

    v.clear();

    v = {"Shahriar", "Shahriar", "Momo", "Momo", "Sharif", "Sharif"};
    int Sz = unique(v.begin(), v.end()) - v.begin();

    cout << Sz << endl; /// Number of unique strings in vector v;
    for (int i = 0; i < Sz; i++)
        cout << v[i] << endl; /// Prints all unique strings in vector v

    /*-------------------------------------------------------------------
               12 : Integer to String
--------------------------------------------------------*/

    /// Converting int to string
    int a = 123;
    s = to_string(a);
    cout << s << endl; /// 123
    s[0] = '3';
    cout << s << endl; /// 323

    /// Converting string to integer

    s = "123";
    a = stoi(s);
    cout << a << endl; /// 123
    a++;
    cout << a << endl; /// 124;

    /*-------------------------------------------------------------------
                13 : Substring (find(), substr())
--------------------------------------------------------*/

    /// Deleting a substring from string

    s = "ShaKAKAhriar";

    s.erase(s.begin() + 3, s.begin() + 7); /// erase substring "KAKA" from string s
    cout << s << endl;

    /// Copying a substring of a string to a string
    tmp = "Gagha Alam Gadha";
    s = "Shahriar ";

    copy(tmp.begin() + 6, tmp.begin() + 10, back_inserter(s)); /// copying "Alam substring to string s back.
    cout << s << endl;                                         /// Shahriar Alam

    /// Checking is a string is substring of another string in O(n*m)
    s = "ashshasdakks";

    if (s.find("asd") != -1)
        cout << "Substring found";
    else
        cout << "Not found";

    // Using substr() function to find substring
    string s = "na";
    string t = "apna collegena";

    int S = s.size();
    int T = t.size();

    for (int i = 0; i < T - S + 1; i++) // Time Complexity :  O(n)
    {
        if (t.substr(i, S) == s) // substr( position , size)
        {
            cout << "Found at Index : " << i << "\n";
        }
    }

    // find(): Searches the string and returns the first occurrence of the parameter
    // in the string. Its time complexity is O(N) where N is the size of the string.
    string s10 = "nincompoop";
    cout << s.find("com") << endl; // Output : 3

    int t;
    cin >> t;
    /*-------------------------------------------------------------------
                14 : Erasing a character from a string
--------------------------------------------------------*/

    /// Erasing all occurrence of a specific char from string.

    s = "aaassdddaaasdd";
    s.erase(remove(s.begin(), s.end(), 'a'), s.end()); /// removes all 'a' from s
    cout << s << endl;

    /*-------------------------------------------------------------------
                15 :Take multiple lines of string as input
--------------------------------------------------------*/

    // for (int tc = 1; tc <= t; tc++)
    // {
    //     string s;
    //     char c;
    //     cin >> c;
    //     getline(cin, s);
    //     s = c + s;
    //     cout << "Case " << tc << " " << s << endl;
    // }

    /*-------------------------------------------------------------------
                16 : (Func) To lower case
--------------------------------------------------------*/
    // string to_lower(string s)
    // {
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] <= 90 && s[i] >= 65)
    //             s[i] += 32;
    //     }
    //     cout << s << endl;
    //     return s;
    // }
    /*-------------------------------------------------------------------
                17 : (Func) is_Vowel()
--------------------------------------------------------*/

    // Is Vowel Function
    // bool isVowel(char c)
    // {
    //     return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // }

    /*-------------------------------------------------------------------
              18 : (Func) is palindrome
--------------------------------------------------------*/
    // Is a Number palindrome 146 = 1 + 4 + 6 = 11 == 11 (Palindrome)
    string s;
    cin >> s;

    int digitSum = 0;

    for (auto i : s)
        digitSum += (i - '0');
    // Getting the character difference
    // If we do 'c' - 'a' then we will get 2 ; similarly for each character we can get their value by subtracting by 0

    string str = to_string(digitSum);
    string tmp = str;

    reverse(tmp.begin(), tmp.end());

    if (str == tmp)
        cout << "Yes ! Plindrome\n ";
    else
        cout << "Not Palindrome\n";

    /*-------------------------------------------------------------------
              19 : Lexographically next permutation
--------------------------------------------------------*/
    string s = "abcd";

    bool f1 = next_permutation(s.begin(), s.end());

    cout << f1 << " " << s << "\n"; // 1 abdc

    string s = "abc";
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    /*
    abc
    acb
    bac
    bca
    cab
    cba
    */

    return 0;
}
