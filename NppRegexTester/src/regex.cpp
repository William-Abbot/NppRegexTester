#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main()
{
    if (regex_match("softwareTesting", regex("(soft)(.*)")))
        cout << "string:literal => matched\n";

    const char mystr[] = "SoftwareTestingHelp";
    string str("software");
    regex str_expr("(soft)(.*)");

    if (regex_match(str, str_expr))
        cout << "string:object => matched\n";

    if (regex_match(str.begin(), str.end(), str_expr))
        cout << "string:range(begin-end)=> matched\n";

    cmatch cm;
    regex_match(mystr, cm, str_expr);

    smatch sm;
    regex_match(str, sm, str_expr);
    cout << "String:range, size:" << sm.size() << " matches\n";

    cout << "the matches are: ";
    for (unsigned i = 0; i < sm.size(); ++i) {
        cout << "[" << sm[i] << "] ";
    }
    cout << endl;


//    string s(R"(this subject has a submarine as a subsequence)");
//    regex rx("\\b(sub)([^ ]*)");
    string s(R"(ABCDABAD)");       // Defining the string input
    regex rx("(A|D)", regex_constants::extended);             // Getting the regex object

    smatch m;

    cout << "the matches are: ";

    while (regex_search(s, m, rx)) {
        cout << m.str() << " ";
        s = m.suffix().str();
    }

    cout << endl;

	return 0;
}