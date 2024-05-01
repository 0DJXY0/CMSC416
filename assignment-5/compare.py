#with open('difference.txt', 'w') as file_out:
#from itertools import izip
count = 0;
with open('junks.txt', "r") as f1, open('sample-output.data', "r") as f2:

        for x, y in zip(f1, f2):
            count += 1;    
            x = x.strip()
            y = y.strip()
            if (x != y):
                    print(f"{x}\t{y}" + ' line ' + str(count))
                    break
