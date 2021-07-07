#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER r_q
#  4. INTEGER c_q
#  5. 2D_INTEGER_ARRAY obstacles
#

def queensAttack(n, k, r_q, c_q, obstacles):
    # Write your code here
    #check row
    result=0
    for i in range (1,n+1):
        if list(map(r_q,i)) not in obstacles:
            result+=1
    for i in range (1,n+1):
        if list(map(i,c_q)) not in obstacles:
            result+=1
    i=r_q
    j=c_q
    while (i>=1 and j>=1):
        if list(map(i,j)) not in obstacles:
            result+=1
        i-=1
        j-=1
    while (i<=n and j>=1):
        if list(map(i,j)) not in obstacles:
            result+=1
        i+=1
        j-=1
    while (i<=n and j<=n):
        if list(map(i,j)) not in obstacles:
            result+=1
        i+=1
        j+=1
    while (i>=1 and j<=n):
        if list(map(i,j)) not in obstacles:
            result+=1
        i-=1
        j+=1
    return result-6
    
            


    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
