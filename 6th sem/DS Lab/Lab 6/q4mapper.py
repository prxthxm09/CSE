import sys
import pandas as pd

# Heart Disease
df = pd.read_csv('heart_disease_data.csv')
df = df.dropna()
words = list(df['age'].values)

# Covid 19
df = pd.read_csv('covid_19_data.csv')
df = df.dropna()
words = list(df['Country/Region'].values)

# Example
df = pd.read_csv('example.txt', delimiter='\t')
df.columns = ['date', 'time', 'city', 'type', 'amount', 'payment']
df = df.dropna()
words = list(df['type'].values)

# German Credit Dataset
df = pd.read_csv('german_credit.csv')
df = df.dropna()
words = list(df['DurationOfCreditInMonths'].values)

def main(separator=' --> '):
    for word in words:
        print('%s%s%d' % (word, separator, 1))

if __name__ == "__main__":
    main()
