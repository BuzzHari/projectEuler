f=[]
f.append(0)
f.append(1)
f.append(1)
while 1:
    f.append(f[-1]+f[-2])
    if (len(str(f[-1]))==1000):
            print(len(f)-1)
            break;


