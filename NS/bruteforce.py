#!bin/python
from itertools import product
from random import choice as choose

alphabet = "abcdefghijklmnopqrstuvwxyz"

def random_alphabet(length):
    global alphabet
    alphabet= [chr(x) for x in range(ord('A'), ord('A')+length)]

def random_password(length):
    global alphabet
    password = ''
    for i in range(length):
        password = password + choose(alphabet)
    return password

def guess(password, alph_limits=(ord('a'), ord('z'))):
    global alphabet
    length = len(password)
    min_ch = alph_limits[0]
    max_ch = alph_limits[1]

    for candidate in product(alphabet,repeat=length):
            if candidate == password:
                return password

# Timing information was obtained by running the following blocks
# in an ipython shell using the shell-magic %%timeit

import bruteforce as bf

# varying password length
password = bf.random_password(length=7)
bf.guess(password)

# varying alphabet size
bf.random_alphabet(50)
password = bf.random_password(length=5)
bf.guess(password)    

