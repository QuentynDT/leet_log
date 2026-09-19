import os
import re
import sys

DIFFICULTIES = ["easy", "medium", "hard"]

def write_file(code: str, file_path: str) -> None:
    os.makedirs(os.path.dirname(file_path), exist_ok=True)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(code)
    print(f"Successfully generated: {file_path}")

def check_existing_file(number: str):
    """Checks if x.cpp exists in any difficulty folder before asking for inputs."""
    for diff in DIFFICULTIES:
        check_path = os.path.join(diff, number, "x.cpp")
        if os.path.exists(check_path):
            print(f"File '{check_path}' already exists.")
            sys.exit(0)

def parse_signature(raw_code: str):
    cleaned = re.sub(r'//.*?\n', '', raw_code)
    cleaned = re.sub(r'/\*.*?\*/', '', cleaned, flags=re.DOTALL)
    cleaned_no_access = re.sub(r'\b(public|private|protected)\s*:', '', cleaned)

    match = re.search(r'([\w:<>\s*&]+)\s+([a-zA-Z_]\w*)\s*\(([^)]*)\)', cleaned_no_access)
    if not match:
        raise ValueError("Could not parse a valid C++ function signature from input.")

    ret_type = match.group(1).strip()
    func_name = match.group(2).strip()
    params_str = match.group(3).strip()

    params = []
    if params_str:
        raw_params = []
        depth = 0
        current = []
        for char in params_str:
            if char == '<':
                depth += 1
            elif char == '>':
                depth -= 1
            if char == ',' and depth == 0:
                raw_params.append(''.join(current).strip())
                current = []
            else:
                current.append(char)
        if current:
            raw_params.append(''.join(current).strip())

        for p in raw_params:
            p_match = re.search(r'^(.*?)\s*([a-zA-Z_]\w*)$', p)
            if p_match:
                p_type = p_match.group(1).strip()
                p_name = p_match.group(2).strip()
                params.append((p_type, p_name))

    filtered_lines = []
    skip = False
    for line in raw_code.splitlines():
        if re.search(r'struct\s+(TreeNode|ListNode)\s*\{', line):
            skip = True
        if not skip:
            filtered_lines.append(line)
        if skip and line.strip() == "};":
            skip = False

    return ret_type, func_name, params, "\n".join(filtered_lines)

def clean_type_for_struct(type_str: str) -> str:
    clean = re.sub(r'\b(const|public|private|protected)\b', '', type_str)
    clean = clean.replace(':', '').replace('&', '').strip()
    return clean

def build_code():
    number_input = input("Problem number:").strip()

    # Step 1: Immediately check if x.cpp exists in easy, medium, or hard
    check_existing_file(number_input)

    # Step 2: Ask for difficulty only if it doesn't exist
    difficulty = input("Difficulty:").strip().lower()
    target_path = os.path.join(difficulty, number_input, "x.cpp")

    print("LeetCode starter function:")
    lines = []
    while True:
        line = input()
        lines.append(line)
        if line.strip() == "};":
            break

    raw_input = "\n".join(lines)
    ret_type, func_name, params, cleaned_leetcode_code = parse_signature(raw_input)

    is_void = (ret_type == "void")
    result_type = clean_type_for_struct(params[0][0]) if is_void and params else clean_type_for_struct(ret_type)

    struct_fields = []
    arg_names = []
    for p_type, p_name in params:
        st_type = clean_type_for_struct(p_type)
        struct_fields.append(f"    {st_type} {p_name};")
        arg_names.append(f"data.{p_name}")

    struct_fields.append(f"    {result_type} ans;")
    struct_fields.append(f"    {result_type} res;")
    struct_body = "\n".join(struct_fields)

    args_str = ", ".join(arg_names)
    solve_call = f"s.{func_name}({args_str});"

    if is_void:
        first_param_name = params[0][1] if params else "data"
        handle_body = f"    {solve_call}\n    data.res = data.{first_param_name};"
    else:
        handle_body = f"    data.res = {solve_call}"

    cpp_template = f"""#include "../../timer.h"

{cleaned_leetcode_code}

struct token {{
{struct_body}
}};

void handle(token& data) {{
    Solution s;
{handle_body}
}}

void runTests(vector<token>& tokens) {{
    cout << '\\n';
    for(token& t : tokens) {{
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\\nExpected: ";
        display(t.ans);
        cout << "\\n\\n";
    }}
}}

int main() {{
    cout.imbue(locale(cout.getloc(), new CleanDoubleFacet));
    vector<token> tokens;

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
    return 0;
}}
"""
    write_file(cpp_template.strip(), target_path)

if __name__ == "__main__":
    build_code()
