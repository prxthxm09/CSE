import pandas as pd

students_data = {'Name': ['John', 'Alice', 'Bob'],
                 'Height': [170, 160, 175],
                 'Qualification': ['BSc', 'MSc', 'PhD']}

df = pd.DataFrame(students_data)

address_list = ['123 Main St', '456 Oak St', '789 Pine St']

df['Address'] = address_list
print(df)

