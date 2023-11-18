profit = [10,15,40]
weight = [1,2,3]

def knapsack_dp(i,w):
    table = [[0]*(w+1) for i in range(len(profit)+1)]
    for i in range(1,len(profit)+1):
        for j in range(1,w+1):
            if weight[i-1]<=j and profit[i-1]+table[i-1][j-weight[i-1]]>table[i-1][j]:
                table[i][j] = profit[i-1]+table[i-1][j-weight[i-1]]
            else:
                table[i][j] = table[i-1][j]
    print_table(table)
    return table[len(profit)][w]


def print_table(table):
    for row in table:
        print(row)

def knapsack(i,w):
    if i==0 or w==0:
        return 0
    
    if w>= weight[i]:
        return max(profit[i]+knapsack(i-1,w-weight[i]),knapsack(i-1,w))

    return knapsack(i-1,w)

def main():
    print(knapsack_dp(len(profit)-1,6))

if __name__ =='__main__':
    main()