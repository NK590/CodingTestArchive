from collections import deque

def solution(cacheSize, cities):
    count = 0
    cache = deque()
    for city in cities:
        city = city.lower()
        if city in cache:
            cache.remove(city)
            cache.append(city)
            count += 1
        else:
            if len(cache) < cacheSize:
                cache.append(city)
            elif len(cache) == cacheSize:
                cache.append(city)
                cache.popleft()
            count += 5
    return count