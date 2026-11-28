Here is the Python code to solve the problem:

def search_events(event_records, date):
    events_on_date = [event for event in event_records if event.date == date]
    return events_on_date

The function `search_events` takes two arguments, `event_records` and `date`. `event_records` is a list of Event objects and `date` is a string representing the date of the events.

The function uses list comprehension to filter the `event_records` list to include only the events that have a `date` attribute equal to `date`. The filtered list is then returned.

The `Event` class could be a custom class with attributes such as `date`, `event_name`, `location`, etc. Make sure the input `event_records` is a list of such objects.

For input handling, you can use the `input` function in Python. You can ask the user for a date and then parse it to a date object. Here is an example:

user_input = input("Enter a date (format: YYYY-MM-DD): ")
parsed_date = datetime.datetime.strptime(user_input, "%Y-%m-%d").date()

events_on_date = search_events(event_records, parsed_date)

for event in events_on_date:
    print(f"Event name: {event.event_name}, Location: {event.location}")

In this code, the user is asked to input a date in the format `YYYY-MM-DD`. The date is then parsed into a `date` object and passed to the `search_events` function. The function returns a list of events on that date and then prints the event name and location for each event in this list.