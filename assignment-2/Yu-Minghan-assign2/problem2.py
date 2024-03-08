import hatchet as ht
import sys

if __name__ == '__main__':
    file_name = "lulesh-64cores.json"

    X = sys.argv[1]
    X = int(X)
  
    gf = ht.GraphFrame.from_caliper(file_name)
    gf_imb = gf.load_imbalance(verbose=True)
    df_imb = gf_imb.dataframe.sort_values(by='time.imbalance', ascending=False).head(X)
    output = df_imb.tail(1)
    output = output["time.ranks"].to_string(index=False,header=False)

    print(output)
