import pandas as pd

df1 = pd.DataFrame({'Name': ['John', 'Alice', 'Bob']})
df2 = pd.DataFrame({'Maths': [90, 85, 78],
                    'Physics': [88, 76, 90],
                    'Chemistry': [75, 82, 88],
                    'Biology': [92, 89, 78]})

df_new = pd.concat([df1, df2], axis=1)

df_new['Total'] = df_new[['Maths', 'Physics', 'Chemistry', 'Biology']].sum(axis=1)

print(df_new)
