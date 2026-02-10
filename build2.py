import os
import re
def write(code, number, difficulty):
    folder_path = os.path.join(difficulty, number)
    file_path = os.path.join(folder_path, 'x.cpp')
    os.makedirs(folder_path, exist_ok=True)
    with open(file_path, 'w') as f:
        f.write(code)

def build_code():
    itypes = []
    inames = []
    lines = []
    sentence = ""
    count = 0
    number = input("Enter number.\n")
    difficulty = input("Enter difficulty.\n")
    cases = input("Enter number of test cases.\n")
    print("Enter leetcode starter function.")
    while True:
        count += 1
        line = input()
        lines.append(line + '\n')
        if count == 3:
            sentence = line
        if line == "};":
            break
    words = re.findall(r'[^\s,()]+', sentence)

    for index, word in enumerate(words):
        if index < 2:
            continue
        if index % 2 == 0:
            if word == "{":
                break
            itypes.append(word)
        else:
            inames.append(word)
    outstring = words[0]
    t = int(cases)
    struct = ""
    inline = ""
    var = ""
    inits = "\n    const int n = " + cases + ";\n    vector<token> tokens(n);"
    for var, vname in zip(itypes, inames):
        struct += "\n    " + var
        if var.endswith('&'):
            struct = struct[:-1]
        struct += " " + vname + ";"
        inline += "data." + vname + ", "
    for i in range(t):
        inits += "\n    tokens[" + str(i) +"] = {};"
    struct += "\n    " + words[0] + " ans;\n    " + words[0] + " res;\n"
    inline = inline[:-2]


    code = """
#include "../../timer.h"

""" + "".join(lines) + """

struct token {""" + struct + """};

void handle(token& data){
    Solution s;
    data.res = s.""" + words[1] + """(""" + inline + """);
}

void runTests(vector<token>& tokens){
    cout << '\\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "\\nExpected: ";
        display(t.ans);
        cout << "\\n\\n";
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
    #print(code)
    write(code, number, difficulty)

if __name__ == "__main__":
    build_code()