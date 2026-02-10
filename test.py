import re

def shatter(sentence):
    words = re.findall(r'[^\s,()&]+', sentence)
    return word_list


def separate_words_by_index(word_list):
    odd_words = []
    even_words = []

    for index, word in enumerate(word_list):
        if index < 2:
            continue
        if index % 2 == 0:
            if word == "{":
                break
            even_words.append(word)
        else:
            odd_words.append(word)

    return odd_words, even_words
lines = []
sentence = ""
count = 0
while True:
    count += 1
    line = input()
    lines.append(line + '\n')
    if count == 3:
        sentence = line
    if line == "};":
        break
words = re.findall(r'[^\s,()]+', sentence)
odd_indexed_list, even_indexed_list = separate_words_by_index(words)

print(f"Original List: {words}")
print("-" * 30)
print(f"{even_indexed_list}")
print(f"{odd_indexed_list}")