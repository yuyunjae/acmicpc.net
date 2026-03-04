# not complete 

import pandas as pd



def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers.loc[customers['id'].isin(orders['customerid'])]
    
