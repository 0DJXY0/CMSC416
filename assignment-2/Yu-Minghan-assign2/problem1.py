import hatchet as ht
import sys

if __name__ == '__main__':
    file_name = "lulesh-1core.json"

    N = sys.argv[1]
    N = int(N)
  
    gf = ht.GraphFrame.from_caliper(file_name)
    sorted_df = gf.dataframe.sort_values(by='time',ascending=False).head(N)
    sorted_df = sorted_df[['name','time']].reset_index(drop=True)
    output = sorted_df.to_string(index=False, header=False)

    print(output)
