from __future__ import print_function 
from operator import itemgetter 
import sys
sum = 0 
for line in sys.stdin:
    line = line.strip()
    word, count = line.split('\t', 1)
    try: 
count = float(count) 
    except ValueError: 
# count was not a number, so silently
# ignore/discard this line
#print( "--skipping (%s, %s)" % ( str(word), str(count) ) )
        continue 
    sum += count 
print( '%1.10f\t0' % sum ) 
