table = [[500,30]]
w = 10

def fractional_knapsack(w):
    table.sort(key=lambda x : x[0]/x[1],reverse=True)
    profit = 0
    for arr in table:
        if arr[1]<w:
            profit = profit + arr[0]
            w = w-arr[1]
        else:
            profit = profit + int((arr[0]*w)/arr[1])
            w = w-arr[1]
            break
    return profit

def main():
    print(fractional_knapsack(w))
    print(table)

if __name__ =='__main__':
    main()