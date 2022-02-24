import sys

str = sys.stdin.readline()

str_array = sorted(str)

str = "".join(str_array)
str = str[::-1]

print(str)
