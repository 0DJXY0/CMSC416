#with open('difference.txt', 'w') as file_out:
#from itertools import izip
count = 0;
import sys


file1 = sys.argv[1]
file2 = sys.argv[2]
file1 = "life.1.512x512.data"
file2 = "life.1.512x512.500.csv"
print("begin comparing")
with open(file1, "r") as f1, open(file2, "r") as f2:
        listx = []
        listy = []
        for x, y in zip(f1, f2):
            count += 1    
            x = x.strip()
            y = y.strip()
            listx.append(x)
            listy.append(y)
            if (x != y):                    
                    print(f"{x}\t{y}" + ' line ' + str(count))
                    break
        '''    
        print(set(listx)^set(listy))
        count = 0
        for i in range(len(listx)):
                if listx[i] not in listy:
                        print(listx[i])

        '''
