#include <iostream>
#include <string>

using namespace std;

// Byte Stuffing (Substring Matching)
string byteStuff(const string& str, const string& flag, const string& escSeq) {
    string result = flag; // Add start flag
    size_t pos = 0;
    while (pos < str.length()) {

        // chekc plag and esc is in or not with get starting address
        size_t flagPos = str.find(flag, pos);
        size_t escPos = str.find(escSeq, pos);

        // if string found and flag is beginning of esc word
        if (flagPos != string::npos && (escPos == string::npos || flagPos < escPos)) {
            result += str.substr(pos, flagPos - pos);
            result += escSeq + flag;
            pos = flagPos + flag.length();

        } else if (escPos != string::npos) {
            result += str.substr(pos, escPos - pos);
            result += escSeq + escSeq;
            pos = escPos + escSeq.length();

        } else {
            result += str.substr(pos);
            break;
        }
    }
    result += flag; // Add end flag
    return result;
}

// Byte Destuffing (Substring Matching)
string byteDestuff(const string& str, const string& flag, const string& escSeq) {
    if (str.length() < flag.length() * 2 || str.substr(0, flag.length()) != flag || str.substr(str.length() - flag.length()) != flag) {
        return "Invalid stuffed string.";
    }

    string result;
    size_t pos = flag.length(); // Skip start flag
    while (pos < str.length() - flag.length()) { // Skip end flag
        size_t escPos = str.find(escSeq, pos);
        
        if (escPos == string::npos || escPos >= str.length() - flag.length()) {
            result += str.substr(pos, str.length() - flag.length() - pos);
            break;

        } else {
            result += str.substr(pos, escPos - pos);
            if (str.substr(escPos + escSeq.length(), flag.length()) == flag) {
                result += flag;
                pos = escPos + escSeq.length() + flag.length();

            } else if (str.substr(escPos + escSeq.length(), escSeq.length()) == escSeq) {
                result += escSeq;
                pos = escPos + escSeq.length() + escSeq.length();

            } else {
                result += str.substr(escPos, escSeq.length());
                pos = escPos + escSeq.length();
            }
        }
    }
    return result;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string flag = "GALF";
    string escSeq = "EPACSE";

    string stuffedStr = byteStuff(str, flag, escSeq);
    cout << "Stuffed string: " << stuffedStr << endl;

    string destuffedStr = byteDestuff(stuffedStr, flag, escSeq);
    cout << "Destuffed string: " << destuffedStr << endl;

    return 0;
}