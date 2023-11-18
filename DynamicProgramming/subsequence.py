import time

N=900
arr = ""

def subsequence(s1,i,s2,j):
    if i<0 or j<0:
        return 0
    if s1[i] == s2[j]:
        return 1 + subsequence(s1,i-1,s2,j-1)
    else:
        return max(subsequence(s1,i-1,s2,j),subsequence(s1,i,s2,j-1))

def main():
    s1 = "Helloji"
    s2 = "Hello"
    print(subsequence(s1,len(s1)-1,s2,len(s2)-1))
    print(arr)

if __name__ =='__main__':
    main()