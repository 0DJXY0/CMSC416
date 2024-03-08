import hatchet as ht
import sys
import warnings;   
warnings.filterwarnings("ignore")

if __name__ == '__main__':
    file_name8 = "lulesh-8cores.json"
    file_name64 = "lulesh-64cores.json"
    N = sys.argv[1]
    N = int(N)
 
    gf8 = ht.GraphFrame.from_caliper(file_name8)
    gf64 = ht.GraphFrame.from_caliper(file_name64)
    gf8.drop_index_levels()
    gf64.drop_index_levels()
    diff = gf64 - gf8
    #sorted_diff = diff.dataframe

    sorted_diff = diff.dataframe.sort_values('time', ascending=False)  
    output = sorted_diff.head(N)
    output = output[["name","time"]].to_string(index=False,header=False)
    #print(sorted_diff)
    print(output)
