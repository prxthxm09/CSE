import pandas as pd

students_data = {'Name': ['John', 'Alice', 'Bob'],
                 'Height': [170, 160, 175],
                 'Qualification': ['BSc', 'MSc', 'PhD']}

df = pd.DataFrame(students_data)
df.insert(2, "Age", [21, 23, 24])
print(df)
