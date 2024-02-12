from
future
import print_function
import sys
# input comes from STDIN (standard input)
for line in sys.stdin:
word, count = line.strip().split('\t', 1)
count = int(count)
print( '%d\t%s' % (count, word) )