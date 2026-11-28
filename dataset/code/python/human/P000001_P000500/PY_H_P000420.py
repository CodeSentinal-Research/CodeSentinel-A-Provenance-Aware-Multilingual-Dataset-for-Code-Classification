# app.py
from flask import Flask, render_template, request, redirect, url_for, flash
from models.car import Car  # Add this import
from main import ParkingManagement

app = Flask(__name__)
app.secret_key = 'your_secret_key_here'

parking_system = ParkingManagement()


@app.route('/')
def index():
    status = {
        'total_slots': parking_system.capacity,
        'available_slots': len(parking_system.available_slots),
        'occupied_slots': len(parking_system.occupied_slots),
        'cars': [ticket for ticket in parking_system.occupied_slots.values()]
    }
    return render_template('index.html', status=status)


@app.route('/create', methods=['POST'])
def create_parking():
    capacity = request.form.get('capacity')
    if capacity and capacity.isdigit():
        parking_system.create_parking_slots(int(capacity))
        flash(f'Successfully created parking lot with {capacity} slots!', 'success')
    else:
        flash('Invalid capacity value!', 'danger')
    return redirect(url_for('index'))


@app.route('/park', methods=['POST'])
def park_car():
    reg_number = request.form.get('registration')
    age = request.form.get('age')

    if not reg_number or not age:
        flash('Both registration number and age are required!', 'danger')
        return redirect(url_for('index'))

    car = Car(reg_number, age)
    slot = parking_system.allocate_slot(car)

    if slot == -1:
        flash('Parking lot is full!', 'danger')
    else:
        flash(f'Car parked successfully in slot {slot}!', 'success')
    return redirect(url_for('index'))


@app.route('/leave', methods=['POST'])
def leave_slot():
    slot = request.form.get('slot')
    if slot and slot.isdigit():
        ticket = parking_system.deallocate_slot(int(slot))
        if ticket:
            flash(f'Slot {slot} vacated successfully!', 'success')
        else:
            flash(f'Invalid slot number {slot}!', 'danger')
    else:
        flash('Please enter a valid slot number!', 'danger')
    return redirect(url_for('index'))


@app.route('/search', methods=['POST'])
def search():
    query_type = request.form.get('query_type')
    value = request.form.get('value')

    results = []
    if query_type == 'registration':
        ticket = parking_system.occupied_slots.get(value)
        results = [ticket] if ticket else []
    elif query_type == 'age_vehicles':
        results = [t for t in parking_system.occupied_slots.values()
                   if t.get_driver_age() == int(value)]
    elif query_type == 'age_slots':
        results = [t for t in parking_system.occupied_slots.values()
                   if t.get_driver_age() == int(value)]

    return render_template('search_results.html',
                           results=results,
                           query_type=query_type,
                           value=value)


if __name__ == '__main__':
    app.run(debug=True)