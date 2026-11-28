# problem title : Convert Seconds to Hours Minutes Seconds
# Split total seconds into hours, minutes, then leftover seconds.
total = int(input())
hours, rem = divmod(total, 3600)
minutes, seconds = divmod(rem, 60)
print(hours, minutes, seconds)
