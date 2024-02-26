import pandas as pd
csv_file=pd.read_csv("covid_19_data.csv")
words1=csv_file["Country/Region"].values
words2=csv_file["Confirmed"].values
for word1,word2 in zip(words1,words2):
	print("%s\t%s"%(word1,word2))