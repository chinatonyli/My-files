import readline
import sys


plain = input("Please input your plain text: ")
value = int(input("Please input your key (included negatives): "))

for letter in plain:
    if ord(letter) >= ord('A') and ord(letter) <= ord('Z'):
        print("%s" % chr(((ord(letter) - ord('A') + value) % 26 + ord('A'))), end='', file=sys.stderr)
    elif ord(letter) >= ord('a') and ord(letter) <= ord('z'):
        print("%s" % chr(((ord(letter) - ord('a') + value) % 26 + ord('a'))), end='', file=sys.stderr)
    else:
        print("%s" % letter, end='', file=sys.stderr)

print("", file=sys.stderr)
