import sys

input = sys.stdin.readline

n, m = map(int, input().split())
personList = [x+1 for x in range(n)]
truthPersonCount, *truthPersonList = map(int, input().split())
truthPersonSet = set(truthPersonList)

partyList = []
count = []

for _ in range(m):
    partyPersonCount, *partyPersonList = map(int, input().split())
    partyList.append(set(partyPersonList))
    count.append(True)

for _ in range(m):
    for i, party in enumerate(partyList):
        if truthPersonSet.intersection(party):
            count[i] = False
            truthPersonSet = truthPersonSet.union(party)

print(sum([1 for x in count if x == True]))