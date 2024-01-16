import pandas as pd

data = {'Name': ['John', 'Alice', 'Bob'],
        'Quiz_1': [8, 9, 7],
        'In-Sem_1': [12, 14, 10],
        'Quiz_2': [7, 8, 9],
        'In-Sem_2': [13, 11, 14]}

df = pd.DataFrame(data)

df['Total'] = df[['Quiz_1', 'In-Sem_1', 'Quiz_2', 'In-Sem_2']].sum(axis=1)

column_means = df[['Quiz_1', 'In-Sem_1', 'Quiz_2', 'In-Sem_2', 'Total']].mean(axis=0)

df.loc['Mean'] =  ['NaN']  + list(column_means)

print(df)
