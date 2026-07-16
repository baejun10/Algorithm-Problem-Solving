
str = input()

words = str .split(" ")

if len(words) % 2 == 0:
    for i in range(len(words)-1, 0, -2):
        print(words[i], end=" ")
else:
    for i in range(len(words)-2, 0, -2):
        print(words[i], end=" ")