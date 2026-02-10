import os
def write(code, number, difficulty):
    folder_path = os.path.join(difficulty, number)
    file_path = os.path.join(folder_path, 'x.cpp')
    os.makedirs(folder_path, exist_ok=True)
    with open(file_path, 'w') as f:
        f.write(code)

def build_code():
    #Enter m for 2d vector, v for 1d vector, x for int, s for string
    number = input("Enter number.\n")
    difficulty = input("Enter difficulty.\n")
    fname = input("Enter function name.\n")
    itype = input("Enter inputs.\n")
    iname = input("Enter name of each input.\n")
    o = input("Enter output.\n")
    cases = input("Enter number of test cases.\n")
    t = int(cases)
    itypes = itype.split()
    inames = iname.split()
    outstring = ""
    instring = "("
    struct = ""
    inline = ""
    var = ""
    inits = "\n    const int n = " + cases + ";\n    vector<token> tokens(n);"
    for c, vname in zip(itypes, inames):
        struct += "\n    "
        if c == 'm':
            var = "vector<vector<int>>&"
        elif c == 'v':
            var = "vector<int>&"
        elif c == 'x':
            var = "int"
        elif c == 's':
            var = "string"
        else:
            var = "unknown"
        if var.endswith('&'):
            struct += var[:-1]
        else:
            struct += var
        struct += " " + vname + ";"
        instring += var + " " + vname + ", "
        inline += "data." + vname + ", "
    for i in range(t):
        inits += "\n    tokens[" + str(i) +"] = {};"
    if o == "m":
        var = "vector<vector<int>>"
    elif o == "v":
        var = "vector<int>"
    elif o == "x":
        var = "int"
    elif o == 's':
        var = "string"
    else:
        var = "unknown"
    outstring = var
    struct += "\n    " + var + " ans;\n    " + var + " res;\n"
    instring = instring[:-2]
    inline = inline[:-2]
    instring += ")"


    code = """
#include "../../timer.h"

class Solution {
public:
    """ + outstring + " " + fname + instring +"""{

    }
};

struct token {""" + struct + """};

void handle(token& data){
    Solution s;
    data.res = s.""" + fname + """(""" + inline + """);
}

void runTests(vector<token>& tokens){
    cout << '\\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "Expected answer: ";
        display(t.ans);
        cout << '\\n';
    }
}

int main(){""" + inits + """
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
"""
    code = code.strip()
    write(code, number, difficulty)

if __name__ == "__main__":
    build_code()