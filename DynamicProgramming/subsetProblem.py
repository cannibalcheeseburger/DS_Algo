arr= [1,2,4,8]

t = 16

dp = [[None]*(t+1) for x in range(len(arr))]

table = [[None]*(t+1) for x in range(len(arr)+1)]

def print_table():
    for row in table:
        print(row)

def subset_tab(i,t):
    for i in range(len(arr)+1):
        table[i][0] = True
    for i in range(1,t+1):
        table[0][i] = False

    for i in range(1,len(arr)+1):
        for j in range(1,t+1):
            #element = i-1 , t = j
            if j>=arr[i-1]:
                table[i][j] = table[i-1][j-arr[i-1]] or table[i-1][j]
            else:
                table[i][j] = table[i-1][j]
    return table[len(arr)][t]

def subset(i,t):

    if t == 0 :
        dp[i][t] = True
        return True
    if i<0 and t!=0:
        dp[i][t] = False
        return False
    
    if dp[i][t]:
        return dp[i][t]
    
    if t>=arr[i]:
        dp[i][t] = subset(i-1,t-arr[i]) or subset(i-1,t)
        
    else:
        dp[i][t] =  subset(i-1,t)
    return dp[i][t]

def main():
    print(subset_tab(len(arr)-1,t))
    print_table()

if __name__ =='__main__':
    main()