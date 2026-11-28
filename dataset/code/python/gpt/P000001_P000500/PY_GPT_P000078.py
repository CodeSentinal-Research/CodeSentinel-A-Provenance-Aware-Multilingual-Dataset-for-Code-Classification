# problem title : Convert Days to Years Weeks Days
# Convert days using 365-day years and seven-day weeks.
days = int(input())
years, days = divmod(days, 365)
weeks, days = divmod(days, 7)
print(years, weeks, days)
