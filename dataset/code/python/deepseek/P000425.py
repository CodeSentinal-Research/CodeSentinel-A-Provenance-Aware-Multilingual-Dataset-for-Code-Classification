Sure, I can provide you with the Python code to solve the problem. In this code, we use SQLite for database operations and pandas for data handling.

import sqlite3
import pandas as pd

def get_inactive_accounts(accounts, inactivity_period):
    conn = sqlite3.connect('banking_system.db')

    df = pd.DataFrame(accounts)

    inactivity_period_days = inactivity_period * 30

    recent_transactions = df.loc[pd.Timestamp(df['last_transaction_date']) >= pd.Timestamp('now') - pd.Timedelta(days=inactivity_period_days)]

    inactive_accounts = df[~recent_transactions.index.isin(df.index)]

    conn.close()

    return inactive_accounts

The `get_inactive_accounts` function connects to a SQLite database named `banking_system.db` and retrieves accounts from this database. It then creates a pandas DataFrame from the accounts. The inactivity period is converted into days and the number of days from now. 

Next, it retrieves all transactions from the past inactivity period. Then, it checks which accounts did not have any transactions in the past inactivity period by using the `~` operator with `recent_transactions.index.isin(df.index)`.

Finally, it returns the inactive accounts. 

Note: This is a simplified example and may need to be adjusted depending on the specifics of your database schema and your actual data.