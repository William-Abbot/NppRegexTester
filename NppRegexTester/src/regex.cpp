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

    cout << "contains: \n";

    auto pos = s.cbegin();
    auto end = s.cend();
    for (; regex_search(pos, end, m, rx); pos = m.suffix().first) {
        cout << "match: " << m.str() << endl;
        cout << " tag: " << m.str(1) << endl;
        cout << " value: " << m.str(2) << endl;
    }

    cout << endl;

    smatch m1;
    regex_match(s, m1, rx);

    cout << "matches: ";
    cout << m1.str() << endl;

	return 0;
}
