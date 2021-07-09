weight=int(input("Weight: "))
ch=input("(L)bs or (K)g: ")
if ch=='l':
    print(f"{weight*0.45} Kg")
elif ch=="k":
    print(f"{weight/0.45} Lbs")
else:
    print("dmm")