#! /usr/bin/python3
import sys
import os

def format(a, b):
    a = int(a.strip())
    b = int(b.strip())
    return a - 16, b - 6 - 3

if __name__ == "__main__":
    a = sys.argv[1]
    b = sys.argv[2]
    print(format(a, b))
