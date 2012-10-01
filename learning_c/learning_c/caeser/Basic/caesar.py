import readline
import sys


plain = input("Please input your plain text: ")
value = int(input("Please input your key (included negatives): "))

for letter in plain:
    if value > 0:
        if letter.isupper():
            print("%s" % chr(((ord(letter) - ord('A') + value) % 26 + ord('A'))), end='', file=sys.stderr)
        elif letter.islower():
            print("%s" % chr(((ord(letter) - ord('a') + value) % 26 + ord('a'))), end='', file=sys.stderr)
        else:
            print("%s" % letter, end='', file=sys.stderr)
    elif value <= 0:
        if letter.isupper():
            print("%s" % chr(((ord(letter) - ord('Z') + value) % 26 + ord('Z'))), end='', file=sys.stderr)
        elif letter.islower():
            print("%s" % chr(((ord(letter) - ord('z') + value) % 26 + ord('z'))), end='', file=sys.stderr)
        else:
            print("%s" % letter, end='', file=sys.stderr)

print("", file=sys.stderr)
