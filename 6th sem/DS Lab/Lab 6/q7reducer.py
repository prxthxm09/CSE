import fileinput
odd_cnt=0
even_cnt=0
for line in fileinput.input():
	cur_type,cur_count=line.strip().split("\t")
	if cur_type=="Even":
		even_cnt+=int(cur_count)
	else:
		odd_cnt+=int(cur_count)
print("%s\t%s\n"%("Odd",odd_cnt))
print("%s\t%s\n"%("Even",even_cnt))